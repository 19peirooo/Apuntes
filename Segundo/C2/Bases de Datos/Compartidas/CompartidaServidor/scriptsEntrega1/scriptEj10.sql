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
