-- Database : Database is a collection of data in a format that can be easily accessed digitally, and a software application used to manage our database is called DBMS (Database Management System)
-- So actually what happens is that jo user hota hai vo directly DB se interact nhi krta vo pehle DBMS se interact krta hai, then vo DB se interact krta hai and then DBMS uske according actions perform krke deta hai user ko!
-- And here the SQL language is used to interact with DBMS!

-- Types of Databases! : Relational Database and Non-Relational Database
-- Relational Database is where the data is stored in form of tables! Example of Relational DBMS are MySQL, PostgreSQL, SQL Server, Oracle, these DBMS works on relational databases and it stores the data in form of tables and we use the SQL language to access these DBMS!
-- Non-Relational Database is where the data is not stored in form of tables! and a good example of this is MongoDB DBMS!

-- SQL : Structured Query Language!
-- SQL is a programming language used to interact with Relational Databases!
-- And it is used to perform CRUD operations : Create Read Update Delete!
-- Pehle jab IBM ne SQL banaya tha tab iska naam SQL nhi SEQUEL tha which means Structured English Query Language but then now it is SQL!

Create Database College; -- This will create a database name a college and syntax can be totally capital or totally small!
Create Database temp1; -- Created a temporary database, now we will remove it in the next line!
Drop Database temp1; -- Database deleted

Use College; -- Now we will use the college database to create a table
-- Creating a table named as Student and designing its columns and naming them id, name and age, and then id me kis tarah ka datatype store hoga vo uske side me likh diya and then humne usko side me likha hua hai primary key (ye aage padhenge), then neeche name ke aage likha hua hai varchar (jo again aage padhenge) and then uske neeche likha hua hai age int not null, means not null ka mtlb ki ye column null nhi hoga, mtlb khaali nhi hoga kyunki ofc age kuch toh hogi hi!
create table Student (
	id int primary key,
    name varchar(50),
    age int not null
);

-- Then yahaa we have inserted values into the table!
Insert into Student values(1, "Utkarsh", 20);
Insert into Student values(2, "Kinshuk", 21);

-- Then here we have displayed the table using the select * from operation!
Select * from Student;

-- ------------------------------------------------------------------------------------------------------------------------------------->
-- Diving deep into all of the above!
-- SQL Datatypes :
	-- 1) Char -> String(0-255), can store characters upto a fixed length, like agar humne char(50) likh diya toh mtlb humari computer memory me 50 characters ko store krne jitni memory alot hojayegi and then bhale hi hume store sirf 4 characters ka data hi store kyu na kraana ho, but still 50 jitni memory rahegi and isse vo saari memory waste hojayegi!
    -- 2) Varchar -> String(0-255), can store characters upto some given length, and here it solves the prblm of memory wastage in the char datatype, jitne characters store krne hai utni hi memory alot hogi! and max limit hum daal sakte hai varchar(50) means 50 characters jitni memory ki zarurat pad sakti hai, pr agar kam memory me kaam hojaye toh remaining ko free krdena!
    -- 3) Blob -> string(0-65535), can store binary large objects! like images, multi-media and all!
    -- 4) Int -> integer(-2,147,483,648 - 2,147,483,648), can store integer values
    -- 5) Tinyint -> integer(-128 - 127), can store integer vaues upto this only
    -- 6) Bigint -> integer(-9,223,372,036,854,775,808 - 9,223,372,036,854,775,807), Can store this big of the values
    -- 7) Float -> Can store decimal numbers with precision upto 23 digits!
    -- 8) Double -> Can store decimal numbers with precision upto 24 - 53 digits!
    -- 9) Boolean -> Boolean values like 0 and 1, and generally we use the int datatype to store the boolean values!
    -- 10) Date -> we can store the date in the format of YYYY-MM-DD ranging from 1000-01-01 to 9999-12-31
    -- 11) Year -> year ranging from 1901 - 2155

-- Now there are some extra datatypes operations like Signed and Unsigned, where if some datatype is marked as signed means it can store negative as well as positive values but if it is marked as unsigned then it will always be positive!
-- So example : Like as we know that tinyint contains only values upto -128 to 127, but what if we want to store 129, we can't but to solve this we will use tinyint unsigned and now it will range from 0 to 255! and now we can store 129 using tinyint unsigned!

-- SQL Commands, there are 5 types of SQL commands! these 5 types are : DDL(Data Definition Language), DQL(Data Query Language), DML(Data Manipulation Language), DCL(Data Control Language) and TCL(Transaction Control Language)
-- DDL Commands are : Create, Alter, Rename, Truncate and Drop!
-- DQL Commands are : Select
-- DML Commands are : Insert, Update and Delete
-- DCL Commands are : Grant or Revoke permissions to the user!
-- TCL Commands are : Start transaction, commit and rollback

-- Performing some operations now!
-- Create Database College; -- This line will show error, bez already created hai ek database college naam se! so we will use "if not exist" command
Create Database if not exists College; -- This will throw a warning that ek baar already create ho chuka hai ye db! pr error nhi ayega! and similarly...
Create Database Temp1;
Drop database if exists Temp1; -- Isse agar koi temp1 naam ka db hai tab hi vo delet hoga vrna nhi! and again isse warning ayegi error nhi! which is a good thing!
Show Databases; -- It will display all the database present in the server!
Show Tables; -- It will display all the tables present in the database used!

-- Table Related Queries!
-- Create :
drop table Student; -- Dropped the previous student table so that begin from the starting, at this point we have created a database named as college and we are using it to create a table named student!
create table Student (
	rollno int primary key,
    name varchar(50)
);

