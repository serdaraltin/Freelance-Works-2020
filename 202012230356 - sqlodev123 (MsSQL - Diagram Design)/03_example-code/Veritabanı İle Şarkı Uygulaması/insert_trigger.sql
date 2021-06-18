create trigger dinleme_sarki_sil
on sarki
for insert
as
declare @Id int
select @Id=id from inserted
insert into dinleme(id, dinleme_sayisi) VALUES(@Id, 0)
