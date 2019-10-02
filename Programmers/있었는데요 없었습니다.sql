-- 코드를 입력하세요
select
    A.animal_id,
    A.name
from
    animal_ins A,
    animal_outs B
where
    A.datetime > B.datetime
    and
    A.animal_id = B.animal_id
order by
    A.datetime