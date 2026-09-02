import numpy as np

A = np.array([[-6, -3], [0, -3]], dtype=int)
B = np.array([[-1, 0], [4, -2]], dtype=int)
I = np.diag([1,1])
print("Matriz A:\n", A, "\n")
print("Matriz B: \n", B, "\n")
# Sistema AX + 3B = -5X
# AX + 5X = -3B
# (A+5I)X = -3B
# X = (A+5I)^-1·-3B

inversa = np.linalg.inv(A + (5*I))  # Inversa de A+5
print("A+5I:\n", A + (5*I), "\n")
print("Inversa de A+5I:\n", inversa, "\n")

comprobacion = (inversa.dot(A+(5*I)))  # Comprueba si es la inversa. Si es, el resultado es la identidad print(comprobacion)
print("Comprobacion Inversa: \n",comprobacion,"\n")

print("-3B:\n", -3*B, "\n")

X=(inversa.dot(-3*B))
print("X=(A+5I)^-1·-3B")
print("X=\n",X,"\n")