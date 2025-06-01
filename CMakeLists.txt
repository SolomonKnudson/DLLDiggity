cmake_minimum_required(VERSION 3.28)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(DllDiggity LANGUAGES CXX)

add_library(DllDiggity INTERFACE)

target_include_directories(DllDiggity INTERFACE 
  $<BUILD_LOCAL_INTERFACE: ${CMAKE_CURRENT_LIST_DIR}/include/>
)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/app)
