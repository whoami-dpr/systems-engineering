USE ventas_e;

-- Agrego la columna Dominio a la tabla 'Empresa'
ALTER TABLE Empresa
ADD Dominio VARCHAR(50);

-- Inserto datos a Empresa
INSERT INTO Empresa (RazonSocial, CUIT, Domicilio, Telefono, Dominio) 
VALUES ('ALBOCAR', '20-24563524-1', '536 nro. 67', '0221 455-8523', 'Albocar');
INSERT INTO Empresa (RazonSocial, CUIT, Domicilio, Telefono, Dominio) 
VALUES ('AUTOCLIPS VAER SA', '30-56225853-4', 'Ate. Brown 876', '011 4457-7778', 'Vaersa');
INSERT INTO Empresa (RazonSocial, CUIT, Domicilio, Telefono, Dominio) 
VALUES ('GOICOECHEA', '30-57788523-5', 'Pte. Perón 4521', '0224 4522-3652', 'Goicoechea');
INSERT INTO Empresa (RazonSocial, CUIT, Domicilio, Telefono, Dominio) 
VALUES ('CGO', '27-24246552-2', '46 Nro. 1587', '0221 412-5623', 'Districgo');
INSERT INTO Empresa (RazonSocial, CUIT, Domicilio, Telefono, Dominio) 
VALUES ('BELPE', '30-45235689-7', '122 Nro. 4201', '0221 423-2323', 'Belpe');
INSERT INTO Empresa (RazonSocial, CUIT, Domicilio, Telefono, Dominio) 
VALUES ('DISTRIFERR', '20-58545565-1', 'Moreau Nro. 524', '0229 45-5623', 'Distriferr');
INSERT INTO Empresa (RazonSocial, CUIT, Domicilio, Telefono, Dominio) 
VALUES ('AZ MOTOR', '30-44215532-5', '44 Esq. 200 Nro. 4522', '0221 452-5262', 'Azmotor');
