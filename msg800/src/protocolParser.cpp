
// Generated from msg800/src/protocol.g4 by ANTLR 4.13.2


#include "protocolListener.h"

#include "protocolParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ProtocolParserStaticData final {
  ProtocolParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ProtocolParserStaticData(const ProtocolParserStaticData&) = delete;
  ProtocolParserStaticData(ProtocolParserStaticData&&) = delete;
  ProtocolParserStaticData& operator=(const ProtocolParserStaticData&) = delete;
  ProtocolParserStaticData& operator=(ProtocolParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag protocolParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<ProtocolParserStaticData> protocolParserStaticData = nullptr;

void protocolParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (protocolParserStaticData != nullptr) {
    return;
  }
#else
  assert(protocolParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ProtocolParserStaticData>(
    std::vector<std::string>{
      "protocol", "none", "bird", "xor", "bird_params_part", "bird_params", 
      "bird_param"
    },
    std::vector<std::string>{
      "", "'none'", "'bird'", "'xor'", "'('", "')'", "','", "'key'", "'='", 
      "'iv'", "'key_str'", "'iv_str'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "U8", "U8_16", "STR", 
      "NEWLINE", "SPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,16,62,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	1,0,1,0,3,0,18,8,0,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,
  	4,1,4,1,4,3,4,35,8,4,1,5,1,5,1,5,1,5,5,5,41,8,5,10,5,12,5,44,9,5,3,5,
  	46,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,60,8,6,1,6,
  	0,0,7,0,2,4,6,8,10,12,0,0,62,0,17,1,0,0,0,2,19,1,0,0,0,4,21,1,0,0,0,6,
  	24,1,0,0,0,8,34,1,0,0,0,10,45,1,0,0,0,12,59,1,0,0,0,14,18,3,2,1,0,15,
  	18,3,4,2,0,16,18,3,6,3,0,17,14,1,0,0,0,17,15,1,0,0,0,17,16,1,0,0,0,18,
  	1,1,0,0,0,19,20,5,1,0,0,20,3,1,0,0,0,21,22,5,2,0,0,22,23,3,8,4,0,23,5,
  	1,0,0,0,24,25,5,3,0,0,25,26,5,4,0,0,26,27,5,12,0,0,27,28,5,5,0,0,28,7,
  	1,0,0,0,29,30,5,4,0,0,30,31,3,10,5,0,31,32,5,5,0,0,32,35,1,0,0,0,33,35,
  	1,0,0,0,34,29,1,0,0,0,34,33,1,0,0,0,35,9,1,0,0,0,36,46,1,0,0,0,37,42,
  	3,12,6,0,38,39,5,6,0,0,39,41,3,12,6,0,40,38,1,0,0,0,41,44,1,0,0,0,42,
  	40,1,0,0,0,42,43,1,0,0,0,43,46,1,0,0,0,44,42,1,0,0,0,45,36,1,0,0,0,45,
  	37,1,0,0,0,46,11,1,0,0,0,47,48,5,7,0,0,48,49,5,8,0,0,49,60,5,13,0,0,50,
  	51,5,9,0,0,51,52,5,8,0,0,52,60,5,13,0,0,53,54,5,10,0,0,54,55,5,8,0,0,
  	55,60,5,14,0,0,56,57,5,11,0,0,57,58,5,8,0,0,58,60,5,14,0,0,59,47,1,0,
  	0,0,59,50,1,0,0,0,59,53,1,0,0,0,59,56,1,0,0,0,60,13,1,0,0,0,5,17,34,42,
  	45,59
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  protocolParserStaticData = std::move(staticData);
}

}

protocolParser::protocolParser(TokenStream *input) : protocolParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

protocolParser::protocolParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  protocolParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *protocolParserStaticData->atn, protocolParserStaticData->decisionToDFA, protocolParserStaticData->sharedContextCache, options);
}

protocolParser::~protocolParser() {
  delete _interpreter;
}

const atn::ATN& protocolParser::getATN() const {
  return *protocolParserStaticData->atn;
}

std::string protocolParser::getGrammarFileName() const {
  return "protocol.g4";
}

const std::vector<std::string>& protocolParser::getRuleNames() const {
  return protocolParserStaticData->ruleNames;
}

const dfa::Vocabulary& protocolParser::getVocabulary() const {
  return protocolParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView protocolParser::getSerializedATN() const {
  return protocolParserStaticData->serializedATN;
}


//----------------- ProtocolContext ------------------------------------------------------------------

protocolParser::ProtocolContext::ProtocolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t protocolParser::ProtocolContext::getRuleIndex() const {
  return protocolParser::RuleProtocol;
}

void protocolParser::ProtocolContext::copyFrom(ProtocolContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Protocol_noneContext ------------------------------------------------------------------

protocolParser::NoneContext* protocolParser::Protocol_noneContext::none() {
  return getRuleContext<protocolParser::NoneContext>(0);
}

protocolParser::Protocol_noneContext::Protocol_noneContext(ProtocolContext *ctx) { copyFrom(ctx); }

void protocolParser::Protocol_noneContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProtocol_none(this);
}
void protocolParser::Protocol_noneContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProtocol_none(this);
}
//----------------- Protocol_birdContext ------------------------------------------------------------------

