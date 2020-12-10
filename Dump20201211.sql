CREATE DATABASE  IF NOT EXISTS `travel_system` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `travel_system`;
-- MySQL dump 10.13  Distrib 8.0.21, for Win64 (x86_64)
--
-- Host: localhost    Database: travel_system
-- ------------------------------------------------------
-- Server version	8.0.21

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `buses`
--

DROP TABLE IF EXISTS `buses`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `buses` (
  `location` varchar(45) NOT NULL,
  `price` int NOT NULL,
  `numBus` int NOT NULL,
  `numAvail` int NOT NULL,
  PRIMARY KEY (`location`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `buses`
--

LOCK TABLES `buses` WRITE;
/*!40000 ALTER TABLE `buses` DISABLE KEYS */;
INSERT INTO `buses` VALUES ('上海',3,50,49),('北京',3,60,58),('广州',2,60,60),('武汉',1,55,55),('深圳',2,70,68),('西安',1,40,38);
/*!40000 ALTER TABLE `buses` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customers`
--

DROP TABLE IF EXISTS `customers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customers` (
  `custName` varchar(45) NOT NULL,
  `custID` int NOT NULL,
  PRIMARY KEY (`custID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customers`
--

LOCK TABLES `customers` WRITE;
/*!40000 ALTER TABLE `customers` DISABLE KEYS */;
INSERT INTO `customers` VALUES ('钱一',1),('刘二',2),('张三',3),('李四',4),('王五',5),('赵六',6),('黄七',7),('柳八',8),('杨九',9);
/*!40000 ALTER TABLE `customers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `flights`
--

DROP TABLE IF EXISTS `flights`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `flights` (
  `flightNum` varchar(45) NOT NULL,
  `price` int NOT NULL,
  `numSeats` int NOT NULL,
  `numAvail` int NOT NULL,
  `FromCity` varchar(45) NOT NULL,
  `ArivCity` varchar(45) NOT NULL,
  PRIMARY KEY (`flightNum`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `flights`
--

LOCK TABLES `flights` WRITE;
/*!40000 ALTER TABLE `flights` DISABLE KEYS */;
INSERT INTO `flights` VALUES ('A101',1200,200,199,'西安','北京'),('A301',1000,150,148,'上海','西安'),('A303',950,180,178,'广州','武汉'),('B110',1400,250,249,'深圳','北京'),('B233',200,150,150,'深圳','广州'),('B777',650,300,300,'北京','西安'),('B900',1000,200,198,'上海','广州'),('D666',600,100,100,'上海','广州'),('D888',1200,300,299,'西安','深圳'),('D999',1000,120,118,'北京','上海'),('E110',600,160,159,'武汉','深圳'),('E200',900,220,219,'西安','武汉');
/*!40000 ALTER TABLE `flights` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hotels`
--

DROP TABLE IF EXISTS `hotels`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `hotels` (
  `location` varchar(45) NOT NULL,
  `price` int NOT NULL,
  `numRooms` int NOT NULL,
  `numAvail` int NOT NULL,
  PRIMARY KEY (`location`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hotels`
--

LOCK TABLES `hotels` WRITE;
/*!40000 ALTER TABLE `hotels` DISABLE KEYS */;
INSERT INTO `hotels` VALUES ('上海',900,300,298),('北京',600,200,199),('广州',600,200,198),('武汉',400,100,99),('深圳',500,400,399),('西安',400,300,300);
/*!40000 ALTER TABLE `hotels` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `reservations`
--

DROP TABLE IF EXISTS `reservations`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `reservations` (
  `custName` varchar(45) NOT NULL,
  `resvType` int NOT NULL,
  `resvKey` varchar(45) NOT NULL,
  `resvName` varchar(45) NOT NULL,
  PRIMARY KEY (`resvKey`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `reservations`
--

LOCK TABLES `reservations` WRITE;
/*!40000 ALTER TABLE `reservations` DISABLE KEYS */;
INSERT INTO `reservations` VALUES ('钱一',1,'145','A101'),('杨九',3,'1466','上海'),('张三',2,'14881','上海'),('张三',1,'15243','A301'),('张三',1,'15811','D888'),('钱一',2,'16422','上海'),('李四',3,'185','深圳'),('张三',1,'2298','A303'),('王五',3,'2367','北京'),('赵六',1,'2394','B110'),('钱一',3,'25248','西安'),('李四',2,'357','深圳'),('黄七',1,'4085','E200'),('柳八',1,'425','D999'),('刘二',2,'4325','广州'),('王五',1,'450','B900'),('刘二',1,'5223','A303'),('赵六',1,'5232','E110'),('钱一',2,'5328','北京'),('赵六',3,'5543','深圳'),('刘二',1,'6354','B900'),('刘二',2,'7348','武汉'),('杨九',1,'775','D999'),('柳八',3,'792','北京'),('赵六',2,'8630','广州'),('黄七',2,'8654','上海'),('钱一',1,'888','A301'),('张三',3,'907','西安');
/*!40000 ALTER TABLE `reservations` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `reservations_AFTER_INSERT` AFTER INSERT ON `reservations` FOR EACH ROW BEGIN
if new.resvType=1 
	then update flights set  numAvail=numAvail-1
    where new.resvName=flights.flightNum and flights.numAvail>=1;

elseif new.resvType=2
    then update hotels set numAvail=numAvail-1
    where new.resvName=hotels.location and numAvail>=1;

else
	update buses set numAvail=numAvail-1
    where new.resvName=buses.location and numAvail>=1;

end if;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `reservations_AFTER_DELETE` AFTER DELETE ON `reservations` FOR EACH ROW BEGIN
if old.resvType=1 
	then update flights set  numAvail=numAvail+1
    where old.resvName=flights.flightNum;
    
elseif old.resvType=2
    then update hotels set numAvail=numAvail+1
    where old.resvName=hotels.location;

else 
	update buses set numAvail=numAvail+1
    where old.resvName=buses.location;
end if;
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Dumping events for database 'travel_system'
--

--
-- Dumping routines for database 'travel_system'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-12-11  0:05:52
