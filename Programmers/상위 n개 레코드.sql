-- �ڵ带 �Է��ϼ���
SELECT
    name
from
    animal_ins
where datetime=(select min(datetime) from animal_ins)


-- �ڵ带 �Է��ϼ���
SELECT
    name
from
    animal_ins
order by
    datetime asc
limit 1