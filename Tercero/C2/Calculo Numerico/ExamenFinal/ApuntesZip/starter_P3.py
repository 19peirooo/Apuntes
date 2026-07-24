"""
Codigo de partida - Examen Parte II, Problema 3 (Tema 4)
EJEMPLO de grafico log-log de matplotlib con datos FICTICIOS, como referencia
de sintaxis (la sintaxis de matplotlib NO se evalua). Sustituye los datos por
tus propios vectores: h y error absoluto.
"""

import numpy as np
import matplotlib.pyplot as plt

hs = np.array([1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6])   # datos ficticios
err_A = hs**2 + 1e-12 / hs**2                          # curva inventada (forma en "V")
err_B = hs**2 + 1e-16 / hs**2                          # otra curva inventada

plt.figure(figsize=(8, 5))
plt.loglog(hs, err_A, 'o-', label='curva A (ejemplo)')
plt.loglog(hs, err_B, 's-', label='curva B (ejemplo)')
plt.xlabel('h')
plt.ylabel('error absoluto')
plt.title('EJEMPLO log-log (sustituir por tus datos)')
plt.legend()
plt.grid(True, which='both', ls=':')
plt.savefig('ejemplo_loglog.png', dpi=120, bbox_inches='tight')
# plt.show()
