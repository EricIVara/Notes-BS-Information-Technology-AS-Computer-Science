
CREATE DATABASE BBQSteakHouseDB;


CREATE TABLE `bbqsteakhousedb`.`address` (`addressID` INT(5) NOT NULL AUTO_INCREMENT , `street` VARCHAR(30) NOT NULL , `city` VARCHAR(30) NOT NULL , `state` VARCHAR(30) NOT NULL , `zip` VARCHAR(5) NOT NULL , PRIMARY KEY (`addressID`)) ENGINE = InnoDB;


CREATE TABLE `bbqsteakhousedb`.`customer` (`customerID` INT(5) NOT NULL , `addressID` INT(5) NOT NULL , `name` VARCHAR(30) NOT NULL , `email` VARCHAR(30) NOT NULL , `phone` VARCHAR(30) NOT NULL , PRIMARY KEY (`customerID`), UNIQUE (`addressID`)) ENGINE = InnoDB;


CREATE TABLE `bbqsteakhousedb`.`order` (`orderNum` INT(5) NOT NULL , `customerID` INT(5) NOT NULL , `transactionID` INT(5) NOT NULL ,`shipDate` DATE NOT NULL , PRIMARY KEY (`orderNum`), INDEX (`customerID`), INDEX (`transactionID`)) ENGINE = InnoDB;


CREATE TABLE `bbqsteakhousedb`.`product` (`productID` INT(5) NOT NULL , `name` VARCHAR(30) NOT NULL , `description` TEXT NOT NULL , `price` DOUBLE NOT NULL , PRIMARY KEY (`productID`)) ENGINE = InnoDB;


CREATE TABLE `bbqsteakhousedb`.`cardtype` (`typeID` INT(5) NOT NULL , `cardType` VARCHAR(30) NOT NULL , PRIMARY KEY (`typeID`)) ENGINE = InnoDB;

CREATE TABLE `bbqsteakhousedb`.`card` (`cardID` INT(5) NOT NULL , `typeID` INT(5) NOT NULL , `cardNum` VARCHAR(16) NOT NULL , `exp` DATE NOT NULL , `ccv` INT(3) NOT NULL , `zip` VARCHAR(5) NOT NULL , PRIMARY KEY (`cardID`), INDEX (`typeID`)) ENGINE = InnoDB;


CREATE TABLE  `bbqsteakhousedb`.`transaction`(`transactionID` INT(5) NOT NULL , `productID` INT(5) NOT NULL ,`cardID` INT(5) NOT NULL , `date` DATE NOT NULL , `qty` INT(2) NOT NULL , `totalPrice` DOUBLE NOT NULL , PRIMARY KEY (`transactionID`), INDEX (`productID`), INDEX (`cardID`)) ENGINE = InnoDB;


INSERT INTO `bbqsteakhousedb`.`address` (`addressID`, `street`, `city`, `state`, `zip`)
VALUES
(77581,"541-2280 Molestie Street","New Orleans","Washington","12620"),
(50721,"Ap #393-7344 Cum St.","Cleveland","Vermont","32128"),
(62041,"742-1769 Congue Avenue","Jonesboro","Delaware","56431"),
(41041,"Ap #950-6689 Neque Street","Warren","Oklahoma","48518"),
(34651,"684-5591 Vitae, Rd.","Toledo","Oregon","56221"),
(35571,"Ap #797-1351 Leo. Rd.","Portland","Michigan","85368"),
(97171,"240-4245 Lacus. St.","Rockville","Maryland","51696"),
(40311,"169-6045 Dolor St.","Atlanta","Illinois","96945"),
(17871,"Ap #328-7072 Egestas St.","Naperville","Michigan","16256"),
(53261,"288-8597 Magna. Ave","Lakewood","Wisconsin","88688"),
(57881,"689-9379 Pede, Rd.","Casper","Florida","65312"),
(34591,"839-662 Enim. Avenue","Covington","Kansas","77695"),
(45891,"6379 Ut, St.","Indianapolis","Alaska","48683"),
(52801,"823-1999 Elit, Rd.","Grand Island","Minnesota","55888"),
(75961,"8091 At, Street","Nampa","Nevada","65169"),
(45581,"265-878 Ullamcorper. Ave","Virginia Beach","Virginia","66746"),
(54661,"P.O. Box 233, 9194 Ac Av.","Aurora","Montana","69263"),
(67081,"Ap #542-1896 Nunc Av.","Waterbury","Georgia","86362"),
(29001,"P.O. Box 177, 4093 Iaculis Ave","Fort Worth","Mississippi","52645"),
(32141,"Ap #969-6334 Enim. Ave","Lincoln","Delaware","11466"),
(70021,"Ap #218-8245 Integer Rd.","Lincoln","Montana","65253"),
(81091,"313-6381 Mattis Av.","West Jordan","California","48579"),
(93551,"704-8632 Quam Street","Dallas","Virginia","63834"),
(65201,"P.O. Box 213, 686 Nulla. St.","Gaithersburg","Indiana","70620"),
(94151,"P.O. Box 908, 1606 Sed St.","Provo","Hawaii","98438"),
(36101,"519-191 Placerat. St.","Fort Wayne","Hawaii","27923"),
(82991,"Ap #465-6586 Sed St.","Austin","Oklahoma","96587"),
(82051,"9672 Est, St.","Miami","Maine","51581"),
(91661,"856 Phasellus Ave","Billings","Arizona","87154"),
(95871,"Ap #744-8460 Magna Rd.","Denver","Missouri","95682");


