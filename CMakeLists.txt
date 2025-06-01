cmake_minimum_required(VERSION 3.28)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(DLLDiggity LANGUAGES CXX)

add_library(DLLDiggity INTERFACE)

target_include_directories(DLLDiggity INTERFACE 
  $<BUILD_LOCAL_INTERFACE: ${CMAKE_CURRENT_LIST_DIR}/include/>
)

set_target_properties(DLLDiggity PROPERTIES
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN ON
  CXX_EXTENTIONS OFF
)

option(DLL_DIGGITY_SHARED 
  "Enable shared DLLDiggity library (Dynamic linking)" 
  OFF
)

set(DLL_DIGGITY_BUILD_TYPE STATIC)
if(DLL_DIGGITY_SHARED)
  set(DLL_DIGGITY_BUILD_TYPE SHARED)
endif()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/app)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/dll_test)
