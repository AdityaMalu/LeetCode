# Write your MySQL query statement below
select x,y,z, Case when x+y>z and z+y>x and z+x>y then 'Yes' else 'No' end as triangle from Triangle