-- Select :
Select * from Student;

-- Insert :
Insert into Student
(rollno, name)
values
(365, "Utkarsh"),
(320, "Kinshuk"),
(359, "Palak");

Insert into Student values (393, "Vansi"); -- This is a shorter version of the above command, but for this we should be aware of the order in which we are inserting values into the columns and it works for single row insertion only!

-- --------------------------------------------------------------------------------------------------------------------------------------->
-- Practice Question 1 :
-- Create a database for a company named XYZ and emplyoee info in form of 3 columns id, name and salary and then insert the values and then display the table!
Create Database XYZ;
Create Table Employee (
	id int primary key,
    name varchar(50),
    salary int
);
Insert into Employee
(id, name, salary)
values
(1, "Ram", 1200000),
(2, "Shyam", 1300000),
(3, "Mohan", 1400000);
Select * from Employee;

-- ---------------------------------------------------------------------------------------------------------------------------------------->
-- Keys : Primary Key and Foreign Key!
-- Primary Key : It is a column (or a set of columns) of the table that uniquely identifies each row. There is only 1 PK and it can not be null! Means bhale hi hum multiple columns ko primary key banaa sakte honge, pr sirf ek ko hi actually primary key banayenge!
-- Foreign Key : A foreign key is a column (or set of columns) in a table that refers to the primary key of some another table! There can be multiple foreign keys! FKs can have duplicate and null values!

-- Constraints : SQL Constraints are used to specify rules for a data in a table!
-- Not Null : If this is a constraint means that column cannot have null value!
-- Unique : All values in column are different
-- Primary Key : Makes a column unique and not null but used for one column only! Hum according to our usage 2 column ke combination ko bhi primary key bnaa sakte hai! called the Composite Key!
-- Foreign Key : Prevents actions that would destroy links between tables!
--             : Syntax will be like -> Create Table temp1 (
--                                          cust_id int,
--                                          Foreign Key (cust_id) refrences customer(id) -- Here we can see koi aur table hogi customer naam se uski ek PK hogi id, usko as a foreign key ki tarah use kiya temp1 table me with a new name which is cust_id!
--                                          );
-- Default : Sets the default values for a column!
--         : Syntax will be like -> salary int default 25000
-- Check : It can limit the values allowed in column!
--       : Syntax will be like -> Create Table City (
--                                  id int primary key,
--                                  city varchar(50),
--                                  age int,
--                                  constraint age_check check (age>=18 and city="delhi") -- This line will always the check the entry and according to that it will add it into the column!
--                                );
--                                  -- OR --
--                             -> Create Table newTab (
--                                  age int check (age>=18)
--                                );

-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
-- First Creating a table for the below commands to run!
Drop table Student;
Create Table Student (
	rollno int primary key,
    name varchar(40),
    marks int not null,
    grade varchar(1),
    city varchar(20)
);
Insert into Student
(rollno, name, marks, grade, city)
values
(101, "Anil", 78, "C", "Pune"),
(102, "Bhumika", 93, "A", "Mumbai"),
(103, "Chetan", 85, "B", "Mumbai"),
(104, "Dhruv", 96, "A", "Delhi"),
(105, "Emanuel", 12, "F", "Delhi"),
(106, "Farah", 82, "B", "Delhi");

-- Here what happened was that I added two extra rows into the table with come wrong ids so I wanted to change it pr vo change nhi ho rha tha toh maine pehle unn dono rows ko delete kiya and then firse add kiya!
Insert into Student
(rollno, name, marks, grade, city)
values
(108, "Ram", 80, "A", "Mumbai"),
(109, "Shyam", 90, "A", "Delhi");

Delete from Student
where rollno = 108;

Delete from Student
where rollno = 109;

Select * from Student;

Insert into Student
(rollno, name, marks, grade, city)
values
(107, "Ram", 80, "A", "Mumbai"),
(108, "Shyam", 90, "A", "Delhi");

Select * from Student;
-- Select Command : used to select any data from the database! Basic Syntax (For individual selection) : Select col1, col2 from Table_name; AND Syntax (for overall selection) : Select * from Table_name;
-- Here also we can use a distinct keyword which will select and display all the non-repeating values, for example, if there is column name city and we will write select distinct city from Table_name; then it will select and display all the cities without repeating!

Select name, marks from Student; -- It will display the columns which has marks and name at its heading!
Select city from Student; -- It will display all the cities!
Select distinct city from Student; -- It will only display pune mumbai and delhi, and not the repeating ones!

-- Clause in SQL : Now there are some clauses in the SQL which defines some conditions, one of them is "Where" clause!

-- Where Clause :
-- Select col1, col2 from Table_name
-- Where Condition
-- Example : Select * from Student where marks > 80;
--         : Select * from Student where city="Delhi";
Select * from Student where marks > 80;
Select * from Student where marks > 80 and city = "Mumbai"; -- Here we have used the logical operater and, similarly we can use or not and rest of them!

-- Operators in SQL : Arithmatic Operators, Logical Operators, Bitwise Operators and Relational Operators!
-- Arithematic Operators : +, -, *, / and %(modulo)
-- Relational Operators : =, !=, >, >=, <, <=
-- Logical Operators : And, Or, Not, In, Between, All, Like, Any
-- Bitwise Operator : & and |

-- We have seen the use of and operator, now we will look for others....
Select * from Student where marks>80 or city="Mumbai";
Select * from Student where marks between 80 and 90;
select * from Student where city in ("Delhi", "Mumbai");
select * from Student where city not in ("Delhi", "Mumbai", "Uttar Pradesh");

