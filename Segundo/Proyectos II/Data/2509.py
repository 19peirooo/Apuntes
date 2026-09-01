# Tuplas: Lista No Mutables
tuple = (21,'cadena', True)

# Conjuntos: No hay elementos repetidos
conjunto = {21, 'cadena', True}
conjunto2 = {21, 'cadena', True, 23}

conjunto.add(21) #Añade valores al conjunto. Si es repetido, no lo añade
print(conjunto)
conjunto.remove(21) #Lanza excepcion si no encuentra numero a eliminar
print(conjunto)
conjunto.discard(45) #No lanza excepcion si no encuentra el numero
print(conjunto)
x = conjunto.pop() #Quita y lo devuelve
print(x)
print(conjunto)
conjunto.update(conjunto2) #Añade un conjunto en otro
conjunto.add(56)
print(conjunto)
print(x in conjunto) #Mira si un elemento esta en un conjunto
print(conjunto <= conjunto2) #Comprueba si uno es subconjunto del otro
print(conjunto >= conjunto2) #Comprueba si uno es suboconjunto del otro
print(conjunto - conjunto2) #Elimina la interseccion

#Diccionario
dicc = {'c1':1,'c2':2}

print(dicc['c1']) #Accede a un elemento por su clave
print(dicc.get('c2')) #Accede a un elemento por su clave
print(dicc.keys()) #Coje todas las claves
print('c1' in dicc) #Ve si esta es clave en el diccionario
print(dicc.items()) #Imprime los elementos con su clave

#Metodos COmunes
lista = [1,2,3,4]
del lista[-2:]
print(lista)

long = len(lista) #Longitud de la lista

iterador = iter(lista)
next(iterador);

#Codiciones y bucles
a = 1
b = 0

print (a and b) #Operador Logico AND

var1 = [1,2,3]
var2 = var1
var3 = var1[:]

print(var1 == var2)
print(var1 is var2)

print(var1 == var3)
print(var1 is var3)

var0 = None

if var0 is None:
    var0 = 1


def cuenta_atras():
    i = 10
    while i > 0:
        print(i)
        i-=1

cuenta_atras()

for i,j in dicc.items():
    print(i,j+1)

#Cuenta Atras con for
for i in range(4,-1,-1):
    print(i)

n = 0
while n < 10:
    n+=1
    print(n)
else:
    print("n es 10")

#Lambda Function
funct = lambda x: x**2 #Funcion en una sola linea. No queda registrada
print(funct(2))

#Map
def fact(x):
    if x == 0:
        return 1
    else:
        return x*fact(x-1)

lista = [(map(fact,range(7)))]
print(lista)
