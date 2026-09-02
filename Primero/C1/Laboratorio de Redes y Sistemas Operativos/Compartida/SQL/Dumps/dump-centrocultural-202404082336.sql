-- MariaDB dump 10.17  Distrib 10.4.11-MariaDB, for Win64 (AMD64)
--
-- Host: localhost    Database: centrocultural
-- ------------------------------------------------------
-- Server version	10.4.11-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `espacio`
--

DROP TABLE IF EXISTS `espacio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `espacio` (
  `CodEspacio` int(11) NOT NULL AUTO_INCREMENT,
  `Edificio` varchar(255) NOT NULL,
  `Capacidad` int(11) NOT NULL,
  PRIMARY KEY (`CodEspacio`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `espacio`
--

LOCK TABLES `espacio` WRITE;
/*!40000 ALTER TABLE `espacio` DISABLE KEYS */;
INSERT INTO `espacio` VALUES (1,'Ed. Verde',20),(2,'Ed. Azul',100),(3,'Ed. Blanco',20),(4,'Ed. Rojo',50),(5,'Ed. Amarillo',10),(6,'Ed. Morado',50),(7,'Ed. Gris',30);
/*!40000 ALTER TABLE `espacio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `inscripciones`
--

DROP TABLE IF EXISTS `inscripciones`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `inscripciones` (
  `TallerID_I` int(11) NOT NULL,
  `ParticipanteID_I` int(11) NOT NULL,
  `FechaInscripcion` date DEFAULT NULL,
  PRIMARY KEY (`TallerID_I`,`ParticipanteID_I`),
  KEY `ParticipanteID_I` (`ParticipanteID_I`),
  CONSTRAINT `inscripciones_ibfk_1` FOREIGN KEY (`TallerID_I`) REFERENCES `taller` (`TallerID`),
  CONSTRAINT `inscripciones_ibfk_2` FOREIGN KEY (`ParticipanteID_I`) REFERENCES `participante` (`ParticipanteID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `inscripciones`
--

LOCK TABLES `inscripciones` WRITE;
/*!40000 ALTER TABLE `inscripciones` DISABLE KEYS */;
INSERT INTO `inscripciones` VALUES (19,1,'2024-02-25'),(19,2,'2024-02-19'),(19,4,'2024-01-01'),(19,6,'2024-01-15'),(20,3,'2024-01-31'),(20,4,'2024-04-01'),(21,5,'2024-01-15'),(21,6,'2024-01-29'),(23,2,'2023-12-02'),(24,6,'2023-12-15'),(25,4,'2023-12-17');
/*!40000 ALTER TABLE `inscripciones` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `instructor`
--

DROP TABLE IF EXISTS `instructor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `instructor` (
  `InstructorID` int(11) NOT NULL AUTO_INCREMENT,
  `DNI` varchar(50) NOT NULL,
  `Especialidad` varchar(255) NOT NULL,
  `Ciudad` varchar(255) NOT NULL,
  `Pais` varchar(255) NOT NULL,
  `CV` text DEFAULT NULL,
  PRIMARY KEY (`InstructorID`),
  UNIQUE KEY `DNI` (`DNI`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `instructor`
--

LOCK TABLES `instructor` WRITE;
/*!40000 ALTER TABLE `instructor` DISABLE KEYS */;
INSERT INTO `instructor` VALUES (1,'98765432Z','Fotografía','Madrid','España','/cv/photography_z.pdf'),(2,'87654321Y','Pintura','Barcelona','España','/cv/painting_y.pdf'),(3,'76543210X','Writing','Paris','Francia','/cv/writing_x.pdf'),(4,'65432109W','Music','Berlín','Alemania','/cv/music_w.pdf'),(5,'54321098V','Dance','Hamburgo','Alemania','/cv/dance_v.pdf'),(6,'43210987U','Cocina','Zaragoza','España','/cv/cooking_u.pdf'),(7,'43210117B','Fotografía','Barcelona','España','/cv/photo_b.pdf'),(8,'55210117A','Fotografía','Barcelona','España',NULL),(9,'77210117C','Pintura','Madrid','España',NULL);
/*!40000 ALTER TABLE `instructor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `participante`
--

DROP TABLE IF EXISTS `participante`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `participante` (
  `ParticipanteID` int(11) NOT NULL AUTO_INCREMENT,
  `DNI` varchar(50) NOT NULL,
  `Nombre` varchar(255) NOT NULL,
  `Apellido` varchar(255) NOT NULL,
  `Edad` int(11) DEFAULT NULL,
  `Telefono` varchar(50) DEFAULT NULL,
  `Email` varchar(255) NOT NULL,
  PRIMARY KEY (`ParticipanteID`),
  UNIQUE KEY `DNI` (`DNI`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `participante`
--

LOCK TABLES `participante` WRITE;
/*!40000 ALTER TABLE `participante` DISABLE KEYS */;
INSERT INTO `participante` VALUES (1,'12345678A','Alicia','Smith',20,'600111222','alicia.smith@example.com'),(2,'23456789B','Julio','López',22,'601222333','julio.lopez@example.com'),(3,'34567890C','Carlos','Brown',23,'602333444','carlos.brown@example.com'),(4,'45678901D','Diana','Pérez',21,'603444555','diana.perez@example.com'),(5,'56789012E','Izhan','Hunt',24,'604555666','izhan.hunt@example.com'),(6,'67890123F','Fiona','Gallagher',25,'605666777','fiona.gallagher@example.com');
/*!40000 ALTER TABLE `participante` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `reservasesp`
--

DROP TABLE IF EXISTS `reservasesp`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `reservasesp` (
  `CodEspacio_R` int(11) NOT NULL,
  `TallerID_R` int(11) NOT NULL,
  `FechaHoraReserva` datetime NOT NULL,
  PRIMARY KEY (`CodEspacio_R`,`TallerID_R`,`FechaHoraReserva`),
  UNIQUE KEY `reservasesp_un` (`CodEspacio_R`,`FechaHoraReserva`),
  KEY `TallerID_R` (`TallerID_R`),
  CONSTRAINT `reservasesp_ibfk_1` FOREIGN KEY (`CodEspacio_R`) REFERENCES `espacio` (`CodEspacio`),
  CONSTRAINT `reservasesp_ibfk_2` FOREIGN KEY (`TallerID_R`) REFERENCES `taller` (`TallerID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `reservasesp`
--

LOCK TABLES `reservasesp` WRITE;
/*!40000 ALTER TABLE `reservasesp` DISABLE KEYS */;
INSERT INTO `reservasesp` VALUES (1,19,'2024-07-01 09:00:00'),(1,24,'2024-07-06 09:00:00'),(2,20,'2024-07-02 10:00:00'),(3,21,'2024-07-03 13:00:00'),(4,22,'2024-07-04 14:00:00'),(5,23,'2024-07-05 15:00:00');
/*!40000 ALTER TABLE `reservasesp` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `taller`
--

DROP TABLE IF EXISTS `taller`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `taller` (
  `TallerID` int(11) NOT NULL AUTO_INCREMENT,
  `Nombre` varchar(255) NOT NULL,
  `Tema` varchar(255) NOT NULL,
  `FechaInicio` date NOT NULL,
  `FechaFin` date NOT NULL,
  `MaxParticipantes` int(11) NOT NULL,
  `Materiales` text DEFAULT NULL,
  `InstructorID` int(11) DEFAULT NULL,
  PRIMARY KEY (`TallerID`),
  KEY `InstructorID` (`InstructorID`),
  CONSTRAINT `taller_ibfk_1` FOREIGN KEY (`InstructorID`) REFERENCES `instructor` (`InstructorID`)
) ENGINE=InnoDB AUTO_INCREMENT=28 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `taller`
--

LOCK TABLES `taller` WRITE;
/*!40000 ALTER TABLE `taller` DISABLE KEYS */;
INSERT INTO `taller` VALUES (19,'Iniciación a la fotografía Digital','Fotografía','2024-07-01','2024-07-15',15,'Cámara',1),(20,'Fotografía paisajística','Fotografía','2024-07-16','2024-07-30',10,'Cámara, Tripode',1),(21,'Técnicas de Pintura Impresionista','Pintura','2024-07-05','2024-07-19',12,'Pinceles, Brochas, Lienzo',2),(22,'Pintura Abstracta','Pintura','2024-08-01','2024-08-15',12,'Pintura, Brochas, Lienzo',2),(23,'Creative Writing Bootcamp','Writing','2024-07-20','2024-08-03',10,'Notebook, Pen',3),(24,'Novel Writing Workshop','Writing','2024-08-05','2024-08-19',8,'Laptop or Notebook',3),(25,'Cocina Fusión Latino-Japonesa','Cocina','2024-10-06','2024-10-16',8,'Delantal',6),(26,'Introduction to Guitar','Music','2024-07-10','2024-07-24',6,'Guitar',4),(27,'Advanced Guitar Techniques','Music','2024-08-01','2024-08-15',6,'Electric Guitar, Amplifier',4);
/*!40000 ALTER TABLE `taller` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'centrocultural'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-04-08 23:36:09
