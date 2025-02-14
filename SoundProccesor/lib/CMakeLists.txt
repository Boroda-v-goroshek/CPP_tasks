cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(sound_proccesor_lib)
add_library(sound_proccesor_lib STATIC reader.hpp reader.cpp sound.hpp sound.cpp Pars.hpp Pars.cpp)