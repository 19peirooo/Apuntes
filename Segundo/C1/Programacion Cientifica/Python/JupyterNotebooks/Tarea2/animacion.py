# Archivo: animaciones.py
# Basado en https://matplotlib.org/examples/animation/simple_anim.html
# Autor: Javier Garcia Algarra 
# Fecha: 28 de diciembre de 2017
# Descripción: Ejemplo de animacion

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Parámetros iniciales
alpha = 0.1  # Difusividad térmica ajustada para estabilidad
longitud = 3
num_puntos = 1000
num_steps = 10000  # Pasos para la simulación de difusión
dx = longitud / (num_puntos - 1)
dt = 0.8 * dx**2 / alpha  # Condición CFL para estabilidad
T_0 = 300  # Temperatura base en Kelvin

# Dominio espacial
x = np.linspace(0, longitud, num_puntos)

# Posiciones y temperaturas de las fuentes de calor/frío
pos_soplete = 1
temp_soplete = 800

pos_chorro = 2
temp_chorro = 273

# Función para generar pulsos gaussianos
def pulso_gaussiano(x, pos, sigma_cuadrado, T_max):
    return T_max * np.exp(-(x - pos)**2 / (2 * sigma_cuadrado))

# Pulsos gaussianos iniciales
varianza_gaussiana = 0.05
T1 = pulso_gaussiano(x, pos_soplete, varianza_gaussiana, temp_soplete - T_0)
T2 = pulso_gaussiano(x, pos_chorro, varianza_gaussiana, temp_chorro - T_0)

# Configuración inicial
T = T_0 + T1 + T2

# Gráfico de los pulsos gaussianos iniciales
plt.title("Pulsos Gaussianos Iniciales")
plt.plot(x, T1 + T_0, label="Pulso Soplete")
plt.plot(x, T2 + T_0, label="Pulso Chorro")
plt.xlabel("Posición (m)")
plt.ylabel("Temperatura (K)")
plt.legend()
plt.show()

# Simulación de la evolución de la temperatura
def evolucion_difusion(T, num_steps, alpha, dx, dt):
    T_new = np.copy(T)
    for _ in range(num_steps):
        T_new[1:-1] = T_new[1:-1] + alpha * dt / dx**2 * (T_new[2:] - 2 * T_new[1:-1] + T_new[:-2])
        T_new[0], T_new[-1] = T_0, T_0  # Condiciones de frontera
    return T_new

# Calcular el estado final después de la difusión
T_final = evolucion_difusion(T, num_steps, alpha, dx, dt)

# Gráfico de comparación inicial y final
plt.plot(x, T, label="T(x,0)")
plt.plot(x, T_final, label="T(x, final)")
plt.title("Distribución de Calor en la Barra para un T0 = {:d}K".format(T_0))
plt.xlabel("Posición (m)")
plt.ylabel("Temperatura (K)")
plt.legend()
plt.show()

# Configuración de la animación
fig, ax = plt.subplots()
line, = ax.plot(x, T, label="Evolución de T(x,t)")
ax.set_xlim(0, longitud)
ax.set_ylim(T_0 - 100, temp_soplete + 100)
ax.set_xlabel("Posición (m)")
ax.set_ylabel("Temperatura (K)")
ax.set_title("Evolución de la Distribución de Temperatura")

# Función de inicialización para la animación
def init():
    line.set_ydata(T)
    return line,

# Función de actualización para la animación
def actualizar(frame):
    global T
    T[1:-1] = T[1:-1] + alpha * dt / dx**2 * (T[2:] - 2 * T[1:-1] + T[:-2])
    T[0], T[-1] = T_0, T_0  # Condiciones de frontera
    line.set_ydata(T)
    return line,

# Creación de la animación
num_frames = 500
ani = animation.FuncAnimation(fig, actualizar, frames=num_frames, init_func=init, interval=30, blit=True)

plt.legend()
plt.show()

