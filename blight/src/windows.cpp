#include <windows.h>
#include <psapi.h>
#include <shellapi.h>
#include <shellscalingapi.h>
#include <tchar.h>
#include <tlhelp32.h>

#include <vector>

#include <yy/log.h>
#include <yy/charset.h>
#include <yy/blight.h>

namespace yy::blight::windows {

bool is_run_as_admin()
{
    SID_IDENTIFIER_AUTHORITY authority = SECURITY_NT_AUTHORITY;

    BOOL is_admin  = FALSE;
    PSID admin_group;
    
    if (AllocateAndInitializeSid(&authority,
                                 2,
                                 SECURITY_BUILTIN_DOMAIN_RID,
                                 DOMAIN_ALIAS_RID_ADMINS,
                                 0,
                                 0,
                                 0,
                                 0,
                                 0,
                                 0,
                                 &admin_group)) {
        CheckTokenMembership(NULL, admin_group, &is_admin);
        FreeSid(admin_group);
    }
    return is_admin;
}

void request_run_as_admin(const std::vector<std::string>& args)
{
    if (!is_run_as_admin()) {
        std::string parameters;
        for (int i = 1; i < args.size(); i++) {
            if (i > 1) {
                // 参数之间用空格分隔
                parameters += " ";
            }
            // 如果参数包含空格，用引号包裹
            if (strchr(args[i].c_str(), ' ') != nullptr) {
                parameters += "\"";
                parameters += args[i];
                parameters += "\"";
            } else {
                parameters += args[i];
            }
        }

        SHELLEXECUTEINFOA sei = { sizeof(sei) };
        sei.lpVerb            = "runas"; // 触发UAC
        sei.lpFile            = args[0].c_str();
        sei.lpParameters      = parameters.c_str();
        sei.hwnd              = NULL;
        sei.nShow             = SW_NORMAL;
        if (ShellExecuteExA(&sei)) {
            ExitProcess(0); // 退出当前实例
        }
    }
}

void request_run_as_admin(int argc, char *argv[]) {
    std::vector<std::string> args;
    for(int i = 0; i < argc; i ++) {
        args.push_back(argv[i]);
    }

    request_run_as_admin(args);
}

bool enable_debug_privilege()
{
    HANDLE h_token;
    bool   succ = false;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &h_token)) {
        TOKEN_PRIVILEGES tp;
        tp.PrivilegeCount = 1;
        LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &tp.Privileges[0].Luid);
        tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
        AdjustTokenPrivileges(h_token, FALSE, &tp, sizeof(tp), NULL, NULL);
        DWORD tmp = GetLastError();
        succ      = (tmp == ERROR_SUCCESS);
        CloseHandle(h_token);
    }
    return succ;
}

bool request_debug_privilege(int argc, char *argv[]) {
    request_run_as_admin(argc, argv);
    return enable_debug_privilege();
}

bool dll_inject(DWORD pid, const std::string &dll_path) {
    HANDLE h_process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (h_process == NULL) {
        // 错误处理
        return false;
    }

    auto wstr_dll_path = charset::gbk_to_utf16(dll_path);

    size_t path_size = (wcslen(wstr_dll_path.c_str()) + 1) * sizeof(wchar_t);
    LPVOID remote_memory_ptr = VirtualAllocEx(h_process, NULL, path_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (remote_memory_ptr == NULL) {
        CloseHandle(h_process);
        return false;
    }


    if (!WriteProcessMemory(h_process, remote_memory_ptr, wstr_dll_path.c_str(), path_size, NULL)) {
        VirtualFreeEx(h_process, remote_memory_ptr, 0, MEM_RELEASE);
        CloseHandle(h_process);
        return false;
    }

    LPTHREAD_START_ROUTINE LoadLibrary_ptr = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryW");
    if (LoadLibrary_ptr == NULL) {
        VirtualFreeEx(h_process, remote_memory_ptr, 0, MEM_RELEASE);
        CloseHandle(h_process);
        return false;
    }

    HANDLE h_remote_thread = CreateRemoteThread(h_process, NULL, 0, LoadLibrary_ptr, remote_memory_ptr, 0, NULL);
    if (h_remote_thread == NULL) {
        VirtualFreeEx(h_process, remote_memory_ptr, 0, MEM_RELEASE);
        CloseHandle(h_process);
        return false;
    }

    WaitForSingleObject(h_remote_thread, INFINITE);

    CloseHandle(h_remote_thread);
    VirtualFreeEx(h_process, remote_memory_ptr, 0, MEM_RELEASE);
    CloseHandle(h_process);
}


} // namespace yy::blight::linux

