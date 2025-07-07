USE ventas_e;

-- Eliminar la columna 'Usuario' de la tabla
ALTER TABLE Usuario
DROP COLUMN Usuario;

-- Agregar un nuevo campo que sea email (varchar(70))
ALTER TABLE Usuario
ADD Email VARCHAR(70);

/* Agregar los campos Domicilio (varchar(150)) y Telefono (varcvhar(30)) en la tabla Usuario.
Luego, agregar los mismos campos a la tabla Empresa. */

ALTER TABLE Usuario
ADD Domicilio VARCHAR(150);
ALTER TABLE Usuario
ADD Telefono VARCHAR(30);

ALTER TABLE Empresa
ADD Domicilio VARCHAR(150);
ALTER TABLE Empresa
ADD Telefono VARCHAR(30);