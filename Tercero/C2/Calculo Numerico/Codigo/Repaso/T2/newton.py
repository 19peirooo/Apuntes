import numpy as np

f = lambda x: np.log(x) + x
df = lambda x: (1./x) + 1.

def newton(f, df, x0, tol=1e-6,maxit=100, verbose=True):

    x_k = x0
    x_kplus1 = x0
    error = 0

    if verbose:
        print("k\t\tx_k\t\tx_k+1\t\terror")

    for k in range(maxit):

        f_xk = f(x_k)
        df_xk = df(x_k)

        if f_xk != 0:
            x_kplus1 = x_k - (f_xk/df_xk)

            error = np.abs(x_kplus1 - x_k)

            if verbose:
                print(f"{k}\t\t{x_k}\t\t{x_kplus1}\t\t{error}")


            if error < tol:
                break
        
        x_k = x_kplus1

    else:
        print("Numero Maximo de Iteraciones Alcanzado")

    
    return x_kplus1 

x0 = 1.
root = newton(f,df,x0)

print(f"xk = {root}, f(xk) = {f(root)}")
