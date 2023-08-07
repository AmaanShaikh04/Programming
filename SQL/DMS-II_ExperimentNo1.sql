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

SELECT * from employee;

UPDATE employee

SET salary = salary + (salary * 5/100);

SELECT * from employee;

SELECT * from employee where department = "HR" and salary < 130000;

SELECT * FROM employee;

SELECT eid, name, join_date, salary + 10000, dob, department FROM employee;
   
SELECT eid, name, join_date, salary - 10000, dob, department FROM employee;
   
SELECT eid, name, salary * 100, dob, department FROM employee;
   
SELECT eid, name, salary / 10, dob, department FROM employee;
   
SELECT eid, name, salary % 100, dob, department FROM employee;

SELECT eid, name, join_date, salary, dob, department FROM employee WHERE salary >= 250000 AND salary <= 550000;

SELECT eid, name, join_date, salary, dob, department FROM employee WHERE salary = 75000;

SELECT eid, name, join_date, salary, dob, department FROM employee WHERE NOT salary = 250000
