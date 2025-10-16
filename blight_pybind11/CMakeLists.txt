add_python_module(yy_blight_cxx)
cxx_project_preset(yy_blight_cxx)

file(GLOB src_files 
    src/*.cpp 
)

target_sources(yy_blight_cxx PRIVATE
    ${src_files}
)

target_link_libraries(yy_blight_cxx PRIVATE
    yy_blight
)