# Write your MySQL query statement below
select 
E1.name
from 
Employee as E1
join 
Employee as E2
on E1.id=E2.managerId
group by
E1.id
having count(E2.id)>=5


