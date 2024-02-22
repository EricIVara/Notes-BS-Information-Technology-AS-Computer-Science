----------------------------------------------------------------
-- Create Database
CREATE DATABASE assisnment;


----------------------------------------------------------------
-- Create the three tables

CREATE TABLE tbldvdTitles(
	asin varChar(15) NOT NULL,
    title varChar(100),
    price double(5,2),
	PRIMARY KEY (asin)
);

CREATE TABLE tbldvdActors(
	actorID	int(5) NOT NULL	AUTO_INCREMENT,
	fname varChar(20),
	lname varChar(20),
	PRIMARY KEY (actorID)
);

CREATE TABLE movie_details(
	asin varChar(15) NOT NULL,
	actorID int(5) NOT NULL,
	PRIMARY KEY (asin, actorID)
);


----------------------------------------------------------------
-- Insert Statements

INSERT INTO tbldvdtitles VALUES('B0B5PRNXZM', 'Lightyear', '19.99');
INSERT INTO tbldvdtitles VALUES('2UGXXT2UJBRQX', 'Zootopia', '19.99');
INSERT INTO tbldvdtitles VALUES('B01NCIFSMT', 'Sing 1', '14.99');
INSERT INTO tbldvdtitles VALUES('B09PMSKBSD', 'Sing 2', '19.99');
INSERT INTO tbldvdtitles VALUES('B07T86S72Q', 'Toy Story 4', '19.99');

INSERT INTO tbldvdActors VALUES('12345','Chris','Evans');
INSERT INTO tbldvdActors VALUES('23456','Ginnifer','Goodwin');
INSERT INTO tbldvdActors VALUES('34567','Matthew','McConaughey');
INSERT INTO tbldvdActors VALUES('45678','Matthew','McConaughey');
INSERT INTO tbldvdActors VALUES('56789','Hanks','Tom');

UPDATE tbldvdActors SET fname = 'Tom', lname = 'Hanks' WHERE actorID = '56789';
DELETE FROM tbldvdActors WHERE actorID = '12345';

INSERT INTO movie_details VALUES('2UGXXT2UJBRQX', '23456');
INSERT INTO movie_details VALUES('B01NCIFSMT', '34567');
INSERT INTO movie_details VALUES('B09PMSKBSD', '45678');
INSERT INTO movie_details VALUES('B07T86S72Q', '56789');


----------------------------------------------------------------
-- Joins

-- Join that combine all data from all tables
SELECT * FROM movie_details FULL INNER JOIN tbldvdTitles, tbldvdActors;

-- Join that combines data based on matching values
SELECT movie_details.asin, movie_details.actorID, tbldvdTitles.title, tbldvdTitles.price, tbldvdActors.fname, tbldvdActors.lname
FROM movie_details
INNER JOIN tbldvdTitles ON movie_details.asin = tbldvdTitles.asin
INNER JOIN tbldvdActors ON movie_details.actorID = tbldvdActors.actorID group by asin;


----------------------------------------------------------------
-- Select all Tables

select * from tbldvdTitles;
select * from tbldvdActors;
select * from movie_details;

----------------------------------------------------------------