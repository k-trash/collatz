cmake_minimum_required(VERSION 3.16.3)
project(collatz CXX)

include_directories(include)

add_library(collatz_lib SHARED
	src/collatz.cpp
)

add_executable(collatz_main src/collatz_main.cpp)

target_link_libraries(collatz_main
	collatz_lib
)
