cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(sound_proccesor_project VERSION 0.2.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(lib)
target_include_directories(sound_proccesor_lib PUBLIC .)


add_executable(sound_proccesor main.cpp)
target_link_libraries(sound_proccesor sound_proccesor_lib)