import numpy as np

def biseccion(f,a,b, tol=1e-6, maxIter = 200, verbose=False):

    k = 0
    fa,fb = f(a),f(b)

    assert fa*fb < 0, "No se puede aplicar biseccion"

    if verbose:
        print(f"{'k':>3} {'a':>12} {'b':>12} {'midpoint':>12} {'f(mid)':>12} {'error':>12}")
    
    while k < maxIter:

        midpoint = (a + b)/2
        f_midpoint = f(midpoint)
        
        error = np.abs(b - a)

        if verbose:
            print(f"{k:3d} {a:12.6e} {b:12.6e} {midpoint:12.6e} {f_midpoint:12.6e} {error:12.6e}")

        if fa*f_midpoint < 0:
            b, fb = midpoint, f_midpoint
        
        elif fb*f_midpoint < 0:
            a, fa = midpoint, f_midpoint

        else:
            if verbose:
                print(f"\nRaíz exacta encontrada en x = {midpoint}")
            break

        
        if error < tol:
            break

        k += 1

    else:
        print("Max Iter Reached")
    
    return midpoint


f = lambda x: np.log(x) + x
a = 0.1
b = 1.

root = biseccion(f,a,b,verbose=True)

print(f"\nRaíz: {root:.8f} --> f(raíz) = {f(root):.3e}")