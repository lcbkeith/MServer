cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_BINARY_DIR}/../../include)

aux_source_directory(. SRC_LIST)
aux_source_directory(Tools SRC_TOOLS)

add_library(ServerBase ${SRC_LIST} ${SRC_TOOLS})