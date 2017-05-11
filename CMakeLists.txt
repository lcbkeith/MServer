project (Mserver)

cmake_minimum_required(VERSION 3.5)
add_compile_options(-std=c++11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(src/ServerBase)
add_subdirectory(src/GatewayServer)
add_subdirectory(src/MiniClient)

