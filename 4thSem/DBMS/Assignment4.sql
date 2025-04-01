create database work

use work;

create table employee (
    empname varchar(30) primary key,
    street varchar(30),
    city varchar(20) not null
);

create table works(
    empname varchar(30) primary key,
    compname varchar(20) not null,
    salary int not null
);

create table company (
    compname varchar(20) primary key,
    city varchar(20) not null
);

create table manages (
    empname varchar(30) primary key,
    mgrname varchar(40)
);

INSERT INTO employee (empname, street, city) VALUES 
('John Doe', '123 Maple St', 'New York'),
('Alice Smith', '456 Oak Ave', 'Chicago'),
('Bob Johnson', '789 Pine Rd', 'Los Angeles'),
('Sara Lee', '321 Cedar Blvd', 'Boston');

INSERT INTO company (compname, city) VALUES 
('TechCorp', 'New York'),
('HealthInc', 'Chicago'),
('EduSoft', 'Boston');

INSERT INTO works (empname, compname, salary) VALUES 
('John Doe', 'TechCorp', 60000),
('Alice Smith', 'HealthInc', 55000),
('Bob Johnson', 'TechCorp', 62000),
('Sara Lee', 'EduSoft', 50000);

INSERT INTO manages (empname, mgrname) VALUES 
('John Doe', 'Michael Scott'),
('Alice Smith', 'Leslie Knope'),
('Bob Johnson', 'Michael Scott'),
('Sara Lee', 'Donna Paulsen');

SELECT empname
FROM works
WHERE compname = 'First Bank Corporation';

SELECT empname
FROM works
WHERE compname <> 'First Bank Corporation';

SELECT compname
FROM works
GROUP BY compname
ORDER BY COUNT(empname) DESC
LIMIT 1;

SELECT DISTINCT c1.compname
FROM company c1
WHERE NOT EXISTS (
    SELECT city
    FROM company c2
    WHERE c2.compname = 'Small Bank Corporation'
    AND NOT EXISTS (
        SELECT *
        FROM company c3
        WHERE c3.compname = c1.compname AND c3.city = c2.city
    )
);

SELECT *
FROM works
WHERE salary > 10000;

UPDATE works
SET salary = salary * 1.10
WHERE compname = 'First Bank Corporation';

SELECT e.empname, m.mgrname
FROM employee e
JOIN manages m ON e.empname = m.empname;

SELECT e.empname, e.street, e.city
FROM employee e
JOIN works w ON e.empname = w.empname
WHERE w.compname = 'First Bank Corporation' AND w.salary > 10000;

SELECT DISTINCT w.compname
FROM works w
WHERE w.salary > (
    SELECT AVG(salary)
    FROM works
    WHERE compname = 'First Bank Corporation'
);
