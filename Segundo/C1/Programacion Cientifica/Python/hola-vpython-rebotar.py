from vpython import *

# Lienzo sobre el que vamos a dibujar
ancho=500
alto=300
scene = canvas(title="Ejemplo VPython, tiro parabólico", width=ancho, height=alto, background=color.yellow)

# Parameters
pelota_radio = 0.1       # m
inicial_altura = -alto    # m
inicial_velocidad_y = 100  # m/s 
inicial_velocidad_x = 20  # m/s
g = -9.81                # m/s^2

# Objeto pelota
pelota = sphere(pos=vector(-2*ancho, inicial_altura, 0),
                radius=pelota_radio, color=color.red, make_trail=True)

# Velocidad inicial
pelota.velocidad = vector(inicial_velocidad_x, inicial_velocidad_y, 0)

# Plano que simula el suelo
hsuelo = -alto + pelota_radio
ground = box(pos=vector(-ancho, hsuelo, 0), size=vector(4*ancho, 0.1, 10), color=color.green)
#label( pos=vec(0.15,10,0), text='Hello!', height=16, border=0)

# Paso de simulación 
dt = 0.05

Tocaelsuelo = False

# Bucle de simulación
while (True):
    rate(50)            # fotogramas por segundo
    
    # Actualizamos la posición
    pelota.pos += pelota.velocidad * dt
    # Actualizamos la velocidad
    pelota.velocidad.y += g * dt
    # Comprobar si ha llegado al suelo
    if pelota.pos.y < hsuelo+pelota_radio:
        pelota.velocidad.y = -pelota.velocidad.y
