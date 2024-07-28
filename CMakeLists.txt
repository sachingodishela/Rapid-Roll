cmake_minimum_required(VERSION 3.2)
project(Rapid-Roll)
include_directories(${CMAKE_SOURCE_DIR}/include)
set(CMAKE_CXX_STANDARD 11)
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)
find_package(glew REQUIRED)
find_package(glfw3 REQUIRED)
find_package(opengl REQUIRED)

add_executable(Rapid-Roll ${SOURCES})
target_link_libraries(Rapid-Roll GLEW::glew glfw opengl32)

