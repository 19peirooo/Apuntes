## 1) Cual es el nombre del profesor que imaparte mayor n�mero de asignaturas. 
SELECT p.nombre_profesor , COUNT(id_prof_asig) as numAsignaturas
FROM profesores p JOIN asignaturas a ON p.id_profesor = a.id_prof_asig 
GROUP BY a.id_prof_asig
ORDER BY numAsignaturas DESC LIMIT 1 
 
## 2) Indicar el el identificador y el nombre de cada grado y el numero de cursos que tiene cada grado
## odenados de mayor a menor. 
SELECT g.id_grado , g.nombre_grado , COUNT(c.id_grado_curso) as numCursos
FROM grado g LEFT JOIN curso c on g.id_grado = c.id_grado_curso 
GROUP BY g.id_grado 
ORDER BY numCursos DESC

## 3) Selcciona toda la informaci�n de los cursos que pertenecen al grado cuyo c�digo  es "INSO"  
## (asegurate de que en tu BD haya un grado con este c�digo)
SELECT c.*
FROM grado g JOIN curso c ON g.id_grado = c.id_grado_curso 
WHERE g.codigo_grado = 'INSO'

## 4) Cuantas aulas dsitintas hay y cules son dichas aulas en las que se imparten las clases.  



## 5)  Del total de asignaturas selecciona el nombre de aquellas que son "anuales" 
## indicando tambi�n el codigo del curso del curso y el nombre  profesor que las imparte.  
SELECT a.nombre_asig , c.codigo_curso , p.nombre_profesor 
FROM asignaturas a JOIN curso c ON a.id_curso_asig = c.id_curso 
JOIN profesores p ON a.id_prof_asig = p.id_profesor 
WHERE a.temporalidad_asig = 'A'

## 6) Indicar el nombre del alumno que est� matriculado en mayor n�mero de asignauras e indicar dicho n�mero. 
SELECT a.nombre_alumno , COUNT(m.id_asigntaura_mat) AS numAsignaturas
FROM alumnos a LEFT JOIN matriculas m ON a.num_matricula = m.id_estudiante_mat 
GROUP BY a.num_matricula  
ORDER BY numAsignaturas DESC LIMIT 1


## 7) Indicar el nombre de la asignatura en la que hay mayor n�mero de alumnos matriculados e indicar dicho n�mero. 
SELECT a.nombre_asig , COUNT(m.id_estudiante_mat) as numEstudiantes
FROM asignaturas a  RIGHT JOIN matriculas m ON a.id_asig  = m.id_asigntaura_mat  
GROUP BY a.id_asig 
ORDER BY numEstudiantes DESC LIMIT 1

## 8)  Cual es el "nombre" del grado cuyo nombre es el m�s largo (mayori numero de caracterrs). Indica cuantos caracteres.
SELECT nombre_grado , LENGTH(nombre_grado) as longitud
FROM grado g 
ORDER BY longitud DESC LIMIT 1

## 9) Actualmente los profesores de 'Programacion I' y 'Programacion II' son diferentes. 
## Asegurate de tener esas asignaturas en tu BD y que sean impartidas por dos profesores distintos.   
## El profesor de 'Progamacion II' va a dejar de dar clases aunque permanece en la univrsidad. 
## Le sustituir� en dicha asignaura el profesor que imparte 'Programacion I'.  
## Actualiza la BD teniendo en cuenta esa informaci�n. 
UPDATE asignaturas 
SET id_prof_asig = 2
WHERE nombre_asig = 'Programacion II'

## 10)  Actualiza la BD teniendo en cuenta que las clases que se impartian 
## en el aula MD203 pasar�n a impartirse en el aula MD900 
UPDATE grupo 
SET aula_grupo = 'MD900'
WHERE aula_grupo = 'MD203'

## 11) Elimina de la BD las asignturas impartidas por los profesores de 'Toledo' 
## (tendr�s que tener en tu BD al menos un profesor de Toledo que imparta alguna asigntaura)
DELETE a
FROM asignaturas a JOIN profesores p ON p.id_profesor = a.id_prof_asig
WHERE p.ciudad_profesor = 'Toledo'

## 12) Nombre de las asigntaturas en las que está matriculado 
## el alumno 'Miguel Varela'. Sacar el nombre y el id del estudiante
SELECT a.num_matricula , a.nombre_alumno , a2.nombre_asig 
FROM matriculas m JOIN alumnos a ON m.id_estudiante_mat = a.num_matricula 
JOIN asignaturas a2 ON m.id_asigntaura_mat = a2.id_asig 
WHERE a.nombre_alumno = 'Miguel Varela'

## 13) Añadir a la query anterior el nombre del curso al que pertenecen dichas asignaturas
SELECT a.num_matricula , a.nombre_alumno , a2.nombre_asig , c.codigo_curso 
FROM matriculas m JOIN alumnos a ON m.id_estudiante_mat = a.num_matricula 
JOIN asignaturas a2 ON m.id_asigntaura_mat = a2.id_asig
JOIN curso c ON a2.id_curso_asig = c.id_curso 
WHERE a.nombre_alumno = 'Miguel Varela'

## 14) Nombre de los profesores que imparte las asignaturas del Q2. Sacar también el id del profesto, el nombre de la asignatura y la temporalidad. 
SELECT p.id_profesor , p.nombre_profesor ,a.nombre_asig, a.temporalidad_asig  
FROM profesores p JOIN asignaturas a ON p.id_profesor = a.id_prof_asig 
WHERE a.temporalidad_asig = 'Q2'

##15) Nombre de todos los profesores del alumno Belen Gonzalez
SELECT DISTINCT p.nombre_profesor 
FROM alumnos a JOIN matriculas m ON a.num_matricula = m.id_estudiante_mat 
JOIN asignaturas a2 ON a2.id_asig = m.id_asigntaura_mat 
JOIN profesores p ON a2.id_prof_asig = p.id_profesor 
WHERE a.nombre_alumno = 'Belen Gonzalez'




