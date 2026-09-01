use university;

select i.ID, i.name, count(t.course_id) as num_asignaturas
from instructor i left join teaches t on t.ID = i.ID
group by i.ID, i.name
order by num_asignaturas desc;
