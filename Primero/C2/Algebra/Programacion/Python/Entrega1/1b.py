import numpy as np

A = np.array([[1, 2], [0, 2]], dtype= float)
B = np.array([[2, -1], [-1, 5]], dtype= float)
C = np.array([[2, 6], [-1, -0.5]], dtype= float)
I = np.diag([1,1])

print("Matriz A:\n", A, "\n")
print("Matriz B: \n", B, "\n")
print("Matriz C:\n", C, "\n")
print("Matriz Identidad: \n", I, "\n")

#ACX + 3B = 10I - X
#ACX + X = 10I - 3B
#(AC + I)X = 10I - 3B
#X = (AC+I)^-1·(10I-3B)

AC = A.dot(C)
inversa = np.linalg.inv(AC+I)
print("Matriz AC:\n", AC, "\n")
print("Matriz AC+I:\n", AC+I, "\n")
print("Inversa de AC+I:\n", inversa, "\n")

comprobacion = (inversa.dot(AC+I))  # Comprueba si es la inversa. Si es, el resultado es la identidad print(comprobacion)
print("Comprobacion Inversa: \n",comprobacion,"\n")

X = inversa.dot((10*I)-(3*B))
print("X=(AC+I)^-1·(10I-3B)")
print("X=\n",X,"\n")