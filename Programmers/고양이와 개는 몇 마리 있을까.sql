-- 코드를 입력하세요
select
    animal_type, count(*), as cnt
from
    animal_ins
group by
    animal_type