INSERT INTO `bbqsteakhousedb`.`customer` (`customerID`, `addressID`, `name`, `email`, `phone`) VALUES
(50201, "77581", "Piper Howell","donec@protonmail.com","214424046"),
(78411, "50721", "Caldwell Potter","ut.sem.nulla@icloud.edu","395479348"),
(72891, "62041", "Leigh Mccarty","ridiculus.mus@google.org","836818381"),
(99041, "41041", "Nola Torres","netus.et.malesuada@icloud.com","598477434"),
(32711, "34651", "Brittany Hutchinson","tempus@icloud.ca","542418440"),
(80451, "35571", "Wesley Hayden","amet@icloud.ca","672446077"),
(23281, "97171", "Michelle Fitzpatrick","justo.faucibus@outlook.net","945361338"),
(97051, "40311", "Cara Travis","pede.ultrices@protonmail.edu","335280153"),
(56281, "17871", "Shaeleigh Green","turpis.in@icloud.ca","193752546"),
(44071, "53261", "Christian Cochran","metus.facilisis@aol.net","522137870"),
(79401, "57881", "Shaeleigh Compton","nisi.aenean@google.couk","635218510"),
(83301, "34591", "Nero Hart","placerat.orci.lacus@google.couk","987908488"),
(91641, "45891", "Priscilla Douglas","orci@yahoo.org","411264248"),
(47991, "52801", "Remedios Nash","ad.litora@icloud.edu","768159476"),
(96571, "75961", "Gay Bush","risus.donec@aol.com","960631664"),
(82071, "45581", "Ciaran Frye","turpis.aliquam.adipiscing@protonmail.ca","650869618"),
(35201, "54661", "Alan Finch","non.dui.nec@aol.ca","458872452"),
(71441, "67081", "Barry Gillespie","libero.at@protonmail.ca","475622866"),
(84781, "29001", "Ariel Barron","sit.amet.luctus@yahoo.ca","536414681"),
(79651, "32141", "Candace Camacho","eros.nam@icloud.org","766468561"),
(44891, "70021", "Justin Horne","tristique.pellentesque.tellus@hotmail.org","480485597"),
(28811, "81091", "George Solis","vehicula.et@aol.ca","746836404"),
(99081, "93551", "Marshall Joseph","aliquet.molestie@hotmail.org","345629338"),
(74491, "65201", "Yuri Baldwin","enim@yahoo.couk","454116084"),
(17761, "94151", "Alice Bowers","malesuada@google.com","273832419"),
(20591, "36101", "Kermit Joyner","sit@aol.couk","243255161"),
(99461, "82991", "Macey Wagner","at@yahoo.com","672831328"),
(56141, "82051", "Samson Snider","imperdiet.non@hotmail.couk","807822763"),
(78181, "91661", "Laura Moss","pede.nonummy@hotmail.ca","870582019"),
(11501, "95871", "Ulysses Haley","odio.nam@hotmail.edu","778117334");


