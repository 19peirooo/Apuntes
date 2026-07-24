import numpy as np

def calc_fd(f,x,h):
    return (f(x + h)- f(x))/(h)

def calc_bd(f,x,h):
    return (f(x)- f(x - h))/(h)

def calc_cd(f,x,h):
    return (f(x+h) - f(x-h))/(2*h)

f = lambda x: x * np.sin(x)

true_val = 1.
x = np.pi/2

h_vals = [10**-n for n in range(1,5)]

for h in h_vals:

    fd = calc_fd(f,x,h)
    bd = calc_bd(f,x,h)
    cd = calc_cd(f,x,h)

    err_fd = np.abs(fd - true_val)
    err_bd = np.abs(bd - true_val)
    err_cd = np.abs(cd - true_val)

    print(f"h = {h}")
    print(f"fd = {fd}, Error: {err_fd}")

    print(f"bd = {bd}, Error: {err_bd}")
    print(f"cd = {cd}, Error: {err_cd}")