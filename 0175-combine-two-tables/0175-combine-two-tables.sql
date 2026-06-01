# Write your MySQL query statement below
Select firstName ,lastName,city,state
From Person as a
Left Join Address as b
ON a.personID = b.personID
