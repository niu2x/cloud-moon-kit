
// Generated from msg800/src/protocol.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  protocolParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, U8 = 12, U8_16 = 13, STR = 14, 
    NEWLINE = 15, SPACE = 16
  };

  enum {
    RuleProtocol = 0, RuleNone = 1, RuleBird = 2, RuleXor = 3, RuleBird_params_part = 4, 
    RuleBird_params = 5, RuleBird_param = 6
  };

  explicit protocolParser(antlr4::TokenStream *input);

  protocolParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~protocolParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProtocolContext;
  class NoneContext;
  class BirdContext;
  class XorContext;
  class Bird_params_partContext;
  class Bird_paramsContext;
  class Bird_paramContext; 

  class  ProtocolContext : public antlr4::ParserRuleContext {
  public:
    ProtocolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ProtocolContext() = default;
    void copyFrom(ProtocolContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Protocol_noneContext : public ProtocolContext {
  public:
    Protocol_noneContext(ProtocolContext *ctx);

    NoneContext *none();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Protocol_birdContext : public ProtocolContext {
  public:
    Protocol_birdContext(ProtocolContext *ctx);

    BirdContext *bird();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Protocol_xorContext : public ProtocolContext {
  public:
    Protocol_xorContext(ProtocolContext *ctx);

    XorContext *xor_();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  ProtocolContext* protocol();

  class  NoneContext : public antlr4::ParserRuleContext {
  public:
    NoneContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NoneContext* none();

  class  BirdContext : public antlr4::ParserRuleContext {
  public:
    BirdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Bird_params_partContext *bird_params_part();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BirdContext* bird();

  class  XorContext : public antlr4::ParserRuleContext {
  public:
    XorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *U8();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  XorContext* xor_();

  class  Bird_params_partContext : public antlr4::ParserRuleContext {
  public:
    Bird_params_partContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Bird_paramsContext *bird_params();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Bird_params_partContext* bird_params_part();

  class  Bird_paramsContext : public antlr4::ParserRuleContext {
  public:
    Bird_paramsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Bird_paramContext *> bird_param();
    Bird_paramContext* bird_param(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Bird_paramsContext* bird_params();

  class  Bird_paramContext : public antlr4::ParserRuleContext {
  public:
    Bird_paramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Bird_paramContext() = default;
    void copyFrom(Bird_paramContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Bird_param_ivContext : public Bird_paramContext {
  public:
    Bird_param_ivContext(Bird_paramContext *ctx);

    antlr4::tree::TerminalNode *U8_16();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Bird_param_keyContext : public Bird_paramContext {
  public:
    Bird_param_keyContext(Bird_paramContext *ctx);

    antlr4::tree::TerminalNode *U8_16();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Bird_param_iv_strContext : public Bird_paramContext {
  public:
    Bird_param_iv_strContext(Bird_paramContext *ctx);

    antlr4::tree::TerminalNode *STR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  Bird_param_key_strContext : public Bird_paramContext {
  public:
    Bird_param_key_strContext(Bird_paramContext *ctx);

    antlr4::tree::TerminalNode *STR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  Bird_paramContext* bird_param();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

