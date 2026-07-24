def biseccion(f, a, b, tol=1.0e-6, maxit=200, verbose=False):
    fa, fb = f(a), f(b)
    assert fa * fb < 0, "No se cumplen condiciones para aplicar M. de Bisección"
    if verbose:
        print("k\t\tx_k\t\te_k\t\tr\t\tek/ek-1")

    err = []
    r = -1
    ratio = -1
    cprev = a
    for k in range(0, maxit):
        c = (a + b) / 2
        fc = f(c)
        if fa * fc < 0:
            b, fb = c, fc
        elif fc * fb < 0:
            a, fa = c, fc
        else:  # fc == 0
            if verbose:
                print(f"raíz exacta: x*: {c}")
            break

        # error = b - a
        error = abs(c - cprev)
        #### Orden de Convergencia
        err.append(error)
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
            print(f"{k}\t\t{c:.8f}\t{error:e}\t{r:.6f}\t{ratio:e}")
        cprev = c
        if error < tol:
            break
    else:
        print(f"Número máximo de iteraciones {maxit} alcanzado")

    return c


if __name__ == "__main__":
    from math import log, ceil

    f = lambda x: log(x) + x
    eps = 1.0e-8
    N = ceil((log(1 - 0.1) - log(2 * eps)) / log(2))
    print(
        f"Necesito calcular xk hasta k={N} para garantizar un error menor que eps={eps}"
    )
    x_raiz = biseccion(f, 0.1, 1, tol=eps, verbose=True)
    print(f"x* = {x_raiz}")
    print(f"f(x*) = {f(x_raiz)}")
