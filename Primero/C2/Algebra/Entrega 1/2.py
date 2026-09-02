import numpy as np
import sympy

a = int(input("Introduzca el parametro a: "))
b = int(input("Introduzca el parametro b: "))

A = np.array([[a, 1, b], [1, a, 2], [1, a, b]], dtype=int)
B = np.array([0, b-2, a-1], dtype=int)
Amp = np.array([[a, 1, b, 0], [1, a, 2, b-2], [1, a, b, a-1]], dtype=int)

print("Matriz de Coeficientes: \n", A, "\n")
print("Terminos Independientes: \n", B, "\n")
print("Matriz Ampliada: \n", Amp, "\n")


print("Para a=",a,"y b=",b)
rangoA = np.linalg.matrix_rank(A)
print("Rango de Matriz de Coeficientes: ",rangoA)
rangoAmpliada = np.linalg.matrix_rank(Amp)
print("Rango de Matriz Ampliada: ", rangoAmpliada)
numIncognitas = 3

x, y, z = sympy.symbols("x y z")

x1, y1, z1, D1 = A[0, 0], A[0, 1], A[0, 2], Amp[0,3]
x2, y2, z2, D2 = A[1, 0], A[1, 1], A[1, 2], Amp[1,3]
x3, y3, z3, D3 = A[2, 0], A[2, 1], A[2, 2], Amp[2,3]

#Discusion y resolucion del sistema
if rangoA == rangoAmpliada:
    if rangoA == numIncognitas:
        print("Sistema Compatible Determinado: 1 unica solucion para x,y,z")
        print("Los 3 planos coinciden en un unico punto y por lo tanto forman un angulo triedro")
    elif rangoA == 2:
        print("Sistema Compatible Indeterminado de orden 1: Infinitas Solucion dependientes de un parametro")
        print("Los 3 planos se unen en una recta formando un haz de planos")
    else:
        print("Sistema Compatible Indeterminado de orden 2: Infinitas Solucion dependientes de dos parametros")
        print("Los 3 planos son coincidentes")
    sol = sympy.linsolve([a*x + y + b*z, x + a*y + 2*z - (b-2), x + a*y + b*z - (a-1)], (x,y,z))
    print("Solucion: ", sol)
else:
    print("Sistema Incompatible: No existen soluciones para x,y,z")
    if rangoA == 2 and rangoAmpliada == 3:
        if (x1/x2 == y1/y2 and x1/x2 == z1/z2 ):
            print("Planos 1 y 2 son paralelos otro los corta")
        elif (x1/x3 == y1/y3 and x1/x3 == z1/z3):
            print("Planos 1 y 3 son paralelos otro los corta")
        elif (x3/x2 == y3/y2 and x3/x2 == z3/z2 ):
            print("Planos 2 y 3 son paralelos otro los corta")
        else:
            print("Los planos se cortan 2 a 2")
    if rangoA == 1 and rangoAmpliada == 2:
        if (x1/x2 == y1/y2 and x1/x2 == z1/z2 and x1/x2 == D1/D2):
            print("Planos 1 y 2 son coincidentes y el otro es paralelo a ellos")
        elif (x1/x3 == y1/y3 and x1/x3 == z1/z3 and x1/x2 == D1/D3):
            print("Planos 1 y 3 son coincidentes y el otro es paralelo a ellos")
        elif (x3/x2 == y3/y2 and x3/x2 == z3/z2 and x3/x2 == D3/D2):
            print("Planos 2 y 3 son coincidentes y el otro es paralelo a ellos")
        else:
            print("Los 3 planos son paralelos")