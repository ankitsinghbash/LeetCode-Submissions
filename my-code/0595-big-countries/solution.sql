# Write your MySQL query statement below
select name as name,population as population,area as area
from World
where population>=25000000 or area>=3000000
