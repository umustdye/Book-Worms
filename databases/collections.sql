BEGIN TRANSACTION;
DROP TABLE IF EXISTS "collections";
CREATE TABLE IF NOT EXISTS "collections" (
	"id"	INTEGER PRIMARY KEY AUTOINCREMENT,
	"title"	TEXT,
	"description"	TEXT,
	"quantity"	INTEGER,
	"genre"	TEXT,
	"year"	INTEGER
);
INSERT INTO "collections" ("id","title","description","quantity","genre","year") VALUES (1,'The Hunger Games','Katniss Everdeen voluntarily takes her younger sister''s place in the Hunger Games: a televised competition in which two teenagers from each of the twelve Districts of Panem are chosen at random to fight to the death. ',22,'Adventure, Fantasy',2010),
 (2,'Spider-Man','When bitten by a genetically modified spider, a nerdy, shy, and awkward high school student gains spider-like abilities that he eventually must use to fight evil as a superhero after tragedy befalls his family. ',4,'Adventure, Fantasy',2007),
 (3,'Bring Me The Horizon 2013-15','Bring Me the Horizon are a British rock band formed in Sheffield in 2004. The group consists of lead vocalist Oliver Sykes, guitarist Lee Malia, bassist Matt Kean, drummer Matt Nicholls and keyboardist Jordan Fish.',7,'Metalcore',2015);
COMMIT;