-- Limit Clause :
Select * from Student
where marks > 80 -- It will select and display all the students whose marks are > 80, but if we want to put a limit then we we will use the limit clause!
limit 4; -- It will put limit upto 4 students

-- Order By Clause : This clause is used to sort the data in acsending order or descending order!
-- Syntax -> Select col1, col2 from Table_name
--           Order by col_name(s) asc;
Select * from Student
order by city asc;

Select * from Student
order by marks desc
limit 3; -- And that is how we have obtained the top 3 students of the class!

-- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
-- Aggregate Functions! : They perform some calculations on some set of values and return a single value!
-- Some of them are : Count(), Min(), Max(), Sum(), Avg()
Select max(marks) from Student;
Select min(marks) from Student;
Select avg(marks) from Student;
Select count(rollno) from Student;
Select sum(marks) from Student;
-- --------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
-- Group By Clause : This means that all rows with the same value for Name will be grouped together. The aggregate function will return the value which we want to obtain within each group.
-- Generally we use group by with some aggregate function!
-- Example :
Select city, count(name)
from Student
Group by city;

Select city, avg(marks)
from Student
Group by city;
-- One point to be notes is that, jis cheez ko select kr rhe hai uske basis pr group bnana hi hoga! like here if we are selecting city then we must have to make a group of city, and if there are multiple attributes we are selecting then we must have to form group of all those attributes!

Select city, avg(marks)
from Student
Group by city
order by avg(marks) desc;

-- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
-- Practice Question 2 : Find the total payment according to the each payment method!
Create Database Transaction;
Use Transaction;
Create Table Payment (
	customer_id int primary key,
    customer varchar(50),
    mode varchar(20),
    city varchar(20)
);
Insert into Payment
(customer_id, customer, mode, city)
values
(101, "Olivia Barrett", "NetBanking", "Portland"),
(102, "Ethan Sinclair", "Credit Card", "Miami"),
(103, "Maya Hernandez", "Credit Card", "Seattle"),
(104, "Liam Donovan", "NetBanking", "Denver"),
(105, "Sophia Nguyen", "Credit Card", "New Orleans"),
(106, "Caleb Foster", "Debit Card", "Minneapolis"),
(107, "Ava Patel", "Debit Card", "Phoenix"),
(108, "Lucas Carter", "NetBanking", "Boston"),
(109, "Isabelle Martinez", "NetBanking", "Nashville"),
(110, "Jackson Brooks", "Credit Card", "Boston");
Select * from Payment;
Select mode, count(customer_id)
from Payment
group by mode;
-- Hence, thats how you do it!

-- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
Use college;
-- Similarly agar hume check krna ho kitne students ko A grade mila and all then also we can use group by clause!
select grade, count(rollno)
from Student
group by grade
order by grade asc;

-- Having Clause : It is similar to where clause, but there is a difference! and "where" rows pr condition lagaane ke kaam aata hai and "having" clause groups ke upar condition lgaane ke kaam aata hai!
-- Use of Having Clause : Count number of students in each city where max marks cross 90!
Select city, count(rollno)
from Student
group by city
having max(marks) > 90;

-- Overall, Order of syntax of SQL Commands is : SELECT -> FROM -> WHERE -> GROUP BY -> HAVING -> ORDER BY -> LIMIT/OFFSET
-- Order of Execution of SQL Commands is : FROM -> WHERE -> GROUP BY -> HAVING -> SELECT -> DISTINCT -> ORDER BY -> LIMIT/OFFSET

-- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
-- Table Related Queries!
-- Update Command : To update existing rows!
-- Syntax : Update table_name
--          set col1 = val1, col2 = val2
--          where condition;

Set SQL_SAFE_UPDATES = 0; -- By default safe mode mysql me on hota hai means, hum koi cheez update nhi kr sakte, this safe made is for like kabhi maanlo humne koi aise changes krdiye apne DB me jo nhi krne the, toh uss cheez se bachne ke liye ye safe mode by default on rehta hai, pr abhi hum isko off kr rhe hai iss command se!
Update Student
set grade = "O"
where grade = "A";
Select * from Student;

Update Student
set marks = 82, grade = "B"
where rollno = 105; -- Emanuel marks are updated succesfully!
Select * from Student;

Update Student
set grade = "O"
where marks between 91 and 100;

Update Student
set grade = "A"
where marks between 81 and 90;

Update Student
set grade = "B"
where marks between 71 and 80;

Update Student
set grade = "C"
where marks between 61 and 70;
Select * from Student;

-- Suppose agar ek question exam me aaya jo galat tha, toh usko exam cell ne remove krdiya and ab sab bacho ko 1 marks extra miljayega, toh uske liye bhi DB ko update kro!
Update Student
set marks = marks + 1;
Select * from Student;

-- Delete Command : Used to delete existing rows!
-- Syntax : Delete from table_name
--          where condition;
Use college;
Update Student
set marks = 12
where rollno = 105;
Delete from Student -- Agar hum sirf iss line ko execute krde tab poora table delete hojayega, and we can't bring that table back, so use this operation very carefully!
where marks < 33;
Select * from Student;

-- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
-- Revisiting Foreign Key!
Use college;
Create table dept (
	id int PRIMARY KEY,
    name varchar(50)
);
Create table teacher (
	id  int,
    name varchar(50),
    dept_id int,
    foreign key (dept_id) references dept(id)
);
-- In the above example we have established a connection or a link between the two tables which are teachers and dept! using foreign key!
-- If we want to visualize it we can go to database in the top nav bar and then we can select college database and then we can see the ER diagram of all the tables we have created! The table which has the primary key is called the parent table and other table is called the child table!

