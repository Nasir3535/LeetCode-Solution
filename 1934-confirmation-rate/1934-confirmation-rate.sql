# Write your MySQL query statement below
Select s.user_id , 
Round(AVG(Case 
            when c.action = 'confirmed' 
                Then 1 
            Else 0
            END),2) 
As 'confirmation_rate'
From Signups As s
Left Join Confirmations As c
ON s.user_id = c.user_id
Group by s.user_id;