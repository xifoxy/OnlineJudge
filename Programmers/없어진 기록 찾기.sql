-- 코드를 입력하세요
SELECT
    ot.animal_id, ot.name
from
    animal_outs ot
where
    not exists(
        select *
        from
             animal_ins ins
        where
            ins.animal_id = ot.animal_id
    )