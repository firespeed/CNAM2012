DROP TABLE ACCA;
DROP TABLE FDC ;

CREATE SEQUENCE seqACCA;

CREATE TABLE FDC(
	fdcDept number not null,
	fdcNumRue varchar(50),
	fdcRue varchar(50),
	fdcCP number(5),
	fdcVille varchar(20),
	primary key (fdcDept) ,
	check (fdcDept BETWEEN 1 AND 92)
);

CREATE TABLE ACCA(
	accaCode number not null,
	accaCommune varchar(50),
	accaMontant varchar(50),
	accaCP number(5),
	accaVille varchar(20),
	fk_fcdDept number not null,
	primary key (accaCode), 
	constraint fk_FDC foreign key  (fk_fcdDept) references FDC(fdcDept) ON DELETE SET NULL,
	CHECK (substr(accaCP,1,2)= fk_fcdDept)
);
-- test constraint check FDC 
--INSERT INTO FDC(fdcDept) VALUES (98);
INSERT INTO FDC(fdcDept) VALUES (91);
INSERT INTO ACCA(accaCode,fk_fcdDept) VALUES (seqACCA.NEXTVAL,91);


--ALTER TABLE FDC 
--ADD CONSTRAINT FDC_check CHECK (fdcDeptBETWEEN 1 AND 92)

ALTER TABLE ACCA 
ADD CONSTRAINT uqacca UNIQUE (accaVille, accaCp);
