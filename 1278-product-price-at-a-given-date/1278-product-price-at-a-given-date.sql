SELECT product_id, new_price AS price
FROM Products
WHERE (product_id, change_date) IN (
    SELECT product_id, MAX(change_date) 
    FROM Products 
    WHERE change_date <= '2019-08-16' 
    GROUP BY product_id
)

UNION

select product_id,10 as price
from Products
where product_id not in (
    select product_id from Products where change_date <= '2019-08-16'
)

