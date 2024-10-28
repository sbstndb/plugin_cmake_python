// kokkos_example.hpp
#include <Kokkos_Core.hpp>
#include <vector>

// Fonction qui utilise Kokkos pour additionner les éléments d'un tableau
int somme_kokkos(const std::vector<int>& data) {
    Kokkos::initialize();
    int somme = 0;
    Kokkos::parallel_reduce(data.size(), KOKKOS_LAMBDA(int i, int& update) {
        update += data[i];
    }, somme);
    Kokkos::finalize();
    return somme;
}

