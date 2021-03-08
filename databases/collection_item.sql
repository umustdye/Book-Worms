BEGIN TRANSACTION;
DROP TABLE IF EXISTS "collection_item";
CREATE TABLE IF NOT EXISTS "collection_item" (
	"id"	INTEGER PRIMARY KEY AUTOINCREMENT,
	"title"	TEXT,
	"description"	TEXT,
	"type"	TEXT,
	"foreignkey"	INTEGER
);
INSERT INTO "collection_item" ("id","title","description","type","foreignkey") VALUES (1,'The Hunger Games','Katniss Everdeen voluntarily takes her younger sister''s place in the Hunger Games: a televised competition in which two teenagers from each of the twelve Districts of Panem are chosen at random to fight to the death. ','Book',1),
 (2,'The Hunger Games: Catching Fire','Katniss Everdeen and Peeta Mellark become targets of the Capitol after their victory in the 74th Hunger Games sparks a rebellion in the Districts of Panem. ','Book',1),
 (3,'The Hunger Games: Mockingjay','Katniss Everdeen is in District 13 after she shatters the games forever. Under the leadership of President Coin and the advice of her trusted friends, Katniss spreads her wings as she fights to save Peeta and a nation moved by her courage. Katniss and a team of rebels from District 13 prepare for the final battle that will decide the fate of Panem. ','Book',1),
 (4,'Spider-Man','When bitten by a genetically modified spider, a nerdy, shy, and awkward high school student gains spider-like abilities that he eventually must use to fight evil as a superhero after tragedy befalls his family. ','DVD',2),
 (5,'Spider-Man 2','Peter Parker is beset with troubles in his failing personal life as he battles a brilliant scientist named Doctor Otto Octavius. ','DVD',2),
 (6,'Spider-Man 3','A strange black entity from another world bonds with Peter Parker and causes inner turmoil as he contends with new villains, temptations, and revenge. ','DVD',2),
 (7,'Sempiternal','Sempiternal is the fourth studio album by British rock band Bring Me the Horizon.','CD',3),
 (8,'That''s the Spirit','That''s the Spirit is the fifth studio album by British rock band Bring Me the Horizon.','CD',3);
COMMIT;
