# 设置项目所需cmake的最低版本
cmake_minimum_required(VERSION 3.0.0)

# 项目名称，也是最后生成的可执行文件名
project(test)

# 启用对Fortran语言的支持
enable_language(CXX)

# 设置全局路径
set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")

# 头文件路径
set (PROJECTPATH ${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/fmt/include/)
include_directories(${PROJECT_SOURCE_DIR}/spdProBar/include/)

file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/*.cpp)

# 添加源文件
add_executable(${PROJECT_NAME} ${SRCS})

add_subdirectory(spdProBar)

# 链接
target_link_libraries(${PROJECT_NAME} spdProBar)
