project (Mserver)

cmake_minimum_required(VERSION 3.5)
add_compile_options(-std=c++11)

add_subdirectory(src/NetWork)
add_subdirectory(src/ServerBase)
add_subdirectory(src/MiniClient)
add_subdirectory(src/GatewayServer)


add_executable(MiniClient src/MiniClient/main.cpp)

target_link_libraries(MiniClient
	boost_system
	boost_thread
	NetWork
	ServerBase
)



add_executable(GatewayServer src/GatewayServer/main.cpp)

target_link_libraries(GatewayServer
	boost_system
	boost_thread
	NetWork
	ServerBase
)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)