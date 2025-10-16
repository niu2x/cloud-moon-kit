find_package(Threads REQUIRED)

add_library(yy_log "")
cxx_project_preset(yy_log)

target_sources(yy_log PRIVATE
    src/log.cpp
)

target_link_libraries(yy_log PUBLIC
    rust_lib
    Threads::Threads
    dl
)

target_include_directories(yy_log PUBLIC
    include
)