CREATE DATABASE Sales;
USE Sales;

CREATE TABLE Sales_table (
	Sales_id INT PRIMARY KEY,
    Product_id INT,
    FOREIGN KEY (Product_id) REFERENCES Products(product_id),
    Quantity_sold INT,
    Sale_date DATE,
    Net_price DECIMAL(10,2)
);

INSERT INTO Sales_table
(Sales_id, Product_id, Quantity_sold, Sale_date, Net_price)
VALUES
(1, 101, 5, '2024-01-01', 2500.00),
(2, 102, 3, '2024-01-02', 900.00),
(3, 103, 2, '2024-01-02', 60.00),
(4, 104, 4, '2024-01-03', 80.00),
(5, 105, 6, '2024-01-03', 90.00);

SELECT * FROM Sales_table;

CREATE TABLE Products (
    product_id INT PRIMARY KEY,
    product_name VARCHAR(100),
    category VARCHAR(50),
    unit_price DECIMAL(10, 2)
);

INSERT INTO Products (product_id, product_name, category, unit_price) VALUES
(101, 'Laptop', 'Electronics', 500.00),
(102, 'Smartphone', 'Electronics', 300.00),
(103, 'Headphones', 'Electronics', 30.00),
(104, 'Keyboard', 'Electronics', 20.00),
(105, 'Mouse', 'Electronics', 15.00);

SELECT * FROM Sales_table;
SELECT * FROM Products;

-- 1) Filter the Sales table to show only sales with a total_price greater than $100.
SELECT * FROM Sales_table
WHERE Net_price > 100;

-- 2) Filter the Products table to show only products in the ‘Electronics’ category.
SELECT * FROM Products
WHERE Category IN ("Electronics");

-- 3) Retrieve the sale_id and total_price from the Sales table for sales made on January 3, 2024.
SELECT Sales_id, net_price FROM Sales_table
WHERE sale_date = '2024-01-03';

-- 4) Retrieve the product_id and product_name from the Products table for products with a unit_price greater than $100.
SELECT Product_id, Product_name FROM Products
WHERE unit_price > 100;

-- 5) Calculate the total revenue generated from all sales in the Sales table.
SELECT SUM(net_price) as Total_sales FROM Sales_table;

-- 6) Calculate the average unit_price of products in the Products table.
SELECT AVG(unit_price) as avg_price FROM Products;

-- 7) Calculate the total quantity_sold from the Sales table.
SELECT SUM(quantity_sold) as Net_quantity FROM Sales_table;

-- 8) Retrieve the sale_id, product_id, and total_price from the Sales table for sales with a quantity_sold greater than 4.
SELECT Sales_id, product_id, net_price FROM Sales_table
WHERE quantity_sold > 4;

-- 9) Retrieve the product_name and unit_price from the Products table, ordering the results by unit_price in descending order.
SELECT product_name, unit_price FROM products
ORDER BY unit_price DESC;

-- 10) Retrieve the total_price of all sales, rounding the values to two decimal places.
SELECT ROUND(SUM(net_price),2) FROM sales_table;

-- 11) Calculate the average total_price of sales in the Sales table.
SELECT AVG(net_price) FROM Sales_table;

-- 12) Retrieve the sale_id and sale_date from the Sales table, formatting the sale_date as ‘YYYY-MM-DD’.
SELECT sales_id, DATE_FORMAT(sale_date, '%Y-%m-%d') FROM sales_table;

-- 13) Calculate the total revenue generated from sales of products in the ‘Electronics’ category.
SELECT SUM(net_price) FROM sales_table as s
INNER JOIN products as p
ON s.product_id = p.product_id
WHERE p.category = "Electronics";

-- 14) Retrieve the product_name and unit_price from the Products table, filtering the unit_price to show only values between $20 and $600.
SELECT p.product_name, p.unit_price FROM Products AS p
WHERE unit_price BETWEEN 20 AND 600;

-- 15) Retrieve the product_name and category from the Products table, ordering the results by category in ascending order.
SELECT p.product_name, p.category FROM Products AS p
ORDER BY category ASC;

-- 16) Calculate the total quantity_sold of products in the ‘Electronics’ category.
SELECT SUM(quantity_sold) as total_quantity_sold FROM sales_table
INNER JOIN products
ON sales_table.product_id = products.product_id
WHERE category = "Electronics";

-- 17) Retrieve the product_name and total_price from the Sales table, calculating the total_price as quantity_sold multiplied by unit_price.
SELECT product_name, net_price FROM sales_table
INNER JOIN products
ON sales_table.product_id = products.product_id;

-- 18) Calculate the total revenue generated from sales for each product category.
SELECT products.category, SUM(net_price) FROM sales_table
INNER JOIN products
ON sales_table.product_id = products.product_id
WHERE category = "Electronics"
GROUP BY category;

