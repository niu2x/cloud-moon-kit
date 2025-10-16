#include <windows.h>

#include <yy/charset.h>

namespace yy::charset {

std::string native_to_utf8(const std::string &sz) {
	return gbk_to_utf8(sz);
}

// GBK → UTF-8 转换
std::string gbk_to_utf8(const std::string& gbk_str) {
    // 先 GBK → UTF-16
    int wide_len = MultiByteToWideChar(936, 0, gbk_str.c_str(), -1, NULL, 0);
    std::wstring wide_str(wide_len, L'\0');
    MultiByteToWideChar(936, 0, gbk_str.c_str(), -1, &wide_str[0], wide_len);

    // 再 UTF-16 → UTF-8
    int utf8_len = WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), -1, NULL, 0, NULL, NULL);
    std::string utf8_str(utf8_len, '\0');
    WideCharToMultiByte(CP_UTF8, 0, wide_str.c_str(), -1, &utf8_str[0], utf8_len, NULL, NULL);

    // 去除字符串末尾的 '\0'
    if (!utf8_str.empty() && utf8_str.back() == '\0') {
        utf8_str.pop_back();
    }
    return utf8_str;
}


std::wstring gbk_to_utf16(const std::string& gbk_str)
{
    int len = MultiByteToWideChar(CP_ACP, 0, gbk_str.c_str(), -1, nullptr, 0);
    if (len <= 0) {
        return L"";
    }
    std::wstring utf16_str(len, 0);
    MultiByteToWideChar(CP_ACP, 0, gbk_str.c_str(), -1, &utf16_str[0], len);
    return utf16_str;
}


}