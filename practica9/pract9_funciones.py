def imprime_nombre(nombre):
    print("hola, " + nombre)

imprime_nombre("Yuriko")

def cuadrado(numero):
    return x**2

x=5
print("El cuadrado de {} es {}".format(x, cuadrado(x)))
      

def varios(x):
    return x**2, x**3, x**4

val1, val2, val3 = varios(3)
print("{} {} {}".format(val1, val2, val3))

def cuadrado_default(x=3):
    return x**2

cuadrado_default()