def secante(f, x_, x0, tol=1.0e-6, maxit=200, verbose=False):
    xk = x_  # x_-1
    xk1 = x0  # x_0
    fxk = f(xk)  # x_k
    fxk1 = f(xk1)  # x_{k+1}

    if verbose:
        print("k\t\tx_k\t\error")
        print(f"-1\t\t{xk:e}\t")
        print(f"0\t\t{xk1:e}\t")

    for k in range(1, maxit):
        xk, xk1 = xk1, xk1 - fxk1 * (xk1 - xk) / (fxk1 - fxk)
        fxk = fxk1
        fxk1 = f(xk1)

        error = abs(xk1 - xk)
        if verbose:
            print(f"{k}\t\t{xk1:e}\t{error:e}")

        if error < tol:
            break
    else:
        xk = None
        print(f"Número máximo de iteraciones {maxit} alcanzado")

    return xk


if __name__ == "__main__":
    from math import exp

    f = lambda x: x * (exp(x / 2.0) + 1)

    # Busco la raíz positiva de f x_root
    x_root = secante(f, 2.5, 2, tol=1e-6, maxit=50, verbose=True)
