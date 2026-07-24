import numpy as np

f_x = lambda x: x**2 - x - 1
g_x = lambda x: np.sqrt(x+1)

def punto_fijo(g, x0, tol=1.0e-6,maxit=200,verbose=False):
    if verbose:
        print(f"{'k':>4}  {'x_k':>18}  {'cota error':>14}")
        print("-" * 42)

    x1 = x0
    for k in range(1, maxit + 1):
        x1 = g(x0)           # Nueva aproximación: x_{k+1} = g(x_k)
        error = abs(x1 - x0) # Cota del error: |x_{k+1} - x_k|

        if verbose:
            print(f"{k:>4}  {x1:>18.10f}  {error:>14e}")

        if error < tol:       # Criterio de parada
            break

        x0 = x1
    else:
        print(f"\nAdvertencia: número máximo de iteraciones ({maxit}) alcanzado.")

    return x1



def biseccion(f,a,b,tol=1.0e-6,maxit=200,verbose=False):

    fa,fb = f(a),f(b)

    assert fa*fb < 0, "No se cumplen las condiciones para aplicar M. de Biseccion"

    for k in range(0,maxit):
        c = (a+b)/2
        fc = f(c)
        if verbose:
            print(f"Iteracion: {k}, a={a}, b={b}, c={c}, f(c)={fc}")

        if fa * fc < 0:
            b, fb = c, fc
        elif fb * fc < 0:
            a,fa = c, fc
        else:
            break
        
        error = b - a
        if np.abs(error) < tol:
            break

    else: #Solo ocurre cuando se completa todo el bucle
        print(f"Maximo de Iteraciones {maxit} alcanzadas")
    
    return c