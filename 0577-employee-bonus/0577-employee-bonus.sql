# Write your MySQL query statement below
select name,bonus from Bonus b right join Employee e on b.empId = e.empId  where bonus < 1000 or bonus is null 