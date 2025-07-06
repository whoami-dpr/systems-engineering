/* Enunciado del problema: Gestión de una cola de tareas pendientes 

Escribe un programa en C que simule la gestión de una cola de tareas pendientes. 
El programa debe permitir al usuario realizar las siguientes operaciones:

Agregar una tarea pendiente: El usuario debe poder ingresar una descripción de la tarea y 
esta debe agregarse a la cola de tareas pendientes.

Completar una tarea: El usuario puede marcar una tarea como completada. 
La tarea se elimina de la cola de tareas pendientes y se agrega a una lista de tareas completadas.

Mostrar tareas pendientes: El programa debe mostrar todas las tareas pendientes en
orden de llegada (primero en entrar, primero en salir).

Mostrar tareas completadas: El programa debe mostrar todas las tareas que se han completado.

Salir del programa: El usuario puede elegir salir del programa en cualquier momento.

Debes implementar la cola de tareas pendientes y la lista de tareas completadas 
utilizando estructuras de datos en C. Puedes usar arreglos, listas enlazadas o cualquier 
otra estructura que consideres adecuada.

Asegúrate de manejar adecuadamente la memoria y validar las entradas del usuario para evitar errores. 
El programa debe ser lo más interactivo y amigable posible para el usuario.

Este ejercicio te permitirá practicar la manipulación de listas y colas en C, así como
la gestión de memoria y la interacción con el usuario a través de la entrada y salida estándar. ¡Buena suerte! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tareas {
    char tarea[50];
};

struct ListaTCompletas {
    struct tareas dato;
    struct ListaTCompletas *psig;
};

struct colaTPendientes{
    struct tareas dato;
    struct colaTPendientes *psig;
}; 

struct ListaTCompletas *a = NULL;
struct colaTPendientes *P = NULL;
struct colaTPendientes *U = NULL;

void insertarNodoCola(struct colaTPendientes **P, struct colaTPendientes **U, char t[50]){
    struct colaTPendientes *Aux = malloc(sizeof(struct colaTPendientes));
    strcpy(Aux->dato.tarea, t);
    Aux->psig = NULL;
    if(*P == NULL){
        *P = Aux;
        *U = Aux;
    } else {
        (*U)->psig = Aux;
        *U = Aux;
    }
}

void cargarCola(){
    int resp = 1;
    char tarea[50];
    while(resp == 1){
        printf("Ingrese la tarea pendiente a cargar\n");
        scanf("%s", &tarea);
        insertarNodoCola(&P, &U, tarea);
        printf("Hay alguna otra tarea a cargar (1. Si /2. No)\n");
        scanf("%d", &resp);
    }
}

void insertarNodoLista(struct ListaTCompletas **a, char t[50]){
    struct ListaTCompletas *Nuevo = malloc(sizeof(struct ListaTCompletas));
    strcpy(Nuevo->dato.tarea, t);
    Nuevo->psig = NULL;
    if(*a == NULL){
        *a = Nuevo;
    } else {
        struct ListaTCompletas *temp = *a;
        while(temp->psig != NULL){
            temp = temp->psig;
        }
        temp->psig = Nuevo;
    }
}

void transferirTarea(struct colaTPendientes **P){
    char tarea[50];
    struct colaTPendientes *Aux;
    struct colaTPendientes *Anterior = NULL;
    Aux = *P;
    printf("ingrese una Tarea Pendiente a Transferir:\n");
    scanf("%s", &tarea);
    if(Aux == NULL){
        printf("Lista Vacia \n");
        return;
    } else if ((strcmp(Aux->dato.tarea, tarea) == 0) && (Aux == *P)){
            insertarNodoLista(&a, tarea);
            *P = Aux->psig;
            free(Aux);
            return;
    } else {
    while (Aux != NULL){ 
        if (strcmp(Aux->dato.tarea, tarea) == 0){
            printf("Tarea transferida con Exito\n");
            insertarNodoLista(&a, tarea);
            Anterior->psig = Aux->psig;
            free(Aux);
            return;
        } else {
            Anterior = Aux;
            Aux = Aux->psig;
        }
    }
    }
}

void MostrarCola(struct colaTPendientes  **P){
    struct colaTPendientes *Aux;
    Aux = *P;
    int i = 1;
    if (Aux == NULL)
        {
            printf("Lista Vacia\n");
        } else {
            while (Aux != NULL) {
        printf("La tarea pendiente: %d\n", i++);
        printf("Es: %s \n", Aux->dato.tarea);
        Aux = Aux->psig;
        }
        }
}

void MostrarLista(struct ListaTCompletas **a){
    struct colaTPendientes *Aux;
    Aux = *a;
    int i = 0;
    if (Aux == NULL)
        {
            printf("Lista Vacia\n");
        } else {
            while (Aux != NULL) {
        printf("La tarea pendiente: %d \n", i++);
        printf("Es: %s \n", Aux->dato.tarea);
        Aux = Aux->psig;
        }
        }
}

void Menu(){
    int resp = 1;
    int caso;
    while (resp != 5){
        printf("---------------------------------------------------\n");
        printf("Bienvenido!, ingrese una opcion:\n");
        printf("1. Si quiere Cargar una tarea a realizar (Es decir Pendiente)\n");
        printf("2. Si quiere transferir una tarea, es decir, pasar de pendiente a completada\n");
        printf("3. Si quiere ver la lista de tareas Pendientes\n");
        printf("4. Si quiere ver la lista de tareas Completadas\n");
        printf("5. Si quiere salir\n");
        printf("--------------------------------------------\n");
        scanf("%d", &caso);
        switch (caso)
        {
        case 1:
            cargarCola();
            break;
        case 2:
            transferirTarea(&P);
            break;
        case 3:
            MostrarCola(&P);
            break;
        case 4:
            MostrarLista(&a);
            break;
        default:
            printf("Opcion incorrecta, vuelva a intentarlo\n");
            break;
        }     
    }
}

int main(){
    Menu();
}
