cmake_minimum_required(VERSION 3.12)
project(mon_module)

find_package(pybind11 REQUIRED)
add_library(mon_module MODULE addition.cpp)

target_link_libraries(mon_module PRIVATE pybind11::module)
set_target_properties(mon_module PROPERTIES PREFIX " " SUFFIX ".so")

