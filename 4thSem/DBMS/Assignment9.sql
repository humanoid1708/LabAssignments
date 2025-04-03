create database if not exists lab9;
use lab9;

CREATE TABLE Customer (
    cust_id INT PRIMARY KEY,
    Principal_amount DECIMAL(10,2),
    Rate_of_interest DECIMAL(5,2),
    No_of_Years INT
);

CREATE TABLE TEMPLIST (
    cust_id INT,
    Simple_Interest DECIMAL(10,2)
);

INSERT INTO Customer (cust_id, Principal_amount, Rate_of_interest, No_of_Years) VALUES
(1, 10000, 5, 2),
(2, 15000, 4.5, 3),
(3, 20000, 6, 1);


DELIMITER $$

CREATE PROCEDURE Calculate_Interest()
BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE v_cust_id INT;
    DECLARE v_Principal DECIMAL(10,2);
    DECLARE v_Rate DECIMAL(5,2);
    DECLARE v_Years INT;
    DECLARE v_SimpleInterest DECIMAL(10,2);
    DECLARE v_CompoundInterest DECIMAL(10,2);

    DECLARE cur CURSOR FOR 
    SELECT cust_id, Principal_amount, Rate_of_interest, No_of_Years FROM Customer;


    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

    OPEN cur;

    read_loop: LOOP
        FETCH cur INTO v_cust_id, v_Principal, v_Rate, v_Years;
        IF done THEN
            LEAVE read_loop;
        END IF;

        SET v_SimpleInterest = (v_Principal * v_Rate * v_Years) / 100;

        SET v_CompoundInterest = v_Principal * POW((1 + v_Rate / 100), v_Years) - v_Principal;

        INSERT INTO TEMPLIST (cust_id, Simple_Interest) VALUES (v_cust_id, v_SimpleInterest);

        SELECT v_cust_id AS Customer_ID, v_CompoundInterest AS Compound_Interest;
    END LOOP;

    CLOSE cur;
END $$

DELIMITER ;
