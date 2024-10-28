import plugin_kokkos

data = [1, 2, 3, 4, 5] # doit faire 15
res = plugin_kokkos.somme_kokkos(data)
print(f"Somme : {res}")

