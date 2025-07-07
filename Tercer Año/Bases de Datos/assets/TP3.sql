use REDVEN

-- 1)
CREATE PROCEDURE SP_CantidadVendida
    @Articulo INT,
    @Fecha1 DATE,
    @Fecha2 DATE
AS
BEGIN
    SELECT COUNT(*) AS CantidadVendida
    FROM Articulo A
    JOIN ItemVenta IV ON A.idArticulo = IV.idArticulo
    JOIN Venta V ON IV.idVenta = V.idVenta
    WHERE A.idArticulo = @Articulo
      AND V.Fecha BETWEEN @Fecha1 AND @Fecha2;
END;

-- 2)
CREATE PROCEDURE SP_ListadoClientes
    @Mes int,
    @Anio int
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM Venta V
        WHERE MONTH(V.Fecha) = @Mes AND YEAR(V.Fecha) = @Anio
    )
    BEGIN
        SELECT DISTINCT C.*
        FROM Cliente C
        JOIN Venta V ON C.Token = V.Token
        WHERE MONTH(V.Fecha) = @Mes AND YEAR(V.Fecha) = @Anio;
    END
    ELSE
    BEGIN
        SELECT 'SIN CLIENTES' AS Mensaje;
    END;
END;

--3)
CREATE PROCEDURE SP_ListarMontoClientes
    @Año int
AS
BEGIN
    SELECT 
        C.Token,
        C.RazonSocial,
        SUM(IV.Cantidad * IV.Precio) AS TotalComprado
    FROM Cliente C
    JOIN Venta V ON C.Token = V.Token
    JOIN ItemVenta IV ON V.idVenta = IV.idVenta
    WHERE YEAR(V.Fecha) = @Año
    GROUP BY C.Token, C.RazonSocial
    HAVING SUM(IV.Cantidad * IV.Precio) > 500000;
END;

-- 4)
ALTER TABLE Articulo
ADD Imagen VARBINARY(MAX)

CREATE PROCEDURE SP_AgregarImagenProducto
	@img VARBINARY(MAX),
	@idArticulo int
AS
BEGIN
    IF NOT EXISTS (SELECT 1 FROM Articulo WHERE idArticulo = @idArticulo)
    BEGIN
        RAISERROR('El artículo no existe.', 16, 1);
        RETURN;
    END

    UPDATE Articulo
    SET Imagen = @img
    WHERE idArticulo = @idArticulo;

	SELECT COUNT(A.Imagen) AS CantidadFotos
	FROM Articulo A
	WHERE A.idArticulo = @idArticulo;
END;

-- 5)
CREATE PROCEDURE SP_SeccionesSinRubro
AS
BEGIN
	SELECT * FROM Seccion S
	WHERE S.idSeccion NOT IN (SELECT R.idSeccion FROM Rubro R);
END;

-- 6)
CREATE PROCEDURE SP_RankingClientes
AS
BEGIN
	SELECT 
		C.RazonSocial AS Nombre_y_Apellido, 
		C.DNI, 
		C.Domicilio, 
		COUNT(V.idVenta) AS CantidadCompras 
	FROM Cliente C
	JOIN Venta V ON C.Token = V.Token
	GROUP BY C.RazonSocial, C.DNI, C.Domicilio
	ORDER BY CantidadCompras DESC;
END;

-- 7)
CREATE PROCEDURE SP_BuenosClientes
	@monto as int
AS
BEGIN
	SELECT 
		C.RazonSocial AS Nombre_y_Apellido, 
		C.DNI,
		V.idVenta
	FROM Cliente C
	JOIN Venta V ON C.Token = V.Token
	JOIN ItemVenta IV ON V.idVenta = IV.idVenta
	GROUP BY C.RazonSocial, C.DNI, V.idVenta
	HAVING SUM(IV.Cantidad*IV.Precio) > @monto;
END;
