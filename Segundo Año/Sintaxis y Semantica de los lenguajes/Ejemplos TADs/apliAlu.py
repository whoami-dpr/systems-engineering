from TadAlu import *

#Crea y carga los datos del alumno1
a1=crearAlu()
n=input("Ingrese un nombre  ")
l=int(input("Ingrese un legajo  "))
p=float(input("Ingrese un promedio  "))
cargarAlu(a1,n,l,p)

#Imprime los datos del alumno1
print( "nombre ", verNom(a1))
print (verLega(a1))
print (verProm(a1))

#Crea y carga los datos del alumno2
a2=crearAlu()
n=input("Ingrese un nombre  ")
l=int(input("Ingrese un legajo  "))
p=float(input("Ingrese un promedio  "))
cargarAlu(a2,n,l,p)

#Imprime los datos del alumno1
print ("nombre ",verNom(a2))
print (verLega(a2))
print (verProm(a2))

#Imprime el nombre del alumno de menor legajo
print ("El nombre del alumno de menor legajo es: ")
if (int(verLega(a1)) < int(verLega(a2))):
    print (verNom(a1))
else:
    print (verNom(a2))
