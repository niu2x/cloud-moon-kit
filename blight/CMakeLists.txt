add_library(yy_blight "")
cxx_project_preset(yy_blight)

target_sources(yy_blight PRIVATE
    src/common.cpp
)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    target_sources(yy_blight PRIVATE
        src/windows.cpp
    )
endif()


if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_sources(yy_blight PRIVATE
        src/linux.cpp
    )
endif()

target_include_directories(yy_blight PUBLIC
    include
)

target_link_libraries(yy_blight PUBLIC
    yy_log
    yy_charset
    boost
)
