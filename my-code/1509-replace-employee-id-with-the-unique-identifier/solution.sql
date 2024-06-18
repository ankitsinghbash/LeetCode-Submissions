select em.unique_id as unique_id , e.name as name
from Employees as e
left join EmployeeUNI as em on e.id = em.id
