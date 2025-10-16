
// Generated from msg800/src/protocol.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "protocolListener.h"


/**
 * This class provides an empty implementation of protocolListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  protocolBaseListener : public protocolListener {
public:

  virtual void enterProtocol_none(protocolParser::Protocol_noneContext * /*ctx*/) override { }
  virtual void exitProtocol_none(protocolParser::Protocol_noneContext * /*ctx*/) override { }

  virtual void enterProtocol_bird(protocolParser::Protocol_birdContext * /*ctx*/) override { }
  virtual void exitProtocol_bird(protocolParser::Protocol_birdContext * /*ctx*/) override { }

  virtual void enterProtocol_xor(protocolParser::Protocol_xorContext * /*ctx*/) override { }
  virtual void exitProtocol_xor(protocolParser::Protocol_xorContext * /*ctx*/) override { }

  virtual void enterNone(protocolParser::NoneContext * /*ctx*/) override { }
  virtual void exitNone(protocolParser::NoneContext * /*ctx*/) override { }

  virtual void enterBird(protocolParser::BirdContext * /*ctx*/) override { }
  virtual void exitBird(protocolParser::BirdContext * /*ctx*/) override { }

  virtual void enterXor(protocolParser::XorContext * /*ctx*/) override { }
  virtual void exitXor(protocolParser::XorContext * /*ctx*/) override { }

  virtual void enterBird_params_part(protocolParser::Bird_params_partContext * /*ctx*/) override { }
  virtual void exitBird_params_part(protocolParser::Bird_params_partContext * /*ctx*/) override { }

  virtual void enterBird_params(protocolParser::Bird_paramsContext * /*ctx*/) override { }
  virtual void exitBird_params(protocolParser::Bird_paramsContext * /*ctx*/) override { }

  virtual void enterBird_param_key(protocolParser::Bird_param_keyContext * /*ctx*/) override { }
  virtual void exitBird_param_key(protocolParser::Bird_param_keyContext * /*ctx*/) override { }

  virtual void enterBird_param_iv(protocolParser::Bird_param_ivContext * /*ctx*/) override { }
  virtual void exitBird_param_iv(protocolParser::Bird_param_ivContext * /*ctx*/) override { }

  virtual void enterBird_param_key_str(protocolParser::Bird_param_key_strContext * /*ctx*/) override { }
  virtual void exitBird_param_key_str(protocolParser::Bird_param_key_strContext * /*ctx*/) override { }

  virtual void enterBird_param_iv_str(protocolParser::Bird_param_iv_strContext * /*ctx*/) override { }
  virtual void exitBird_param_iv_str(protocolParser::Bird_param_iv_strContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

