#include <stdarg.h>

#include <boost/predef.h>

#include <yy/ip_addr.h>

#include "ip_addrBaseListener.h"
#include "ip_addrLexer.h"
#include "ip_addrParser.h"

namespace yy {

class MyListener : public ip_addrBaseListener {
public:
    void exitIp_addr(ip_addrParser::Ip_addrContext* ctx) override
    {
    }

    void exitIpv4(ip_addrParser::Ipv4Context* ctx) override
    {
        std::stringstream ss;
        ss << ctx->NUM(0)->getSymbol()->getText() << ".";
        ss << ctx->NUM(1)->getSymbol()->getText() << ".";
        ss << ctx->NUM(2)->getSymbol()->getText() << ".";
        ss << ctx->NUM(3)->getSymbol()->getText();
        ip_addr_.ipv4 = ss.str();
    }

    void exitPort(ip_addrParser::PortContext* ctx) override
    {
        ip_addr_.port = atoi(ctx->NUM()->getSymbol()->getText().c_str());
    }

    const IP_Address& get_ip_addr() const
    {
        return ip_addr_;
    }

    MyListener() {
        ip_addr_.ipv4 = "127.0.0.1";
        ip_addr_.port = 8080;
    }

private:
    IP_Address ip_addr_;
};

class MyErrorListener : public antlr4::BaseErrorListener {
public:
    bool is_some_error() const {
        return some_error_;
    }

private:
    void syntaxError(antlr4::Recognizer* recognizer,
                     antlr4::Token*      offendingSymbol,
                     size_t              line,
                     size_t              charPositionInLine,
                     const std::string&  msg,
                     std::exception_ptr  e) override
    {
        some_error_ = true;
    }

    bool some_error_ = false;
};

std::optional<IP_Address> parse_ip_addr(const std::string& sz)
{
    MyErrorListener error_listener;

    antlr4::ANTLRInputStream  input(sz);
    ip_addrLexer              lexer(&input);
    antlr4::CommonTokenStream token_stream(&lexer);
    ip_addrParser             parser(&token_stream);

    lexer.removeErrorListeners();
    parser.removeErrorListeners();
    
    lexer.addErrorListener(&error_listener);
    parser.addErrorListener(&error_listener);

    auto* tree = parser.ip_addr();
    
    if(error_listener.is_some_error())
        return std::nullopt;

    MyListener listener;
    antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);



    return listener.get_ip_addr();
}

} // namespace yy


