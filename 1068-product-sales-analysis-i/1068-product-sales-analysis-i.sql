# Write your MySQL query statement below
Select product_name,year,price
From Sales as a
Left Join Product as b
ON a.product_id = b.product_id;