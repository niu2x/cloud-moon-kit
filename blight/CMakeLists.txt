add_library(blight "")
cxx_project_preset(blight)

target_sources(blight PRIVATE
    src/common.cpp
)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    target_sources(blight PRIVATE
        src/windows.cpp
    )
endif()


if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_sources(blight PRIVATE
        src/linux.cpp
    )
endif()

target_include_directories(blight PUBLIC
    include
)

target_link_libraries(blight PUBLIC
    log
    boost
)
