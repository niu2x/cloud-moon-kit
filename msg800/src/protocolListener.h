
// Generated from msg800/src/protocol.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "protocolParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by protocolParser.
 */
class  protocolListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProtocol_none(protocolParser::Protocol_noneContext *ctx) = 0;
  virtual void exitProtocol_none(protocolParser::Protocol_noneContext *ctx) = 0;

  virtual void enterProtocol_bird(protocolParser::Protocol_birdContext *ctx) = 0;
  virtual void exitProtocol_bird(protocolParser::Protocol_birdContext *ctx) = 0;

  virtual void enterProtocol_xor(protocolParser::Protocol_xorContext *ctx) = 0;
  virtual void exitProtocol_xor(protocolParser::Protocol_xorContext *ctx) = 0;

  virtual void enterNone(protocolParser::NoneContext *ctx) = 0;
  virtual void exitNone(protocolParser::NoneContext *ctx) = 0;

  virtual void enterBird(protocolParser::BirdContext *ctx) = 0;
  virtual void exitBird(protocolParser::BirdContext *ctx) = 0;

  virtual void enterXor(protocolParser::XorContext *ctx) = 0;
  virtual void exitXor(protocolParser::XorContext *ctx) = 0;

  virtual void enterBird_params_part(protocolParser::Bird_params_partContext *ctx) = 0;
  virtual void exitBird_params_part(protocolParser::Bird_params_partContext *ctx) = 0;

  virtual void enterBird_params(protocolParser::Bird_paramsContext *ctx) = 0;
  virtual void exitBird_params(protocolParser::Bird_paramsContext *ctx) = 0;

  virtual void enterBird_param_key(protocolParser::Bird_param_keyContext *ctx) = 0;
  virtual void exitBird_param_key(protocolParser::Bird_param_keyContext *ctx) = 0;

  virtual void enterBird_param_iv(protocolParser::Bird_param_ivContext *ctx) = 0;
  virtual void exitBird_param_iv(protocolParser::Bird_param_ivContext *ctx) = 0;

  virtual void enterBird_param_key_str(protocolParser::Bird_param_key_strContext *ctx) = 0;
  virtual void exitBird_param_key_str(protocolParser::Bird_param_key_strContext *ctx) = 0;

  virtual void enterBird_param_iv_str(protocolParser::Bird_param_iv_strContext *ctx) = 0;
  virtual void exitBird_param_iv_str(protocolParser::Bird_param_iv_strContext *ctx) = 0;


};

