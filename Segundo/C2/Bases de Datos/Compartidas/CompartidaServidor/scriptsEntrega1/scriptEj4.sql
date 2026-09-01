use university;

select s.building, s.room_number 
from section s 
where year = 2018 
group by s.building, s.room_number
order by count(s.course_id) desc
limit 1;
