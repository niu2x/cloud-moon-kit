add_executable(load_so "")
cxx_project_preset(load_so)

target_sources(load_so PRIVATE
    src/main.cpp
)

target_link_libraries(load_so PRIVATE
    blight
)