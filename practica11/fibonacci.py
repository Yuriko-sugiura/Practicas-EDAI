from functools import lru_cache
@lru_cache(None)

def fabronacci(n): 
    if n<=1:
        return n
    return fabronacci(n-1)+fabronacci(n-2)

posicion1 = [7]

for p in posicion1:
    print(f"F({p}) = {fabronacci(p)}")

posicion2 = [21]

for p in posicion2:
    print(f"F({p}) = {fabronacci(p)}")

posicion3 = [40]

for p in posicion3:
    print(f"F({p}) = {fabronacci(p)}")

posicion4 = [71]

for p in posicion4:
    print(f"F({p}) = {fabronacci(p)}")

posicion5 = [94]

for p in posicion5:
    print(f"F({p}) = {fabronacci(p)}")
