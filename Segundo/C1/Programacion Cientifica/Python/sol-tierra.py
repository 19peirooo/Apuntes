from vpython import *

#constantes
R=15e9
orbitatierra=150e9
Ms=2e30
Me=6e24
G=6.67e-11
v0tierra=-30e3

#Sol
sol=sphere(pos=vector(0,0,0), radius=R, color=color.yellow)
sol.m=Ms

#Tierra
v0tierra=vector(v0tierra,0,0)
tierra=sphere(pos=vector(0,orbitatierra,0), radius=0.33*R, color=color.white)
tierra.m=Me
tierra.p=v0tierra*tierra.m


#El momento total del sistema debe ser nulo
sol.p=-tierra.p

attach_trail(tierra)

t=0
dt= 12*3600    #12 horas
 
while True:
    rate(100)

    #vector sol-tierra
    rse=tierra.pos-sol.pos
    
    #Fse fuerza del sol sobre la Tierra
    Fse=-G*sol.m*tierra.m*rse/mag(rse)**3
    
    #Tercera ley de Newton
    Fes=-Fse
    
    #Segunda ley F = dp/dt, resolvemos por Euler
    # p(t+1) = p(t) + F * dt
    tierra.p = tierra.p + Fse*dt
    sol.p = sol.p + Fes*dt

    # posiciones, resolvemos la EDO p = mdr/dt 
    # dr/dt = p/m -> r(t+1) = r(t) + p/m dt
    sol.pos=sol.pos+sol.p*dt/sol.m
    tierra.pos=tierra.pos+tierra.p*dt/tierra.m

