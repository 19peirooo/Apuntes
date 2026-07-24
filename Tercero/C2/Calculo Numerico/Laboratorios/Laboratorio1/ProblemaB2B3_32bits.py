from math import pi
import numpy as np

f32 = np.float32

k = f32(1.0)
S = f32(0.0)

while True:
    termino = f32(1.0) / (k * k)
    S_new = S + termino
    if S_new == S:
        break
    S = S_new
    k += f32(1.0)

M = int(k) - 1

S_true = f32(pi) ** 2 / f32(6.0)
print(f"Última iteración sumada M={M}")
print(f"Último término sumado M={1.0 / (M * M):e}")
print(f"Suma S_M={S}")
print(f"Error absoluto: {abs(S - S_true)}")
print(f"Error Relativo: {abs(S - S_true) / abs(S_true)}")

# B3: ¿Podemos sumar más términos?

U = int(1.0e4 * M)
S_backwards = f32(0.0)
for k in range(U, 0, -1):
    S_backwards += f32(1.0) / f32(k) ** 2

print(f"Última iteración sumada U={U}")
print(f"Suma S_backwards={S_backwards}")
print(f"Error Absoluto: {abs(S_backwards - S_true):e}")
print(f"Error Relativo: {abs(S_backwards - S_true) / abs(S_true):e}")
