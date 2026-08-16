# Write your MySQL query statement below

select 
employee_id,department_id 
from 
Employee as e1
where
(select count(department_id) from Employee as e2 where e1.employee_id=e2.employee_id  group by employee_id)=1 or primary_flag='Y'

