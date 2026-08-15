# Write your MySQL query statement below
select 
t1.student_id,t1.student_name,t1.subject_name,count(Examinations.subject_name) as 
attended_exams 
from
(
select 
student_id,subject_name,student_name
from 
Students
cross join
Subjects
) as t1
left join
Examinations 
on
t1.student_id =Examinations.student_id and t1.subject_name =Examinations.subject_name 
group by
t1.student_id,t1.subject_name,t1.student_name
order by
t1.student_id ,t1.subject_name
