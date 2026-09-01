from vpython import *

scene = canvas (title = "Movimiento Circular", width = 300, height = 300)

radius = 5
masa = 0.25
longitud_cuerda = radius
velocidad_angular = 2
centro = vector(0,0,0)

pelota = sphere(pos = vector(radius, 0, 0), radius = 0.5, color = color.red, make_trail = True)

string = cylinder(pos = centro, axis= pelota.pos - centro, radius = 0.05, color = color.white)

dt = 0.01
tiempo = 0
angulo = 0

while True:
    rate(50)

    tiempo += dt
    angulo = velocidad_angular * tiempo

    pelota.pos = vector(radius * cos(angulo), radius * sin(angulo), 0)

    string.axis = pelota.pos - centro
