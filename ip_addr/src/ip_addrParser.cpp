
// Generated from ip_addr/src/ip_addr.g4 by ANTLR 4.13.2


#include "ip_addrListener.h"

#include "ip_addrParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Ip_addrParserStaticData final {
  Ip_addrParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Ip_addrParserStaticData(const Ip_addrParserStaticData&) = delete;
  Ip_addrParserStaticData(Ip_addrParserStaticData&&) = delete;
  Ip_addrParserStaticData& operator=(const Ip_addrParserStaticData&) = delete;
  Ip_addrParserStaticData& operator=(Ip_addrParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ip_addrParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Ip_addrParserStaticData> ip_addrParserStaticData = nullptr;

void ip_addrParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ip_addrParserStaticData != nullptr) {
    return;
  }
#else
  assert(ip_addrParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Ip_addrParserStaticData>(
    std::vector<std::string>{
      "ip_addr", "ip", "ipv4", "port"
    },
    std::vector<std::string>{
      "", "':'", "'.'", "", "'localhost'"
    },
    std::vector<std::string>{
      "", "", "", "NUM", "LOCAL", "NEWLINE", "SPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,6,32,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
  	3,0,16,8,0,1,1,1,1,3,1,20,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,
  	1,3,0,0,4,0,2,4,6,0,0,30,0,15,1,0,0,0,2,19,1,0,0,0,4,21,1,0,0,0,6,29,
  	1,0,0,0,8,9,5,1,0,0,9,16,3,6,3,0,10,11,3,2,1,0,11,12,5,1,0,0,12,13,3,
  	6,3,0,13,16,1,0,0,0,14,16,3,2,1,0,15,8,1,0,0,0,15,10,1,0,0,0,15,14,1,
  	0,0,0,16,1,1,0,0,0,17,20,3,4,2,0,18,20,5,4,0,0,19,17,1,0,0,0,19,18,1,
  	0,0,0,20,3,1,0,0,0,21,22,5,3,0,0,22,23,5,2,0,0,23,24,5,3,0,0,24,25,5,
  	2,0,0,25,26,5,3,0,0,26,27,5,2,0,0,27,28,5,3,0,0,28,5,1,0,0,0,29,30,5,
  	3,0,0,30,7,1,0,0,0,2,15,19
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ip_addrParserStaticData = std::move(staticData);
}

}

ip_addrParser::ip_addrParser(TokenStream *input) : ip_addrParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ip_addrParser::ip_addrParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ip_addrParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *ip_addrParserStaticData->atn, ip_addrParserStaticData->decisionToDFA, ip_addrParserStaticData->sharedContextCache, options);
}

ip_addrParser::~ip_addrParser() {
  delete _interpreter;
}

const atn::ATN& ip_addrParser::getATN() const {
  return *ip_addrParserStaticData->atn;
}

std::string ip_addrParser::getGrammarFileName() const {
  return "ip_addr.g4";
}

const std::vector<std::string>& ip_addrParser::getRuleNames() const {
  return ip_addrParserStaticData->ruleNames;
}

const dfa::Vocabulary& ip_addrParser::getVocabulary() const {
  return ip_addrParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ip_addrParser::getSerializedATN() const {
  return ip_addrParserStaticData->serializedATN;
}


//----------------- Ip_addrContext ------------------------------------------------------------------

ip_addrParser::Ip_addrContext::Ip_addrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ip_addrParser::PortContext* ip_addrParser::Ip_addrContext::port() {
  return getRuleContext<ip_addrParser::PortContext>(0);
}

ip_addrParser::IpContext* ip_addrParser::Ip_addrContext::ip() {
  return getRuleContext<ip_addrParser::IpContext>(0);
}


size_t ip_addrParser::Ip_addrContext::getRuleIndex() const {
  return ip_addrParser::RuleIp_addr;
}

void ip_addrParser::Ip_addrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ip_addrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIp_addr(this);
}

