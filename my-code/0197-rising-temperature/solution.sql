select w.id as id 
from Weather as w
inner join Weather as w1 on 
datediff(w.recordDate,w1.recordDate)=1 and (w.temperature>w1.temperature) 
