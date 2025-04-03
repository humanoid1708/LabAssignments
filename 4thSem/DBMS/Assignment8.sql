create database if not exists lab8;
use lab8;

CREATE TABLE Highschooler (
    ID INT PRIMARY KEY,
    name TEXT,
    grade INT
);

CREATE TABLE Friend (
    ID1 INT,
    ID2 INT,
    PRIMARY KEY (ID1, ID2),
    FOREIGN KEY (ID1) REFERENCES Highschooler(ID),
    FOREIGN KEY (ID2) REFERENCES Highschooler(ID)
);

CREATE TABLE Likes (
    ID1 INT,
    ID2 INT,
    PRIMARY KEY (ID1, ID2),
    FOREIGN KEY (ID1) REFERENCES Highschooler(ID),
    FOREIGN KEY (ID2) REFERENCES Highschooler(ID)
);

INSERT INTO Highschooler (ID, name, grade) VALUES
(1, 'Alice', 10),
(2, 'Bob', 11),
(3, 'Charlie', 12),
(4, 'David', 10);

INSERT INTO Friend (ID1, ID2) VALUES
(1, 2),
(2, 1),
(2, 3),
(3, 2);

CREATE TRIGGER Insert_Friend_Symmetry
AFTER INSERT ON Friend
FOR EACH ROW
BEGIN
    IF NOT EXISTS (SELECT * FROM Friend WHERE ID1 = NEW.ID2 AND ID2 = NEW.ID1) THEN
        INSERT INTO Friend (ID1, ID2) VALUES (NEW.ID2, NEW.ID1);
    END IF;
END;

CREATE TRIGGER Delete_Friend_Symmetry
AFTER DELETE ON Friend
FOR EACH ROW
BEGIN
    DELETE FROM Friend WHERE ID1 = OLD.ID2 AND ID2 = OLD.ID1;
END;
