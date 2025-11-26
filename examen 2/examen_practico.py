def max_recursivo(lista):

    if len(lista) == 1:
        return lista[0]

#Divide - se parte la lista en dos mitades

    mitad = len(lista) // 2
    izq = lista[:mitad]
    der = lista[mitad:]

#Conquer - Se busca eñ maximo de cada mitad

    max_izq = max_recursivo(izq)
    max_der = max_recursivo(der)

    return max(max_izq, max_der)

#Se pide el tamaño de la lista y se agrgan uno por uno.

n = int(input("Ingrese el tamaño de la lista:"))
lista = []

print("Ingrese los elementos")
for _ in  range(n):
    valor = int(input())
    lista.append(valor)

#llamamos a la funcion recursiva y se muestra el resultado

resultado = max_recursivo(lista)
print("El valor máximo es:", resultado)

