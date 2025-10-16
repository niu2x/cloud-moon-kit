#include <vector>

#include <yy/dynlib.h>
#include <yy/log.h>

int main(int argc, char* argv[])
{
    std::vector<std::unique_ptr<yy::DynamicLib>> libraries;

    for (int i = 1; i < argc; i++) {
        auto lib = yy::DynamicLib::create(argv[i]);
        lib->load();
        libraries.push_back(std::move(lib));
    }
    return 0;
}