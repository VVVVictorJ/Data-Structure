cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_FLAGS "-std=c++11")

set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

aux_source_directory("${PROJECT_SOURCE_DIR}/src/lib/src" Ds_src)

include_directories("${PROJECT_SOURCE_DIR}/src/lib/include")

add_library(d_s SHARED ${Ds_src})

add_library(d_s_static STATIC ${Ds_src})

set_target_properties(d_s_static PROPERTIES OUTPUT_NAME "d_s")
