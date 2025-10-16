
// Generated from ip_addr/src/ip_addr.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ip_addrParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ip_addrParser.
 */
class  ip_addrListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterIp_addr(ip_addrParser::Ip_addrContext *ctx) = 0;
  virtual void exitIp_addr(ip_addrParser::Ip_addrContext *ctx) = 0;

  virtual void enterIp(ip_addrParser::IpContext *ctx) = 0;
  virtual void exitIp(ip_addrParser::IpContext *ctx) = 0;

  virtual void enterIpv4(ip_addrParser::Ipv4Context *ctx) = 0;
  virtual void exitIpv4(ip_addrParser::Ipv4Context *ctx) = 0;

  virtual void enterPort(ip_addrParser::PortContext *ctx) = 0;
  virtual void exitPort(ip_addrParser::PortContext *ctx) = 0;


};

