import numpy as np
#PROBLEMA B - Resolver el problema de Basel

MAX_N_SUM = 94906266
MAX_N_SUM_INVERSE = 0
MAX_N_KAHAN = 677111375

TRUE_VAL = np.pi**2 / 6

#Funcion para hacer el sumatorio
def s_n(n):
    res = 0

    for i in range(1,n+1):
        new_term = 1/(i**2)

        new_sum = res + new_term

        # Quiero que cierre el bucle cuando ya no haga falta sumar mas numeros porque ya no tienen relevancia
        if new_sum == res:
            return i, res
        
        res = new_sum

    return i,res

#Mejorar la precision sumando de manera inversa
def s_n_inverse(n):
    res = 0.0
    count = 0

    for i in range(n, 0, -1):
        new_term = 1/(i**2)
        new_sum = res + new_term

        if new_sum == res:
            return count, res
        
        res = new_sum
        count += 1

    return count, res

def kahan_sum(n):
    s = 0. # Suma
    new_s = 0.
    c = 0. # Guarda el error de redondeo perdido
    for i in range(1,n+1):
        new_term = 1/(i**2)
        y = new_term - c # Restamos el error antes de sumar --> Corrijo lo que perdi antes
        t = s + y #Hacemos la suma normal
        c = (t - s) - y #Calculamos en nuevo error
        new_s = t

        if new_s == s:
            return i,s
        
        s = new_s

    return i,s

test_vals = [10**i for i in range(15)]

for n in test_vals:
    # k, root = s_n(n) # Para usar suma normal
    # k, root = s_n_inverse(n)
    k , root = kahan_sum(n) # Para usar suma de kahan
    print(f"{k} --> s_n: {root}")
    print(f"Error Absoluto: {np.abs(root - TRUE_VAL):e}")
    print(f"Error Relativo: { (np.abs(root - TRUE_VAL) / TRUE_VAL)*100:e}%")