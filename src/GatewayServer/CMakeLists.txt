project(GatewayServer)
cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_BINARY_DIR}/../../include)
aux_source_directory(. SRC_LIST)
add_executable(GatewayServer ${SRC_LIST})

target_link_libraries(GatewayServer 
    boost_system
    boost_thread
    ServerBase
)