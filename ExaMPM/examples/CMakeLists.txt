

find_package(pybind11 REQUIRED)
find_package(Kokkos REQUIRED)

#set_target_properties(CUDA::cuda_driver PROPERTIES IMPORTED_LOCATION "/usr/lib64/libcuda.so")


#add_executable(DamBreak dam_break.cpp )
add_library(DamBreak SHARED main.cpp dam_break.cpp)
target_link_libraries( DamBreak PRIVATE exampm pybind11::module) #CUDA::cuda_driver)
target_include_directories(DamBreak PRIVATE ${Kokkos_INCLUDE_DIRS})
set_target_properties(DamBreak PROPERTIES PREFIX "")

##install(TARGETS DamBreak FreeFall DESTINATION ${CMAKE_INSTALL_BINDIR})
