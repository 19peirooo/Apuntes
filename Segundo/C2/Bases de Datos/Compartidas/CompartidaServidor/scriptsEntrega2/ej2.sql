
DROP ROLE IF EXISTS 'rol_adm_instructor';
DROP ROLE IF EXISTS 'rol_con_student';
DROP USER IF EXISTS 'user_1A'@'localhost';
DROP USER IF EXISTS 'user_2B'@'localhost';


-- Apartado 1
create role 'rol_adm_instructor';
grant all privileges on university.instructor to 'rol_adm_instructor';

create user 'user_1A'@'localhost' identified by 'user_1!';
grant 'rol_adm_instructor' to 'user_1A'@'localhost';

set default role 'rol_adm_instructor' to 'user_1A'@'localhost';

-- Apartado 2
create role 'rol_con_student';
grant usage on university.* to 'rol_con_student';
grant select (name,tot_cred) on university.student to 'rol_con_student';

create user 'user_2B'@'localhost' identified by 'user_2!';
grant 'rol_con_student' to 'user_2B'@'localhost';

set default role 'rol_con_student' to 'user_2B'@'localhost';

-- Apartado 3
use university;
-- Con user_1A: 
-- select * from instructor;
-- select name,tot_cred from student;

-- Con user_2B
-- select * from student
-- select name,tot_cred from student