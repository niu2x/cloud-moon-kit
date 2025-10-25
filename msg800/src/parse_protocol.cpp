#include "protocolParser.h"
#include "protocolLexer.h"
#include "protocolBaseListener.h"

#include <cstdlib>

#include "protocol.h"

using NetworkProtocol     = yy::msg800::NetworkProtocol;
using BirdNetworkProtocol = yy::msg800::BirdNetworkProtocol;

class MyErrorListener : public antlr4::BaseErrorListener {
public:
    bool is_some_error() const
    {
        return some_error_;
    }

private:
    void syntaxError(antlr4::Recognizer*,
                     antlr4::Token*,
                     size_t,
                     size_t,
                     const std::string&,
                     std::exception_ptr) override
    {
        some_error_ = true;
    }

    bool some_error_ = false;
};

class MyListener : public protocolBaseListener {
public:
    void exitProtocol_none(protocolParser::Protocol_noneContext*) override
    {
        protocol_ = std::make_unique<yy::msg800::NoneNetworkProtocol>();
    }

    void exitProtocol_bird(protocolParser::Protocol_birdContext*) override
    {
        protocol_ = std::make_unique<BirdNetworkProtocol>(bird_key_, bird_iv_);
    }

    void exitProtocol_xor(protocolParser::Protocol_xorContext*) override
    {
        protocol_ = std::make_unique<yy::msg800::XOR_NetworkProtocol>(xor_key_);
    }

    void exitXor(protocolParser::XorContext* ctx) override
    {
        xor_key_ = std::stoi(ctx->U8()->getSymbol()->getText().c_str() + 4, nullptr, 16);
    }

    void exitBird_param_key(protocolParser::Bird_param_keyContext* ctx) override
    {
        auto value = ctx->U8_16()->getSymbol()->getText();
        for (int i = 0; i < 16; i++) {
            auto    sz   = value.substr(4 + i * 2, 2);
            uint8_t n    = std::stoi(sz, nullptr, 16);
            bird_key_[i] = n;
        }
    }

    void exitBird_param_iv(protocolParser::Bird_param_ivContext* ctx) override
    {
        auto value = ctx->U8_16()->getSymbol()->getText();
        for (int i = 0; i < 16; i++) {
            auto    sz  = value.substr(4 + i * 2, 2);
            uint8_t n   = std::stoi(sz, nullptr, 16);
            bird_iv_[i] = n;
        }
    }

    void exitBird_param_key_str(protocolParser::Bird_param_key_strContext* ctx) override
    {
        auto value = ctx->STR()->getSymbol()->getText();
        value.resize(16);
        std::copy(value.begin(), value.end(), bird_key_);
    }

    void exitBird_param_iv_str(protocolParser::Bird_param_iv_strContext* ctx) override
    {
        auto value = ctx->STR()->getSymbol()->getText();
        value.resize(16);
        std::copy(value.begin(), value.end(), bird_iv_);
    }

    std::unique_ptr<NetworkProtocol>& get_protocol()
    {
        return protocol_;
    }

    MyListener()
    {
        const char* bird_key_str = std::getenv("MSG800_BIRD_KEY_STR"); // 获取环境变量 PATH
        if (bird_key_str) {
            std::string value(bird_key_str);
            value.resize(16);
            std::copy(value.begin(), value.end(), bird_key_);
        }

        const char* bird_iv_str = std::getenv("MSG800_BIRD_IV_STR"); // 获取环境变量 PATH
        if (bird_iv_str) {
            std::string value(bird_iv_str);
            value.resize(16);
            std::copy(value.begin(), value.end(), bird_iv_);
        }
    }

private:
    std::unique_ptr<NetworkProtocol> protocol_;

    uint8_t xor_key_ = 0;

    BirdNetworkProtocol::Crypto::Key bird_key_;
    BirdNetworkProtocol::Crypto::IV  bird_iv_;
};

std::unique_ptr<NetworkProtocol> parse_protocol(const std::string& protocol_desc)
{
    MyErrorListener error_listener;

    antlr4::ANTLRInputStream  input(protocol_desc);
    protocolLexer             lexer(&input);
    antlr4::CommonTokenStream token_stream(&lexer);
    protocolParser            parser(&token_stream);

    lexer.removeErrorListeners();
    parser.removeErrorListeners();

    lexer.addErrorListener(&error_listener);
    parser.addErrorListener(&error_listener);

    auto* tree = parser.protocol();

    if (error_listener.is_some_error()) {
        return nullptr;
    }

    MyListener listener;
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    return std::move(listener.get_protocol());
}
