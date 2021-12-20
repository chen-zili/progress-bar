# 设置项目所需cmake的最低版本
cmake_minimum_required(VERSION 3.0.0)

# 项目名称，也是最后生成的可执行文件名
project(spdProgressBar)

# 语言支持
enable_language(CXX)

# 支持c++ 11
set(CMAKE_CXX_STANDARD 11)

# # 添加预编译
# add_definitions(-UPETSC_USE_REAL_SINGLE -DPETSC_USE_REAL_DOUBLE )

# 设定编译组态，RelWithDebInfo指优化运行速度同时产生debug信息
# set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")

# pkg
find_package(fmt REQUIRED)

# 设置源文件和头文件路径
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/source/*.cpp)

# 设置头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include/)

# 添加源文件
add_executable(${PROJECT_NAME} ${SRCS})

# link lib
if(fmt_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${fmt_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} fmt::fmt)
else(fmt_FOUND)
    message(FATAL_ERROR "fmt library not found")
endif(fmt_FOUND)