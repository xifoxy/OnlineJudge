-- 코드를 입력하세요
select 
    count(distinct name) 
from 
    animal_ins


SELECT COUNT(*)
FROM
    (
    SELECT NAME
    FROM ANIMAL_INS
    WHERE NAME IS NOT NULL
    GROUP BY NAME
    ) SQ1
