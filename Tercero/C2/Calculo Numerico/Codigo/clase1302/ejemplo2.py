from math import sqrt
import sympy as sp

fcc = lambda x: 1/ (sqrt(x**2 + 1) - x)
f = lambda x: sqrt(x**2 + 1) + x

x_vals = [10**(n) for n in range(3, 8)]

def main():
    for x in x_vals:
        print(f"f({x}) --> {fcc(x)}")
        print(f"Error Relativo: {abs(fcc(x) - f(x))}")
        print(f"Error Absoluto: {abs(fcc(x)- f(x) / f(x))}")


if __name__ == "__main__":
    main()
