import numpy as np

def punto_fijo(g, x0, tol=1.e-6, maxit=200, verbose=False):

    k = 0
    x_k = x0
    x_k_minus1 = x0

    print(f"{'k':>4}  {'x_k':>18}  {'cota error':>14}")
    print("-" * 42)

    while k < maxit:

        x_k = g(x_k_minus1)
        error = np.abs(x_k - x_k_minus1)

        if verbose:
            print(f"{k:>4}  {x_k:>18.10f}  {error:>14e}")

        if error < tol:       # Criterio de parada
            break

        k += 1
    else:
        print(f"\nAdvertencia: número máximo de iteraciones ({maxit}) alcanzado.")

    return x_k
