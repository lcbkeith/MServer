cmake_minimum_required(VERSION 3.5)

include_directories(${PROJECT_BINARY_DIR}/../../include)

aux_source_directory(. SRC_LIST)
add_library(ServerBase ${SRC_LIST})