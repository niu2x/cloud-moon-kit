
// Generated from ip_addr/src/ip_addr.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ip_addrListener.h"


/**
 * This class provides an empty implementation of ip_addrListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ip_addrBaseListener : public ip_addrListener {
public:

  virtual void enterIp_addr(ip_addrParser::Ip_addrContext * /*ctx*/) override { }
  virtual void exitIp_addr(ip_addrParser::Ip_addrContext * /*ctx*/) override { }

  virtual void enterIp(ip_addrParser::IpContext * /*ctx*/) override { }
  virtual void exitIp(ip_addrParser::IpContext * /*ctx*/) override { }

  virtual void enterIpv4(ip_addrParser::Ipv4Context * /*ctx*/) override { }
  virtual void exitIpv4(ip_addrParser::Ipv4Context * /*ctx*/) override { }

  virtual void enterPort(ip_addrParser::PortContext * /*ctx*/) override { }
  virtual void exitPort(ip_addrParser::PortContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

