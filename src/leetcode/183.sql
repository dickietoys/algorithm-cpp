Suppose that a website contains two tables, the Customers table and the Orders table. Write a SQL query to find all customers who never order anything.

Table: Customers.

+----+-------+
| Id | Name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Table: Orders.

+----+------------+
| Id | CustomerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
Using the above tables as example, return the following:

+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+

{"headers":
{"Customers": ["Id", "Name"],
"Orders": ["Id", "CustomerId"]},
"rows": {"Customers":
[
[1, "Joe"],
[2, "Henry"],
[3, "Sam"],
[4, "Max"]],
"Orders": [
[1, 3],
[2, 1]
]}}


select tmp.Name Customers from (select C.Name, O.Id from Customers C left join Orders O on C.Id = O.CustomerId) tmp where tmp.Id is null
