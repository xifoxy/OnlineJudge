-- �ڵ带 �Է��ϼ���
SELECT
    datetime as �ð�
from
    animal_ins
where
    datetime=(select min(datetime) from animal_ins)