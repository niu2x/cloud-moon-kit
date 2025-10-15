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


add_subdirectory(blight)
add_subdirectory(blight_pybind11)


