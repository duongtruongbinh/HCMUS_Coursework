use QLDT1;
go
CREATE PROCEDURE cau1
	@magv varchar(50),
	@madt varchar(50)
As
BEGIN
	If( not exists(select *
		from giaovien
		where magv=@magv) or not exists (select *
		from detai
		where madt=@madt))
		Return
	Declare @n int
	Select @n=count(*)
	from detai
	where gvcndt=@magv
	Declare @m int
	Select @m=count(*)
	from thamgiadt
	where madt=@madt
	If(n<3 and m>=2) 
		Update detai set gvcndt=@magv where madt=@madt
end
