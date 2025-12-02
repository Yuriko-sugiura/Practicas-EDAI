memoria = {}

def fibonacci_top_down(n):
    if n in memoria:
        return memoria[n]

    if n == 0:
        return 0
    if n == 1:
        return 1
    
    memoria[n] = fibonacci_top_down(n-1) + fibonacci_top_down(n-2)
    return memoria[n]

n = int(input("Ingrese un numero"))
print ("Resultado:", fibonacci_top_down(n))
