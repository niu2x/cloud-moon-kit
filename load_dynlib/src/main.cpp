#include <vector>

#include <yy/dynlib.h>
#include <yy/log.h>

int main(int argc, char* argv[])
{
    if (argc >= 2) {
        auto lib = yy::DynamicLib::create(argv[1]);
        lib->load();

        if (argc >= 3) {
            auto addr = lib->lookup_symbol(argv[2]);
            printf("symbol %s's address is %p\n", argv[2], addr);
        }
    }
    return 0;
}