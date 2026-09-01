from vpython import *

ancho = 1000
alto = 300
scene = canvas(title="Tiro Parabolico", width = ancho, height=alto, background=color.yellow)

pelota_radio = 10
inicio_altura = -alto+50
inicio_velocidad_y = 200
inicio_velocidad_x = 75
g = -9.81

pelota =sphere(pos = vector(-ancho, inicio_altura, 0), radius = pelota_radio, color=color.red, make_trail= True)
pelota.velocidad = vector(inicio_velocidad_x, inicio_velocidad_y, 0)

suelo = -alto + pelota_radio
ground = box(pos = vector(-ancho, suelo,0), size = vector(2*ancho,0.1,10), color = color.green)

dt = 0.05
alpha = 0.8

Tocasuelos  = False

while True:
    rate(50)

    pelota.pos += pelota.velocidad * dt
    pelota.velocidad.y += g*dt

    if pelota.pos.y < suelo:
        pelota.velocidad.y = -alpha * pelota.velocidad.y
