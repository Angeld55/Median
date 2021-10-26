cmake_minimum_required(VERSION 3.13)
project("Median data structure")

add_library(MedianDS STATIC src/MedianGetter.cpp src/MedianGetter.h)

add_executable(SimpleApp src/SimpleApp.cpp)
target_link_libraries(SimpleApp MedianDS)

add_executable(MedianTest tests/MedianTest.cpp)
target_link_libraries(MedianTest MedianDS)
