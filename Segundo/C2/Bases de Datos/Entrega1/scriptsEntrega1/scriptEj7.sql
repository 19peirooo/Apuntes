use classicmodels;

select 
	CONCAT(e.firstName,' ',e.lastName) as empleado,
	CONCAT(m.firstName,' ',m.lastName) as jefe
from employees e left join employees m on e.reportsTo = m.employeeNumber;
