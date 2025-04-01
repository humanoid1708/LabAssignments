-- schema.sql (DDL Commands)
CREATE DATABASE EducationalInstitute;
USE EducationalInstitute;

CREATE TABLE Students (
    StudentID INT PRIMARY KEY AUTO_INCREMENT,
    Name VARCHAR(100),
    Age INT,
    Course VARCHAR(50)
);

CREATE TABLE Courses (
    CourseID INT PRIMARY KEY AUTO_INCREMENT,
    CourseName VARCHAR(100),
    Duration INT -- in months
);

CREATE TABLE Enrollments (
    EnrollmentID INT PRIMARY KEY AUTO_INCREMENT,
    StudentID INT,
    CourseID INT,
    EnrollmentDate DATE,
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID)
);

-- data.sql (DML Commands)
INSERT INTO Students (Name, Age, Course) VALUES ('Alice', 22, 'Computer Science');
INSERT INTO Students (Name, Age, Course) VALUES ('Bob', 24, 'Mathematics');

INSERT INTO Courses (CourseName, Duration) VALUES ('Computer Science', 48);
INSERT INTO Courses (CourseName, Duration) VALUES ('Mathematics', 36);

INSERT INTO Enrollments (StudentID, CourseID, EnrollmentDate) VALUES (1, 1, '2025-03-28');
INSERT INTO Enrollments (StudentID, CourseID, EnrollmentDate) VALUES (2, 2, '2025-03-28');
