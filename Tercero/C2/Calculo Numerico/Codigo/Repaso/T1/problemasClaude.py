import numpy as np

def ej1():
    pi_true = np.pi
    pi_aprox = 355/113

    err_abs = np.abs(pi_true - pi_aprox)
    err_rel = (err_abs/pi_true)*100

    num_decimales = -np.log10(err_rel)

    print(f"pi={pi_true}. Aprox: {pi_aprox}")
    print(f"Error Absoluto: {err_abs:2e}. Error Relativo: {err_rel:2e}%")
    print(f"Numero decimales Correcto: {num_decimales}")

def ej2():
    x = 9.81
    y = 3.2

    err_abs_x = 0.05 
    err_abs_y = 0.02

    err_rel_x = err_abs_x/x  
    err_rel_y = err_abs_y/y

    # z = x*y
    z = x*y
    err_rel_z = err_rel_x + err_rel_y
    err_abs_z = err_rel_z * z

    print("z = x * y")
    print(f"z = {z:e}")
    print(f"Error Absoluto: {err_abs_z:e}")
    print(f"Error Relativo: {err_rel_z*100:2f}%")

    # w = x/y
    w = x/y
    err_rel_w = err_rel_x + err_rel_y
    err_abs_w = err_rel_z * w

    print("w = x / y")
    print(f"w = {w:e}")
    print(f"Error Absoluto: {err_abs_w:e}")
    print(f"Error Relativo: {err_rel_w*100:2f}%")

def ej3():

    x_vals = [1e7,1e10,1e13,1e16]

    f = lambda x: np.sqrt(x+1) - np.sqrt(x) #Con valores muy grandes --> Ocurre cancelacion catastrofica 
    f_true = lambda x: 1/(np.sqrt(x+1) + np.sqrt(x))

    for x in x_vals:
        f_true_x = f_true(x)
        f_x = f(x)
        err_abs = np.fabs(f_true_x - f_x)
        err_rel = err_abs/f_true_x 
        print(f"f({x:.0e}) = {f_true_x:e}")
        print(f"Error Absoluto: {err_abs:e}")
        print(f"Error Relativo: {err_rel*100:.2e}%")
        print()

def eps_64():
    x = np.float64(1)

    while np.float64(1.) + x != np.float64(1.):
        x = x/np.float64(2.)
    EPS = np.float64(2.)*x
    return EPS

def eps_32():
    x = np.float32(1)

    while np.float32(1.) + x != np.float32(1.):
        x = x/np.float32(2.)
    EPS = np.float32(2.)*x
    return EPS

def ej4():
    eps64 = eps_64()
    eps32 = eps_32()

    print("=== Doble Precision (64 bits) ===")
    print(f"EPS Calculado: {eps64}")
    print(f"numpy.finfo eps:      {np.finfo(float).eps:.16e}")
    print(f"¿Coinciden? {eps64 == np.finfo(float).eps}\n")

    print("=== Simple Precision (32 bits) ===")
    print(f"EPS Calculado: {eps32}")
    print(f"numpy.finfo eps:      {np.finfo(float).eps:.16e}")
    print(f"¿Coinciden? {eps32 == np.finfo(float).eps}")

def ej5():

    print("=== OVERFLOW ===")
    x = 2.
    anterior = x

    while x != float("inf"):
        anterior = x
        x = x*x
    print(f"Ultimo valor: {anterior}")
    print(f"numpy finfo max:      {np.finfo(float).max:.6e}")
    print(f"¿Nuestro valor <= max? {anterior <= np.finfo(float).max}")

    print()  

    print("=== OVERFLOW ===")
    x = 1.
    anterior = x

    while x != 0.0:
        anterior = x
        x = x/2
    
    print(f"Ultimo valor: {anterior}")
    print(f"numpy finfo tiny:         {np.finfo(float).tiny:.6e}")
    print(f"numpy smallest_subnormal: {np.finfo(float).smallest_subnormal:.6e}")
    print(f"¿Nuestro valor == smallest_subnormal? {anterior == np.finfo(float).smallest_subnormal}")


ej5()