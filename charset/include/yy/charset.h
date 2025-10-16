#pragma once

#include <string>

namespace yy::charset {

std::string native_to_utf8(const std::string &);

std::string gbk_to_utf8(const std::string& gbk_str);

std::wstring gbk_to_utf16(const std::string& gbk_str);

}