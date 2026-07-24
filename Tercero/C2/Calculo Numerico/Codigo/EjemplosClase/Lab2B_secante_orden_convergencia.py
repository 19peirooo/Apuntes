from math import log


def secante(f, x_, x0, tol=1.0e-6, maxit=200, verbose=False, xs=None):
    err = []  # errores con respecto a la raíz real xs
    r = -1  # orden de convergencia
    ratio = -1
    xk = x_  # x_-1
    xk1 = x0  # x_0
    fxk = f(xk)  # x_k
    fxk1 = f(xk1)  # x_{k+1}

    if verbose:
        print("k\t\tx_k\t\te_k\t\tr\t\tek/ek-1")
        print(f"-1\t\t{xk:e}\t")
        print(f"0\t\t{xk1:e}\t")

    for k in range(1, maxit):
        xk, xk1 = xk1, xk1 - fxk1 * (xk1 - xk) / (fxk1 - fxk)
        fxk = fxk1
        fxk1 = f(xk1)

        error = abs(xk1 - xk)
        #### Orden de Convergencia
        err.append(abs(xk - xs))
        if len(err) >= 2:
            ratio = err[-1] / err[-2]
        if len(err) >= 3:
            e1 = err[-3]
            e2 = err[-2]
            e3 = err[-1]
            r = log(e2 / e3) / log(e1 / e2)
            err.pop(0)  # Opcional
        ###
        if verbose:
            print(f"{k}\t\t{xk1:e}\t{error:e}\t{r:.6f}\t{ratio:e}")

        if error < tol:
            break
    else:
        xk = None
        print(f"Número máximo de iteraciones {maxit} alcanzado")

    return xk


if __name__ == "__main__":
    from math import exp

    f = lambda x: x * (exp(x / 2.0) + 1)

    # Calcular el orden de convergencia con respecto a la raíz real xs=0.0
    x_root = secante(f, 2.5, 2, tol=1e-15, maxit=50, verbose=True, xs=0.0)
