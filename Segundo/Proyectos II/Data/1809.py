from typing import Any
def factorial(x):
    if x == 0:
        return 1
    else:
        return x*factorial(x-1)

def tipo(var):
    return type(var)


# Tipado Estatico
num: int = 45
palabra: str = "hola"
exito: bool = True
pi: float = 3.14159

#Varios tipos
n: str | None = 45
n1: str | int = 45
n2: Any = 45 #Puede ser todos los tipos

#Listas
lista = [21, 'cadena', True, 45, 67, "hola", 'mundo', '56']
lista1: list = [21, 'cadena', True]
lista_enteros: list[int] = [21,45,67]
lista_enteros_o_cadenas: list[int | str] = [21, 45, 67 , 'cadena']

i = 0
j = 4
k = 2

print("Indice: ", lista[i])
print("Ultimo Indice con -1: ", lista[-1])
print("Rango de Indices: ", lista[i:j]) #No coge el ultimo
print("Rango de Indices con step: ", lista[i::k])
lista.append(78) #Añade un elemento a la lista
print("He añadido el 78n con append: ", lista)
print("Lista al reves con [::-1]: ", lista[::-1])
lista.extend(lista_enteros)
print("Añado otra lista con extend(): ", lista)
lista.insert(3,'22')
print("Introduzco el valor 22 en la posicion 3 con insert()", lista)
lista.remove('22')
print("Elimino el 22 con remove(): ", lista)
lista.pop()
print("Elimino el ultimo objeto con pop(): ", lista)
print("Indice del 56 con index(): ", lista.index('56'))


#Pila y Cola

def pila():
    pila = [1,2,3,4,5]
    print(pila)
    print("Añado el valor a mi pila: ")
    pila.append(34)
    print(pila)
    print("Quiero sacar el valor nuevo de mi pila: ")
    pila.pop()
    print(pila)

pila()
def cola():
    cola = [1,2,3,4,5]
    print(cola)
    print("Quito el uno de mi cola: ")
    cola.pop(0)
    print(cola)
    cola.append(1)
    print("Aparece al final: ")
    print(cola)

print()
cola()