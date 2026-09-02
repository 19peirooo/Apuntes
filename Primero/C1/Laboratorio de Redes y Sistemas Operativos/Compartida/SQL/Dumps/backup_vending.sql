-- MySQL dump 10.19  Distrib 10.3.29-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: redVending
-- ------------------------------------------------------
-- Server version	10.3.29-MariaDB-0ubuntu0.20.04.1

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
-- Table structure for table `CentroComercial`
--

DROP TABLE IF EXISTS `CentroComercial`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `CentroComercial` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(255) NOT NULL,
  `direccion` varchar(255) NOT NULL,
  `encargado` varchar(255) NOT NULL,
  `telefono` int(11) NOT NULL,
  `hora_apertura` time NOT NULL,
  `hora_cierre` time NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CentroComercial`
--

LOCK TABLES `CentroComercial` WRITE;
/*!40000 ALTER TABLE `CentroComercial` DISABLE KEYS */;
INSERT INTO `CentroComercial` VALUES (1,'La Vaguada','Av. de Monforte de Lemos\n 36','Jorge',654545454,'08:30:00','22:30:00'),(2,'Centro comercial 3C','Av. de los Labradores 9','Andrea',612323536,'09:00:00','23:00:00'),(3,'Xanadu','Calle Puerto de Navacerrada 1','Marcos',666223355,'08:00:00','23:30:00');
/*!40000 ALTER TABLE `CentroComercial` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Maquinas`
--

DROP TABLE IF EXISTS `Maquinas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Maquinas` (
  `codigo` int(11) NOT NULL,
  `tipologia` varchar(255) NOT NULL,
  `capacidad` int(11) NOT NULL,
  `id_centro` int(11) NOT NULL,
  PRIMARY KEY (`codigo`),
  KEY `Maquinas_FK` (`id_centro`),
  CONSTRAINT `Maquinas_FK` FOREIGN KEY (`id_centro`) REFERENCES `CentroComercial` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Maquinas`
--

LOCK TABLES `Maquinas` WRITE;
/*!40000 ALTER TABLE `Maquinas` DISABLE KEYS */;
INSERT INTO `Maquinas` VALUES (1,'Simple',100,1),(2,'Doble',200,2),(3,'Premium',450,2),(4,'Doble',200,3);
/*!40000 ALTER TABLE `Maquinas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Productos`
--

DROP TABLE IF EXISTS `Productos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Productos` (
  `codigo` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(255) NOT NULL,
  `peso` int(11) NOT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Productos`
--

LOCK TABLES `Productos` WRITE;
/*!40000 ALTER TABLE `Productos` DISABLE KEYS */;
INSERT INTO `Productos` VALUES (1,'Cascos',300),(2,'Toalla',1100),(3,'Snack',200),(4,'Almendras',50);
/*!40000 ALTER TABLE `Productos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Stock`
--

DROP TABLE IF EXISTS `Stock`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Stock` (
  `cod_maquina` int(11) NOT NULL,
  `cod_producto` int(11) NOT NULL,
  `cantidad` int(11) NOT NULL,
  `precio` int(11) NOT NULL,
  PRIMARY KEY (`cod_maquina`,`cod_producto`),
  KEY `Stock_FK_1` (`cod_producto`),
  CONSTRAINT `Stock_FK` FOREIGN KEY (`cod_maquina`) REFERENCES `Maquinas` (`codigo`),
  CONSTRAINT `Stock_FK_1` FOREIGN KEY (`cod_producto`) REFERENCES `Productos` (`codigo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Stock`
--

LOCK TABLES `Stock` WRITE;
/*!40000 ALTER TABLE `Stock` DISABLE KEYS */;
INSERT INTO `Stock` VALUES (1,2,2,15),(1,3,10,2),(2,1,3,20),(2,4,30,15),(3,2,15,5),(4,1,14,18);
/*!40000 ALTER TABLE `Stock` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-06-02 11:48:15