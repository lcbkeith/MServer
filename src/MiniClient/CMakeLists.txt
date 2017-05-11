project(MiniClient)
cmake_minimum_required(VERSION 3.5)

aux_source_directory(. SRC_LIST)
add_executable(MiniClient ${SRC_LIST})

target_link_libraries(MiniClient
    pthread
    boost_system
    boost_thread
    ServerBase
)
