project (MZserver)

cmake_minimum_required(VERSION 3.5)
add_compile_options(-std=c++11)

add_subdirectory(src/ServerBase)
add_subdirectory(src/GatewayServer)
add_subdirectory(src/MiniClient)

set(EXECUTABLE_OUTPUT_PATH "./output")