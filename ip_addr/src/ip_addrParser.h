
// Generated from ip_addr/src/ip_addr.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  ip_addrParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, NUM = 3, NEWLINE = 4, SPACE = 5
  };

  enum {
    RuleIp_addr = 0, RuleIp = 1, RuleIpv4 = 2, RulePort = 3
  };

  explicit ip_addrParser(antlr4::TokenStream *input);

  ip_addrParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ip_addrParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class Ip_addrContext;
  class IpContext;
  class Ipv4Context;
  class PortContext; 

  class  Ip_addrContext : public antlr4::ParserRuleContext {
  public:
    Ip_addrContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PortContext *port();
    IpContext *ip();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ip_addrContext* ip_addr();

  class  IpContext : public antlr4::ParserRuleContext {
  public:
    IpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ipv4Context *ipv4();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IpContext* ip();

  class  Ipv4Context : public antlr4::ParserRuleContext {
  public:
    Ipv4Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Ipv4Context* ipv4();

  class  PortContext : public antlr4::ParserRuleContext {
  public:
    PortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortContext* port();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

