create table movie(
mov_id int,
mov_name varchar(255),
rel_yr int,
act_id int,
dir_id int
);

create table actor(
act_id int,
name varchar (255),
dob int,
addr varchar (255)
);

insert into movie values(1,'Wolf of Wall Street',2013,101,102);
insert into movie values(2,'Inception',2010,101,103);
insert into movie values(3,'Back to the Future',1985,102,104);
insert into movie values(4,'El Camino',2019,103,105);

insert into actor values(101,'Leonardo DiCaprio',20130815,'Mumbai');
insert into actor values(101,'Leonardo DiCaprio',20130815,'Mumbai');
insert into actor values(102,'Micheal J. Fox',19850720,'NYC');
insert into actor values(103,'Aaron Paul',20190904,'Pune');

SELECT * from movie;
SELECT * from actor;

SELECT movie.mov_id, movie.mov_name, movie.rel_yr, actor.name from 
movie join actor on movie.act_id = actor.act_id;