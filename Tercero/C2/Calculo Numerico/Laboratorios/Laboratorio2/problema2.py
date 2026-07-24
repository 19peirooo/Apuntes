import numpy as np

#Bisección con aproximación lineal
def biseccion(f, a, b,real_root, tol=10.e-8, maxit=20, verbose=False, aprox_lineal = False):
    fa, fb = f(a), f(b)
    assert fa * fb < 0, "No se cumplen condiciones para aplicar M. de Bisección"
    errores = []
    r = 0
    C = 0
    if verbose:
        print("k\t\tx_k\t\tcota error\t\tr\t\tC")
    for k in range(0, maxit):
        if not aprox_lineal:
            c = (a + b) / 2
            fc = f(c)
            
        else:
            m = (fb - fa)/(b-a)
            intercept = fa - (m*a) # Tambien lo puedes hacer con b
            c = -(intercept/m)
            fc = f(c)

        if fa * fc < 0:
            b, fb = c, fc
        elif fc * fb < 0:
            a, fa = c, fc
        else:  # fc == 0
            if verbose:
                print(f"raíz exacta: x*: {c}")
            break

        error = np.abs(c - real_root)
        errores.append(error)

        if (len(errores) >= 3):

            if len(errores) > 3: errores.pop(0)

            e3 = errores[-1]
            e2 = errores[-2]
            e1 = errores[-3]

            r = (np.log(e2/e3))/(e1/e2)
            C = e3 / (e2)**r
        
        if verbose:
            print(f"{k}\t\t{c:.8f}\t{error:e}\t\t{r:e}\t\t{C:e}")

        if error < tol:
            break
    else:
        if aprox_lineal:
            print(f"Número máximo de iteraciones {maxit} alcanzado con aproximacion lineal")
        else:
            print(f"Número máximo de iteraciones {maxit} alcanzado")

    return c

f = lambda x: x**2 - 2
a = 0
b = 2

real_root = np.sqrt(2)

found_root = biseccion(f,a,b,real_root,aprox_lineal=True, verbose=True)

print(f"Found Root: {found_root}")