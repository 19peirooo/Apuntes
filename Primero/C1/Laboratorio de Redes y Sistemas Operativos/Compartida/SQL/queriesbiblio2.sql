## Queries para biblioteca

## Si estuvieramos desde el cliente de  MariaDB (mysql) ejecutar.
## show databases;
## use  biblioteca;
## show tables;

## En DBeaver, establcer conexión con BD y ejecutar script

## 1) Cuales son las distintas salas en las que hay estantenias  dentro de la biblioteca
SELECT COUNT(DISTINCT sala) as numSalas
FROM estanteria e 

## 2) En que planta se encuentra cada sala
SELECT sala , planta 
FROM estanteria e 
GROUP BY sala 

## 3) Cuantas estanterías hay 
SELECT COUNT(cod_estanteria)
FROM estanteria e 
WHERE sala IS NOT NULL

#3.1) Cuantas estanterías hay en cada planta. Indicar la planta
SELECT planta , COUNT(cod_estanteria) AS numEstanterias 
FROM estanteria e 
WHERE planta IS NOT NULL
GROUP BY planta

## 4) Cuales son esas estanterías y en que planta y sala está ubicada cada una


## 5) Obtener las estanterías que aún no están ubicadas en la bibilioteca
SELECT cod_estanteria 
FROM estanteria e 
WHERE planta IS NULL

## 6) Cuantos ejemplares hay en cada estantería
SELECT e.cod_estanteria , count(e2.cod_estanteria_ej) as numEjemplares
FROM estanteria e LEFT JOIN ejemplar e2 on e.cod_estanteria = e2.cod_estanteria_ej 
GROUP BY e.cod_estanteria 

## 7) Obtener el num_matricula de los alumno y obtener cuantos ejemplares tiene o ha tenido prestados cada uno, ordernados de mayor a menor
SELECT num_matricula_prestamo , COUNT(cod_ejemplar_prestamo) 
FROM prestamo p  
GROUP BY num_matricula_prestamo 

## 7.1) Obtener además el nombre del alumno
SELECT p.num_matricula_prestamo ,a.nombre , COUNT(p.cod_ejemplar_prestamo) 
FROM prestamo p JOIN alumno a ON p.num_matricula_prestamo = a.num_matricula 
GROUP BY num_matricula_prestamo 

## 8)  Listar los cod del ejemplares que están actualmente prestados. Indicar el nombre y curso del alumno que lo tiene prestado 
SELECT p.cod_ejemplar_prestamo , a.nombre , a.curso 
FROM prestamo p JOIN alumno a on a.num_matricula = p.num_matricula_prestamo  
WHERE fecha_devolucion IS NULL

## 9) Nombre, curso y numero de ejemplares que tiene prestado cada alumno
SELECT a.nombre , a.curso , COUNT(p.num_matricula_prestamo) as numPrestamos
FROM alumno a LEFT JOIN prestamo p ON a.num_matricula = p.num_matricula_prestamo
WHERE p.fecha_devolucion IS NULL 
GROUP BY p.num_matricula_prestamo

## 10) Lista de ejemplares que nunca han sido prestados
SELECT e.cod_ejemplar
FROM prestamo p RIGHT JOIN ejemplar e ON p.cod_ejemplar_prestamo = e.cod_ejemplar 
WHERE p.fecha_prestamo IS NULL



