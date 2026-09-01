DELIMITER //

USE university

CREATE TRIGGER Actualizacion_Presupuesto
BEFORE UPDATE ON department
FOR EACH ROW
BEGIN
    -- Incremento del 5%
    SET NEW.budget = NEW.budget * 1.05;

    -- Impuesto según el nuevo presupuesto
    IF NEW.budget < 80000 THEN
        SET NEW.budget = NEW.budget - 150;
    ELSE
        SET NEW.budget = NEW.budget - 325;
    END IF;
END;
//

DELIMITER ;
