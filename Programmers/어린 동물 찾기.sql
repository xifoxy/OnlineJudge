-- �ڵ带 �Է��ϼ���
SELECT
    animal_id, name
from
    animal_ins
where
    intake_condition not like 'aged'
order by
    animal_id asc