import numpy as np

f = lambda x: np.log(x) + x

def biseccion(f,a,b,tol=1.0e-6,maxit=200,verbose=False):

    fa,fb = f(a),f(b)

    assert fa*fb < 0, "No se cumplen las condiciones para aplicar M. de Biseccion"

    err_prev = 1
    c_prev = a + b
    for k in range(0,maxit):
        c = (a+b)/2
        fc = f(c)

        if fa * fc < 0:
            b, fb = c, fc
        elif fb * fc < 0:
            a,fa = c, fc
        else:
            break
        
        error = np.abs(c - c_prev) if c_prev is not None else None
        ratio = error/err_prev if err_prev is not None else None

        if verbose:
            print(f"Iteracion: {k}, a={a}, b={b}, c={c}, f(c)={fc}, error={error:e}, ratio={ratio:e}")
        
        if np.abs(error) < tol:
            break

        err_prev = error
        c_prev = c

    else: #Solo ocurre cuando se completa todo el bucle
        print(f"Maximo de Iteraciones {maxit} alcanzadas")
    
    return c

root = biseccion(f,0.1,2,verbose=True)
print(f"Raiz: {root}")