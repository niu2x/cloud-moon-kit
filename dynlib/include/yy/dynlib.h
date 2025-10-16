#pragma once

#include <sstream>
#include <filesystem>
#include <memory>

#include <boost/noncopyable.hpp>

namespace yy {

class DynamicLib : private boost::noncopyable {
public:
    static std::unique_ptr<DynamicLib> create(const std::filesystem::path& path);

    explicit DynamicLib(const std::filesystem::path& path);
    virtual ~DynamicLib();

    virtual bool load()   = 0;
    virtual void unload() = 0;

protected:
    std::filesystem::path library_path_;
};

} // namespace yy
