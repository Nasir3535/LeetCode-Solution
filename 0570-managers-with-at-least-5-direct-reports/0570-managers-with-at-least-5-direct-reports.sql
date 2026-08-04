# Write your MySQL query statement below
Select name from employee where id in
(Select managerId
from employee
group by managerId
having count(managerId) >= 5);