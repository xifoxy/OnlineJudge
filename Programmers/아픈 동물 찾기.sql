-- �ڵ带 �Է��ϼ���
SELECT
    animal_id, name
from
    animal_ins
where
    intake_condition like 'sick'
order by
    animal_id asc