-- �ڵ带 �Է��ϼ���
SELECT
    datetime
from
    animal_ins
where datetime=(select max(datetime) from animal_ins)