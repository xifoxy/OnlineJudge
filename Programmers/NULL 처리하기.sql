-- �ڵ带 �Է��ϼ���
SELECT
    animal_type, 
    case when name is null then 'No name' else name end,
    sex_upon_intake
from
    animal_ins