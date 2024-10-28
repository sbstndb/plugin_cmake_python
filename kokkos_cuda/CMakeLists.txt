# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(plugin_kokkos)

# Recherche pybind11
find_package(pybind11 REQUIRED)
#find_package(CUDA REQUIRED)
# Recherche Kokkos
find_package(Kokkos REQUIRED)



#link_directories(
#    /usr/local/cuda/lib64
#    )

set_target_properties(CUDA::cuda_driver PROPERTIES IMPORTED_LOCATION "/usr/lib64/libcuda.so")


# Ajout du module
add_library(plugin_kokkos SHARED main.cpp kokkos_example.cpp)

# Lier Kokkos et pybind11
target_link_libraries(plugin_kokkos PRIVATE Kokkos::kokkos pybind11::module CUDA::cuda_driver)
target_include_directories(plugin_kokkos PRIVATE ${Kokkos_INCLUDE_DIRS})

# Configuration de l’extension .so
set_target_properties(plugin_kokkos PROPERTIES PREFIX "")

