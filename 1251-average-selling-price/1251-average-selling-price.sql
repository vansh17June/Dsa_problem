# Write your MySQL query statement below
select 
p.product_id,ROUND( CASE WHEN 
   sum(p.price*u.units)/sum(u.units) is null then 0 else sum(p.price*u.units)/sum(u.units)
   END,2) as average_price
from 
Prices as p
left join 
UnitsSold as u
on 
p.product_id =u.product_id and datediff(u.purchase_date,p.start_date)>=0 and datediff(p.end_date,u.purchase_date)>=0
group by
p.product_id
