## 1) Cual es la media de edad de los participantes que hay apuntados a los talleres de 'Pintura'
SELECT AVG(p.Edad) as EdadMedia
FROM participante p JOIN inscripciones i ON p.ParticipanteID = i.ParticipanteID_I
JOIN taller t ON i.TallerID_I = t.TallerID 
WHERE t.Tema = 'Pintura';

## 2) Indica el nombre de la especialidad de la que hay más instructores
SELECT Especialidad, COUNT(InstructorID) as numInstructores
FROM instructor i 
GROUP BY Especialidad
ORDER BY numInstructores DESC LIMIT 1;

## 3) Indica el país del que hay más instructores indicando además cuantos son. 
SELECT Pais , COUNT(InstructorID) as numInstructores 
FROM instructor i
GROUP BY Pais 
ORDER BY numInstructores DESC LIMIT 1;

## 4) Muestra el número de participantes que se han insrito en cada unos de los talleres indicando además el id del taller, el nombre y el máximo de particpantes permitidos.
SELECT t.TallerID , t.Nombre , t.MaxParticipantes , COUNT(i.ParticipanteID_I) as numParticipantes
FROM taller t LEFT JOIN inscripciones i ON t.TallerID = i.TallerID_I 
GROUP BY t.TallerID;

## 5) Actualiza la BD teniendo en cuenta que el Instructor cuyo DNI es 54321098V ahora tendrá la misma Especialidad que el insrtuctor cuyo DNI es 65432109W
UPDATE instructor 
SET Especialidad = (SELECT Especialidad FROM instructor WHERE DNI = '65432109W')
WHERE DNI = '54321098V';

## 6) Indica los DNIS y los nombres de los instructores que no han entregado el CV
SELECT DNI 
FROM  instructor i 
WHERE CV IS NULL;

## 7) Cual es el nombre y la fecha de inicio del taller en el que hay más particpantes inscritos. Indica cuantos son.
SELECT t.Nombre , t.FechaInicio , COUNT(i.ParticipanteID_I) as numParticipantes
FROM taller t LEFT JOIN inscripciones i ON t.TallerID = i.TallerID_I 
GROUP BY t.TallerID
ORDER BY numParticipantes DESC LIMIT 1;

## 8)  Utilizando una sola query añade a la BD dos nuevos "espacios" y asignales los edificios que tu quieras. La capacidad del primero debe ser 25 y la del segundo 15. 
INSERT INTO espacio(Edificio,Capacidad)
VALUES ('Ed.Azul',25),('Ed.Rojo',15);

## 9) Se pide el nombre del taller en el que se inscribió el primer participante. Indica también el nombre y apellidos de dicho participante 
SELECT  t.Nombre , p.Nombre , p.Apellido 
FROM inscripciones i JOIN taller t ON i.TallerID_I = t.TallerID 
JOIN participante p ON p.ParticipanteID = i.ParticipanteID_I
WHERE i.FechaInscripcion = 
	(SELECT MIN(i2.FechaInscripcion)
	FROM inscripciones i2); 

## 10) Cuales son los identificadores y los nombres de los talleres en los que no hay inscrito nigún participante 
SELECT t.TallerID , t.Nombre
FROM taller t LEFT JOIN inscripciones i ON t.TallerID = i.TallerID_I 
WHERE i.TallerID_I IS NULL;
