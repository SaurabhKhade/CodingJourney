SELECT *
FROM Cinema
WHERE Id%2 = 1
AND Description <> 'boring'
ORDER BY Rating DESC