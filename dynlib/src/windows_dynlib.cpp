#include <windows.h>
#include <string.h>

#include <string>
#include <iostream>

#include <yy/dynlib.h>
#include <yy/log.h>
#include <yy/charset.h>

namespace yy {

void format_error_message(DWORD err, char *buffer, size_t buf_size) {
    if (err == 0) {
        snprintf(buffer, buf_size, "No error");
        return;
    }

    LPVOID msg_buf;
    DWORD size = FormatMessageA(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        err,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // 默认语言
        (LPSTR)&msg_buf,  // 系统分配的缓冲区
        0, NULL);

    if (size && msg_buf) {
        // 去掉结尾的换行符（Windows错误信息通常带有\r\n）
        char *msg = (char*)msg_buf;
        for (char *p = msg; *p; p++) {
            if (*p == '\r' || *p == '\n') {
                *p = '\0';
                break;
            }
        }
        snprintf(buffer, buf_size, "%s", msg);
        LocalFree(msg_buf); // 释放系统分配的内存
    } else {
        snprintf(buffer, buf_size, "Unknown error (code %lu)", err);
    }
}

static std::string get_error() {
    DWORD code = GetLastError();
    char message[1024] = {0};
    format_error_message(code, message, 1024);
    return charset::gbk_to_utf8(message);
}

class WinDynamicLib : public DynamicLib {
public:
    explicit WinDynamicLib(const std::filesystem::path& path)
    : DynamicLib(path),
      lib_handler_(NULL)
    {
    }

    ~WinDynamicLib()
    {
        unload();
    }

    bool load() override
    {
        if (lib_handler_) {
            return true;
        }

        LOG(debug) << "DynamicLib load: " << library_path_;

        lib_handler_ = LoadLibrary(library_path_.c_str());
        if (!lib_handler_) {
            LOG(warn) << "dlopen failed: " << get_error();
        }
        return lib_handler_ != NULL;
    }

    void unload() override
    {
        if (!lib_handler_) {
            return;
        }

        LOG(debug) << "DynamicLib unload: " << library_path_;

        FreeLibrary(lib_handler_);
        lib_handler_ = NULL;
    }

    void* lookup_symbol(const std::string& symbol_name)
    {
        if (!lib_handler_) {
            LOG(warn) << "DynamicLib lookup symbol while lib_handler_ is NULL";
            return NULL;
        }

        return GetProcAddress(lib_handler_, symbol_name.c_str());
    }

private:
    HINSTANCE lib_handler_;
};

std::unique_ptr<DynamicLib> DynamicLib::create(const std::filesystem::path& path)
{
    return std::make_unique<WinDynamicLib>(path);
}

} // namespace yy