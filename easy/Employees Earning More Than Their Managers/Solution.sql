SELECT a.name AS Employee
FROM Employee a
JOIN Employee b
ON a.managerId = b.Id
WHERE a.salary > b.salary