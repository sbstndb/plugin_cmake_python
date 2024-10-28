#include "kokkos_example.hpp"
#include <Kokkos_Core.hpp>

int somme_kokkos(const std::vector<int>& data) {
    int somme = 0 ; 
    Kokkos::initialize();
    {
    
    size_t n = data.size();

    Kokkos::View<int*> device_data("device_data", n);

    Kokkos::View<int*>::HostMirror host_data = Kokkos::create_mirror_view(device_data);
    for (size_t i = 0; i < n; ++i) {
        host_data(i) = data[i];
    }
    Kokkos::deep_copy(device_data, host_data);

    Kokkos::parallel_reduce(n, KOKKOS_LAMBDA(int i, int& update) {
        update += device_data(i);
    }, somme);

    }
    Kokkos::finalize();

    return somme;
}

