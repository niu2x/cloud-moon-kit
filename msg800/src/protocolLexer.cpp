
// Generated from msg800/src/protocol.g4 by ANTLR 4.13.2


#include "protocolLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ProtocolLexerStaticData final {
  ProtocolLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ProtocolLexerStaticData(const ProtocolLexerStaticData&) = delete;
  ProtocolLexerStaticData(ProtocolLexerStaticData&&) = delete;
  ProtocolLexerStaticData& operator=(const ProtocolLexerStaticData&) = delete;
  ProtocolLexerStaticData& operator=(ProtocolLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag protocollexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<ProtocolLexerStaticData> protocollexerLexerStaticData = nullptr;

void protocollexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (protocollexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(protocollexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ProtocolLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "F_HEX_DIGIT", "F_U8", "U8", "U8_16", "STR", "NEWLINE", 
      "SPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,16,134,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,
  	1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,
  	1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,4,15,117,8,15,11,15,12,15,
  	118,1,16,4,16,122,8,16,11,16,12,16,123,1,16,1,16,1,17,4,17,129,8,17,11,
  	17,12,17,130,1,17,1,17,0,0,18,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,
  	19,10,21,11,23,0,25,0,27,12,29,13,31,14,33,15,35,16,1,0,4,3,0,48,57,65,
  	70,97,102,4,0,48,57,65,90,95,95,97,122,2,0,10,10,13,13,2,0,9,9,32,32,
  	134,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,
  	1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	1,37,1,0,0,0,3,42,1,0,0,0,5,47,1,0,0,0,7,51,1,0,0,0,9,53,1,0,0,0,11,55,
  	1,0,0,0,13,57,1,0,0,0,15,61,1,0,0,0,17,63,1,0,0,0,19,66,1,0,0,0,21,74,
  	1,0,0,0,23,81,1,0,0,0,25,83,1,0,0,0,27,86,1,0,0,0,29,93,1,0,0,0,31,116,
  	1,0,0,0,33,121,1,0,0,0,35,128,1,0,0,0,37,38,5,110,0,0,38,39,5,111,0,0,
  	39,40,5,110,0,0,40,41,5,101,0,0,41,2,1,0,0,0,42,43,5,98,0,0,43,44,5,105,
  	0,0,44,45,5,114,0,0,45,46,5,100,0,0,46,4,1,0,0,0,47,48,5,120,0,0,48,49,
  	5,111,0,0,49,50,5,114,0,0,50,6,1,0,0,0,51,52,5,40,0,0,52,8,1,0,0,0,53,
  	54,5,41,0,0,54,10,1,0,0,0,55,56,5,44,0,0,56,12,1,0,0,0,57,58,5,107,0,
  	0,58,59,5,101,0,0,59,60,5,121,0,0,60,14,1,0,0,0,61,62,5,61,0,0,62,16,
  	1,0,0,0,63,64,5,105,0,0,64,65,5,118,0,0,65,18,1,0,0,0,66,67,5,107,0,0,
  	67,68,5,101,0,0,68,69,5,121,0,0,69,70,5,95,0,0,70,71,5,115,0,0,71,72,
  	5,116,0,0,72,73,5,114,0,0,73,20,1,0,0,0,74,75,5,105,0,0,75,76,5,118,0,
  	0,76,77,5,95,0,0,77,78,5,115,0,0,78,79,5,116,0,0,79,80,5,114,0,0,80,22,
  	1,0,0,0,81,82,7,0,0,0,82,24,1,0,0,0,83,84,3,23,11,0,84,85,3,23,11,0,85,
  	26,1,0,0,0,86,87,5,104,0,0,87,88,5,101,0,0,88,89,5,120,0,0,89,90,5,95,
  	0,0,90,91,1,0,0,0,91,92,3,25,12,0,92,28,1,0,0,0,93,94,5,104,0,0,94,95,
  	5,101,0,0,95,96,5,120,0,0,96,97,5,95,0,0,97,98,1,0,0,0,98,99,3,25,12,
  	0,99,100,3,25,12,0,100,101,3,25,12,0,101,102,3,25,12,0,102,103,3,25,12,
  	0,103,104,3,25,12,0,104,105,3,25,12,0,105,106,3,25,12,0,106,107,3,25,
  	12,0,107,108,3,25,12,0,108,109,3,25,12,0,109,110,3,25,12,0,110,111,3,
  	25,12,0,111,112,3,25,12,0,112,113,3,25,12,0,113,114,3,25,12,0,114,30,
  	1,0,0,0,115,117,7,1,0,0,116,115,1,0,0,0,117,118,1,0,0,0,118,116,1,0,0,
  	0,118,119,1,0,0,0,119,32,1,0,0,0,120,122,7,2,0,0,121,120,1,0,0,0,122,
  	123,1,0,0,0,123,121,1,0,0,0,123,124,1,0,0,0,124,125,1,0,0,0,125,126,6,
  	16,0,0,126,34,1,0,0,0,127,129,7,3,0,0,128,127,1,0,0,0,129,130,1,0,0,0,
  	130,128,1,0,0,0,130,131,1,0,0,0,131,132,1,0,0,0,132,133,6,17,0,0,133,
  	36,1,0,0,0,4,0,118,123,130,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  protocollexerLexerStaticData = std::move(staticData);
}

}

protocolLexer::protocolLexer(CharStream *input) : Lexer(input) {
  protocolLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *protocollexerLexerStaticData->atn, protocollexerLexerStaticData->decisionToDFA, protocollexerLexerStaticData->sharedContextCache);
}

protocolLexer::~protocolLexer() {
  delete _interpreter;
}

std::string protocolLexer::getGrammarFileName() const {
  return "protocol.g4";
}

const std::vector<std::string>& protocolLexer::getRuleNames() const {
  return protocollexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& protocolLexer::getChannelNames() const {
  return protocollexerLexerStaticData->channelNames;
}

const std::vector<std::string>& protocolLexer::getModeNames() const {
  return protocollexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& protocolLexer::getVocabulary() const {
  return protocollexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView protocolLexer::getSerializedATN() const {
  return protocollexerLexerStaticData->serializedATN;
}

const atn::ATN& protocolLexer::getATN() const {
  return *protocollexerLexerStaticData->atn;
}




void protocolLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  protocollexerLexerInitialize();
#else
  ::antlr4::internal::call_once(protocollexerLexerOnceFlag, protocollexerLexerInitialize);
#endif
}
