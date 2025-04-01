create database lab2;

use lab2;

create table suppliers (
    Sno int primary key,
    Name varchar(25) not null,
    Status varchar(15) not null,
    City varchar(30)
);

create table parts (
    Pno int primary key,
    Pname varchar(25) not null,
    Color varchar(25),
    Weight varchar(15) not null,
    City varchar(30)
);

create table projects (
    Jno int primary key,
    Jname varchar(25) not null,
    City varchar(30)
);

create table shipments (
    Sno int unique,
    Pno int unique,
    Jno int unique,
    qty int not null,
    foreign key (Sno) references suppliers(Sno),
    foreign key (Pno) references parts(Pno),
    foreign key (Jno) references projects(Jno)
);

desc suppliers;
desc parts;
desc projects;
desc shipments;