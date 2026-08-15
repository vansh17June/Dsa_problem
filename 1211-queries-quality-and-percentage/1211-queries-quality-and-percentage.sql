# Write your MySQL query statement below
select 
query_name,
round(sum(rating/position)/count(position),2) as quality,
round(sum(Case when rating<3 then 1 else 0 End)*100/count(position),2) as poor_query_percentage
from 
Queries
group by 
query_name