INSERT INTO `bbqsteakhousedb`.`order` (`orderNum`, `customerID`, `transactionID`, `shipDate`) VALUES
(87786,50201,38397,"2023-05-28"),
(96569,78411,95171,"2023-04-23"),
(34473,72891,54534,"2023-09-03"),
(38670,99041,66814,"2022-04-12"),
(67434,32711,49878,"2022-10-19"),
(45766,80451,29244,"2022-07-08"),
(32733,23281,53980,"2021-12-22"),
(87484,97051,13866,"2022-02-20"),
(86871,56281,31992,"2023-04-10"),
(66553,44071,65429,"2023-05-25"),
(33131,79401,97185,"2023-04-28"),
(32561,83301,60186,"2022-09-04"),
(81687,91641,30273,"2021-12-26"),
(33342,47991,67676,"2023-04-22"),
(24622,96571,82593,"2023-03-20"),
(31347,82071,86654,"2022-05-20"),
(49552,35201,49779,"2022-09-15"),
(56531,71441,38721,"2023-07-10"),
(42616,84781,77587,"2021-11-16"),
(75633,79651,66526,"2022-01-19"),
(20361,44891,13032,"2022-05-06"),
(67378,28811,43768,"2023-10-27"),
(35782,99081,85697,"2022-08-21"),
(50351,74491,86734,"2022-12-07"),
(46733,17761,84948,"2022-09-24"),
(78782,20591,84161,"2023-07-12"),
(84857,99461,23468,"2023-02-25"),
(39777,56141,25447,"2021-12-08"),
(44823,78181,35182,"2022-08-12"),
(28283,11501,42253,"2022-05-24");


INSERT INTO `bbqsteakhousedb`.`product` (`productID`, `name`, `description`, `price`) VALUES
(84022,"potatos","chili on fries","39.64"),
(20179,"fries","extra cheese","35.28"),
(46612,"potatos","extra cheese","21.87"),
(84363,"wings","extra cheese","4.45"),
(68536,"potatos","chili on fries","20.19"),
(15712,"cheeseburger","no mustard","4.39"),
(91247,"steak","no mustard","41.40"),
(14682,"cheeseburger","no mustard","18.64"),
(79769,"potatos","bqq sauce","22.38"),
(70013,"potatos","no cheese","42.60"),
(10760,"steak","extra cheese","47.07"),
(19610,"steak","chili on fries","24.44"),
(57414,"fries","no cheese","25.74"),
(35616,"potatos","chili on fries","38.49"),
(46668,"cheeseburger","bqq sauce","45.97"),
(42242,"potatos","no mustard","9.17"),
(88593,"potatos","chili on fries","49.52"),
(79770,"hotdog","chili on fries","22.74"),
(39744,"fries","extra cheese","19.25"),
(83754,"potatos","chili on fries","3.53"),
(61494,"cheeseburger","no cheese","37.16"),
(70362,"hotdog","extra cheese","26.56"),
(53884,"fries","extra cheese","35.59"),
(12383,"fries","extra cheese","22.37"),
(92918,"wings","bqq sauce","31.59"),
(76726,"hotdog","bqq sauce","39.57"),
(75763,"potatos","chili on fries","4.98"),
(80829,"steak","no cheese","12.11"),
(33970,"steak","chili on fries","33.38"),
(65529,"hotdog","no mustard","11.75");



INSERT INTO `bbqsteakhousedb`.`cardtype` (`typeID`, `cardType`) VALUES
(60977,"credit card"),
(68583,"credit card"),
(58851,"credit card"),
(93530,"debit crad"),
(69219,"credit card"),
(67535,"credit card"),
(20943,"credit card"),
(16167,"debit crad"),
(30388,"debit crad"),
(13711,"credit card"),
(64257,"credit card"),
(20137,"debit crad"),
(39232,"debit crad"),
(19618,"debit crad"),
(19591,"debit crad"),
(12970,"credit card"),
(48262,"debit crad"),
(19665,"debit crad"),
(22235,"debit crad"),
(84728,"credit card"),
(73349,"credit card"),
(93508,"credit card"),
(20183,"credit card"),
(34301,"credit card"),
(93074,"debit crad"),
(15911,"credit card"),
(11534,"debit crad"),
(72106,"credit card"),
(32436,"debit crad"),
(38536,"credit card");


