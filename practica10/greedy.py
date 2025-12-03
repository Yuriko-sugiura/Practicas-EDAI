def cambio_greedy(cantidad, monedas):
    resultado = {}
    for moneda in monedas:
        num = cantidad // moneda
        if num > 0:
            resultado[moneda] = num
            cantidad -= moneda * num
    return resultado

cantidad = int(input("Ingresa la cantidad de dinero: "))
monedas = [50, 20, 10, 5, 2, 1]

resultado = cambio_greedy(cantidad, monedas)

print("\nCambio:")
for moneda in resultado:
    if resultado[moneda] == 1:
        print(f"1 moneda de {moneda}")
    else:
        print(f"{resultado[moneda]} monedas de {moneda}")
