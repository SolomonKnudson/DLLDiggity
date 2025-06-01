cmake_minimum_required(VERSION 3.28)

add_executable(dll-driver
	${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(dll-driver PRIVATE
  DLLDiggity
)

target_compile_features(dll-driver PRIVATE cxx_std_17)
set_target_properties(dll-driver PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED on
        CXX_EXTENSIONS off
)
