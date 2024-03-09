cmake_minimum_required(VERSION 3.5)

project (MAIN CXX)

add_library(num_alg numerical_algorithm.h numerical_algorithm.cpp)

add_library(test test.h test.cpp)

add_executable(main main.cpp)

target_link_libraries(main num_alg test)
