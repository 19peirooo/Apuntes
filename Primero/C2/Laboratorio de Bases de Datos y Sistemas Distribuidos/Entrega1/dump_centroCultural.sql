-- MariaDB dump 10.19  Distrib 10.6.16-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: centroCultural
-- ------------------------------------------------------
-- Server version	10.6.16-MariaDB-0ubuntu0.22.04.1

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
-- Table structure for table `Inscripciones`
--

DROP TABLE IF EXISTS `Inscripciones`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Inscripciones` (
  `Participante` int(11) NOT NULL,
  `Taller` varchar(100) NOT NULL,
  PRIMARY KEY (`Taller`,`Participante`),
  KEY `Inscripciones_Participantes_FK` (`Participante`),
  CONSTRAINT `Inscripciones_Participantes_FK` FOREIGN KEY (`Participante`) REFERENCES `Participantes` (`id_Participante`),
  CONSTRAINT `Inscripciones_Talleres_FK` FOREIGN KEY (`Taller`) REFERENCES `Talleres` (`id_Taller`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='Tabla que relaciona los talleres con los sus participantes';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Inscripciones`
--

LOCK TABLES `Inscripciones` WRITE;
/*!40000 ALTER TABLE `Inscripciones` DISABLE KEYS */;
INSERT INTO `Inscripciones` VALUES (2,'BC01'),(6,'BC01'),(1,'BC12'),(4,'BC50'),(6,'BC50'),(4,'BC67'),(5,'BC87'),(1,'BC98'),(3,'BC98'),(4,'BC98');
/*!40000 ALTER TABLE `Inscripciones` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Instructores`
--

DROP TABLE IF EXISTS `Instructores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Instructores` (
  `DNI_Instructor` varchar(100) NOT NULL,
  `Especialidad` varchar(100) DEFAULT NULL,
  `Ciudad` varchar(100) DEFAULT NULL,
  `Pais` varchar(100) DEFAULT NULL,
  `Ruta a CV` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`DNI_Instructor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='Instructores que imparten los talleres';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Instructores`
--

LOCK TABLES `Instructores` WRITE;
/*!40000 ALTER TABLE `Instructores` DISABLE KEYS */;
INSERT INTO `Instructores` VALUES ('23415698J','Arte Contemporanea','Madrid','España','/home/javi/Curriculums'),('23432465B','MMA','Don Benito','España','/dir1/dir2'),('61254346K','Futbol','Sao Paulo','Brasil','/home/vini/CVs'),('67812345F','Programacion','Marseille','Francia','C:/home/CVs'),('76812367V','Fisica','Valencia','España','/home/trabajo'),('78117075B','Combate Callejero','Frankfurt','Alemania','/home/work/CV');
/*!40000 ALTER TABLE `Instructores` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Participantes`
--

DROP TABLE IF EXISTS `Participantes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Participantes` (
  `id_Participante` int(11) NOT NULL AUTO_INCREMENT,
  `DNI` varchar(100) NOT NULL,
  `Nombre` varchar(100) DEFAULT NULL,
  `Apellidos` varchar(100) DEFAULT NULL,
  `Edad` int(11) DEFAULT NULL,
  `Telefono` varchar(100) DEFAULT NULL,
  `Email` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_Participante`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='Participantes de los talleres';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Participantes`
--

LOCK TABLES `Participantes` WRITE;
/*!40000 ALTER TABLE `Participantes` DISABLE KEYS */;
INSERT INTO `Participantes` VALUES (1,'12345678A','Javier','Fuentes Juan',48,'654 12 98 03','j.fuentes@gmail.com'),(2,'46712361G','Jon','Vitoria Serrano',25,'722 87 12 34','jon.vitoria@hotmail.com'),(3,'16482528O','Josep','Pedrerol Gomez',19,'692 12 94 57','jose.p@yahoo.es'),(4,'12367232K','Kylian','Mbappe',26,'611 34 87 76','tortuga@gmail.com'),(5,'98765432L','Miguel','Zarate Renet',18,'602 00 00 00','zaratazo@gmail.com'),(6,'51299670X','Victor Manuel','Peiro Martinez',18,'674 32 59 57','victor.peiro@live.u-tad.com');
/*!40000 ALTER TABLE `Participantes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Reservas`
--

DROP TABLE IF EXISTS `Reservas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Reservas` (
  `Sala` varchar(100) NOT NULL,
  `Taller` varchar(100) NOT NULL,
  `Fecha_Taller` date DEFAULT NULL,
  PRIMARY KEY (`Sala`,`Taller`),
  KEY `Reservas_Talleres_FK` (`Taller`),
  CONSTRAINT `Reservas_Salas_FK` FOREIGN KEY (`Sala`) REFERENCES `Salas` (`codigo_Sala`),
  CONSTRAINT `Reservas_Talleres_FK` FOREIGN KEY (`Taller`) REFERENCES `Talleres` (`id_Taller`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='Relaciones entre las salas y los talleres';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Reservas`
--

LOCK TABLES `Reservas` WRITE;
/*!40000 ALTER TABLE `Reservas` DISABLE KEYS */;
INSERT INTO `Reservas` VALUES ('BE102','BC43','2024-12-05'),('BE116','BC12','2022-01-03'),('LO211','BC43','2024-12-03'),('LO211','BC98','2021-10-05'),('M110','BC32','2027-12-12'),('MSA','BC43','2024-12-04');
/*!40000 ALTER TABLE `Reservas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Salas`
--

DROP TABLE IF EXISTS `Salas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Salas` (
  `codigo_Sala` varchar(100) NOT NULL,
  `Edificio` varchar(100) DEFAULT NULL,
  `Capacidad` int(11) DEFAULT NULL,
  PRIMARY KEY (`codigo_Sala`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='Salas en las que se imparten los talleres';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Salas`
--

LOCK TABLES `Salas` WRITE;
/*!40000 ALTER TABLE `Salas` DISABLE KEYS */;
INSERT INTO `Salas` VALUES ('BE102','Berlin',45),('BE116','Berlin',40),('LO211','Londres',20),('M110','Madrid',50),('MSA','Madrid',200);
/*!40000 ALTER TABLE `Salas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Talleres`
--

DROP TABLE IF EXISTS `Talleres`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Talleres` (
  `id_Taller` varchar(100) NOT NULL,
  `Nombre_Taller` varchar(100) DEFAULT NULL,
  `Tema` varchar(100) DEFAULT NULL,
  `Fecha_Inicio` date DEFAULT NULL,
  `Fecha_Final` date DEFAULT NULL,
  `numParticipantesMax` int(11) DEFAULT NULL,
  `Instructor` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id_Taller`),
  KEY `Talleres_Instructores_FK` (`Instructor`),
  CONSTRAINT `Talleres_Instructores_FK` FOREIGN KEY (`Instructor`) REFERENCES `Instructores` (`DNI_Instructor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci COMMENT='Tabla conteniendo todos los talleres disponibles';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Talleres`
--

LOCK TABLES `Talleres` WRITE;
/*!40000 ALTER TABLE `Talleres` DISABLE KEYS */;
INSERT INTO `Talleres` VALUES ('BC01','Termodinamica Para Amigos','Fisica','2019-10-05','2019-10-06',17,'76812367V'),('BC12','Judo Para Expertos','MMA','2022-03-01','2022-03-05',10,'23432465B'),('BC32','Pinta como Warhol','Arte Contemporanea','2026-12-04','2028-05-11',5,'23415698J'),('BC43','Curso 0 Python','Programacion','2024-12-03','2024-12-05',50,'67812345F'),('BC50','Fisica Cuantica','Fisica','2020-10-11','2021-10-11',40,'76812367V'),('BC67','Sobreviviendo en la calle','Combate Callejero','2024-12-24','2025-01-18',25,'78117075B'),('BC87','Karate para Niños','MMA','2023-09-12','2023-10-12',30,'23432465B'),('BC98','Dribble Like Vini JR','Futbol','2021-05-10','2023-11-04',8,'61254346K');
/*!40000 ALTER TABLE `Talleres` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'centroCultural'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-03-21 11:07:46
