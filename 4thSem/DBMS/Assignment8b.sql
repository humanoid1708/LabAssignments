create database if not exists lab8b;
use lab8b;

-- Book table
create table book (
    isbn int primary key,
    title varchar(50),
    soldcopies int
);

-- Author table
create table author (
    name varchar(50),
    soldcopies int
);

-- Writing table (many-to-many relationship)
create table writing (
    isbn int,
    name varchar(50),
    foreign key (isbn) references book(isbn)
);

-- Insert values into book
insert into book values
(101, 'The Data Journey', 5000),
(102, 'Code Whisperer', 7000),
(103, 'AI for All', 8500);

-- Insert values into author
insert into author values
('Alice Smith', 15000),
('Bob Johnson', 12000),
('Clara Davis', 10000);

-- Insert values into writing
insert into writing values
(101, 'Alice Smith'),
(102, 'Bob Johnson'),
(103, 'Clara Davis'),
(103, 'Alice Smith');  -- co-authored


delimiter //
create trigger update_soldcopy
after update on book
for each row 
BEGIN
    if exists(select soldcopies from book where book.soldcopies <> author.soldcopies) then update table author set soldcopies = book.soldcopies where book.soldcopies <> author.soldcopies;
    end if;
end;
//
delimiter ;
