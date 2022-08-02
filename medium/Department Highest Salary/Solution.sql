SELECT b.name AS Department, a.name AS Employee, a.salary
FROM Employee a, Department b
WHERE a.departmentId = b.id
AND a.salary = (SELECT MAX(salary) FROM Employee c WHERE c.departmentId = b.id)