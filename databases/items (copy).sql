BEGIN TRANSACTION;
DROP TABLE IF EXISTS "items";
CREATE TABLE IF NOT EXISTS "items" (
	"id"	INTEGER PRIMARY KEY AUTOINCREMENT,
	"title"	TEXT,
	"name"	TEXT,
	"year"	INTEGER,
	"length"	INTEGER,
	"genre"	TEXT,
	"quantity"	INTEGER,
	"description"	TEXT
);
INSERT INTO "items" ("id","title","name","year","length","genre","quantity","description") VALUES (1,'The Hobbit','JRR Tolkien',1937,320,'Fantasy',17,'The Hobbit is set within Tolkien''s fictional universe and follows the quest of home-loving Bilbo Baggins, the titular hobbit, to win a share of the treasure guarded by Smaug the dragon. Bilbo''s journey takes him from light-hearted, rural surroundings into more sinister territory.'),
 (2,'1984','George Orwell',1949,292,'Fiction',20,'1984 is a dystopian novella by George Orwell published in 1949, which follows the life of Winston Smith, a low ranking member of ''the Party'', who is frustrated by the omnipresent eyes of the party, and its ominous ruler Big Brother. ''Big Brother'' controls every aspect of people''s lives.'),
 (3,'The Hitchhiker''s Guide to the Galaxy','Douglas Adams',1979,208,'Fiction',42,'The Hitchhiker''s Guide to the Galaxy is a fictional electronic guide book in the multimedia scifi/comedy series of the same name by Douglas Adams. The Guide serves as "the standard repository for all knowledge and wisdom" for many members of the series'' galaxy-spanning civilization.'),
 (4,'Airplane!','Jim Abrahms',1980,88,'Comedy',73,'A man afraid to fly must ensure that a plane lands safely after the pilots become sick.'),
 (5,'Alien','Ridley Scott',1979,117,'Horror',22,'After a space merchant vessel receives an unknown transmission as a distress call, one of the crew is attacked by a mysterious life form and they soon realize that its life cycle has merely begun.'),
 (6,'Back to the Future','Robert Zemeckis',1985,116,'Sci-Fi',85,'Marty McFly, a 17-year-old high school student, is accidentally sent thirty years into the past in a time-traveling DeLorean invented by his close friend, the eccentric scientist Doc Brown.'),
 (7,'Landmark','Hippo Campus',2017,44,'Indie',5,'Landmark is the first full length album by Hippo Campus. Three singles were released from the album, ''Boyish'' (October 2016), ''Monsoon'' (November 2016) and ''Way It Goes'' (January 2017). The album itself was released on the 24th of February 2017.'),
 (8,'Pray for the Wicked','Panic! At The Disco',2018,34,'Pop rock',12,'Pray for the Wicked is the sixth studio album by American pop rock solo project Panic! at the Disco. The album was released on June 22, 2018 on Fueled by Ramen and DCD2. It is the follow-up to the band''s fifth studio album, Death of a Bachelor.'),
 (9,'Abbey Road','The Beatles',1969,47,'Rock',11,'Abbey Road is the eleventh studio album by the English rock band the Beatles, released on 26 September 1969 by Apple Records.');
COMMIT;
