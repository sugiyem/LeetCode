SELECT d.name AS Department, e1.name AS Employee, e1.Salary
FROM Employee e1, Department d
WHERE e1.departmentId = d.id 
AND 3 > (SELECT COUNT(DISTINCT(e2.Salary))
         FROM Employee e2
         WHERE e1.departmentId = e2.departmentId
         AND e1.Salary < e2.Salary)