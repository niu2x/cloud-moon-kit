add_library(yy_charset "")
cxx_project_preset(yy_charset)

target_sources(yy_charset PRIVATE
    src/charset.cpp
)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    target_sources(yy_charset PRIVATE
        src/windows_charset.cpp
    )
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_sources(yy_charset PRIVATE
        src/posix_charset.cpp
    )
endif()

target_include_directories(yy_charset PUBLIC
    include
)

