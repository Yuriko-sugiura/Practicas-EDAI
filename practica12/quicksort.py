def quicksort(lista):
    if len(lista) <=1:
        return lista
    
    pico = lista[len(lista)//2]

    menor = [x for x in lista if x < pico]
    igual = [x for x in lista if x == pico]
    mayor = [x for x in lista if x > pico]

    return quicksort(menor) + igual + quicksort(mayor)


n = int(input("Ingrese la cantidad de elementos que tendra su lista:"))
lista = []

print("Ingrese los elementos contenidos en su lista")
for _ in range(n):
    lista.append(int(input()))

print("Lista ordenada:", quicksort(lista))
