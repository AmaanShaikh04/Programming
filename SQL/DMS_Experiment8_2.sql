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


Insert into EMP
Select * from EMP where Id in 
(Select Id from EMP where Salary > 70000);

Select * from EMP;