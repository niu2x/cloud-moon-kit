find_package(Threads REQUIRED)

add_library(log "")
cxx_project_preset(log)

target_sources(log PRIVATE
    src/log.cpp
)

target_link_libraries(log PUBLIC
    rust_lib
    Threads::Threads
    dl
)

target_include_directories(log PUBLIC
    include
)