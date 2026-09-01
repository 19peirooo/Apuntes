use classicmodels;

select c.customerNumber, c.customerName, COUNT(p.customerNumber) as cantidad_pagos
from customers c left join payments p on p.customerNumber = c.customerNumber
group by c.customerNumber, c.customerName
order by cantidad_pagos desc 
limit 5;
