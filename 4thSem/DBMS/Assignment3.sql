create database lab3;

use lab3;

create table emp (
    empno int primary key,
    ename varchar(40) not null,
    job char(10) not null,
    mgrnum int not null,
    hiredate date not null,
    sal int,
    comm int
);

create table dept (
    deptno int primary key,
    dname varchar(30) not null,
    loc varchar(40) not null
);

INSERT INTO dept (deptno, dname, loc) VALUES (10, 'ACCOUNTING', 'NEW YORK');
INSERT INTO dept (deptno, dname, loc) VALUES (20, 'RESEARCH', 'DALLAS');
INSERT INTO dept (deptno, dname, loc) VALUES (30, 'SALES', 'CHICAGO');
INSERT INTO dept (deptno, dname, loc) VALUES (40, 'OPERATIONS', 'BOSTON');

alter table emp add column deptno int, add foreign key (deptno) references dept(deptno);

INSERT INTO emp (empno, ename, job, mgrnum, hiredate, sal, comm, deptno) 
VALUES (1001, 'JOHN SMITH', 'MANAGER', 7839, '2020-01-10', 5000, NULL, 10);

INSERT INTO emp (empno, ename, job, mgrnum, hiredate, sal, comm, deptno) 
VALUES (1002, 'SALLY JONES', 'CLERK', 1001, '2021-03-15', 2500, NULL, 20);

INSERT INTO emp (empno, ename, job, mgrnum, hiredate, sal, comm, deptno) 
VALUES (1003, 'MIKE WILLIAMS', 'SALESMAN', 1001, '2019-11-20', 3000, 500, 30);

INSERT INTO emp (empno, ename, job, mgrnum, hiredate, sal, comm, deptno) 
VALUES (1004, 'KAREN DAVIS', 'ANALYST', 1001, '2022-06-05', 4000, NULL, 20);

INSERT INTO emp (empno, ename, job, mgrnum, hiredate, sal, comm, deptno) 
VALUES (1005, 'JAMES MILLER', 'SALESMAN', 1003, '2023-09-01', 2800, 300, 30);



