cmake_minimum_required(VERSION 3.28)

add_executable(dll-test
	${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(dll-test PRIVATE
  DllDiggity
)

target_compile_features(dll-test PRIVATE cxx_std_17)
set_target_properties(dll-test PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED on
        CXX_EXTENSIONS off
)
