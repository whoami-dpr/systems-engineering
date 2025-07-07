USE REDVEN;

-- Mostrar toda la informaci�n de los clientes.
SELECT * FROM Cliente

-- Listar solamente el �apellido y nombres� (orden descendente) de todos los clientes.
SELECT Apellido, Nombre FROM Cliente ORDER BY Apellido DESC;

/* Realizar una selecci�n que le permita mostrar la CANTIDAD 
total de clientes portipo de IVA existente. */
SELECT IDTipoIva, COUNT(*) AS CantidadCliente
FROM Cliente
GROUP BY IDTipoIVA;

/* Realizar una selecci�n que le permita listar toda la informaci�n pertinente de
aquellos clientes que tienen el apellido Martinez. */
SELECT * FROM Cliente WHERE Apellido = 'Martinez'

/* Muestre un informe que brinde como resultado: la cantidad de clientes que tienen un mismo nombre.
Debe indicar Nombre, Cantidad. */
SELECT C.RazonSocial, COUNT(C.Token) AS Cantidad
FROM Cliente C
GROUP BY C.RazonSocial
HAVING COUNT(C.Token) > 1;

/* Realizar una selecci�n que le permita listar la cantidad de veces que se 
vendi� cada producto en el a�o actual. Cantidad de veces, no es cantidad de art�culos. */
SELECT A.Descripcion, COUNT(IV.idVenta) AS CantVecesVendida
FROM Venta V
JOIN ItemVenta IV ON V.idVenta = IV.idVenta
JOIN Articulo A ON IV.idArticulo = A.idArticulo
WHERE YEAR(V.Fecha) = 2018
GROUP BY A.Descripcion;

/* Realizar una selecci�n que le permita listar solamente el �apellido y nombre� y 
DNI de todos los clientes ordenados por DNI (ascendente), que no tengan un CUIT registrado */
SELECT RazonSocial, DNI 
FROM Cliente
WHERE CUIT IS NULL
ORDER BY DNI ASC;

/* Listar los clientes que est�n registrados como Responsables Inscriptos, pero 
no tienen registrado su CUIT como es debido. */
SELECT * FROM Cliente
WHERE IDTipoIva = (SELECT IDTipoIva FROM TipoDeIva WHERE Descripcion = 'Resp. Inscripto')
AND (CUIT IS NULL OR CUIT = '');

/* Realizar una selecci�n que le permita listar el promedio de veces que ha sido vendido 
cada art�culo en el historial, y ordenar de manera descendente de mayor a menor. 
De cada art�culo incluir el dato de c�digo y descripci�n. */
SELECT 
    A.codigo,
    A.Descripcion, 
    AVG(IV.cantidad) AS promedio
FROM Venta V 
JOIN ItemVenta IV ON V.idVenta = IV.idVenta 
JOIN Articulo A ON IV.idArticulo = A.idArticulo
GROUP BY A.codigo, A.Descripcion
ORDER BY promedio DESC;

/* Devuelva el listado de la cantidad de art�culos registrada por cada secci�n por cada empresa. 
Ordenar todo por orden alfab�tico. */
SELECT 
    E.RazonSocial,
    S.NombreSeccion,
    COUNT(A.idArticulo) AS CantidadArticulos
FROM Seccion S
JOIN Empresa E ON S.idEmpresa = E.idEmpresa
JOIN Rubro R ON R.idSeccion = S.idSeccion
JOIN Articulo A ON A.idRubro = R.idRubro
GROUP BY E.RazonSocial, S.NombreSeccion
ORDER BY E.RazonSocial, S.NombreSeccion;

SELECT * FROM Empresa

-- Resuelva el listado que devuelva cual fue el monto vendido por empresa en el a�o actual.
SELECT 
    E.RazonSocial, 
    SUM(IV.Cantidad * IV.Precio) AS MontoVendido
FROM Empresa E
JOIN Seccion S ON E.idEmpresa = S.idEmpresa
JOIN Rubro R ON S.idSeccion = R.idSeccion
JOIN Articulo A ON R.idRubro = A.idRubro
JOIN ItemVenta IV ON A.idArticulo = IV.idArticulo
JOIN Venta V ON V.idVenta = IV.idVenta
WHERE YEAR(V.Fecha) = YEAR(GETDATE())
GROUP BY E.RazonSocial
ORDER BY E.RazonSocial;

/* Realizar una selecci�n de los productos que se contengan la palabra �unipolar�, 
junto con sus precios */
SELECT Descripcion, Precio FROM Articulo WHERE Descripcion LIKE '%unipolar%';

-- Generar la consulta que emita la lista de precios m�s completa de cada empresa.
SELECT 
    E.RazonSocial AS Empresa,
    A.Descripcion AS Articulo,
    A.Precio
FROM Empresa E
JOIN Seccion S ON E.idEmpresa = S.idEmpresa
JOIN Rubro R ON S.idSeccion = R.idSeccion
JOIN Articulo A ON R.idRubro = A.idRubro
ORDER BY E.RazonSocial, A.Descripcion;

/* Devolver el listado de los Usuarios que est�n registrados en m�s de una empresa. 
Devolver, Apellido y Nombre, y la cantidad de empresas en las que se encuentra registrado. */
SELECT U.AyN, COUNT(*) AS UsuariosRegistrados
FROM Usuario U
JOIN UsuarioXEmpresa UXE ON U.UserToken = UXE.UserToken
JOIN Empresa E ON UXE.idEmpresa = E.idEmpresa

GROUP BY U.AyN
HAVING COUNT(DISTINCT UXE.idEmpresa) > 1

/* Listar los art�culos que nunca han sido vendidos. Luego listar la 
cantidad de art�culos que jam�s fueron vendidos.  */
SELECT A.idArticulo, A.Descripcion
INTO ArticulosNoVendidos
FROM Articulo A
WHERE A.idArticulo NOT IN (
    SELECT IV.idArticulo FROM ItemVenta IV
);

SELECT COUNT(*) AS CantidadArticulosNoVendidos
FROM ArticulosNoVendidos;

-- Listar el monto total vendido por mes en el a�o 2019 por cada una de las empresas.SELECT 
    E.RazonSocial, 
    MONTH(V.Fecha) AS Mes,
    SUM(IV.Cantidad * IV.Precio) AS MontoPorMes
FROM Empresa E
JOIN Seccion S ON E.idEmpresa = S.idEmpresa
JOIN Rubro R ON S.idSeccion = R.idSeccion
JOIN Articulo A ON R.idRubro = A.idRubro
JOIN ItemVenta IV ON A.idArticulo = IV.idArticulo
JOIN Venta V ON V.idVenta = IV.idVenta
WHERE YEAR(V.Fecha) = 2019
GROUP BY E.RazonSocial, MONTH(V.Fecha)
ORDER BY E.RazonSocial, Mes;

/* Listar las ventas realizadas por d�a de la semana en todo el historial de la base de datos, pero,
ordenada por n�mero de d�a. */
SELECT 
    DATEPART(WEEKDAY, Fecha) AS NumeroDiaSemana,
    DATENAME(WEEKDAY, Fecha) AS NombreDiaSemana,
    COUNT(*) AS VentasRealizadasPorDia
FROM Venta
GROUP BY DATEPART(WEEKDAY, Fecha), DATENAME(WEEKDAY, Fecha)
ORDER BY NumeroDiaSemana;