cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(bit_array_project VERSION 0.2.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(lib)

target_include_directories(bitArray PUBLIC .) 

add_subdirectory(tests)

