#pragma once

#include <boost/predef.h>

#if BOOST_OS_LINUX
    #include <yy/blight/linux.h>
#endif

#if BOOST_OS_WINDOWS
    #include <yy/blight/windows.h>
#endif