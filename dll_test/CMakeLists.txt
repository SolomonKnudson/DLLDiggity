cmake_minimum_required(VERSION 3.28)

add_library(dll-test ${DLL_DIGGITY_BUILD_TYPE})
add_library(DllDiggity::dll-test ALIAS dll-test)

target_sources(dll-test PRIVATE 
  ${CMAKE_CURRENT_LIST_DIR}/src/dll_test.cpp
)

target_include_directories(dll-test 
  PUBLIC $<BUILD_LOCAL_INTERFACE: ${CMAKE_CURRENT_LIST_DIR}/include>
  PUBLIC $<BUILD_LOCAL_INTERFACE: ${CMAKE_CURRENT_BINARY_DIR}/exports>
)

include(GenerateExportHeader)
generate_export_header(dll-test
  BASE_NAME DLLDiggity
  EXPORT_FILE_NAME exports/DLLDiggity/exports.hpp)

set_target_properties(dll-test PROPERTIES
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN ON
  CXX_EXTENTIONS OFF
)
