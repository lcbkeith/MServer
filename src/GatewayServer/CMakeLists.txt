project(GatewayServer)
cmake_minimum_required(VERSION 3.5)
aux_source_directory(. SRC_LIST)
add_executable(GatewayServer ${SRC_LIST})

target_link_libraries(GatewayServer 
    boost_system
    boost_thread
    ServerBase)