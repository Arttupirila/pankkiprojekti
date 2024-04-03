-- MySQL dump 10.13  Distrib 8.0.36, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: bankdb
-- ------------------------------------------------------
-- Server version	8.2.0

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
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `account` (
  `idAccount` varchar(18) NOT NULL,
  `balance` decimal(10,2) NOT NULL,
  `creditLimit` decimal(10,2) NOT NULL,
  `accountOwner` varchar(45) NOT NULL,
  PRIMARY KEY (`idAccount`),
  KEY `accountOwner_idx` (`accountOwner`),
  CONSTRAINT `accountOwner` FOREIGN KEY (`accountOwner`) REFERENCES `customer` (`idCustomer`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES ('FI0445678900000084',900.45,0.00,'6'),('FI2223456700000002',2200.95,0.00,'5'),('FI2223456700000102',900.35,0.00,'3'),('FI2445678900000104',2200.80,0.00,'4'),('FI4889012300000028',2800.30,0.00,'3'),('FI8334567800000063',900.30,0.00,'1'),('FI8445678900000064',2600.00,4500.00,'4'),('FI8990123400000069',2200.95,0.00,'2');
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `card`
--

DROP TABLE IF EXISTS `card`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card` (
  `idCard` varchar(20) NOT NULL,
  `cardPin` varchar(255) NOT NULL,
  `cardValid` tinyint(1) NOT NULL,
  PRIMARY KEY (`idCard`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card`
--

LOCK TABLES `card` WRITE;
/*!40000 ALTER TABLE `card` DISABLE KEYS */;
INSERT INTO `card` VALUES ('3810-5623-7914-5069','6498',1),('4716-8305-9247-0183','5732',1),('6319-7042-8350-1674','7290',1),('6902-3815-9430-1782','8215',1),('8201-6374-5908-1462','3467',1),('9407-2685-3140-7592','8904',1);
/*!40000 ALTER TABLE `card` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cardaccount`
--

DROP TABLE IF EXISTS `cardaccount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cardaccount` (
  `idCard` varchar(20) NOT NULL,
  `idAccount` varchar(18) NOT NULL,
  PRIMARY KEY (`idCard`,`idAccount`),
  KEY `idAccount_idx` (`idAccount`),
  CONSTRAINT `cardIdAccount` FOREIGN KEY (`idAccount`) REFERENCES `account` (`idAccount`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `cardIdCard` FOREIGN KEY (`idCard`) REFERENCES `card` (`idCard`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cardaccount`
--

LOCK TABLES `cardaccount` WRITE;
/*!40000 ALTER TABLE `cardaccount` DISABLE KEYS */;
INSERT INTO `cardaccount` VALUES ('4716-8305-9247-0183','FI0445678900000084'),('6319-7042-8350-1674','FI0445678900000084'),('4716-8305-9247-0183','FI2223456700000002'),('9407-2685-3140-7592','FI2223456700000102'),('6902-3815-9430-1782','FI2445678900000104'),('8201-6374-5908-1462','FI4889012300000028'),('3810-5623-7914-5069','FI8990123400000069');
/*!40000 ALTER TABLE `cardaccount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customer` (
  `idCustomer` varchar(45) NOT NULL,
  `firstName` varchar(45) NOT NULL,
  `lastName` varchar(45) NOT NULL,
  `streetAddress` varchar(45) NOT NULL,
  `phoneNumber` varchar(45) NOT NULL,
  PRIMARY KEY (`idCustomer`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES ('1','Sara','Nieminen','Pajukuja 6 A 8','+358463456789'),('2','Tuija','Koskinen','Mäntytie 4','+358469012345'),('3','Amir','Hosseini','Katajatie 3 C 15','+358428901234'),('4','Jussi','Lehto','Katajatie 14 A 8','+358504567890'),('5','Anton','Järvinen','Kuusitie 30','+358402345678'),('6','Kirsi','Järvinen','Kuusitie 30','+358484567890');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customeraccount`
--

DROP TABLE IF EXISTS `customeraccount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customeraccount` (
  `idCustomer` varchar(45) NOT NULL,
  `idAccount` varchar(18) NOT NULL,
  PRIMARY KEY (`idCustomer`,`idAccount`),
  KEY `tili_id_idx` (`idAccount`),
  CONSTRAINT `accountIdAccount` FOREIGN KEY (`idAccount`) REFERENCES `account` (`idAccount`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `customerIdCustomer` FOREIGN KEY (`idCustomer`) REFERENCES `customer` (`idCustomer`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customeraccount`
--

LOCK TABLES `customeraccount` WRITE;
/*!40000 ALTER TABLE `customeraccount` DISABLE KEYS */;
INSERT INTO `customeraccount` VALUES ('5','FI0445678900000084'),('6','FI0445678900000084'),('5','FI2223456700000002'),('3','FI2223456700000102'),('4','FI2445678900000104'),('3','FI4889012300000028'),('1','FI8334567800000063'),('4','FI8445678900000064'),('2','FI8990123400000069');
/*!40000 ALTER TABLE `customeraccount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transaction`
--

DROP TABLE IF EXISTS `transaction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transaction` (
  `idTransaction` int NOT NULL AUTO_INCREMENT,
  `idAccount` varchar(18) NOT NULL,
  `idCard` varchar(20) DEFAULT NULL,
  `dateAndTime` datetime NOT NULL,
  `transactionType` varchar(45) NOT NULL,
  `transactionAmount` decimal(10,2) NOT NULL,
  `participantAccount` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idTransaction`),
  KEY `idAccount_idx` (`idAccount`),
  CONSTRAINT `transactionIdAccount` FOREIGN KEY (`idAccount`) REFERENCES `account` (`idAccount`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=108 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transaction`
--

LOCK TABLES `transaction` WRITE;
/*!40000 ALTER TABLE `transaction` DISABLE KEYS */;
INSERT INTO `transaction` VALUES (100,'FI8334567800000063',NULL,'2024-04-01 15:00:00','Withdrawal',100.00,NULL),(101,'FI8990123400000069','3810-5623-7914-5069','2024-04-01 15:01:00','Withdrawal',100.00,NULL),(102,'FI4889012300000028','8201-6374-5908-1462','2024-04-01 15:02:00','Withdrawal',100.00,NULL),(103,'FI2223456700000102','9407-2685-3140-7592','2024-04-01 15:03:00','Withdrawal',100.00,NULL),(104,'FI2445678900000104','6902-3815-9430-1782','2024-04-01 15:04:00','Withdrawal',100.00,NULL),(105,'FI8445678900000064','6902-3815-9430-1782','2024-04-01 15:05:00','Withdrawal',100.00,NULL),(106,'FI2223456700000002','4716-8305-9247-0183','2024-04-01 15:06:00','Withdrawal',100.00,NULL),(107,'FI0445678900000084','6319-7042-8350-1674','2024-04-01 15:07:00','Withdrawal',100.00,NULL);
/*!40000 ALTER TABLE `transaction` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-04-02 21:14:43
