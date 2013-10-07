CREATE TABLE IF NOT EXISTS `syslogs` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ipaddress` varchar(255) NOT NULL,
  `datetime` datetime NOT NULL,
  `comp` varchar(255) NOT NULL,
  `application` varchar(255) NOT NULL,
  `pid` int(11) NOT NULL,
  `owner` varchar(255) NOT NULL,
  `message` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;
