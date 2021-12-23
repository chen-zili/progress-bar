# 设置项目所需cmake的最低版本
cmake_minimum_required(VERSION 3.0.0)

# 项目名称，也是最后生成的可执行文件名
project(spdProBar)

# 语言支持
enable_language(CXX)

# 支持c++ 11
set(CMAKE_CXX_STANDARD 11)

# 设置源文件和头文件路径
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/source/*.cpp)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include/)
include_directories(${PROJECTPATH}/fmt/include/)

# 生成
add_library(${PROJECT_NAME} SHARED ${SRCS})

# 设置lib属性
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "spdProBar")
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/lib/)


target_link_libraries(${PROJECT_NAME} ${PROJECTPATH}/fmt/lib/libfmt.so.8)