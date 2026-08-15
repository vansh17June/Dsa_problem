# Write your MySQL query statement below
select customer_id  from Customer join Product  on Customer.product_key=Product.product_key  group by customer_id having count(distinct Product.product_key )=(
    select count( product_key) from Product 
)