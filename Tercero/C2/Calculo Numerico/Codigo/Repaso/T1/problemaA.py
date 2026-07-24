import numpy as np

a = 1.
b = 10.**8
c = 1.

D = lambda a,b,c: b**2 - (4*a*c)
xplus = lambda a,b,c: (-b + np.sqrt(D(a,b,c)))/(2*a)
xminus = lambda a,b,c: (-b - np.sqrt(D(a,b,c)))/(2*a)

#x+ es 0 --> Esto es incorrecto ya que una raiz es 0 solo cuando c es 0 --> Ocurre cancelacion catastrofica
# Soluciones: 
# 1. Multiplicar y Dividir por el conjugado
# 2. El producto de 2 raices es igual c/a

# Usaremos solucion 2 por rapidez --> x+ * x- = c/a
xplus_true = lambda a,b,c: c/(a*xminus(a,b,c))

err_rel = lambda a,b,c: (np.fabs(xplus_true(a,b,c) - xplus(a,b,c))/xplus_true(a,b,c))*100
err_abs = lambda a,b,c: np.fabs(xplus_true(a,b,c) - xplus(a,b,c))


print(f"x+={xplus_true(a,b,c):e} x-={xminus(a,b,c):e}")
print(f"Error Relativo: {err_rel(a,b,c):.2f}%. Error Absoluto: {err_abs(a,b,c):e}")