
#Parametros a y b, tendremos que cambiar su valor manualmente
a <- 1 
b <- 2

M <- rbind(c(a,1,b),c(1,a,2),c(1,a,b)) #Matriz de coeficientes
N <- c(0,b-2,a-1) #Terminos Independientes
MN <- cbind(M,N) #Ampliada


library(matlib)
showEqn(M,N)

#Compruebo los rangos de ambas matrices
R(M)
R(MN)

echelon(M,N)
#Compruebo rangos iguales

if (R(M) == R(MN)){
  if(R(M) == 3){
    print("Sistema Compatible Determinado, 1 unica solucion para x,y,z")
    print("Los 3 planos coinciden en un punto")
    Solve(M,N, fractions = TRUE)
  } else if (R(M) == 2){
    print("Sistema Compatible Indeterminado de orden 1, Infinitas soluciones dependientes de 1 parametro")
    print("Planos forman un haz de planos")
    Solve(M,N, fractions = TRUE)
  } else {
    print("Sistema Compatible Indeterminado de orden 2, Infinitas soluciones dependientes de 2 parametros")
    print("Los 3 planos son coincidentes")
    Solve(M,N, fractions = TRUE)
  }
} else {
  print("Sistema Incompatible, no existen soluciones para x,y,z")
  if (a == 3 && b == 2){
    print("2 planos son paralelos y uno los corta")
  }
}

#Representacion grafica
plotEqn3d(M,N,xlim=c(-10,10), ylim=c(-10,10), zlim=c(-10,10))


