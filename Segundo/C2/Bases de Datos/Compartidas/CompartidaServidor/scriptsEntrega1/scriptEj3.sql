use university;

select dept_name 
from instructor i 
group by dept_name 
order by COUNT(i.ID) desc 
limit 1;
