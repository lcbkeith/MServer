project (Mserver)

cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(CMAKE_CXX_FLAGS_DEBUG"$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE"$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_BUILD_TYPE "Debug")

add_subdirectory(src/ServerBase)
add_subdirectory(src/GatewayServer)
add_subdirectory(src/MiniClient)

