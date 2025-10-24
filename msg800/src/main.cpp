#include "protocolParser.h"
#include "protocolLexer.h"
#include "protocolBaseListener.h"

#include <vector>
#include <iostream>
#include <thread>
#include <cstdlib>

#include <boost/program_options.hpp>
#include <boost/asio.hpp>

#include <yy/ip_addr.h>
#include <yy/log.h>

#include "tunnel_server.h"
#include "protocol.h"


namespace po = boost::program_options;
using IP_Address = yy::IP_Address;
using NetworkProtocol = yy::msg800::NetworkProtocol;
using BirdNetworkProtocol = yy::msg800::BirdNetworkProtocol;

static void run(const IP_Address& local_addr,
                const IP_Address& remote_addr,
                std::unique_ptr<NetworkProtocol>,
                std::unique_ptr<NetworkProtocol>);

static std::unique_ptr<NetworkProtocol> parse_protocol(const std::string& protocol_desc);

int main(int argc, char* argv[])
{
    po::options_description desc("Usage: msg800 -l <local_peer> -r <remote_peer>");

    // clang-format off
    desc.add_options()
        ("help,h", "produce help message")
        ("local,l", po::value<std::string>(), "local peer")
        ("remote,r", po::value<std::string>(), "remote peer")
        ("downstream_protocol,d", po::value<std::string>()->default_value("none"), "downstream protocol")
        ("upstream_protocol,u", po::value<std::string>()->default_value("none"), "upstream protocol")
    ;
    // clang-format on

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);    

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    IP_Address local_addr;
    IP_Address remote_addr;

    if (vm.count("local")) {
        auto opt_local_addr = yy::parse_ip_addr(vm["local"].as<std::string>());
        if (opt_local_addr) {
            local_addr = *opt_local_addr;

            LOG(info) << "local_ip: " << (*opt_local_addr).ipv4;
            LOG(info) << "local_port: " << (*opt_local_addr).port;
        }
        else {
            std::cerr << "bad local_addr: " << vm["local"].as<std::string>() << std::endl;
            return 1;
        }
    }
    else {
        std::cerr << "must set a local_addr" << std::endl;
        return 1;
    }

    if (vm.count("remote")) {
        auto opt_remote_addr = yy::parse_ip_addr(vm["remote"].as<std::string>());
        if (opt_remote_addr) {
            remote_addr = *opt_remote_addr;

            LOG(info) << "remote_ip: " << (*opt_remote_addr).ipv4;
            LOG(info) << "remote_port: " << (*opt_remote_addr).port;
        }
        else {
            std::cerr << "bad remote_addr: " << vm["remote"].as<std::string>() << std::endl;
            return 1;
        }
    }
    else {
        std::cerr << "must set a remote_addr" << std::endl;
        return 1;
    }

    auto downstream_protocol = parse_protocol(vm["downstream_protocol"].as<std::string>());
    if (!downstream_protocol) {
        std::cerr << "parse downstream_protocol fail" << std::endl;
        return 1;
    }

    auto upstream_protocol   = parse_protocol(vm["upstream_protocol"].as<std::string>());
    if (!upstream_protocol) {
        std::cerr << "parse upstream_protocol fail" << std::endl;
        return 1;
    }

    run(local_addr, remote_addr, std::move(downstream_protocol), std::move(upstream_protocol));

    return 0;
}

void run(const IP_Address& local_addr,
         const IP_Address& remote_addr,

         std::unique_ptr<NetworkProtocol> downstream_protocol,
         std::unique_ptr<NetworkProtocol> upstream_protocol)
{
    try {
        boost::asio::io_context io_context;

        yy::msg800::TunnelServer tunnel_server(io_context,
                                               local_addr,
                                               remote_addr,
                                               std::move(downstream_protocol),
                                               std::move(upstream_protocol));
        tunnel_server.startup();

        io_context.run();

    } catch (std::exception& e) {
        std::cerr << e.what();
    }
}

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
        xor_key_ = std::stoi(ctx->U8()->getSymbol()->getText().c_str()+4, nullptr, 16);
    }

    void exitBird_param_key(protocolParser::Bird_param_keyContext* ctx) override
    {
        auto value = ctx->U8_16()->getSymbol()->getText();
        for (int i = 0; i < 16; i++) {
            auto    sz   = value.substr(4+i * 2, 2);
            uint8_t n    = std::stoi(sz, nullptr, 16);
            bird_key_[i] = n;
        }
    }

    void exitBird_param_iv(protocolParser::Bird_param_ivContext* ctx) override
    {
        auto value = ctx->U8_16()->getSymbol()->getText();
        for (int i = 0; i < 16; i++) {
            auto    sz  = value.substr(4+i * 2, 2);
            uint8_t n   = std::stoi(sz, nullptr, 16);
            bird_iv_[i] = n;
        }
    }


    void exitBird_param_key_str(protocolParser::Bird_param_key_strContext * ctx) override { 
        auto value = ctx->STR()->getSymbol()->getText();
        value.resize(16);
        std::copy(value.begin(), value.end(), bird_key_);   
    }

    void exitBird_param_iv_str(protocolParser::Bird_param_iv_strContext * ctx) override { 
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
