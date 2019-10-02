-- 코드를 입력하세요
SELECT
    a.name, a.datetime
from   
    animal_ins a
where
    not exists(
        select *
        from
            animal_outs b
        where
            a.animal_id = b.animal_id
    )


order by
    a.datetime asc
limit 3