from vpython import *
import random

# Constantes
k = 9e9  # Constante de Coulomb (N·m²/C²)
q = -1.602e-19   # Carga de las partículas (Coulombs)
m = 1.673e-27    # Masa de las partículas (kg)
dt = 0.01  # Paso de tiempo (s)
L = 5     # Longitud de la caja (m)
max_speed = 3  # Velocidad máxima para mantener estabilidad

# Crear la caja (paredes visibles)
caja = box(pos = vector(0,0,0), size= vector(L,L,L),opacity = 0.1, color = color.white)

# Crear partículas con posiciones y velocidades aleatorias
particles = []
radius = 0.1  # Radio de las partículas
min_dist = 2 * radius  # Distancia mínima para evitar fuerzas infinitas
for _ in range(5):  # Aumentar el número de partículas si se desea
    pos = vector(random.uniform(-L/2 + radius, L/2 - radius),
                 random.uniform(-L/2 + radius, L/2 - radius),
                 random.uniform(-L/2 + radius, L/2 - radius))
    vel = vector(random.uniform(-1, 1), random.uniform(-1, 1), random.uniform(-1, 1))
    particle = sphere(radius=radius, color=color.red, make_trail=True)
    particle.pos = pos
    particle.velocity = vel
    particles.append(particle)

# Función para limitar la magnitud de un vector
def limit_vector(v, max_magnitude):
    if mag(v) > max_magnitude:
        return norm(v) * max_magnitude
    return v

# Función para calcular la fuerza de repulsión
def calculate_force(p1, p2):
    r_vec = p2.pos - p1.pos  # Vector de distancia
    r_mag = mag(r_vec)       # Magnitud de la distancia
    if r_mag < min_dist:     # Limitar la distancia mínima para evitar fuerzas infinitas
        r_mag = min_dist
    force_mag = k * (q * q) / (r_mag ** 2) * -1  # Magnitud de la fuerza (repulsión)
    force_dir = norm(r_vec)  # Dirección de la fuerza
    return force_mag * force_dir

# Simulación
while True:
    rate(100)
    for p in particles:
        # Calcular la fuerza neta sobre cada partícula
        net_force = vector(0, 0, 0)
        for other in particles:
            if p != other:
                net_force += calculate_force(p, other)

        # Actualizar velocidad y posición
        acceleration = net_force / m
        p.velocity += acceleration * dt
        p.velocity = limit_vector(p.velocity, max_speed)  # Limitar velocidad máxima
        p.pos += p.velocity * dt

        # Verificar colisiones con las paredes (choque elástico)
        if abs(p.pos.x) >= L/2 - radius:
            p.velocity.x *= -1  # Revertir velocidad en x
            p.pos.x = (L/2 - radius) * (-1 if p.pos.x < 0 else 1)  # Corregir posición

        if abs(p.pos.y) >= L/2 - radius:
            p.velocity.y *= -1  # Revertir velocidad en y
            p.pos.y = (L/2 - radius) * (-1 if p.pos.y < 0 else 1)  # Corregir posición

        if abs(p.pos.z) >= L/2 - radius:
            p.velocity.z *= -1  # Revertir velocidad en z
            p.pos.z = (L/2 - radius) * (-1 if p.pos.z < 0 else 1)  # Corregir posición

        # Evitar velocidades infinitas tras una colisión
        p.velocity = limit_vector(p.velocity, max_speed)
