select t2.Name Employee from Employee t1, Employee t2 where t1.Id = t2.ManagerId and t1.Salary < t2.Salary
