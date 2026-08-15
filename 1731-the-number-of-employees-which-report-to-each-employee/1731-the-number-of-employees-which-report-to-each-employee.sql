# Write your MySQL query statement below
select 
e1.employee_id as employee_id ,e1.name as name, count(e2.reports_to) as reports_count,Round(AVG(e2.age)) as average_age
from 
Employees as e1 
join 
Employees as e2
on e1.employee_id=e2.reports_to 
group by 
e1.employee_id
order by 
e1.employee_id

