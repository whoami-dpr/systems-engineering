alter procedure Nombre 
 @patron varchar(30), @valor int
as
begin
 declare @@intero int;
 set @@intero = 0;
 if(@valor > 2) 
 begin 
 select * from cliente where razonsocial like '%' + @patron + '%'
 end 
 else
 begin 
  print 'EL valor no cumple' 
 end 

end

exec Nombre 'Maxi',1;

exec Nombre 'Maxi',3;

-- devuelva de la tabla cliente toda la lista de clientes,  en cada caso
-- si el cliente tiene CUIT devolver el CUIT si no, la leyenda 'CONS. FINAL'
select  
RazonSocial, case when (CUIT is not null) then CUIT else 'Cons. Final' end
from cliente 
where CUIT is not null

-- 1)	Cree el SP (Stored Procedure), que recibiendo un art�culo determinado 
-- y un par de fechas, devuelva la cantidad que se han vendido de dicho producto
-- en el per�odo conformado por las fechas recibidas. 

create procedure Ejercicio1P3
@idArt int, @Fi date, @Ff date
as
begin

	select cantidadVendida = Sum(IV.Cantidad)

	from venta V join ItemVenta IV on V.idVenta = IV.idventa
		join Articulo A on IV.idArticulo = A.idArticulo

	where IV.idArticulo = @idArt
	      and V.Fecha between @Fi and @Ff
end

exec Ejercicio1P3 9180,'01/01/2000','01/04/2024'

-- 2)	Cree el SP, en la que recibiendo un mes y a�o, devuelva el listado 
-- clientes que compraron en ese per�odo. En caso de no haber ning�n cliente, 
-- que devuelva la leyenda SIN CLIENTES.

alter procedure Ejercicio2P3 
	@mes smallint, @a�o smallint
as 
begin
if ((select count(*)
from cliente C join Venta V on C.Token = V.Token
where month(V.Fecha) = @mes and year(V.Fecha) = @a�o) >= 1) 
begin
	(select distinct  c.RazonSocial 
	from cliente C join Venta V on C.Token = V.Token
	where month(V.Fecha) = @mes and year(V.Fecha) = @a�o )
end 
 else begin select 'SIN RESULTADOS' end
end

exec Ejercicio2P3 01,2021

-- 3) Crear el SP que devuelva los Clientes que han comprado m�s de $500000
-- en un a�o que se recibe por par�metro.
create procedure Ejecricio3P3
@a�o int
as 
begin 
	select
	C.RazonSocial, TotalComprado = Sum(IV.Cantidad * IV.Precio)
	from
	cliente C join Venta V on C.Token = V.Token
	join ItemVenta IV on V.idventa = IV.idVenta
	where @a�o = Year(V.Fecha)
	group by C.RazonSocial
	having Sum(IV.Cantidad * IV.Precio) > 500000
	order by C.RazonSocial 
end

exec Ejecricio3P3 2021

-- 4) Se requiere la creaci�n de un SP que reciba una imagen como par�metro, 
-- la inserte a un producto que se recibe como par�metro, y luego devuelva 
-- la cantidad de fotos que tiene registrado el art�culo correspondiente.
create procedure Ejercicio4P3
@img image, @desc varchar(100), @idArt int
as 
begin 
if (@desc is null or not (len(@desc) >= 0 and len(@desc) <= 100))
begin print 'No se cumple condicion de descripcion' end
else
begin
	insert into imagen values(@idArt, @img, @desc);

	select count(*) from imagen where @idArt = idArticulo

end
	
end

exec Ejercicio4P3 'peraararsdasdfdsfdsf','hol',9180