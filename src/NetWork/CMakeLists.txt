cmake_minimum_required(VERSION 3.5)
aux_source_directory(. SRC_LIST)
add_compile_options(-std=c++11)
add_library(NetWork ${SRC_LIST})
target_link_libraries(
	NetWork	
	)