-- --------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
-- Cascading for Foreign Keys!
-- There are some problems like hum kya chahte hai ki jab bhi koi do tables linked hai tab agar hum koi change ek table me kre toh vo change dusre table me bhi reflect hojaye! so for that we use "On Update Cascade" and "On delete cascade"
-- Agar hum bss harr foreign key vaali line ke baad ye do line likh denge toh humara kaam hogya! means in the above example all we have to write is....
Create table teacher (
	id int,
    name varchar(50),
    dept_id int,
    foreign key (dept_id) references dept(id)
    On Update Cascade
    On Delete Cascade
);
-- Formal Defintions of The cascading foreign keys!
-- On Delete Cascade : When a row in the parent table is deleted, all related rows in the child table (rows that reference the deleted row via a foreign key) are automatically deleted as well.
-- On Update Cascade : When the value of a foreign key in the parent table is updated, all corresponding foreign key values in the child table are automatically updated as well.

-- --------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
-- Alter Command : It is used to change the schema! means jab bhi hume columns ki basic design means datatype constraints yaa koi bhi design ya layout me changes krne hote hai toh uske liye we use this command!
-- Operations with Alter Command : ADD, DROP, CHANGE, MODIFY Column & RENAME Table!

-- Syntax :
-- ADD Column : Alter Table table_name
--              Add Column col_name datatype constraints;

-- DROP Column : Alter Table table_name
--               Drop Column col_name;

-- RENAME Table : Alter Table table_name
--                Rename to new_table_name;

-- CHANGE Column : Alter Table table_name
--                 Change old_name new_name new_datatype new_constraints;

-- MODIFY Column : Alter Table table_name
--                 Modify col_name new_datatype new_constraints;

-- Working Examples :
Alter Table Student
add age int;

Alter Table Student
drop column age;

Alter Table Student
rename to Students;
Select * from Students;

Alter Table Students
rename to Student;
Select * from Student;

-- Truncate Command : It deletes the data inside the table and not the whole table!
-- Syntax : Truncate Table table_name;

-- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
-- Practice Question 3 : In the student table change the column name to fullname, delete all the students who have scored marks less than 80, delete the column of grades!
Alter Table Student
change name full_name varchar(50);

Delete from Student
where marks < 80;

Alter table Student
Drop column grade;

Select * from Student;
-- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
-- Date format function in SQL is used to format Date and time in a particular format needed according to system requirements!
DATE_FORMAT(date, format) -- This is the syntax!

-- Specifier	Description                 Example
-- --------------------------------------------------
-- %Y	        Year(4 digits)	            2024
-- %y	        Year(2 digits)	            24
-- %m           Month(2 digits)             09
-- %b	        Month(abbreviated name)	    Sep
-- %M	        Month(full name)	        September
-- %d	        Day of the month(2 digits)  23
-- %H	        Hour(00-23)	                14
-- %i	        Minutes(00-59)          	30
-- %s	        Seconds(00-59)	            05

-- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------->
-- Joins in SQL! : It is used to combine rows from 2 or more tables, based on related column between them! Overall means it is used to join 2 or more than 2 columns but for that we should be having some common columns!
-- Now there are 4 different types of joins, as we have studied in maths, like...Inner Join (Intersection) and Outer Join (Left Join -> A+(A Intersection B), Right Join -> B+(B Intersection A), Full Join -> AUB)!

-- Inner Join : Returns records that are having matching values in both the tables!
-- Syntax : Select column(s)
--          From TableA
--          Inner Join TableB -> Yahaa konsa table left ya right hai isse fark nhi padta, toh upar neeche likhne se bhi result me koi fark nhi padega! but as per rules jo pehle likha hota hai that is left table and baad vaala right table!
--          On TableA.col_name = TableB.col_name; 

-- Example :
Create Table Student2 (
	student_id int,
    name varchar(50)
);
Insert into Student2
(student_id, name)
values
(101, "Adam"),
(102, "Bob"),
(103, "Casey");

Create Table Course (
	student_id int,
    course varchar(50)
);
Insert into Course
(student_id, course)
values
(102, "English"),
(105, "Maths"),
(103, "Science"),
(107, "Computer Science");

Select * from Student2;
Select * from Course;

Select *
From Student2 as s2 -- Here as is used to provide aliases to the table names or column names and yahaa humne student2 vaali table ko s2 alias dediya!
Inner Join Course as c
On Student2.student_id = Course.student_id;

-- Left Join : Returns all the records from the left table and matching records from the right table!
-- Syntax : Select column(s)
--          From TableA
--          Left Join TableB -- This line simply means that Table A ka Table B se left join krna hai! and jo pehle likha hua hai vo left hai and jo baad me vo right hai!
--          On TableA.col_name = TableB.col_name;

-- Example :
Select *
From Student2
Left Join Course
On Student2.student_id = Course.student_id;

-- Right Join : Returns all the records from the right table and matching records from the left table!
-- Syntax : Select column(s)
--          From TableA
--          Right Join TableB -- This line simply means that Table A ka Table B se right join krna hai! and jo pehle likha hua hai vo left hai and jo baad me vo right hai!
--          On TableA.col_name = TableB.col_name;

-- Example :
Select *
From Student2
Right Join Course
On Student2.student_id = Course.student_id;

