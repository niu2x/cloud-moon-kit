cmake_minimum_required(VERSION 3.17.0 FATAL_ERROR)

project(cloud_moon_kit VERSION 0.1.0 LANGUAGES CXX C)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(cxx_project)
include(python)

add_subdirectory(third_party/pybind11)

add_library(boost INTERFACE)
target_include_directories(boost INTERFACE
   third_party/x86_64-unknown-linux/boost-1.89.0/include
)
target_link_libraries(boost INTERFACE
   boost_process
)
target_link_directories(boost INTERFACE
   third_party/x86_64-unknown-linux/boost-1.89.0/lib
)

add_custom_target(build_rust
   COMMAND cargo build --release
   WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/rust_support
)

add_library(rust_lib INTERFACE)
target_include_directories(rust_lib INTERFACE
   rust_support/include
)
target_link_libraries(rust_lib INTERFACE
   rust_support
)
target_link_directories(rust_lib INTERFACE
   rust_support/target/release
)

add_dependencies(rust_lib build_rust)  # 在运行 tests 前先构建 C++ 项目

add_subdirectory(blight)
add_subdirectory(blight_pybind11)
add_subdirectory(log)
add_subdirectory(dynlib)

add_subdirectory(load_dynlib)
