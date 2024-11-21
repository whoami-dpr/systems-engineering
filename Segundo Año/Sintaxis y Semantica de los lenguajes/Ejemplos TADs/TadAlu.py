def crearAlu():
    #Crea un alumno vacio
    alumno=["",0,0]
    return alumno

def cargarAlu(alumno,n,l,p):
    #Carga los datos de un alumno
    alumno[0]=n
    alumno[1]=l
    alumno[2]=p

def verNom(alumno):
    #Retorna el nombre de un alumno
    return alumno[0]

def verLega(alumno):
    #Retorna el nombre de un alumno
    return alumno[1]

def verProm(alumno):
    #Retorna el nombre de un alumno
    return alumno[2]

def modiNom(alumno,n):
    #Modifica el nombre de un alumno
    alumno[0]=n

def modiLega(alumno,l):
    #Modifica el nombre de un alumno
    alumno[1]=l

def modiProm(alumno,p):
    #Modifica el nombre de un alumno
    alumno[2]=p

def asignarAlu(alumno1,alumno2):
    #Asigna los datos de un alumno en otro. Se puede hacer con las funciones o directamente elemento a elemento
    # alumno1[0]=alumno2[0]....
    modiNom(alumno1,verNom(alumno2))
    modiLega(alumno1,verLega(alumno2))
    modiProm(alumno1,verProm(alumno2))


