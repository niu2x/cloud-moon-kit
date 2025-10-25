cmake_minimum_required(VERSION 3.17.0 FATAL_ERROR)

project(cloud_moon_kit VERSION 0.1.2 LANGUAGES CXX C)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(cxx_project)
include(python)

add_subdirectory(third_party/pybind11)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	add_library(boost INTERFACE)
	target_include_directories(boost INTERFACE
		third_party/x86_64-unknown-linux/boost-1.89.0/include
	)
	target_link_libraries(boost INTERFACE
		boost_process
		boost_program_options
	)
	target_link_directories(boost INTERFACE
		third_party/x86_64-unknown-linux/boost-1.89.0/lib
	)

	add_library(antlr4 INTERFACE)
	target_include_directories(antlr4 INTERFACE
		${CMAKE_SOURCE_DIR}/third_party/x86_64-unknown-linux/antlr4/include/antlr4-runtime
	)
	target_link_directories(antlr4 INTERFACE
		${CMAKE_SOURCE_DIR}/third_party/x86_64-unknown-linux/antlr4/lib
	)
	target_link_libraries(antlr4 INTERFACE
		antlr4-runtime
	)
	target_compile_definitions(antlr4 INTERFACE ANTLR4CPP_STATIC)

	add_library(openssl INTERFACE)
	target_include_directories(openssl INTERFACE
		${CMAKE_SOURCE_DIR}/third_party/x86_64-unknown-linux/openssl/include/
	)
	target_link_directories(openssl INTERFACE
		${CMAKE_SOURCE_DIR}/third_party/x86_64-unknown-linux/openssl/lib
	)
	target_link_libraries(openssl INTERFACE
		ssl
		crypto
	)


elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
	# set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

	add_library(boost INTERFACE)
	target_include_directories(boost INTERFACE
		third_party/x86_64-pc-windows-msvc/boost-1.89.0/include
	)
	target_link_libraries(boost INTERFACE
		libboost_program_options-vc143-mt-x64-1_89
		libboost_process-vc143-mt-x64-1_89
	)

	target_link_directories(boost INTERFACE
		third_party/x86_64-pc-windows-msvc/boost-1.89.0/lib
	)


	add_library(antlr4 INTERFACE)
	target_include_directories(antlr4 INTERFACE
		${CMAKE_SOURCE_DIR}/third_party/x86_64-pc-windows-msvc/antlr4/include/antlr4-runtime
	)
	target_link_directories(antlr4 INTERFACE
		${CMAKE_SOURCE_DIR}/third_party/x86_64-pc-windows-msvc/antlr4/lib
	)
	target_link_libraries(antlr4 INTERFACE
		antlr4-runtime
	)
	target_compile_definitions(antlr4 INTERFACE ANTLR4CPP_STATIC)


	add_library(openssl INTERFACE)
	target_include_directories(openssl INTERFACE
		${CMAKE_SOURCE_DIR}/third_party/x86_64-pc-windows-msvc/openssl/include/
	)
	target_link_directories(openssl INTERFACE
		${CMAKE_SOURCE_DIR}/third_party/x86_64-pc-windows-msvc/openssl/lib
	)
	target_link_libraries(openssl INTERFACE
		libssl
		libcrypto
	)

	install(FILES
		third_party/x86_64-pc-windows-msvc/OpenSSL/bin/libcrypto-3-x64.dll
		third_party/x86_64-pc-windows-msvc/OpenSSL/bin/libssl-3-x64.dll
		DESTINATION bin
	)
	
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
	add_library(boost INTERFACE)
	target_include_directories(boost INTERFACE
		third_party/aarch64-apple-darwin/boost-1.89.0/include
	)
	target_link_libraries(boost INTERFACE
		boost_process
		boost_program_options
	)
	target_link_directories(boost INTERFACE
		third_party/aarch64-apple-darwin/boost-1.89.0/lib
	)
endif()

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
add_subdirectory(msg800)
add_subdirectory(ip_addr)
add_subdirectory(load_dynlib)
add_subdirectory(charset)
add_subdirectory(crypto)

