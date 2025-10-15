#pragma once

#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <dlfcn.h>
#include <unistd.h>

#include <string>

namespace yy::blight::linux {

void inject_so(pid_t pid, const std::string& dll_path);
}