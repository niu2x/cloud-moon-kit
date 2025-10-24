add_executable(msg800 "")
cxx_project_preset(msg800)

target_sources(msg800 PRIVATE
    src/main.cpp
    src/protocol.cpp
    src/tunnel_server.cpp

    src/protocolBaseListener.cpp
    src/protocolLexer.cpp
    src/protocolListener.cpp
    src/protocolParser.cpp
)

target_link_libraries(msg800 PRIVATE
    yy_log
    yy_ip_addr
    yy_crypto
    antlr4
)

install(TARGETS msg800 RUNTIME DESTINATION bin)