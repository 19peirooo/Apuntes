-- Resultado Ejercicio 1
use classicmodels;

select * from offices where territory = 'EMEA' and city != 'London';

select ' '; -- Para dejar espacio entre resultados

-- Resultado Ejercicio 3
use university;

select dept_name 
from instructor i 
group by dept_name 
order by COUNT(i.ID) desc 
limit 1;

select ' ';

-- Resultado Ejercicio 4
use university;

select s.building, s.room_number 
from section s 
where year = 2018 
group by s.building, s.room_number
order by count(s.course_id) desc
limit 1;

select ' ';

-- Resultado Ejercicio 5
use university;

select c.course_id, c.title as course_name , c.dept_name
from course c left join section s on c.course_id = s.course_id
where s.course_id is null;

select ' ';

select s.building, s.room_number
from section s
where year = '2018'
group by s.building, s.room_number
order by  count(*) asc
limit 1;

select ' ';

-- Resultado Ejercicio 6
use university;

select i.ID, i.name, count(t.course_id) as num_asignaturas
from instructor i left join teaches t on t.ID = i.ID
group by i.ID, i.name
order by num_asignaturas desc;

select ' ';

-- Resultado Ejercicio 7
use classicmodels;

select 
        CONCAT(e.firstName,' ',e.lastName) as empleado,
        CONCAT(m.firstName,' ',m.lastName) as jefe
from employees e left join employees m on e.reportsTo = m.employeeNumber;

select ' ';

-- Resultado Ejercicio 8
set global local_infile = 1;

use classicmodels;

drop table if exists asignatura;

create table asignatura (
        ID int,
        asignatura varchar(50),
        semestre int,
        creditos float,
        primary key (ID)
);

load data infile '/var/lib/mysql-files/asignatura.csv'
into table asignatura
fields terminated by ';'
enclosed by '"'
lines terminated by '\n'
ignore 1 rows;

select * from asignatura;


select ' ';

-- Resultado Ejercicio 9
use classicmodels;

select c.customerNumber, c.customerName, COUNT(p.customerNumber) as cantidad_pagos
from customers c left join payments p on p.customerNumber = c.customerNumber
group by c.customerNumber, c.customerName
order by cantidad_pagos desc 
limit 5;

select ' ';

-- Resultado Ejercicio 10
use classicmodels;

select p.productName, p.productLine,
	case
		when productLine = 'Classic Cars' then '5%'
		when productLine = 'Planes' then '2%'
		when productLine = 'Motoocycles' then '4%'
		when productLine = 'Ships' then '3%'
		else '6%'
	end as descuento
from products p 
where p.productName = 'HMS Bounty';
