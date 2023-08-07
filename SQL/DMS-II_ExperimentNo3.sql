create table employee
	(
		eid int,
		name varchar(255),
		department varchar(50)
	);

INSERT INTO employee VALUES(1,'A','HR');
INSERT INTO employee VALUES(2,'B','Engineer');
INSERT INTO employee VALUES(3,'C','HOD');
INSERT INTO employee VALUES(4,'D','Management');
INSERT INTO employee VALUES(5,'E','HR');

SELECT * FROM employee;

CREATE SEQUENCE s1
start with 1
increment by 1
minvalue 0
maxvalue 100
cycle;

INSERT INTO employee VALUES(s1.nextval,'F','Engineer');
INSERT INTO employee VALUES(s1.nextval,'G','HOD');

SELECT * FROM employee;