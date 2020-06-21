-- MySQL dump 10.13  Distrib 5.7.29, for Linux (x86_64)
--
-- Host: localhost    Database: BeerGame
-- ------------------------------------------------------
-- Server version	5.7.29-0ubuntu0.18.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Game`
--

DROP TABLE IF EXISTS `Game`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Game` (
  `gId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `instrId` int(11) NOT NULL,
  `pFactId` int(10) unsigned NOT NULL,
  `pDistributorId` int(10) unsigned NOT NULL,
  `pWholesalerId` int(10) unsigned DEFAULT NULL,
  `pRetailerId` int(10) unsigned DEFAULT NULL,
  `orderDelay` int(11) NOT NULL,
  `shipmentDealy` int(11) NOT NULL,
  `holdingCost` double NOT NULL,
  `backorderCost` double NOT NULL,
  `startingInventory` int(11) NOT NULL,
  `weeksToBePlayed` int(11) NOT NULL,
  `currentWeek` int(11) NOT NULL,
  `infoCode` int(11) NOT NULL,
  `factoryDelay` int(11) NOT NULL,
  `numberOfPlayers` int(11) NOT NULL,
  `players` longtext NOT NULL,
  `consumerDemandPerWeek` longtext,
  PRIMARY KEY (`gId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Game`
--

LOCK TABLES `Game` WRITE;
/*!40000 ALTER TABLE `Game` DISABLE KEYS */;
/*!40000 ALTER TABLE `Game` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Instructor`
--

DROP TABLE IF EXISTS `Instructor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Instructor` (
  `instrId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `instrEmail` varchar(100) NOT NULL,
  `instrPassword` varchar(100) NOT NULL,
  `games` longtext,
  PRIMARY KEY (`instrId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Instructor`
--

LOCK TABLES `Instructor` WRITE;
/*!40000 ALTER TABLE `Instructor` DISABLE KEYS */;
/*!40000 ALTER TABLE `Instructor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Player`
--

DROP TABLE IF EXISTS `Player`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Player` (
  `pId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `role` int(11) NOT NULL,
  `inventory` int(11) NOT NULL,
  `backorder` int(11) NOT NULL,
  `incomingOrder` int(11) NOT NULL,
  `outgoingShipment` int(11) NOT NULL,
  `cost` double NOT NULL,
  `totalCost` double NOT NULL,
  `orderReceived` tinyint(1) NOT NULL,
  `shipmentReceived` tinyint(1) NOT NULL,
  `orderPlaced` tinyint(1) NOT NULL,
  `shipmentPlaced` tinyint(1) NOT NULL,
  `demand` int(11) NOT NULL,
  `gameId` int(11) NOT NULL,
  PRIMARY KEY (`pId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Player`
--

LOCK TABLES `Player` WRITE;
/*!40000 ALTER TABLE `Player` DISABLE KEYS */;
/*!40000 ALTER TABLE `Player` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PlayerEvent`
--

DROP TABLE IF EXISTS `PlayerEvent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PlayerEvent` (
  `eventId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `gId` int(11) NOT NULL,
  `numberOfBeers` int(11) NOT NULL,
  `orderedInWeek` int(11) NOT NULL,
  `shipmentInWeek` int(11) NOT NULL,
  `toPlayerId` int(11) NOT NULL,
  `fromPlayerId` int(11) NOT NULL,
  PRIMARY KEY (`eventId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PlayerEvent`
--

LOCK TABLES `PlayerEvent` WRITE;
/*!40000 ALTER TABLE `PlayerEvent` DISABLE KEYS */;
/*!40000 ALTER TABLE `PlayerEvent` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `USERS`
--

DROP TABLE IF EXISTS `USERS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `USERS` (
  `email` varchar(100) NOT NULL,
  `password` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `USERS`
--

LOCK TABLES `USERS` WRITE;
/*!40000 ALTER TABLE `USERS` DISABLE KEYS */;
INSERT INTO `USERS` VALUES ('test','1234');
/*!40000 ALTER TABLE `USERS` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-05-04 23:44:33
