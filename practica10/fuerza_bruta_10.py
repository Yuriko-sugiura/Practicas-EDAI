import itertools
import time

contraseña = "0234567890"
caracteres = "0123456789"
intentos = 0

inicio = time.time()

for combinacion in itertools.product(caracteres, repeat=10):
    intento = ''.join(combinacion)
    intentos +=1

    if intento == contraseña:
        fin = time.time()
        print("Contraseña encontrada:", intento)
        print("Intentos:", intentos)
        print("Tiempo:", round(fin-inicio, 2), "segundos")
        break
