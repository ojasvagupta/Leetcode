# Write your MySQL query statement below
SELECT 
  query_name, 
  ROUND(AVG(rating * 1.0 / position), 2) AS quality, 
  ROUND(100.0 * COUNT(CASE WHEN rating < 3 THEN 1 END) / COUNT(rating), 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name;