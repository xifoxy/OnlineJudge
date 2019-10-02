-- 코드를 입력하세요
SELECT
    a.animal_id, a.animal_type, a.name
from
    animal_ins a
where
    exists(
        select *
        from
            animal_outs b
        where
            b.animal_id = a.animal_id
            and
            b.sex_upon_outcome != a.sex_upon_intake
    )
order by
    a.animal_id