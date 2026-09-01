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
