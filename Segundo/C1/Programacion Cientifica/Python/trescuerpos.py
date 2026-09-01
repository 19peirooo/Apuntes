# Introduccion a la programacion cientifica            
# Grado en Fisica Computacional. Centro Universitario U-tad
# Autor: Javier Garcia Algarra
# Agosto de 2023

# Problema de los tres cuerpos con tres planetas ficticios

from vpython import *
import numpy as np

simularorbita = "ocho" # ("caos","ocho","euler")
# Magnitudes astronómicas
if simularorbita == "caos":
    Masa=np.array([0.05,1.2,0.03])*1e22
    Radio=np.array([0.8,1.188,0.5])*1e6
    posicion=np.array([vector(19,0,0),vector(0,0,0),vector(-5,15,0)])*1e6
    V0=np.array([vector(0,100,0),vector(0,0,0),vector(100,12,0)])
    G=6.7e-11
    dt=600

if simularorbita == "euler":
    vp = 40
    pp = 20
    Masa=np.array([0.05,0.1,0.05])*1e22
    Radio=np.array([0.8,1.2,0.8])*1e6
    posicion=np.array([vector(-pp,0,0),vector(0,0,0),vector(pp,0,0)])*1e6
    V0=np.array([vector(0,vp,0),vector(0,0,0),vector(0,-vp,0)])
    G=6.7e-11
    dt=1000

# Orbita en forma de 8. Datos iniciales tomados de "Some Observations on the Fig-8 Solution
#  Off the 3-Body Problem", F.Janssens, Feb 2004
if simularorbita == "ocho":
    Masa=np.array([1/3,1/3,1/3])
    Radio=np.array([0.05,0.05,0.05])
    posicion=np.array([vector( 0.746156, 0,0),vector(-0.373078, 0.238313,0),vector(-0.373078, -0.238313,0)])
    V0=np.array([vector(0,0.324677,0),vector(0.764226 , -0.162339,0),vector(-0.764226 , -0.162339,0)])
    G=1
    dt=0.005


numplanetas = 3
planetas=list()
colors=[color.yellow,color.red,color.green]
for i in range(numplanetas):
    pl=sphere(pos=posicion[i], radius=Radio[i], color = colors[i], make_trail=True, trail_type='points', interval=40, retain=10)
    pl.m = Masa[i]
    pl.v = V0[i]
    pl.p = pl.v*pl.m
    planetas.append(pl)


g1 = graph(title="Energía cinética",xtitle="t [s]",ytitle="[kg*m/s^2]",width=400, height=200)
EC_0 = gcurve(color=color.yellow)
EC_1 = gcurve(color=color.red)
EC_2 = gcurve(color=color.green)

def FGr(pA,pB,rAB):
    return -G*pA.m*pB.m*rAB.hat/mag(rAB)**2

t = 0
while True:
    rate(50)
    # radiovectores
    r01 = planetas[1].pos-planetas[0].pos
    r02 = planetas[2].pos-planetas[0].pos
    r12 = planetas[2].pos-planetas[1].pos
    
    #Fuerzas gravitatorias entre los tres cuerpos
    F01 = FGr(planetas[0],planetas[1],r01)
    F02 = FGr(planetas[0],planetas[2],r02)
    F12 = FGr(planetas[1],planetas[2],r12)
    
    #Tercera ley de Newton
    Fs = np.array([[vector(0,0,0),F01,F02],
                  [-F01,vector(0,0,0),F12],
                  [-F02,-F12,vector(0,0,0)]])
    t=t+dt
    for m in range(numplanetas):
        Fres = vector(0,0,0)
        for n in range(numplanetas):
            Fres = Fres + Fs[n][m]
        planetas[m].p = planetas[m].p + Fres * dt
        planetas[m].pos = planetas[m].pos + planetas[m].p * dt/planetas[m].m
    EC_0.plot(t,mag(planetas[0].p)**2/2*planetas[0].m)
    EC_1.plot(t,mag(planetas[1].p)**2/2*planetas[1].m)
    EC_2.plot(t,mag(planetas[2].p)**2/2*planetas[2].m)
