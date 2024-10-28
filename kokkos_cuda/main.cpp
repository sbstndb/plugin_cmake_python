#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // for std vector support
#include "kokkos_example.hpp"


PYBIND11_MODULE(plugin_kokkos, m) {
    m.def("somme_kokkos", &somme_kokkos, "+ de selements d'un tableau");
}

