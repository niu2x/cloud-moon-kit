#include <stdarg.h>

#include <yy/dynlib.h>

namespace yy {

DynamicLib::DynamicLib(const std::filesystem::path& path)
: library_path_(path)
{
}

DynamicLib::~DynamicLib()
{
}

} // namespace yy
