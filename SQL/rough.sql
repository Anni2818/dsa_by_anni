-- commad to dispay all the databases in the system
show databases;

-- create a database
create database db_name;

-- shift to any db 
use db_name;

-- create table
create table student(
    stud_id int primary key,
    name varchar(50) not null
);

-- insert into table 
insert into student values(1,"Anni");

-- show all the data 
select * from student;

-- var vs varchar 
-- var assigns fixed space for the input and the space may be wasted
-- varchar adjusts the assignment of the space optimally according to the need 

-- BOLB = binary large object stores the large binary data mainly images and videos

-- signed tinyint => -128 to 127
-- unsigned tinyint => 0 to 255

-- even json can be a datatype in sql

-- order of execution is always from right to left
-- we can use select statement without the from clause....  in the dummy tables
-- eg => we can use commands like 'select now()' ,etc.


-- for between keyword the limits are inclusive
-- is between nastay te fakt between astay

-- in keyword for replacing the multiple OR's

-- patterns => % is like * which means all
--             _ is for one char only

-- ORDER BY is used for sorting the data in our desired way

-- we can group the data by using the group by clause.
-- this is used along with the aggregation functions which are: (count,sum,avg,min,max,etc.)
-- generally the practice is to give the column names before the from keyword and at the end of the query as well
-- eg. => select dep,name from worker group by dep,name; 
-- when aggregation applied the table is rearranged then further processing is done.


-- ################ IMPORTANT #########
-- MAX(salary) is an aggregate function, but you are trying to use it inside the WHERE clause.
-- SQL doesn’t allow that, because WHERE is applied before grouping/aggregation.

-- HAVING :
-- it is used for filtering like where, but only when group by is used 

-- where vs having :
