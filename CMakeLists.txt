cmake_minimum_required(VERSION 3.5)
project(libmath LANGUAGES CXX)

add_library(libmath STATIC
    src/libmath.cpp
)

target_include_directories(libmath
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(libmath PUBLIC cxx_std_17)
