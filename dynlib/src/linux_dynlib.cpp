#include <dlfcn.h>
#include <string.h>

#include <yy/dynlib.h>
#include <yy/log.h>

namespace yy {

class LinuxDynamicLib : public DynamicLib {
public:
    explicit LinuxDynamicLib(const std::filesystem::path& path)
    : DynamicLib(path),
      lib_handler_(nullptr)
    {
    }

    ~LinuxDynamicLib()
    {
        unload();
    }

    bool load() override
    {
        if (lib_handler_) {
            return true;
        }

        LOG(debug) << "DynamicLib load: " << library_path_;

        lib_handler_ = dlopen(library_path_.c_str(), RTLD_GLOBAL | RTLD_LAZY);
        if (!lib_handler_) {
            LOG(warn) << "dlopen failed: " << dlerror();
        }
        return lib_handler_ != nullptr;
    }

    void unload() override
    {
        if (!lib_handler_) {
            return;
        }

        LOG(debug) << "DynamicLib unload: " << library_path_;

        dlclose(lib_handler_);
        lib_handler_ = nullptr;
    }

private:
    void* lib_handler_;
};

std::unique_ptr<DynamicLib> DynamicLib::create(const std::filesystem::path& path)
{
    return std::make_unique<LinuxDynamicLib>(path);
}

} // namespace yy