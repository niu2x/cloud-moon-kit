
// Generated from ip_addr/src/ip_addr.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  ip_addrLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, NUM = 3, LOCAL = 4, NEWLINE = 5, SPACE = 6
  };

  explicit ip_addrLexer(antlr4::CharStream *input);

  ~ip_addrLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

