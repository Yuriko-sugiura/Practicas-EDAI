vg = 'Global'
def funcion_v1():
    print(vg)

funcion_v1()
print(vg)

def funcion_v2():
    vg = 'Local'
    print(vg)

funcion_v2()
print(vg)

def funcion_v3():
    print(vg)
    vg = 'Local'
    print(vg)

funcion_v3()