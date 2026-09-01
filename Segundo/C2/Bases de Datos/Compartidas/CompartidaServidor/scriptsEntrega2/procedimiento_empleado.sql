DELIMITER //

USE classicmodels

DROP PROCEDURE IF EXISTS Cruzar_Info_Empleado_Oficina;

CREATE PROCEDURE Cruzar_Info_Empleado_Oficina(
    IN empNumber INT,
    OUT empNum INT,
    OUT fName VARCHAR(50),
    OUT lName VARCHAR(50),
    OUT emailAddr VARCHAR(100),
    OUT jobTitle VARCHAR(50),
    OUT officeCity VARCHAR(50),
    OUT officeCountry VARCHAR(50)
)
BEGIN
    SELECT 
        e.employeeNumber, e.firstName, e.lastName, e.email, e.jobTitle,
        o.city, o.country
    INTO 
        empNum, fName, lName, emailAddr, jobTitle, officeCity, officeCountry
    FROM 
        employees e
    JOIN 
        offices o ON e.officeCode = o.officeCode
    WHERE 
        e.employeeNumber = empNumber;
END //

DELIMITER ;
