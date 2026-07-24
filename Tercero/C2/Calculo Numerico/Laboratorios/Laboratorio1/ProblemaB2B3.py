from math import pi

k = 1.0
S = 0.0

while True:
    termino = 1.0 / (k * k)
    S_new = S + termino
    if S_new == S:
        break
    S = S_new
    k += 1.0

M = int(k) - 1

S_true = pi**2 / 6.0
print(f"Última iteración sumada M={M}")
print(f"Último término sumado M={1.0 / (M * M):e}")
print(f"Suma S_M={S:.30f}")
print(f"Error absoluto: {abs(S - S_true)}")
print(f"Error Relativo: {abs(S - S_true) / abs(S_true)}")

# B3: ¿Podemos sumar más términos?

U = int(10 * M)
S_backwards = 0.0
for k in range(U, 0, -1):
    S_backwards += 1.0 / float(k) ** 2

print(f"Última iteración sumada U={U}")
print(f"Suma S_backwards={S_backwards}")
print(f"Error Absoluto: {abs(S_backwards - S_true):e}")
print(f"Error Relativo: {abs(S_backwards - S_true) / abs(S_true):e}")
