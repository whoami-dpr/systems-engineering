from TadAlu import *
def crearCurso():
    #Crea un curso vacio
    curso=[]
    return curso

def agregarAlu(curso,a):
    #Agrega un alumno a al curso
    curso.append(a)

def eliminarAlu(curso,a):
    #Elimina al  alumno a del curso
    curso.remove(a)

def recuperarAlu(curso,i):
    #Retorna el alumno de la posicion iesima
    return curso[i]

def tamanio(curso):
    #Retorna la cantidad de alumnos del curso
    return len(curso)

def existeAlu(curso, a):
    #Retorna True o False si el alumno a pertenece al curso
    return  a in curso
