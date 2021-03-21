cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(ColorGraph)

include_directories(include)
add_executable(ColorGraph src/main.cpp src/Graph.cpp src/Vertex.cpp)
