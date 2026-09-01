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

