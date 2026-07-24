import numpy as np

f = lambda x: 1/(np.sqrt(x**2 + 1) - x) # Ocurre cancelación catastrofica

# Ocurre cancelación catastrofica cuando x**2 es muy grande, la maquina no la suficiente precision para
# detectar el + 1 asi que no va a tener efecto. Entonces en el denominador tenemos

def evaluate_function(f):

    x_vals = [10**n for n in range(4,10)]

    for x_val in x_vals:
        print(f"x = {x_val:e} --> f(x) = {f(x_val)}")

evaluate_function(f)

