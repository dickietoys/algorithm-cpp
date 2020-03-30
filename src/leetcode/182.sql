select Email from (select Email, count(*) nums from Person group by Email) tmp where nums > 1