-- Full Join : Returns all the record when there is a match in either right or left table! Also In MySQL full join jaisa koi keyword exist nhi krta, so yahaa pr hum left join and right join ka union use krte hai!
-- Syntax in mySQL : Select * from tableA
--                   Left join tableB
--                   On tableA.col_name = tableB.col_name
--                   Union
--                   Select * from tableA
--                   Right join tableB
--                   On tableA.col_name = tableB.col_name

-- Example :
Select * from Student2 as s2
left join Course as c
on s2.student_id = c.student_id
Union
Select * from student2 as s2
right join Course as c
on s2.student_id = c.student_id;
-- So in MySQL we indirectly perform Full Join!

-- Now there are some more extra joins in MySQL, and they are : Left Exclusive Join, Right Exclusive Join and Full Exclusive Join
-- Left Exclusive Join : Which is same as A-B, hence....
Select *
from Student2
left join Course
on student2.student_id = Course.student_id
where course.student_id is null;
-- This will select and display only the content which are exclusively in the left table!

-- Right Exclusive Join : Which is same as B-A, hence....
Select *
from Student2
right join Course
on student2.student_id = Course.student_id
where Student2.student_id is null;
-- This will select and display only the content which are exclusively in the right table!

-- Full Exclusive Join : Which is same as A-B U B-A, hence....
Select * from Student2
left join Course
on student2.student_id = Course.student_id
where course.student_id is null
union
Select * from Student2
right join Course
on student2.student_id = Course.student_id
where Student2.student_id is null;
-- We have just joined the Left Exclusive and Right Exclusive Join using Union!

-- Self Join : Where a table is joined with itself!
Select *
from Student2 as a
join Student2 as b -- Yahaa hum alias use krte hai, so hum ek table ko ek baar a naam dedete hai and ek baar b and then dono ko join krdete hai!
on a.student_id = b.student_id;

-- Example : lets understand the use of Self Join!, first lets create a table
Create table  Employee2 (
	id int primary key,
    name varchar(50),
    manager_id varchar(50)
);
Insert into employee2
(id, name, manager_id)
values
(101, "Adam", 103),
(102, "Bob", 104),
(103, "Casey", null),
(104, "Donald", 103);
Select * from employee2;
-- Now we have to see the hierarchy of the above table, that kon kiska manager hai and all! Hence, we will use self join!
Select *
from employee2 as a
join employee2 as b
on a.id = b.manager_id; -- So yahaa kya hua ki jab sab rows pr check kiya gya, ki agar dono tables me agar a ke kisi employee ki ID b table ke kisi employee ki manager ID se match krti hai toh uss poore row ko join krdiya jaayega! and that's what its output of this statement shows!
-- And aise hi hierarchy setup hogyi employees and unke managers ki!

-- So now you got the actuall concept ki upar kya hua, so now lets simplify the above table....
Select a.name as manager_name, b.name
from employee2 as a
join employee2 as b
on a.id = b.manager_id;

-- ---------------------------------------------------------------------------------------------------------------------------------------------------->
-- Extras in JOINS...
-- There are multiple types of JOINS, INNER JOIN, LEFT JOIN, RIGHT JOIN, FULL JOIN, CROSS JOIN, NATURAL JOIN, EQUI JOIN, JOIN, RIGHT-EXCLUSIVE JOIN, LEFT-EXCLUSIVE JOIN, FULL-EXCLUSIVE JOINS and SELF JOIN
-- Not all JOINS are distinct!
-- INNER JOIN : Join ka simple mtlb hai ki do tables ko join krna! ab agar baat INNER JOIN ki hai toh isme jo dono tables me common column hai unpr kuch conditions lgai jaati hai! and unke basis tuples return ho jaati hai! common column hona zaruri hai JOIN krne ke liye kyunki conditions common columns pr hi lagti hai! and agar common columns pr condition lagaane ke bajaye kisi aur un-common columns pr condition lagaoge toh 3 cheeze hongi! yaa toh 1) No-Match ya toh 2) Partial Match ya toh 3) Cartesian Product.
-- LEFT JOIN : Again isme jo left table hota hai uska saara data toh final table me hota hi hai! but saath saath jo common columns se jo data retrieve hua vo bhi hota hai! again isme bhi condtions common columns pr lagti hai!
-- RIGHT JOIN : Just Opposite of LEFT JOIN.
-- FULL JOIN : Isme dono tables ka saara data aa jaata hai! common columns pr lagai gyi conditions ke basis pr!
-- CROSS JOIN : Returns the Cartesian product of the two tables, i.e., it returns all possible combinations of rows from the two tables. It does not require a join condition.
-- NATURAL JOIN : Isme dono tables me jo same name ke columns hai unko simply join krdeta hai, isme bhi koi condition ki requirement nhi hoti!
-- EQUI JOIN : It's a specific type of Inner Join where the join condition is based on equality between columns in the two tables. isme equality vaali condition hi hoti hai! thats why it is called equi join!
-- JOIN : Its a little different, as becoz isme agar koi condition nhi doge toh ye ek CROSS JOIN ke tarah kaam krega! and agar condition doge toh it will work as INNER JOIN.
-- LEFT-EXCLUSIVE JOIN : Isme bhi common columns pr hi condition lgaani hoti hai! and then it does Left Table - Right Table. No syntax, ye hume condition lgaa ke hi krni hoti hai!
-- RIGHT-EXCLUSIVE JOIN : Isme bhi common columns pr hi condition lgaani hoti hai! and then it does Right Table - Left Table. No syntax, ye hume condition lgaa ke hi krni hoti hai!
-- FULL-EXCLUSIVE JOIN : Isme bhi common columns pr hi condition lgaani hoti hai! and then it does Left-Exclusive Join U Right-Exclusive Join. No syntax, ye hume condition lgaa ke hi krni hoti hai!
-- SELF JOIN : Isme ek table apne aap se hi join hojaata hai!