INSERT INTO `bbqsteakhousedb`.`card` (`cardID`, `typeID`, `cardNum`, `exp`, `ccv`, `zip`) VALUES
(16197,60977,275396466285955,"2011-1-15","536","74633"),
(14109,68583,239442651418792,"2005-3-15","286","13778"),
(48456,58851,208995511088916,"2005-2-15","603","95786"),
(17231,93530,422699886768154,"2003-3-15","935","93413"),
(84774,69219,507977946878379,"2009-2-15","409","30447"),
(96264,67535,231099430699637,"2001-3-15","816","53183"),
(85507,20943,298936860778138,"2006-2-15","249","33513"),
(71021,16167,781357490128560,"2006-3-15","229","63522"),
(53029,30388,491962280252086,"2002-2-15","912","23408"),
(82412,13711,515522998755366,"2010-2-15","999","64384"),
(99867,64257,756292987214060,"2006-2-15","745","99822"),
(91084,20137,853823403618941,"2004-2-15","990","31085"),
(88190,39232,840164536952714,"2009-3-15","181","35303"),
(33170,19618,702480907530978,"2010-2-15","167","28741"),
(19304,19591,660205522056023,"2010-2-15","932","52450"),
(41065,12970,350226853043943,"2010-2-15","521","42003"),
(40828,48262,149964052330897,"2005-3-15","530","42156"),
(64957,19665,550005671205264,"2001-2-15","628","23062"),
(25156,22235,996884032079147,"2003-2-15","257","71069"),
(52828,84728,910254765561928,"2003-3-15","792","24547"),
(95185,73349,728276408953943,"2004-3-15","883","62803"),
(47590,93508,712568036563928,"2004-2-15","506","73358"),
(75764,20183,802401994436720,"2001-2-15","972","72966"),
(75262,34301,563162885663764,"2011-3-15","529","88846"),
(92028,93074,648363921468729,"2008-3-15","444","51682"),
(90834,15911,963788211884325,"2008-2-15","501","99948"),
(94277,11534,764992763017943,"2001-3-15","493","83673"),
(44284,72106,410770875659674,"2012-1-15","456","77533"),
(62729,32436,739831379306705,"2006-3-15","327","48428"),
(13998,38536,886410461461548,"2012-1-15","155","95448");


INSERT INTO `bbqsteakhousedb`.`transaction` (`transactionID`, `productID`, `cardID`, `date`, `qty`, `totalPrice`) VALUES
(87031,16197,84022,"2022-11-23",12,"56.58"),
(30548,14109,20179,"2022-07-02",11,"29.41"),
(35722,48456,46612,"2022-07-16",5 ,"25.36"),
(29693,17231,84363,"2022-02-26",3 ,"47.43"),
(84667,84774,68536,"2023-10-02",2 ,"21.05"),
(70072,96264,15712,"2022-07-17",5 ,"39.74"),
(22903,85507,91247,"2023-08-04",12,"76.98"),
(34908,71021,14682,"2023-08-04",4 ,"43.45"),
(94186,53029,79769,"2023-10-19",12,"04.08"),
(76300,82412,70013,"2022-04-30",4 ,"22.61"),
(12447,99867,10760,"2022-10-01",3 ,"76.94"),
(85584,91084,19610,"2022-10-08",0 ,"22.65"),
(89174,88190,57414,"2021-12-15",3 ,"48.32"),
(68516,33170,35616,"2022-08-26",8 ,"76.17"),
(28671,19304,46668,"2023-09-17",2 ,"84.31"),
(66494,41065,42242,"2022-10-10",2 ,"88.82"),
(21551,40828,88593,"2023-05-30",15,"04.69"),
(93423,64957,79770,"2023-09-10",12,"81.88"),
(98667,25156,39744,"2022-10-02",10,"43.59"),
(21329,52828,83754,"2023-09-11",7 ,"22.57"),
(15404,95185,61494,"2023-08-06",1 ,"28.33"),
(96369,47590,70362,"2023-10-15",8 ,"61.32"),
(47214,75764,53884,"2023-06-06",9 ,"15.41"),
(20947,75262,12383,"2023-08-25",12,"18.03"),
(42396,92028,92918,"2022-01-31",7 ,"26.87"),
(14253,90834,76726,"2022-07-26",9 ,"27.61"),
(42248,94277,75763,"2023-08-25",8 ,"27.88"),
(10371,44284,80829,"2022-09-29",3 ,"02.71"),
(49959,62729,33970,"2021-11-24",11,"90.76"),
(95632,13998,65529,"2021-12-02",5 ,"29.40");