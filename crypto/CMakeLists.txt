find_package(Threads REQUIRED)

add_library(yy_crypto "")
cxx_project_preset(yy_crypto)

target_sources(yy_crypto PRIVATE
    src/aes_crypto.cpp
)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
endif()

target_link_libraries(yy_crypto PUBLIC
    yy_log
    openssl
)

target_include_directories(yy_crypto PUBLIC
    include
)

