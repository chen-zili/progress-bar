# 设置项目所需cmake的最低版本
cmake_minimum_required(VERSION 3.0.0)

# 项目名称，也是最后生成的可执行文件名
project(spdProgressBar)

# 语言支持
enable_language(CXX)

# 支持c++ 11
set(CMAKE_CXX_STANDARD 11)

# 设定编译组态
set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")

# 设置源文件和头文件路径
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/source/*.cpp)

# 设置头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include/)

# 生成
add_library(spdProgressBar SHARED ${SRCS})

# 设置lib属性
set_target_properties(spdProgressBar PROPERTIES OUTPUT_NAME "spdProgressBar")
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/lib/)

