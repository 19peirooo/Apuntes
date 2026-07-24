import numpy as np

def simpson38(f, a, b, N):          # N múltiplo de 3
    assert N % 3 == 0, "N debe ser multiplo de 3"
    x = np.linspace(a, b, N + 1)
    y = f(x)
    h = (b - a) / N
    w = np.ones(N + 1)
    w[1:-1:3] = 3
    w[2:-1:3] = 3
    w[3:-1:3] = 2
    return (3 * h / 8) * np.dot(w, y)
