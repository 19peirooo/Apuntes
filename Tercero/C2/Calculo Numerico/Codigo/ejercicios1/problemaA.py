# PROBLEMA A - Resolución de ecuaciones de 2º grado 
from math import sqrt,fabs

a = 1.0
b = 10**8
c = 1.0

#Ocurre cancelacion catastrofica al restar cuando 4ac es much menor que b en xpos
D = lambda a,b,c: sqrt(b**2 - (4*a*c))
xpos = lambda a,b,c: (-b + D(a,b,c))/(2*a)
xneg = lambda a,b,c: (-b - D(a,b,c))/(2*a)

#Solucion 1 --> Multiplicar y Dividir Por el Conjugado
#Solucion 2 --> El producto de 2 raices distintas es igual a c/a

#Solucion 1
xpos1 = lambda a,b,c: (2*c)/(-b - D(a,b,c)) 

err_rel1 = lambda a,b,c: (fabs(xpos1(a,b,c) - xpos(a,b,c))/xpos1(a,b,c))*100
err_abs1 = lambda a,b,c: fabs(xpos1(a,b,c) - xpos(a,b,c))

#Solucion 2 
xpos2 = lambda a,b,c: c / (a * xneg(a,b,c))

err_rel2 = lambda a,b,c: (fabs(xpos2(a,b,c) - xpos(a,b,c))/xpos2(a,b,c))*100
err_abs2 = lambda a,b,c: fabs(xpos2(a,b,c) - xpos(a,b,c))

print(f"Solucion 1 de {a}x^2 + {b}x + {c} = 0")
print(f"x+ = {xpos1(a,b,c):e}, x- = {xneg(a,b,c):e}")
print(f"Error Relativo: {err_rel1(a,b,c):.2f}%. Error Absoluto: {err_abs1(a,b,c):e}")

print("")

print(f"Solucion 2 de {a}x^2 + {b}x + {c} = 0")
print(f"x+ = {xpos2(a,b,c):e}, x- = {xneg(a,b,c):e}")
print(f"Error Relativo: {err_rel2(a,b,c):.2f}%. Error Absoluto: {err_abs2(a,b,c):e}")