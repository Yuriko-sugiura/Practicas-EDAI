def obtenerMayor(param1, param2):
    if param1 < param2:
        print('{} es mayor que {}'.format(param2, param1))

obtenerMayor(5, 7)

obtenerMayor(7, 5)

x = y = z = 3

if x == y == z: 
    print(True)

#if-else

def obtenerMayorv2(param1, param2):
    if param1 < param2:
        return param2
    else:
        return param1


print("El mayor es: {}".format(obtenerMayorv2(4, 20)))
print("El mayor es: {}".format(obtenerMayorv2(11, 6)))

def obtenerMayor_idiom(param1, param2):
    valor = param2 if param1 < param2 else param1
    return valor

print("El mayor es: {}".format(obtenerMayor_idiom(11, 6)))

#if-elif-else

def numeros(num):
    if num == 1:
        print("Tu numero es 1")
    elif num == 2:
        print("Tu numero es 2")
    elif num == 3:
        print("Tu numero es 3")
    elif num == 4:
        print("Tu numero es 4")
    else:
        print("No hay opción, (No c cual sea mano)")

numeros(2)
numeros(5)

def numeros_idiom(num):
    if num in (1,2,3,4):
        print("Tu numero es {}".format(num))
    else:
        print("{} no  es una opcion".format(num))

numeros_idiom(2)
numeros_idiom(5)

def ObtenerMasGrande(a, b, c):
    if a>b:
        if a>c:
            return a
        else:
            return c
    else:
        if b>c:
            return b
        else:
            return c
    
print("El mas grande es {}".format(ObtenerMasGrande(7, 13, 1) ))