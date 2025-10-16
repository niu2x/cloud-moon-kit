#pragma once

#include <optional>
#include <string>

namespace yy {

struct IP_Address {
    std::string ipv4;
    uint16_t    port;
};

std::optional<IP_Address> parse_ip_addr(const std::string& sz);

} // namespace yy
