CREATE TABLE `people` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` char(20) NOT NULL DEFAULT '',
  `sex` char(5) NOT NULL DEFAULT '',
  `age` int(4) NOT NULL DEFAULT '0',
  `country` char(10) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)

) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

INSERT INTO `people` VALUES ('1', 'Alan', 'boy', '20', 'AU'),
('2', 'Bollin', 'girl', '15', 'DE'),
('3', 'Catalan', 'boy', '25', 'US'),
('4', 'Dio', 'boy', '999', 'UK'),
('5', 'Eric', 'boy', '20', 'JP');