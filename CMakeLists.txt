cmake_minimum_required(VERSION 3.10)

project(proj)

add_library(ev EvCar.cpp)
add_library(ic ICECar.cpp)
add_library(func Functionalities.cpp)

add_executable(main Main.cpp)

target_link_libraries(main pthread func ic ev)