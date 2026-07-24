def punto_fijo(g, x0, tol=1.0e-6, maxit=200, verbose=False):
    xk = x0

    if verbose:
        print("k\t\tx_k\t\tcota error")
        print(f"0\t\t{xk:.8f}\t")

    for k in range(1, maxit):
        xprev = xk
        xk = g(xprev)

        error = abs(xk - xprev)
        if verbose:
            print(f"{k}\t\t{xk:.8f}\t{error:e}")

        if error < tol:
            break
    else:
        xk = None
        print(f"Número máximo de iteraciones {maxit} alcanzado")

    return xk


if __name__ == "__main__":
    from math import sqrt

    f = lambda x: x**2 - x - 1.0

    # Busco la raíz positiva de f x_root
    g1 = lambda x: x**2 - 1.0
    g2 = lambda x: sqrt(x + 1.0)
    g3 = lambda x: 1.0 + 1.0 / x
    g4 = lambda x: x - f(x) / (2 * x - 1)
    x_root = punto_fijo(g4, 1.5, verbose=True)
