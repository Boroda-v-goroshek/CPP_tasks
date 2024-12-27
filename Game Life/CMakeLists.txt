cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(game_life VERSION 0.2.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(lib)
target_include_directories(life PUBLIC .)

add_subdirectory(tests)

add_executable(run_game main.cpp)
target_link_libraries(run_game life)