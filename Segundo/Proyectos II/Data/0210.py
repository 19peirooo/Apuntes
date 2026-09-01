import functools

#Map --> Aplica un funcion a todos los elementos de una lista
def fact(x):
    if x == 0:
        return 1
    else:
        return x*fact(x-1)

lista = list(map(fact,range(7)))  #Hay que hacer el casting para poder ver los elementos de la lista
print(lista)

lista2 = [(map(fact,range(7)))]  #Si no hago casting imprime el iterador del map
print(lista2)

lista3 = list(map(lambda x : x**2,range(1,10,3)))
print(lista3)

lista4 = list(map(lambda x,y : x+y,range(7),range(7)))
print(lista4)

#Filter --> Filtar los elementos de una lista en funcion de una condicion

lista5 = list(filter(lambda x: not x%3,range(10)))
print(lista5)

#reduce --> Reduce todos los elementos de una secuencia mediante un algoritmo
print("Reduce: ")
print(functools.reduce(lambda x,y : x*y, range(1,5)))

#Listas Comprendidas
print([x for x in lista])

print([x for x in range(10) if not x%2])

print([x**2 -1 for x in range(10)])

binario = [0,1]
print([(x,y,z) for x in binario for y in binario for z in binario])

print([[x+y for x in range(5)]for y in range(5)])

print(["par" if not x%2 else "impar" for x in range(1,11)])

print({x:x*2 for x in range(10)}) #Diccionario comprendido

todos = {x:x*2 for x in range(10)}
print({x:y for x,y in todos.items() if not x%2})

#Funciones

def f1 (arg1, arg2=None):
    return 0;

def f2(arg1,arg2,arg3=None):
    if arg3 == None:
        return arg1+arg2
    else:
        return arg1+arg2+arg3

print(f2(1,2))
print(f2(1,2,3))

def f3(*l):
    return functools.reduce(lambda x,y: x+y ,l)

print(f3(1,2,3,4,5))

def f4(**kwargs):
    for k,v in kwargs.items():
        print(k,v)

f4(nombre = "victor", apellido = "peiro")


class Perro:
    def __init__(self,E,R):
        self.edad = E;
        self.raza = R;


    def getEdad(self):
        return self.edad

    def getRaza(self):
        return self.raza

    def ladrar(self):
        print("Guau")

p1 = Perro(21,"GoldenRetriever")
print(p1.getEdad())