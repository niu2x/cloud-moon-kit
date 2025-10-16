find_package(Threads REQUIRED)

add_library(yy_ip_addr "")
cxx_project_preset(yy_ip_addr)

target_sources(yy_ip_addr PRIVATE
    src/ip_addr.cpp
    src/ip_addrBaseListener.cpp
    src/ip_addrLexer.cpp
    src/ip_addrListener.cpp
    src/ip_addrParser.cpp
)

target_link_libraries(yy_ip_addr PUBLIC
    yy_log
    antlr4
)

target_include_directories(yy_ip_addr PUBLIC
    include
)
