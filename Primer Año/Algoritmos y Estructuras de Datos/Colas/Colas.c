#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// COLAS

struct Producto {
    char nombre[50];
    int Cod;
    int Stock;
};

struct Cola{
    struct Producto dato;
    struct Cola *psig; 
};

struct Cola *P = NULL; // Creo dos punteros, este apunta al principio
struct Cola *U = NULL; // Este apunta al final de la lista

// EN INSERTAR NODO EN LA COLA, LOS NODOS LOS INSERTO SIEMPRE AL FINAL DE LA LISTA.
// PARA LUEGO RECORRER LA LISTA CON EL PUNTERO *P QUE APUNTA AL INICIO DE LA LISTA.

void insertarNodoEnCola(struct Cola **P, struct Cola **U, char nom[50], int Cod, int Stock){
    struct Cola *Nuevo = malloc(sizeof(struct Cola));
    strcpy(Nuevo->dato.nombre, nom);
    Nuevo->dato.Cod = Cod;
    Nuevo->dato.Stock = Stock;
    Nuevo->psig = NULL;
    if (*P == NULL) // si la lista esta vacia, esto.
    {
        *P = Nuevo;
        *U = Nuevo;
    } else {  // esto si la lista NO esta vacia.
        (*U)->psig = Nuevo;
        *U = Nuevo;
    }
};

void CargarCola(){
    int codigo, s, resp;
    char nom[50];
    resp = 1;
    while (resp == 1){
        printf("Ingrese el Nombre a asignar: \n");
        scanf("%s", nom);
        printf("Ingrese el Codigo a asignar: \n");
        scanf("%d", &codigo);
        printf("Ingrese el Stock a asignar: \n");
        scanf("%d", &s);
        insertarNodoEnCola(&P, &U,nom, codigo, s);
        printf("Hay otro prodcuto a cargar? (1. Si / 2. No) \n");
        scanf("%d", &resp);
    }
}

void desencolar(struct Cola **P, struct Cola **U){
    struct Cola *Aux;
    Aux = *P;
    if (Aux == NULL){
        printf("Lista vacia");
    }  else {
        *P = Aux->psig;
        printf("----------------------------\n");
        printf("Elemento: %s \n", Aux->dato.nombre);
        printf("Codigo: %d \n", Aux->dato.Cod);
        printf("Eliminado con Exito!\n");
        printf("----------------------------\n");
        free(Aux);

    }
}


void mostrarLista(struct Cola **P){
    struct Cola *Aux;
    Aux = *P;
    int i = 1;
    if (Aux == NULL)
    {
        printf("Lista Vacia");
    } else {
          while(Aux != NULL){
        printf("--------------------------------\n");
        printf("El Producto: %d \n", i++);
        printf("Nombre: %s \n", Aux->dato.nombre);
        printf("Codigo: %d \n", Aux->dato.Cod);
        printf("Stock: %d \n", Aux->dato.Stock);
        printf("--------------------------------\n");
        Aux = Aux->psig;
        }
    }
}

void Menu(){
    int resp, caso;
    resp = 1;
    while (resp !=4)
    {
        printf("----------------------------------------------------------\n");
        printf("Bienvenido!, ingrese una opcion:\n");
        printf("1. Si quiere agregar Productos a una Cola\n");
        printf("2. Si quiere eliminar el ultimo elemento de la Cola\n");
        printf("3. Si quiere mostrar todos los elementos de la Cola\n");
        printf("4. Si quiere salir\n");
        printf("----------------------------------------------------------\n");
        scanf("%d", &caso);
        switch (caso)
        {
        case 1:
            CargarCola();
            break;
        case 2:
            desencolar(&P, &U);
            break;
        case 3:
            mostrarLista(&P);
            break;
        default:
            printf("Opcion Incorrecta\n");
            break;
        }
    }
}

int main(){
    Menu();
}