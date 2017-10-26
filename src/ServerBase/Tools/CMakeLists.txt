cmake_minimum_required(VERSION 2.8)

include_directories(${PROJECT_BINARY_DIR}/../../../include)

aux_source_directory(. TOOL_SRC)
add_library(Tools ${TOOL_SRC})