from math import sqrt
# Ocurre cancelación catastrófica al calcular x1
# cuando b > 0 y b^2 >> 4ac


def roots(a, b, c):
    sd = sqrt(b**2 - 4 * a * c)
    x1 = (-b + sd) / 2 * a
    x2 = (-b - sd) / 2 * a
    return x1, x2


# a, b, c = 1, 9**12, -3
a, b, c = 1, 10**8, 1

x1_cc, x2 = roots(a, b, c)
print(f"x+ = {x1_cc:g} (CC)")
print(f"x- = {x2:g}")

x1 = c / (x2 * a)
print(f"x+ = {x1:g}")


print(f"Error absoluto: {abs(x1_cc - x1)}")
print(f"Error relativo: {abs(x1_cc - x1) / abs(x1)}")
