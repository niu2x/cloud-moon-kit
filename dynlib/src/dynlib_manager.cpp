#include <stdarg.h>

#include <yy/dynlib.h>
#include <yy/log.h>

namespace yy {

DynamicLibManager::DynamicLibManager()
{
}

DynamicLibManager::~DynamicLibManager()
{
}

DynamicLib* DynamicLibManager::load_library(const std::filesystem::path& path)
{
    auto it = libraries_.find(path);
    if (it != libraries_.end()) {
        return it->second.get();
    }

    auto lib = DynamicLib::create(path);
    if (lib->load()) {
        auto [new_it, unused] = libraries_.insert(std::make_pair(path, std::move(lib)));
        return new_it->second.get();
    } else {
        LOG(warn) << "load " << path << " fail";
        return nullptr;
    }
}

DynamicLib* DynamicLibManager::get_library(const std::filesystem::path& path)
{
    auto it = libraries_.find(path);
    return it != libraries_.end() ? it->second.get() : nullptr;
}

void DynamicLibManager::unload_library(DynamicLib* lib)
{
    unload_library(lib->get_path());
}

void DynamicLibManager::unload_library(const std::filesystem::path& path)
{
    auto it = libraries_.find(path);
    if (it != libraries_.end()) {
        libraries_.erase(it);
    }
}

} // namespace yy
