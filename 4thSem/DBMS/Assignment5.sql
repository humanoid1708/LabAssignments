create database position;

use position;

create table employee(
    empno int primary key,
    name varchar(30) not null,
    skill varchar(10),
    payrate int not null
);

create table position(
    postingno int primary key,
    skill varchar(10) not null
);

create table dutyallocation(
    postingno int,
    empno int,
    day date not null,
    shift varchar(20) not null,
    foreign key (postingno) references position(postingno)
    foreign key (empno) references employee(empno)
);


INSERT INTO employee (empno, name, skill, payrate) VALUES
(123459, 'Alice', 'Chef', 3000),
(123460, 'Bob', 'Waiter', 2500),
(123461, 'Charlie', 'Chef', 3200),
(123462, 'David', 'Manager', 5000),
(123463, 'Eva', 'Chef', 3100),
(123464, 'Frank', 'Waiter', 2600),
(123465, 'Grace', 'Chef', 2900);

INSERT INTO position (postingno, skill) VALUES
(201, 'Chef'),
(202, 'Waiter'),
(203, 'Chef'),
(204, 'Manager');

INSERT INTO dutyallocation (postingno, empno, day, shift) VALUES
(201, 123459, '2025-03-25', 'Morning'),
(201, 123461, '2025-03-25', 'Evening'),
(203, 123461, '2025-03-26', 'Night'),
(202, 123460, '2025-03-25', 'Morning'),
(204, 123462, '2025-03-26', 'Night'),
(203, 123463, '2025-03-26', 'Morning'),
(201, 123463, '2025-03-27', 'Evening'),
(202, 123464, '2025-03-27', 'Night'),
(201, 123465, '2025-03-28', 'Morning');

