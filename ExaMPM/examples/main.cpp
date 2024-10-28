#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // for std vector support
#include "dam_break.hpp"


PYBIND11_MODULE(DamBreak, m) {
    m.def("loop", &loop, "do the work");
}

