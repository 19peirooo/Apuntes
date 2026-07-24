import numpy as np

def secante(f, x0, x1,xs, tol=1.e-6, maxit=50, verbose=True):

    it = 0
    xk = x0
    xk1 = x1
    f_xk = f(xk)
    f_xk1 = f(xk1)
    r = 0
    
    err = []

    while it < maxit:
        xprev = xk1
        

        xk1 = ((f_xk1*xk)-(f_xk*xk1))/(f_xk1-f_xk)
        xk = xprev

        f_xk = f_xk1
        f_xk1 = f(xk1)

        error = np.abs(xk1-xk)
        err.append(np.abs(xk-xs))

        if len(err) >= 3:
            e1 = err[-1]
            e2 = err[-2]
            e3 = err[-3]

            r = (np.log(e2/e3))/(np.log(e1/e2))

            err.pop(0)

        if verbose:
            print(f"Iter {it+1}: x = {xk}, f(x) = {f(xk)}, error = {error}, r = {r}")
        
        if error < tol:
            break
        
        it += 1
        
    else:
        print("Numero maximo de iteraciones alcanzadas")
    
    return xk

f = lambda x: x*(np.exp(x/2) + 1)
x1 = 2.5
x2 = 2
xs = 0

x_root = secante(f,x1,x2, xs)
print(f"root={x_root}")