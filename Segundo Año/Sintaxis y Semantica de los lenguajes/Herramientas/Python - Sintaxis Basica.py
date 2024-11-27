# variables
import datetime
from datetime import datetime

nombreVariable = 0
nombreString = "Hola Mundo"

[1, "Matias", 3.24, 4, 5]

print("Hola Mundo")
print(nombreString)

variableInput = input("Ingrese un valor: ")
variableInputInt = int(input("Ingrese un numero: "))
variableInputFloat = float(input("Ingrese un numero: "))

# Estructura IF
nombre = "Matias"
if (nombre == "Matias") and not (variableInputInt != 1):
    print("Hola Matias")
elif (nombre == "Juan"):
    print("Hola Juan")
else:
    print("No eres Matias")

# Estructura WHILE
while nombreVariable < 10:
    print(nombreVariable)
    nombreVariable += 1

while (nombreVariable < 10):
    if nombreVariable == 3:
        print("Tres")
    nombreVariable += 1

# Estructura FOR
for i in range(10):
    print(i)

for elemento in ['Matias', 'Juan', 'Pedro']:
    print(elemento)

for indice, elemento in enumerate(['Matias', 'Juan', 'Pedro']):
    print(elemento)
    print(indice)


def nombreFuncion(parametro1, parametro2):
    print(parametro1)
    print(parametro2)
    print(parametro1 + parametro2)
    return parametro1 + parametro2


suma = nombreFuncion(parametro2=1, parametro1=2)
print(suma)
