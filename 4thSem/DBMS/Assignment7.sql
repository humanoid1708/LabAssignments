CREATE DATABASE lab7;

USE lab7;

CREATE TABLE Zipcode (
    zip INT PRIMARY KEY,
    city VARCHAR(100) NOT NULL
);


CREATE TABLE Customer (
    cno INT PRIMARY KEY,
    cname VARCHAR(100) NOT NULL,
    street VARCHAR(255),
    zip INT,
    phno VARCHAR(20),
    FOREIGN KEY (zip) REFERENCES Zipcode(zip)
);


INSERT INTO Zipcode (zip, city) VALUES
(10001, 'New York'),
(20002, 'Washington DC'),
(30303, 'Atlanta'),
(60606, 'Chicago'),
(94105, 'San Francisco');


INSERT INTO Customer (cno, cname, street, zip, phno) VALUES
(1, 'Alice', '123 Main St', 10001, '123-456-7890'),
(2, 'Bob', '456 Elm St', 20002, '234-567-8901'),
(3, 'Charlie', '789 Oak St', 30303, '345-678-9012'),
(4, 'David', '101 Pine St', 60606, '456-789-0123'),
(5, 'Eve', '202 Birch St', 94105, '567-890-1234');


DELIMITER //

CREATE FUNCTION GetCustomerCity(cust_no INT) 
RETURNS VARCHAR(100) 
DETERMINISTIC
BEGIN
    DECLARE customer_city VARCHAR(100);
    
    SELECT z.city INTO customer_city
    FROM Customer c
    JOIN Zipcode z ON c.zip = z.zip
    WHERE c.cno = cust_no;
    
    RETURN customer_city;
END //

DELIMITER ;
