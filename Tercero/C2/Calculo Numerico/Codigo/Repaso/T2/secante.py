import numpy as np

f = lambda x: np.log(x) + x

def secante(f, x1, x2, tol=1e-6,maxit=100, verbose=True):

    x_kminus1 = x1
    x_k = x2
    x_kplus1 = x2
    error = 0

    if verbose:
        print("k\t\tx_k\t\tx_k+1\t\terror")

    for k in range(maxit):

        f_xk = f(x_k)
        f_xkminus1 = f(x_kminus1)

        x_kplus1 = x_k - f_xk*((x_k-x_kminus1)/(f_xk - f_xkminus1))

        error = np.abs(x_kplus1 - x_k)

        if verbose:
            print(f"{k}\t\t{x_k}\t\t{x_kplus1}\t\t{error}")


        if error < tol:
            break

        x_kminus1 = x_k
        x_k = x_kplus1
        

    else:
        print("Numero Maximo de Iteraciones Alcanzado")

    
    return x_kplus1 

x1 = 1.
x2 = 2.
root = secante(f,x1,x2)

print(f"xk = {root}, f(xk) = {f(root)}")
