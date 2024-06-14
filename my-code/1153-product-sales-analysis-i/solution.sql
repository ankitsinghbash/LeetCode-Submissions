# Write your MySQL query statement below
#use left join because give that go in each iteration of sales table is compulsary:

SELECT p.product_name AS product_name,s.year as year , s.price as price
FROM Sales s
LEFT JOIN Product p ON s.product_id=p.product_id
