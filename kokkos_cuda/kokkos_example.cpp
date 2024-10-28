// kokkos_example.cpp
#include "kokkos_example.hpp"
#include <Kokkos_Core.hpp>

// Implémentation de la fonction somme_kokkos_gpu
int somme_kokkos(const std::vector<int>& data) {
    // Initialiser Kokkos (et CUDA si activé)
    int somme = 0 ; 
    Kokkos::initialize();
    {
    
    size_t n = data.size();

    // Allouer la vue Kokkos sur le device
    Kokkos::View<int*> device_data("device_data", n);

    // Copier les données de l'hôte vers le device
    Kokkos::View<int*>::HostMirror host_data = Kokkos::create_mirror_view(device_data);
    for (size_t i = 0; i < n; ++i) {
        host_data(i) = data[i];
    }
    Kokkos::deep_copy(device_data, host_data);

    // Somme parallèle sur le device (GPU)
    Kokkos::parallel_reduce(n, KOKKOS_LAMBDA(int i, int& update) {
        update += device_data(i);
    }, somme);

    // Finaliser Kokkos
    }
    Kokkos::finalize();

    return somme;
}

