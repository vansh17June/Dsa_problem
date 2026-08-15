# Write your MySQL query statement below
select 
P.project_id,Round(sum(E.experience_years)/count(E.experience_years),2) as average_years
from 
Project as P
join 
Employee as E
on 
P.employee_id =E.employee_id 
group by
P.project_id  
