find_package(Threads REQUIRED)

add_library(yy_dynlib "")
cxx_project_preset(yy_dynlib)

target_sources(yy_dynlib PRIVATE
    src/dynlib.cpp
)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_sources(yy_dynlib PRIVATE
        src/linux_dynlib.cpp
    )
endif()

target_link_libraries(yy_dynlib PUBLIC
    yy_log
)

target_include_directories(yy_dynlib PUBLIC
    include
)

