find_package(Threads REQUIRED)

add_library(yy_std_alias "")
cxx_project_preset(yy_std_alias)

target_sources(yy_std_alias PRIVATE
    src/std_alias.cpp
)

target_link_libraries(yy_std_alias PUBLIC
    yy_log
)

target_include_directories(yy_std_alias PUBLIC
    include
)

