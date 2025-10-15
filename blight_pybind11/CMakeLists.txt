add_python_module(blight_cxx)
cxx_project_preset(blight_cxx)

file(GLOB src_files 
    src/*.cpp 
)

target_sources(blight_cxx PRIVATE
    ${src_files}
)

target_link_libraries(blight_cxx PRIVATE
    blight
)