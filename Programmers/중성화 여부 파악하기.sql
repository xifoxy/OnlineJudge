-- �ڵ带 �Է��ϼ���
SELECT
    animal_id,
    name,
    case
        when sex_upon_intake like 'Neutered%' or sex_upon_intake like 'Spayed%' then 'O'
        else 'X'
    end as �߼�ȭ
    
from
    animal_ins
