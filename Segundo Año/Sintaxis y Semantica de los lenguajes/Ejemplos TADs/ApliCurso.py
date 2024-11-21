
from TadCurso import *
c=crearCurso()

#Cargar el curso con 3 alumnos
for i in range(1,4):
    a=crearAlu()
    n=input("Ingrese un nombre ")
    l=input("Ingrese un legajo ")
    p=float(input("Ingrese un promedio "))
    print('')
    cargarAlu(a,n,l,p)
    agregarAlu(c,a)

#Imprime los alumnos con prom >=8
#print(c)
print('Listado de alumnos con promedio mayor o igual a 8')
tam= tamanio(c )
for i in range(0,tam):
    a=recuperarAlu(c,i)
    if (verProm(a) >=8):
        print ('Nombre: ',verNom(a))
        print ('Legajo :', verLega(a))
        print ('Promedio' , verProm(a))
        print ('__________'*3)
print('********')
a=recuperarAlu(c,1)
print ('Nombre: ',verNom(a))
print ('Legajo :', verLega(a))
print ('Promedio' , verProm(a))
print ('__________'*3)

eliminarAlu(c,a)
tam= tamanio(c )
for i in range(0,tam):
    a=recuperarAlu(c,i)
    print ('Nombre: ',verNom(a))
    print ('Legajo :', verLega(a))
    print ('Promedio' , verProm(a))
    print ('__________'*3)

    