-- EQUI and INNER JOIN : INNER JOIN supports more conditions (e.g., >, <). but EQUI JOIN focuses strictly on =.
-- Practice all these Joins toh have a taste of them all!

-- ---------------------------------------------------------------------------------------------------------------------------------------------------->
-- Unions : It is used to combine the result records of the 2 or more select statements, and it gives a unique value! mathematically it is AUB!
-- To use it : Every select statement should have same number of columns
--           : Columns must have similar datatypes
--           : Columns in every select should have same order!
-- Syntax : Select column(s) from Table A
--        : Union
--        : Select column(s) from Table B
-- Also jaise union hota hai, jo saari duplicate/repeated values ko hataa deta hai, vaise hi ek union all hota hai jo saari duplicate/repeated values ko bhi allow krta hai!

-- ----------------------------------------------------------------------------------------------------------------------------------------------------->
-- Sub Query : A subquery (also called a nested or inner query) is a query written inside another SQL query. It is enclosed in parentheses () and can return a value or a set of values.
--           : Subqueries are used to perform intermediate calculations or fetch data for the main query.

-- Sub Query Syntax : SELECT column_name(s)
--                    FROM table_name
--                    WHERE column_name operator (subquery); 

-- Ways to use Sub Queries : WHERE, FROM & SELECT

-- Sub Query using WHERE Clause :
SELECT full_name, marks
FROM student
WHERE marks > (SELECT AVG(marks) FROM student);

-- Sub Query using FROM Clause :
-- Without subquery :
SELECT MAX(marks) 
FROM student 
WHERE city = 'Delhi';

-- With subquery :
SELECT MAX(marks)
FROM (SELECT * FROM student WHERE city = 'Delhi') AS temp;

-- With subquery in the SELECT clause :
SELECT (SELECT MAX(marks) FROM student) AS max_marks, full_name
FROM student;

-- Key Points : Dynamic Nature : Subqueries are executed dynamically during query runtime. For example, in the average marks query, the subquery recalculates the average whenever the main query is run.
--            : Parentheses : Subqueries must be enclosed in parentheses ().
--            : Scope : A subquery can return a single value (scalar), a list of values, or a table.
--            : Usage : Use subqueries for readability and reusability, especially when breaking down complex queries.

-- Advantages of Subqueries : Simplifies Queries : Breaks down complex queries into smaller, manageable parts.
--                          : Dynamic Calculations : Automatically updates results when underlying data changes.
--                          : Modular Design : Easier to debug and reuse.

-- Disadvantages of Subqueries : Performance Overhead : Subqueries can slow down execution if not optimized.
--                             : Readability : Excessive nesting can make queries harder to understand.

-- ---------------------------------------------------------------------------------------------------------------------------------------------------->
-- Real Tables vs Virtual Tables : Real tables store actual data, and operations are performed directly on them.
--                               : Views are virtual tables that don't store data; they are like temporary tables created to simplify data retrieval.
--                               : Views are used to present data in a specific way without altering the original data.

-- Example :  A teacher only needs selected student information (like roll number, name, and marks) and not the entire student record.
-- Solution :
-- Create View : A virtual table (view) is created that includes only the columns relevant to the teacher :
CREATE VIEW view1 AS
SELECT rollno, full_name, marks
FROM student;
-- This view behaves like a table with only the selected columns (rollno, full_name, marks). Original Table remains unaffected.

-- Perform Operations on the View : The same operations you perform on real tables can be done on the view :
SELECT * FROM view1; -- The result shows only the data as per the view (virtual table).

-- Drop View : If the view is no longer needed, it can be removed :
DROP VIEW view1; -- This removes the view but does not affect the original table.

-- Note : Views are useful for data abstraction, hiding unnecessary details from the user. No impact on the original data. You can perform operations like SELECT on views, but they do not store data permanently.

