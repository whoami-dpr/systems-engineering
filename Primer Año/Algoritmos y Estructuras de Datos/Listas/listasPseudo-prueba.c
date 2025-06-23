#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ListaAlu = ^Nodoejem
            Nodoejem = Registro
                Dato: Alumno
                Psig: ListaAlu
            Fin registro

Alumno = Registro
    Nom: Caracter 20;
    Curso: Entero 2;
    Fin Registro;


Variables
    L, Nuevo: ListaAlu

Hacer
    Crear(Nuevo)
    Imprimir: "Ingrese nombre"
    Leer: nuevo*dato.nom
    Nuevo*psig=Nil;

    L:= Nuevo;

    Liberar(Nuevo)