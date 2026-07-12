# Write your MySQL query statement below
SELECT  A.name
FROM Employee A
JOIN Employee B
ON A.id = B.managerId
GROUP BY B.managerId 
HAVING COUNT(*) >= 5;