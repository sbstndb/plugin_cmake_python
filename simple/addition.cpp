#include <pybind11/pybind11.h>

int addition ( int a , int b) {
	return a + b ; 		
}


PYBIND11_MODULE(mon_module, m){
	m.def("addition", &addition, "Fonction qui +") ; 
}


