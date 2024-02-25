cmake_minimum_required(VERSION 3.10)
project(virtual-replace)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#include_directories(include)

add_executable(example  example.cpp)
add_executable(example2  example2.cpp)
add_executable(example3  example3.cpp)

#target_link_libraries(lib)

if(CMAKE_BUILD_TYPE MATCHES Debug)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
endif()


