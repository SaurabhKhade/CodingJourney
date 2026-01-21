/* Write your T-SQL query statement below */
SELECT Name
FROM Customer
WHERE Referee_Id IS NULL OR Referee_Id <> 2