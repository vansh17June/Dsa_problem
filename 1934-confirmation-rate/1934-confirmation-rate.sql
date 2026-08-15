# Write your MySQL query statement below
select 
s.user_id,ROUND(AVG(
    CASE WHEN action='confirmed' THEN 1
          else 0
    END      
),2)
as confirmation_rate 
from 
Signups as s
left join 
Confirmations as c
on
s.user_id =c.user_id
group by 
s.user_id 