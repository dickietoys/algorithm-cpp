select  t2.Name Department,  t1.Name Employee,  t1.Salary Salary from
Employee t1,
(select DepartmentId, max(Salary) MaxSalary from Employee group by DepartmentId) tmp,
Department t2
where t1.DepartmentId = tmp.DepartmentId and Salary = tmp.MaxSalary and t1.DepartmentId = t2.Id
