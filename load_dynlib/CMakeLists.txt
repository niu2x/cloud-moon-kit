add_executable(load_dynlib "")
cxx_project_preset(load_dynlib)

target_sources(load_dynlib PRIVATE
    src/main.cpp
)

target_link_libraries(load_dynlib PRIVATE
    yy_dynlib
)