protocolParser::BirdContext* protocolParser::Protocol_birdContext::bird() {
  return getRuleContext<protocolParser::BirdContext>(0);
}

protocolParser::Protocol_birdContext::Protocol_birdContext(ProtocolContext *ctx) { copyFrom(ctx); }

void protocolParser::Protocol_birdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProtocol_bird(this);
}
void protocolParser::Protocol_birdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProtocol_bird(this);
}
//----------------- Protocol_xorContext ------------------------------------------------------------------

protocolParser::XorContext* protocolParser::Protocol_xorContext::xor_() {
  return getRuleContext<protocolParser::XorContext>(0);
}

protocolParser::Protocol_xorContext::Protocol_xorContext(ProtocolContext *ctx) { copyFrom(ctx); }

void protocolParser::Protocol_xorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProtocol_xor(this);
}
void protocolParser::Protocol_xorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProtocol_xor(this);
}
protocolParser::ProtocolContext* protocolParser::protocol() {
  ProtocolContext *_localctx = _tracker.createInstance<ProtocolContext>(_ctx, getState());
  enterRule(_localctx, 0, protocolParser::RuleProtocol);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(17);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case protocolParser::T__0: {
        _localctx = _tracker.createInstance<protocolParser::Protocol_noneContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(14);
        none();
        break;
      }

      case protocolParser::T__1: {
        _localctx = _tracker.createInstance<protocolParser::Protocol_birdContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(15);
        bird();
        break;
      }

      case protocolParser::T__2: {
        _localctx = _tracker.createInstance<protocolParser::Protocol_xorContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(16);
        xor_();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoneContext ------------------------------------------------------------------

protocolParser::NoneContext::NoneContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t protocolParser::NoneContext::getRuleIndex() const {
  return protocolParser::RuleNone;
}

void protocolParser::NoneContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNone(this);
}

void protocolParser::NoneContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNone(this);
}

protocolParser::NoneContext* protocolParser::none() {
  NoneContext *_localctx = _tracker.createInstance<NoneContext>(_ctx, getState());
  enterRule(_localctx, 2, protocolParser::RuleNone);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(19);
    match(protocolParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BirdContext ------------------------------------------------------------------

protocolParser::BirdContext::BirdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

protocolParser::Bird_params_partContext* protocolParser::BirdContext::bird_params_part() {
  return getRuleContext<protocolParser::Bird_params_partContext>(0);
}


size_t protocolParser::BirdContext::getRuleIndex() const {
  return protocolParser::RuleBird;
}

void protocolParser::BirdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBird(this);
}

void protocolParser::BirdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBird(this);
}

protocolParser::BirdContext* protocolParser::bird() {
  BirdContext *_localctx = _tracker.createInstance<BirdContext>(_ctx, getState());
  enterRule(_localctx, 4, protocolParser::RuleBird);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    match(protocolParser::T__1);
    setState(22);
    bird_params_part();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- XorContext ------------------------------------------------------------------

protocolParser::XorContext::XorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* protocolParser::XorContext::U8() {
  return getToken(protocolParser::U8, 0);
}


size_t protocolParser::XorContext::getRuleIndex() const {
  return protocolParser::RuleXor;
}

void protocolParser::XorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXor(this);
}

void protocolParser::XorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXor(this);
}

protocolParser::XorContext* protocolParser::xor_() {
  XorContext *_localctx = _tracker.createInstance<XorContext>(_ctx, getState());
  enterRule(_localctx, 6, protocolParser::RuleXor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    match(protocolParser::T__2);
    setState(25);
    match(protocolParser::T__3);
    setState(26);
    match(protocolParser::U8);
    setState(27);
    match(protocolParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bird_params_partContext ------------------------------------------------------------------

protocolParser::Bird_params_partContext::Bird_params_partContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

protocolParser::Bird_paramsContext* protocolParser::Bird_params_partContext::bird_params() {
  return getRuleContext<protocolParser::Bird_paramsContext>(0);
}


size_t protocolParser::Bird_params_partContext::getRuleIndex() const {
  return protocolParser::RuleBird_params_part;
}

void protocolParser::Bird_params_partContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBird_params_part(this);
}

void protocolParser::Bird_params_partContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBird_params_part(this);
}

protocolParser::Bird_params_partContext* protocolParser::bird_params_part() {
  Bird_params_partContext *_localctx = _tracker.createInstance<Bird_params_partContext>(_ctx, getState());
  enterRule(_localctx, 8, protocolParser::RuleBird_params_part);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(34);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case protocolParser::T__3: {
        enterOuterAlt(_localctx, 1);
        setState(29);
        match(protocolParser::T__3);
        setState(30);
        bird_params();
        setState(31);
        match(protocolParser::T__4);
        break;
      }

      case protocolParser::EOF: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bird_paramsContext ------------------------------------------------------------------

protocolParser::Bird_paramsContext::Bird_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<protocolParser::Bird_paramContext *> protocolParser::Bird_paramsContext::bird_param() {
  return getRuleContexts<protocolParser::Bird_paramContext>();
}

protocolParser::Bird_paramContext* protocolParser::Bird_paramsContext::bird_param(size_t i) {
  return getRuleContext<protocolParser::Bird_paramContext>(i);
}


size_t protocolParser::Bird_paramsContext::getRuleIndex() const {
  return protocolParser::RuleBird_params;
}

void protocolParser::Bird_paramsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBird_params(this);
}

void protocolParser::Bird_paramsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBird_params(this);
}