void ip_addrParser::Ip_addrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ip_addrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIp_addr(this);
}

ip_addrParser::Ip_addrContext* ip_addrParser::ip_addr() {
  Ip_addrContext *_localctx = _tracker.createInstance<Ip_addrContext>(_ctx, getState());
  enterRule(_localctx, 0, ip_addrParser::RuleIp_addr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(15);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(8);
      match(ip_addrParser::T__0);
      setState(9);
      port();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(10);
      ip();
      setState(11);
      match(ip_addrParser::T__0);
      setState(12);
      port();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(14);
      ip();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IpContext ------------------------------------------------------------------

ip_addrParser::IpContext::IpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ip_addrParser::Ipv4Context* ip_addrParser::IpContext::ipv4() {
  return getRuleContext<ip_addrParser::Ipv4Context>(0);
}

tree::TerminalNode* ip_addrParser::IpContext::LOCAL() {
  return getToken(ip_addrParser::LOCAL, 0);
}


size_t ip_addrParser::IpContext::getRuleIndex() const {
  return ip_addrParser::RuleIp;
}

void ip_addrParser::IpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ip_addrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIp(this);
}

void ip_addrParser::IpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ip_addrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIp(this);
}

ip_addrParser::IpContext* ip_addrParser::ip() {
  IpContext *_localctx = _tracker.createInstance<IpContext>(_ctx, getState());
  enterRule(_localctx, 2, ip_addrParser::RuleIp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(19);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ip_addrParser::NUM: {
        enterOuterAlt(_localctx, 1);
        setState(17);
        ipv4();
        break;
      }

      case ip_addrParser::LOCAL: {
        enterOuterAlt(_localctx, 2);
        setState(18);
        match(ip_addrParser::LOCAL);
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

//----------------- Ipv4Context ------------------------------------------------------------------

ip_addrParser::Ipv4Context::Ipv4Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ip_addrParser::Ipv4Context::NUM() {
  return getTokens(ip_addrParser::NUM);
}

tree::TerminalNode* ip_addrParser::Ipv4Context::NUM(size_t i) {
  return getToken(ip_addrParser::NUM, i);
}


size_t ip_addrParser::Ipv4Context::getRuleIndex() const {
  return ip_addrParser::RuleIpv4;
}

void ip_addrParser::Ipv4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ip_addrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIpv4(this);
}

void ip_addrParser::Ipv4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ip_addrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIpv4(this);
}

ip_addrParser::Ipv4Context* ip_addrParser::ipv4() {
  Ipv4Context *_localctx = _tracker.createInstance<Ipv4Context>(_ctx, getState());
  enterRule(_localctx, 4, ip_addrParser::RuleIpv4);

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
    match(ip_addrParser::NUM);
    setState(22);
    match(ip_addrParser::T__1);
    setState(23);
    match(ip_addrParser::NUM);
    setState(24);
    match(ip_addrParser::T__1);
    setState(25);
    match(ip_addrParser::NUM);
    setState(26);
    match(ip_addrParser::T__1);
    setState(27);
    match(ip_addrParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortContext ------------------------------------------------------------------

ip_addrParser::PortContext::PortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ip_addrParser::PortContext::NUM() {
  return getToken(ip_addrParser::NUM, 0);
}


size_t ip_addrParser::PortContext::getRuleIndex() const {
  return ip_addrParser::RulePort;
}

void ip_addrParser::PortContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ip_addrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPort(this);
}

void ip_addrParser::PortContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ip_addrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPort(this);
}

ip_addrParser::PortContext* ip_addrParser::port() {
  PortContext *_localctx = _tracker.createInstance<PortContext>(_ctx, getState());
  enterRule(_localctx, 6, ip_addrParser::RulePort);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29);
    match(ip_addrParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void ip_addrParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ip_addrParserInitialize();
#else
  ::antlr4::internal::call_once(ip_addrParserOnceFlag, ip_addrParserInitialize);
#endif
}
