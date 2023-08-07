create table employee
	(
		eid int,
		name varchar(255),
		join_date varchar(15),
		salary int,
		dob varchar(15),
		department varchar(50)
	);

INSERT INTO employee VALUES(101,'A','21/02/2021',250000,'09/01/1997','HR');
INSERT INTO employee VALUES(102,'B','23/05/2019',550000,'19/03/1996','Engineer');
INSERT INTO employee VALUES(103,'C','04/10/2020',400000,'26/04/1989','HOD');
INSERT INTO employee VALUES(104,'D','09/02/2021',250000,'24/12/1983','Management');
INSERT INTO employee VALUES(105,'E','23/09/2021',75000,'06/11/1999','HR');

SELECT * FROM employee;

DELETE FROM employee WHERE salary <=250000;
COMMIT;

SELECT * FROM employee;

DELETE FROM employee WHERE salary = 75000;
ROLLBACK;

SAVEPOINT A;
DELETE FROM employee WHERE eid=101;

SAVEPOINT B;
DELETE FROM employee WHERE eid=103;

SAVEPOINT C;
DELETE FROM employee WHERE eid=105;

SELECT * FROM employee;