-- ---------------------------------------------------------------------------------------------------------------------------------------------------->
-- Window Functions!
-- Window functions in SQL are used to perform calculations across a set of rows that are related to the current row, while still keeping the individual rows in the result. They don't collapse the rows like aggregate functions (SUM, AVG, etc.), but provide additional calculated values alongside the row-level data.
-- Syntax : <window_function>() OVER (
--          [PARTITION BY column1, column2, ...] (Optional)
--          [ORDER BY column1 [ASC | DESC], column2, ...] (Required)
--          [ROWS or RANGE frame_specification] (Optional)
--          )
-- Syntax Explaination : <window_function> : Here we write the window function, which we are going to use! like, ROW_NUMBER(), RANK() etc.
--                     : PARTITION BY : PARTITION BY is used in window functions (like ROW_NUMBER(), RANK(), SUM(), etc.) to divide the result set into groups (partitions) but does not reduce the number of rows. After partitioning, the window function is applied to each group separately, but the full result set remains intact.
--                                    : GROUP BY also does grouping of rows, but the difference is, GROUP BY reduce the original table and perform some operations on each group, and create each row per group!
--                                    : PARTITION BY also does grouping of rows, but the it does not reduce the rows of the original table, it just group them "theoritically"
--                                    : Example : Suppose you have a Table T, which has attributes Department & Salary.
--                                              : Applying GROUP BY : SELECT Department, AVG(Salary) AS Avg_Salary FROM Table GROUP BY Department. The resultant table for this query will have two columns Department and Avg_Salary. And rows are grouped in Departments and Avg_Salary column will show the average salary of the employees of that group!
--                                              : Applying PARTITION BY : SELECT Department, Salary ROW_NUMBER() OVER (PARTITION BY Department ORDER BY Salary DESC) AS Row_Number FROM Table. It will just simply form another column as Row_Number, which will just contain Row_Number according to the salary of every group that is Department in descending order! Like a an employee in a Department with maximum salary will have Row_number 1.
--                     : ORDER BY : Specifies the order in which the rows should be processed.Always needed for window functions to define how rows should be sorted. This is crucial for functions like ROW_NUMBER() and RANK() to assign values in the correct order.
--                     : ROWS or RANGE : The ROWS and RANGE clauses are used to define the "window frame" or the range of rows that the window function will consider when calculating its result. These clauses come into play when you want to perform calculations that depend on a specific set of rows relative to the current row.
--                                     : The window frame is the subset of rows that the window function looks at to perform its calculation. By default, if no ROWS or RANGE clause is specified, the window function looks at all the rows within the partition (or the entire result set if there's no partition).
--                                     : Common Options for ROWS and RANGE : "ROWS/RANGE BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW" : This option looks at all rows (if rows) from the start of the partition up to the current row. This is useful for cumulative calculations, such as a running total.
--                                                                         : "ROWS/RANGE BETWEEN 1 PRECEDING AND CURRENT ROW" : This option looks at the previous row (if rows) and the current row. It is used when you want to calculate something based only on the current and previous rows.
--                                     : "ROWS" : When using ROWS, the window frame refers to a fixed number of rows. The window function calculates the sum based on physical rows before and after the current row. Considers individual rows for calculations, regardless of whether values in the ordered column are identical.
--                                              : When you use ROWS, it calculates the window function over specific rows, based on their position in the dataset, even if the values in the ordering column are the same.
--                                              : It does not group rows with identical values. Each row is treated independently.
--                                              : When to use : Use ROWS when you want to keep the row-wise calculation without grouping rows with identical values together.
--                                                            : Example : If you want the running total, and you care about each row's individual calculation regardless of identical values.
--                                     : "RANGE" : When you use RANGE, it groups rows with identical values together and applies the window function across that group. Rows with the same value in the ORDER BY column are treated as a logical group, even if they are physically separate rows in the dataset.
--                                               : It is called a logical window because it groups rows logically by their values rather than their row position. 
--                                               : When to use : Use RANGE when you want to treat rows with the same value as a group and apply the calculation across that group.
--                                                             : Example : If you're calculating the cumulative sum of salaries but want to treat employees with the same salary (like 6000) together.
--                                     : Real World Scenarios for "ROWS" & "RANGE" : ROWS : Scenario : Tracking daily sales and calculating a running total for a company. Imagine you're working in the finance department of a retail company, and you need to track the daily sales for the entire month. You want to calculate a cumulative sales total to see how the total sales are accumulating each day.
--                                                                                                   : Data : You have sales data for each day of the month. The goal is to calculate a running total that adds up the sales for each day as you progress through the month.
--                                                                                 : "RANGE" : Scenario : Employee Salary Bands - Grouping Salaries and Calculating the Running Total for Groups! Imagine you are an HR manager working with employee salary data, and you want to calculate the cumulative salary for employees grouped by their salary bands. Employees who have the same salary should be treated as a group for the running total calculation.
--                                                                                                      : Data : You have a list of employees, each with a salary. You need to calculate the cumulative salary total but group employees by their salary range (employees with the same salary should be treated as a group).

-- Important Window Functions!
-- ROW_NUMBER() : Assigns a unique number to each row within a partition, starting from 1. The rows are ordered based on the ORDER BY clause.
--              : Use case : To rank rows uniquely, such as giving each customer in a dataset a unique ID.
--              : Syntax : ROW_NUMBER() OVER (PARTITION BY partition_column ORDER BY order_column)

-- RANK() : Similar to ROW_NUMBER(), but it allows for tied ranks. When rows have the same value, they receive the same rank, "but the next rank will be skipped". Analogy : If two people crossed a finish line together, they both be marked Rank 1, and next person to cross the finish line will be marked Rank 3, Rank 2 will be skipped!
--        : To rank rows where ties are possible (like scores in a competition).

--        : Syntax : RANK() OVER (PARTITION BY partition_column ORDER BY order_column)
-- DENSE_RANK() : Similar to RANK(), but there is no gap in the rank. Even if rows are tied, the next rank number is not skipped. Analogy : If two people crossed a finish line together, they both be marked Rank 1, and next person to cross the finish line will this time be marked Rank 2, unlike Rank 3 in RANK()!
--              : When you want to avoid skipping ranks even in the case of tied values.
--              : Syntax : DENSE_RANK() OVER (PARTITION BY partition_column ORDER BY order_column)

-- NTILE() : Divides the result set into a specified number of buckets (or tiles) and assigns each row to a bucket. Useful for grouping data into equal parts, like quartiles, deciles, etc.
--         : Example : If there is an Employee table, and has attributes like, EmpID, Department, Salary, now if I apply, SELECT employee_id, department, salary, NTILE(4) OVER (PARTITION BY department ORDER BY salary DESC) AS quartile FROM employees; It will partition the rows on basis of groups that is Department in this case and order in DESC, now NTIL(4), will mark each row in a partition from 1-4 making quartiles and it will be follow in all the partitions!

-- SUM() : Calculates the sum of a column's values within a window frame (partition).
--       : Use case : To calculate the cumulative sum or total sales over a period.
--       : Syntax : SUM(column_name) OVER (PARTITION BY partition_column ORDER BY order_column)

-- AVG() : Calculates the average of a column’s values within a specified window.
--       : Use Case : To calculate the average salary or average score within a partition.
--       : Syntax : AVG(column_name) OVER (PARTITION BY partition_column ORDER BY order_column)

-- MIN() & MAX() : MIN() returns the smallest value in a column within a window. MAX() returns the largest value in a column within a window.
--               : To get the minimum or maximum value of a metric (like score or salary) within a partition.
--               : Syntax : MIN(column_name) OVER (PARTITION BY partition_column ORDER BY order_column) and MAX(column_name) OVER (PARTITION BY partition_column ORDER BY order_column)

-- LAG() : The LAG window function in SQL is used to retrieve the value of a column from a previous row within the same result set, based on the specified ordering. It is particularly useful for tasks involving comparisons or calculations between rows, such as finding differences between successive rows or identifying trends over time.
--       : Syntax : LAG(column_name, offset, default_value) OVER (PARTITION BY partition_column ORDER BY order_column)

-- Try examples to practice and get to know them!

-- ---------------------------------------------------------------------------------------------------------------------------------------------------->
-- CASE Expressions in SQL!
-- The CASE expression in SQL allows you to perform conditional logic in your queries, similar to an IF-ELSE structure in programming. It is commonly used to apply logic inside a SELECT, UPDATE, DELETE, or INSERT statement. The CASE expression evaluates a condition and returns a result based on the outcome of the condition.
-- Two Types of CASE Expressions : Simple CASE Expression : Evaluates one expression against multiple possible values.
--                               : Searched CASE Expression : Evaluates multiple conditions and returns the corresponding result for the first true condition.

-- CASE Expression Syntax : SELECT column1,
--                              CASE column_to_check
--                                      WHEN value1 THEN result1
--                                      WHEN value2 THEN result2
--                                  ELSE result3
--                              END AS alias_name
--                          FROM table_name;
-- Note : when using a CASE statement, you can either specify the column name immediately after CASE or include the condition in the WHEN clause. Using it in both places will result in a syntax error.

-- Simple CASE Expression Example :
-- Example : SELECT student_id, name, marks,
--              CASE marks
--                      WHEN 90 THEN 'Excellent'
--                      WHEN 80 THEN 'Good'
--                      WHEN 70 THEN 'Average'
--                  ELSE 'Needs Improvement'
--              END AS performance
--           FROM students;

-- Searched CASE Expression Example :
-- Example : SELECT student_id, name, marks,
--              CASE marks
--                      WHEN marks >= 90 THEN 'Excellent'
--                      WHEN marks >= 70 AND marks < 90 THEN 'Good'
--                      WHEN marks >= 50 AND marks < 70 THEN 'Average'
--                  ELSE 'Needs Improvement'
--              END AS performance
--           FROM students;

-- Using CASE with Aggregations Example :
-- Example : SELECT student_id, name, marks,
--              CASE marks
--                      WHEN marks >= 90 THEN 'Excellent'
--                      WHEN marks >= 70 AND marks < 90 THEN 'Good'
--                      WHEN marks >= 50 AND marks < 70 THEN 'Average'
--                  ELSE 'Needs Improvement'
--              COUNT(*) AS student_count
--              END AS performance
--           FROM students
--           GROUP BY performance;

-- Using CASE with UPDATE Statements Example :
-- Example : UPDATE Students
--           SET Performance =
--              CASE marks
--                      WHEN marks >= 90 THEN 'Excellent'
--                      WHEN marks >= 70 AND marks < 90 THEN 'Good'
--                      WHEN marks >= 50 AND marks < 70 THEN 'Average'
--                  ELSE 'Needs Improvement'
--              END;

-- Rest practice to understand more use cases and examples!

-- ---------------------------------------------------------------------------------------------------------------------------------------------------->
-- Some conditional functions :
-- IFNULL() : The IFNULL() function is used to check if a value is NULL (empty or missing) and replace it with a specified value if it is NULL. If the value is not NULL, it simply returns the original value.
--          : Syntax : IFNULL(expression, replacement_value), expression : This is the value or column you want to check for NULL. replacement_value : This is the value that will be returned if the expression is NULL.
-- COALESCE() : The COALESCE() function is used to check multiple values and return the first non-NULL value among them. If all the values are NULL, it will return NULL.
--            : Think of COALESCE() like a series of backup options : It first looks at the first value. If it's NULL, it checks the second value. If the second value is also NULL, it checks the third value, and so on. If none of them have a value (i.e., all are NULL), it returns NULL.
--            : Syntax : COALESCE(value1, value2, ..., valueN)
--            : Example : Let’s say we have a customer contact details table with the following columns : customer_id, phone_number, email_address and mailing_address!
--                      : We want to get the best contact information for each customer, and we want to : Prefer the phone_number first. If phone_number is missing (NULL), use email_address. If both phone_number and email_address are missing, use the mailing_address.
--                      : Then we will write : SELECT customer_id, COALESCE(phone_number, email_address, mailing_address) AS best_contact FROM customers; Then, resultant table will contain 2 columns, customer_id & best_contact (This contains values using the COALESCE() function).