-- 19) Find the product category with the highest average unit price.
SELECT category
FROM products
GROUP BY category
ORDER BY AVG(unit_price) DESC
LIMIT 1;

-- 20) Identify products with total sales exceeding 30.
SELECT product_name
FROM products
INNER JOIN sales_table
ON sales_table.product_id = products.product_id
GROUP BY product_name
HAVING SUM(net_price) > 30;

-- 21) Count the number of sales made in each month.
SELECT DATE_FORMAT(s.sale_date, '%M') AS month, COUNT(*) AS sales_count
FROM Sales_table s
GROUP BY month;

-- 22) Determine the average quantity sold for products with a unit price greater than $100.
SELECT AVG(quantity_sold)
FROM sales_table
INNER JOIN products
ON sales_table.product_id = products.product_id
WHERE unit_price > 100;

-- 23) Retrieve the product name and total sales revenue for each product.
SELECT product_name, SUM(net_price) as total_revenue
FROM sales_table
INNER JOIN products
ON sales_table.product_id = products.product_id
GROUP BY product_name;

-- 24) List all sales along with the corresponding product names.
SELECT sales_id, product_name FROM sales_table
INNER JOIN products
ON sales_table.product_id = products.product_id;

-- 25) Rank products based on Total sales revenue
SELECT product_name, SUM(net_price) AS Sales_revenue,
RANK() OVER (ORDER BY SUM(net_price) DESC) AS Ranking -- Window Function RANK() OVER()!
FROM products
INNER JOIN sales_table
ON sales_table.product_id = products.product_id
GROUP BY product_name
ORDER BY sales_revenue DESC;

-- 26) Calculate the running total revenue for each product category.
SELECT p.category, p.product_name, s.sale_date, 
SUM(s.total_price) OVER (PARTITION BY p.category ORDER BY s.sale_date) AS running_total_revenue
FROM Sales s
JOIN Products p ON s.product_id = p.product_id;

-- 27) Categorize sales as “High”, “Medium”, or “Low” based on total price (e.g., > $200 is High, $100-$200 is Medium, < $100 is Low).
SELECT sales_id, 
       CASE 
           WHEN net_price > 200 THEN 'High'
           WHEN net_price BETWEEN 100 AND 200 THEN 'Medium'
           ELSE 'Low'
       END AS sales_category
FROM Sales_table;

-- 28) Identify sales where the quantity sold is greater than the average quantity sold.
SELECT sales_id, s.product_id, quantity_sold, s.sale_date ,product_name, s.net_price FROM sales_table AS s
INNER JOIN products AS p
ON s.Product_id = p.product_id
WHERE quantity_sold > (SELECT AVG(quantity_sold) FROM sales_table);

-- 29) Extract the month and year from the sale date and count the number of sales for each month.
SELECT CONCAT(YEAR(sale_date), '-', LPAD(MONTH(sale_date), 2, '0')) AS month,
       COUNT(*) AS sales_count
FROM Sales
GROUP BY YEAR(sale_date), MONTH(sale_date);

-- 30) Calculate the number of days between the current date and the sale date for each sale.
SELECT sales_id, DATEDIFF(NOW(), sale_date) AS days_since_sale
FROM Sales_table;

-- 31) Identify sales made during weekdays versus weekends.
SELECT sales_id,
       CASE 
           WHEN DAYOFWEEK(sale_date) IN (1, 7) THEN 'Weekend'
           ELSE 'Weekday'
       END AS day_type
FROM Sales_table;

-- 32) Write a query to create a view named Total_Sales that displays the total sales amount for each product along with their names and categories.
CREATE VIEW Total_sales AS
SELECT p.product_name, p.category, SUM(net_price) as Net_Sales
FROM products as p
INNER JOIN sales_table as s
ON p.product_id = s.Product_id
GROUP BY p.product_name, p.category;
SELECT * FROM Total_sales;

-- 33) Retrieve the product details (name, category, unit price) for products that have a quantity sold greater than the average quantity sold across all products.
SELECT p.product_name, p.category, p.unit_price, s.quantity_sold
FROM products as p
INNER JOIN sales_table as s
ON p.product_id = s.Product_id
WHERE quantity_sold > (SELECT AVG(quantity_sold) FROM sales_table);

-- 34) Create a view named Top_Products that lists the top 3 products based on the total quantity sold.
CREATE VIEW Top_products AS
SELECT p.product_name, s.quantity_sold FROM sales_table as s
INNER JOIN products AS p
ON p.product_id = s.Product_id
ORDER BY quantity_sold DESC LIMIT 3;
SELECT * FROM top_Products;