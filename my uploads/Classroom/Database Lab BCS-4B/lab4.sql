
create table hotel(
hotelno varchar(10) primary key,
hotelname varchar(20),
city varchar(20),
)

insert into hotel values('fb01', 'Grosvenor', 'London');
insert into hotel values('fb02', 'Watergate', 'Paris');
insert into hotel values('ch01', 'Omni Shoreham', 'London');
insert into hotel values('ch02', 'Phoenix Park', 'London');
insert into hotel values('dc01', 'Latham', 'Berlin');

 -- create a table named hotel

 create table room(

roomno numeric(5),
hotelno varchar(10),
type varchar(10),
price decimal(5,2),
primary key (roomno, hotelno),
foreign key (hotelno) REFERENCES hotel(hotelno)
)

insert into room values(501, 'fb01', 'single', 19);
insert into room values(601, 'fb01', 'double', 29);
insert into room values(701, 'fb01', 'family', 39);
insert into room values(1001, 'fb02', 'single', 58);
insert into room values(1101, 'fb02', 'double', 86);
insert into room values(1001, 'ch01', 'single', 29.99);
insert into room values(1101, 'ch01', 'family', 59.99);
insert into room values(701, 'ch02', 'single', 10);
insert into room values(801, 'ch02', 'double', 15);
insert into room values(901, 'dc01', 'single', 18);
insert into room values(1001, 'dc01', 'double', 30);
insert into room values(1101, 'dc01', 'family', 35);

create table guest(
guestno numeric(5),
guestname varchar(20),
guestaddress varchar(50),
primary key (guestno)
)

insert into guest values(10001, 'John Kay', '56 High St, London');
insert into guest values(10002, 'Mike Ritchie', '18 Tain St, London');
insert into guest values(10003, 'Mary Tregear', '5 Tarbot Rd, Aberdeen');
insert into guest values(10004, 'Joe Keogh', '2 Fergus Dr, Aberdeen');
insert into guest values(10005, 'Carol Farrel', '6 Achray St, Glasgow');
insert into guest values(10006, 'Tina Murphy', '63 Well St, Glasgow');
insert into guest values(10007, 'Tony Shaw', '12 Park Pl, Glasgow');

create table booking(
hotelno varchar(10),
guestno numeric(5),
datefrom date,
dateto date,
roomno numeric(5),
primary key (hotelno, guestno, datefrom),
foreign key (roomno, hotelno) REFERENCES room(roomno, hotelno),
foreign key (guestno) REFERENCES guest(guestno)
)

 

insert into booking values('fb01', 10001, '04-04-01', '04-04-08', 501);
insert into booking values('fb01', 10004, '04-04-15', '04-05-15', 601);
insert into booking values('fb01', 10005, '04-05-02', '04-05-07', 501);
insert into booking values('fb01', 10001, '04-05-01', null, 701);
insert into booking values('fb02', 10003, '04-04-05', '10-04-04', 1001);
insert into booking values('ch01', 10006, '04-04-21', null, 1101);
insert into booking values('ch02', 10002, '04-04-25', '04-05-06', 801);
insert into booking values('dc01', 10007, '04-05-13', '04-05-15', 1001);
insert into booking values('dc01', 10003, '04-05-20', null, 1001);


-- q1

select h.hotelno,h.hotelname 
from hotel h
where h.city = 'London'
order by h.hotelname desc;

-- q2

select h.hotelno,h.hotelname 
from hotel h
where h.hotelname like '__t%';

-- q3

select b.hotelno,b.guestno,b.roomno
from booking b
where b.dateto is NULL;

--q4

select g.guestname,g.guestaddress
from guest g
where (g.guestname like 'Tony%') or (g.guestname like '%Farrel');

-- q5

select b.roomno,b.hotelno
from booking b
where b.datefrom >= '2005-01-01' and b.datefrom <= '2010-12-31';

-- q6

select r.roomno
from room r join hotel h on r.hotelno = h.hotelno
where h.hotelno like '%01' and r.type = 'single' and r.price>=20 and r.price<=40;

-- q7

select roomno,hotelno
from room 
where price = (select max(price) from room)
group by roomno,hotelno;


--q8

select h.city, count(*) 'Number of Guests'
from booking b left join hotel h on b.hotelno = h.hotelno
group by h.city;

--q9

select b.guestno
from booking b
where b.datefrom <= '2023-02-24'
intersect
select b.guestno
from booking b
where b.dateto is NULL;

--q10

select r.hotelno
from room r
where type = 'double'
intersect
select r.hotelno
from room r
where type = 'family';

--q11

(select r.hotelno
from room r
where type = 'double'
intersect
select r.hotelno
from room r
where type = 'single')
except
select r.hotelno
from room r
where type = 'family';

--q12

select b.roomno
from booking b 
where b.guestno = 10003 or b.guestno = 10007
except
select b.roomno
from booking b 
where b.guestno = 10001;

--q13

select h.hotelname,h.city
from hotel h join room r on h.hotelno = r.hotelno
group by h.hotelname,h.city
having sum(price)>50.00;

--q14

select h.hotelno,h.hotelname, count(r.roomno) 'Number of Rooms'
from hotel h join room r on h.hotelno = r.hotelno
group by h.hotelno,h.hotelname;


--q15

select g.guestno,g.guestname
from guest g
where g.guestname like 'j%' or g.guestname like 'm%';

--q16

select top 5 b.roomno,b.hotelno, r.type,r.price
from booking b join room r on (r.roomno = b.roomno and r.hotelno = b.hotelno);






