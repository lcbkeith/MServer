project (Mserver)

cmake_minimum_required(VERSION 3.5)
add_compile_options(-std=c++11)

INCLUDE_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}/include
  )

  message(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_subdirectory(src/ServerBase)
add_subdirectory(src/GatewayServer)
add_subdirectory(src/MiniClient)

