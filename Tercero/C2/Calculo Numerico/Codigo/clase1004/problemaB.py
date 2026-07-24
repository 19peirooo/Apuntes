import numpy as np
import matplotlib.pyplot as plt

def calc_fd(f,x,h):
    return (f(x + h)- f(x))/(h)

def calc_bd(f,x,h):
    return (f(x)- f(x - h))/(h)

def calc_cd(f,x,h):
    return (f(x+h) - f(x-h))/(2*h)

f = lambda x: np.exp(np.sin(2*x))
df = lambda x: 2*np.cos(2*x)*np.exp(np.sin(2*x))

x = 0.5
true_val = df(x)

h_vals = [10**-n for n in range(1,16)]
errs_fd = []
errs_bd = []
errs_cd = []

for h in h_vals:

    fd = calc_fd(f,x,h)
    bd = calc_bd(f,x,h)
    cd = calc_cd(f,x,h)

    err_fd = np.abs(fd - true_val)
    err_bd = np.abs(bd - true_val)
    err_cd = np.abs(cd - true_val)

    errs_fd.append(err_fd)
    errs_bd.append(err_bd)
    errs_cd.append(err_cd)

    print(f"h = {h}")
    print(f"fd = {fd}, Error: {err_fd}")

    print(f"bd = {bd}, Error: {err_bd}")
    print(f"cd = {cd}, Error: {err_cd}")

plt.figure()

plt.loglog(h_vals, errs_fd, 'o-', label='Forward (FD)')
# plt.loglog(h_vals, errs_bd, 's-', label='Backward (BD)')
plt.loglog(h_vals, errs_cd, '^-', label='Centered (CD)')

plt.xlabel('h')
plt.ylabel('Error absoluto')
plt.title('Error vs h (escala log-log)')
plt.legend()
plt.grid(True, which="both")

plt.gca().invert_xaxis()

plt.show()