#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona{
    char nom[50];
    int edad;
};

struct Lista{
    struct Persona dato;
    struct Lista *psig;
};

struct Lista *P = NULL;

void insertarFinal(struct Lista **P, char n[50], int edad){
    struct Lista *Nuevo = malloc(sizeof(struct Lista));
    strcpy(Nuevo->dato.nom, n);
    Nuevo->dato.edad = edad;
    Nuevo->psig = NULL;
    if(*P == NULL){
        *P = Nuevo;
    } else {
        struct Lista *Aux;
        Aux = *P;
        while(Aux->psig != NULL){
            Aux = Aux->psig;
        }
        Aux->psig = Nuevo;
    }
};

void cargarLista(){
    int resp = 1;
    int edad;
    char nom[50];
    while(resp == 1){
        printf("Ingrese el nombre de la persona a listar\n");
        scanf("%s", &nom);
        printf("Ingrese la edad de la persona a listar\n");
        scanf("%d", &edad);
        insertarFinal(&P, nom, edad);
        printf("Hay alguna otra tarea a cargar (1. Si /2. No)\n");
        scanf("%d", &resp);
    }
}

void mostrarLista(struct Lista **P){
    int i = 1;
    struct Lista *Aux = *P;
    if (Aux == NULL)
    {
        printf("Lista Vacia\n");
        return;
    }
    while (Aux != NULL){
        printf("La Persona: %d \n", i++);
        printf("Nombre: %s \n", Aux->dato.nom);
        printf("Edad: %d \n", Aux->dato.edad);
        Aux = Aux->psig;
    }
    printf("Lista recorrida con exito!\n");
};

void Menu(){
    int resp = 1;
    int caso;
    while (resp != 3){
        printf("---------------------------------------------------\n");
        printf("Bienvenido!, ingrese una opcion:\n");
        printf("1. Si quiere Listar una Persona\n");
        printf("2. Si quiere ver la lista de Persona\n");
        printf("3. Si quiere salir\n");
        printf("--------------------------------------------\n");
        scanf("%d", &caso);
        switch (caso)
        {
        case 1:
            cargarLista();
            break;
        case 2:
            mostrarLista(&P);
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