find_package(Threads REQUIRED)

add_library(yy_log "")
cxx_project_preset(yy_log)

target_sources(yy_log PRIVATE
    src/log.cpp
)

target_link_libraries(yy_log PUBLIC
    yy_charset
    boost
    rust_lib
    Threads::Threads
)

target_include_directories(yy_log PUBLIC
    include
)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(yy_log PUBLIC
        dl
    )
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    target_link_libraries(yy_log PUBLIC
        Ws2_32
        Userenv
        ntdll
    )
endif()
