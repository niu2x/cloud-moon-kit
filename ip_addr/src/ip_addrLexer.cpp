
// Generated from ip_addr/src/ip_addr.g4 by ANTLR 4.13.2


#include "ip_addrLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct Ip_addrLexerStaticData final {
  Ip_addrLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Ip_addrLexerStaticData(const Ip_addrLexerStaticData&) = delete;
  Ip_addrLexerStaticData(Ip_addrLexerStaticData&&) = delete;
  Ip_addrLexerStaticData& operator=(const Ip_addrLexerStaticData&) = delete;
  Ip_addrLexerStaticData& operator=(Ip_addrLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ip_addrlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Ip_addrLexerStaticData> ip_addrlexerLexerStaticData = nullptr;

void ip_addrlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (ip_addrlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(ip_addrlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Ip_addrLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "NUM", "NEWLINE", "SPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "':'", "'.'"
    },
    std::vector<std::string>{
      "", "", "", "NUM", "NEWLINE", "SPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,5,34,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,1,0,1,1,1,1,
  	1,2,4,2,17,8,2,11,2,12,2,18,1,3,4,3,22,8,3,11,3,12,3,23,1,3,1,3,1,4,4,
  	4,29,8,4,11,4,12,4,30,1,4,1,4,0,0,5,1,1,3,2,5,3,7,4,9,5,1,0,3,1,0,48,
  	57,2,0,10,10,13,13,2,0,9,9,32,32,36,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,
  	0,0,7,1,0,0,0,0,9,1,0,0,0,1,11,1,0,0,0,3,13,1,0,0,0,5,16,1,0,0,0,7,21,
  	1,0,0,0,9,28,1,0,0,0,11,12,5,58,0,0,12,2,1,0,0,0,13,14,5,46,0,0,14,4,
  	1,0,0,0,15,17,7,0,0,0,16,15,1,0,0,0,17,18,1,0,0,0,18,16,1,0,0,0,18,19,
  	1,0,0,0,19,6,1,0,0,0,20,22,7,1,0,0,21,20,1,0,0,0,22,23,1,0,0,0,23,21,
  	1,0,0,0,23,24,1,0,0,0,24,25,1,0,0,0,25,26,6,3,0,0,26,8,1,0,0,0,27,29,
  	7,2,0,0,28,27,1,0,0,0,29,30,1,0,0,0,30,28,1,0,0,0,30,31,1,0,0,0,31,32,
  	1,0,0,0,32,33,6,4,0,0,33,10,1,0,0,0,4,0,18,23,30,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ip_addrlexerLexerStaticData = std::move(staticData);
}

}

ip_addrLexer::ip_addrLexer(CharStream *input) : Lexer(input) {
  ip_addrLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *ip_addrlexerLexerStaticData->atn, ip_addrlexerLexerStaticData->decisionToDFA, ip_addrlexerLexerStaticData->sharedContextCache);
}

ip_addrLexer::~ip_addrLexer() {
  delete _interpreter;
}

std::string ip_addrLexer::getGrammarFileName() const {
  return "ip_addr.g4";
}

const std::vector<std::string>& ip_addrLexer::getRuleNames() const {
  return ip_addrlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ip_addrLexer::getChannelNames() const {
  return ip_addrlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ip_addrLexer::getModeNames() const {
  return ip_addrlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ip_addrLexer::getVocabulary() const {
  return ip_addrlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ip_addrLexer::getSerializedATN() const {
  return ip_addrlexerLexerStaticData->serializedATN;
}

const atn::ATN& ip_addrLexer::getATN() const {
  return *ip_addrlexerLexerStaticData->atn;
}




void ip_addrLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  ip_addrlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(ip_addrlexerLexerOnceFlag, ip_addrlexerLexerInitialize);
#endif
}