protocolParser::Bird_paramsContext* protocolParser::bird_params() {
  Bird_paramsContext *_localctx = _tracker.createInstance<Bird_paramsContext>(_ctx, getState());
  enterRule(_localctx, 10, protocolParser::RuleBird_params);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(45);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case protocolParser::T__4: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case protocolParser::T__6:
      case protocolParser::T__8:
      case protocolParser::T__9:
      case protocolParser::T__10: {
        enterOuterAlt(_localctx, 2);
        setState(37);
        bird_param();
        setState(42);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == protocolParser::T__5) {
          setState(38);
          match(protocolParser::T__5);
          setState(39);
          bird_param();
          setState(44);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bird_paramContext ------------------------------------------------------------------

protocolParser::Bird_paramContext::Bird_paramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t protocolParser::Bird_paramContext::getRuleIndex() const {
  return protocolParser::RuleBird_param;
}

void protocolParser::Bird_paramContext::copyFrom(Bird_paramContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Bird_param_ivContext ------------------------------------------------------------------

tree::TerminalNode* protocolParser::Bird_param_ivContext::U8_16() {
  return getToken(protocolParser::U8_16, 0);
}

protocolParser::Bird_param_ivContext::Bird_param_ivContext(Bird_paramContext *ctx) { copyFrom(ctx); }

void protocolParser::Bird_param_ivContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBird_param_iv(this);
}
void protocolParser::Bird_param_ivContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBird_param_iv(this);
}
//----------------- Bird_param_keyContext ------------------------------------------------------------------

tree::TerminalNode* protocolParser::Bird_param_keyContext::U8_16() {
  return getToken(protocolParser::U8_16, 0);
}

protocolParser::Bird_param_keyContext::Bird_param_keyContext(Bird_paramContext *ctx) { copyFrom(ctx); }

void protocolParser::Bird_param_keyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBird_param_key(this);
}
void protocolParser::Bird_param_keyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBird_param_key(this);
}
//----------------- Bird_param_iv_strContext ------------------------------------------------------------------

tree::TerminalNode* protocolParser::Bird_param_iv_strContext::STR() {
  return getToken(protocolParser::STR, 0);
}

protocolParser::Bird_param_iv_strContext::Bird_param_iv_strContext(Bird_paramContext *ctx) { copyFrom(ctx); }

void protocolParser::Bird_param_iv_strContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBird_param_iv_str(this);
}
void protocolParser::Bird_param_iv_strContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBird_param_iv_str(this);
}
//----------------- Bird_param_key_strContext ------------------------------------------------------------------

tree::TerminalNode* protocolParser::Bird_param_key_strContext::STR() {
  return getToken(protocolParser::STR, 0);
}

protocolParser::Bird_param_key_strContext::Bird_param_key_strContext(Bird_paramContext *ctx) { copyFrom(ctx); }

void protocolParser::Bird_param_key_strContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBird_param_key_str(this);
}
void protocolParser::Bird_param_key_strContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<protocolListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBird_param_key_str(this);
}
protocolParser::Bird_paramContext* protocolParser::bird_param() {
  Bird_paramContext *_localctx = _tracker.createInstance<Bird_paramContext>(_ctx, getState());
  enterRule(_localctx, 12, protocolParser::RuleBird_param);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(59);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case protocolParser::T__6: {
        _localctx = _tracker.createInstance<protocolParser::Bird_param_keyContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(47);
        match(protocolParser::T__6);
        setState(48);
        match(protocolParser::T__7);
        setState(49);
        match(protocolParser::U8_16);
        break;
      }

      case protocolParser::T__8: {
        _localctx = _tracker.createInstance<protocolParser::Bird_param_ivContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(50);
        match(protocolParser::T__8);
        setState(51);
        match(protocolParser::T__7);
        setState(52);
        match(protocolParser::U8_16);
        break;
      }

      case protocolParser::T__9: {
        _localctx = _tracker.createInstance<protocolParser::Bird_param_key_strContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(53);
        match(protocolParser::T__9);
        setState(54);
        match(protocolParser::T__7);
        setState(55);
        match(protocolParser::STR);
        break;
      }

      case protocolParser::T__10: {
        _localctx = _tracker.createInstance<protocolParser::Bird_param_iv_strContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(56);
        match(protocolParser::T__10);
        setState(57);
        match(protocolParser::T__7);
        setState(58);
        match(protocolParser::STR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void protocolParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  protocolParserInitialize();
#else
  ::antlr4::internal::call_once(protocolParserOnceFlag, protocolParserInitialize);
#endif
}
