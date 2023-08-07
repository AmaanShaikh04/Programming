BEGIN TRANSACTION;
/*CREATE A TABLE CALLED EMP*/
CREATE TABLE EMP(
	Id int,
	Name varchar(255),
	Salary int
);

INSERT INTO EMP VALUES(1,'Jonathan','68000');
INSERT INTO EMP VALUES(2,'Joseph','27188');
INSERT INTO EMP VALUES(3,'Jotaro','78676');
INSERT INTO EMP VALUES(4,'Josuke','99772');
INSERT INTO EMP VALUES(5,'Giorno','34532');


Select * from EMP;

CREATE TABLE Dept (
	Id int,
	dept_name varchar(255)
);

INSERT INTO Dept VALUES(1,'Admin');
INSERT INTO Dept VALUES(2,'HR');
INSERT INTO Dept VALUES(3,'Management');
INSERT INTO Dept VALUES(4,'HR');
INSERT INTO Dept VALUES(5,'Management');


Select * from Dept;

Update EMP Set Salary=Salary+10000 where Id in
(Select Id from Dept where dept_name='HR');

Select * from EMP; 