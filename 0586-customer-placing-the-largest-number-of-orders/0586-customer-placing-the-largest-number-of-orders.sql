# Write your MySQL query statement below
Select customer_number
From Orders
Group by customer_number
Order by count(customer_number) DESC
Limit 1;