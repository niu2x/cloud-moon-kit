#pragma once

#include <sstream>
#include <filesystem>
#include <memory>
#include <map>

#include <boost/noncopyable.hpp>

namespace yy {

class DynamicLib : private boost::noncopyable {
public:
    static std::unique_ptr<DynamicLib> create(const std::filesystem::path& path);

    explicit DynamicLib(const std::filesystem::path& path);
    virtual ~DynamicLib();

    virtual bool load()   = 0;
    virtual void unload() = 0;
    virtual void* lookup_symbol(const std::string& symbol_name) = 0;

    const std::filesystem::path& get_path() const
    {
        return library_path_;
    }

protected:
    std::filesystem::path library_path_;
};

class DynamicLibManager : private boost::noncopyable {
public:
    DynamicLibManager();

    ~DynamicLibManager();

    DynamicLib* load_library(const std::filesystem::path& path);

    DynamicLib* get_library(const std::filesystem::path& path);

    void unload_library(DynamicLib* lib);

    void unload_library(const std::filesystem::path&);

private:
    std::map<std::filesystem::path, std::unique_ptr<DynamicLib>> libraries_;
};

} // namespace yy
