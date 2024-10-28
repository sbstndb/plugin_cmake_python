# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(plugin_kokkos)

# Recherche pybind11
find_package(pybind11 REQUIRED)

# Recherche Kokkos
find_package(Kokkos REQUIRED)

# Ajout du module
add_library(plugin_kokkos MODULE main.cpp)

# Lier Kokkos et pybind11
target_link_libraries(plugin_kokkos PRIVATE Kokkos::kokkos pybind11::module)
target_include_directories(plugin_kokkos PRIVATE ${Kokkos_INCLUDE_DIRS})

# Configuration de l’extension .so
set_target_properties(plugin_kokkos PROPERTIES PREFIX "" SUFFIX ".so")

