#include <dlfcn.h>

#include <yy/blight.h>
#include <yy/log.h>

int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++) {
        dlopen(argv[i], RTLD_NOW);
    }
    return 0;
}