# Write your MySQL query statement below
select 
p1.product_name as product_name,sum(p2.unit) as unit
from
Products as p1
join 
Orders as p2
on 
p1.product_id =p2.product_id and month(p2.order_date)='02' and year(p2.order_date)='2020'
group by p1.product_id
having sum(p2.unit)>=100

