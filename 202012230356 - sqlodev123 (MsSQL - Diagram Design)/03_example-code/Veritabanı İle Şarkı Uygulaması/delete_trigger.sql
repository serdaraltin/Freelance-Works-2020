create trigger dinleme_sarki_sil
on sarki
for delete
as
declare @Id int
select @Id=id from deleted
delete from dinleme where id = @Id
