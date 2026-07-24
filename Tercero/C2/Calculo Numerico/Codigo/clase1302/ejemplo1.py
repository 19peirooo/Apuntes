import numpy as np
import sympy as sp

def f(x):
    return (1 - np.cos(x))/x**2

x_vals = [10**(-n) for n in range(1, 11)]

def main():
    for x in x_vals:
        print(f"{x} --> {f(x)}")


if __name__ == "__main__":
    main()
