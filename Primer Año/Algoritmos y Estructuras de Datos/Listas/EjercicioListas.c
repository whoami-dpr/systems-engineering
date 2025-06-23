#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
    char nombre[50];
    char prov[50];
    int cod;
};

struct Lista {
    struct Producto dato;
    struct Lista *psig;
};

typedef struct Lista *L;

L puntero = NULL;

void insertarLista(L *puntero, char nom[50], char prov[50], int cod){
    L Aux;
    Aux = malloc(sizeof(struct Lista));
    strcpy(Aux->dato.nombre, nom);
    strcpy(Aux->dato.prov, prov);
    Aux->dato.cod = cod;
    Aux->psig = *puntero;
    *puntero = Aux;
}

void CargarProductos(){
    char nombre [50];
    char prov[50];
    int cod, resp;
    resp = 1;
    while (resp == 1)
    {
        printf("Ingrese el nombre del producto: \n");
        scanf("%s", &nombre);
        printf("Ingrese el nombre proveedor del producto: \n");
        scanf("%s", &prov);
        printf("Ingrese el codigo del producto: \n");
        scanf("%d", &cod);
        insertarLista(&puntero, nombre, prov, cod);
        printf("Hay algun otro producto para cargar? (1. Si/2. No)");
        scanf("%d", &resp);
    }
}

void EliminarxCod(L *puntero){
    L Actual, Anterior;
    Actual = *puntero;
    int cod;
    printf("Ingrese el codigo del producto que quiere eliminar \n");
    scanf("%d", &cod);
    while (Actual != NULL){
        if (Actual->dato.cod == cod)
        {
            *puntero = Actual -> psig;
            free(Actual);
            printf("Producto eliminado con exito \n");
            return;
        } else {
        Anterior = Actual;
        Actual = Actual->psig;
        }
    }
}

void ModificarxCod(L *puntero){
    L Actual = *puntero;
    L Aux = *puntero;
    int cod, resp, caso;
    char nom[50];
    char prov[50];
    printf("Ingrese el codigo del producto que quiere modificar: \n");
    scanf("%d", &cod);
    while (Actual != NULL){
        if (Actual->dato.cod == cod){
        printf("Producto encontrado con exito para modificar \n \n");
        resp = 1;
        while (resp == 1) {
        printf("Elija que tipo de dato quiere modificarle: \n");
        printf("1. para el cambiar el nombre \n");
        printf("2. para el cambiar el nombre del proveedor \n");
        printf("3. para el cambiar el codigo \n");
        scanf("%d", &caso);
        switch (caso)
        {
        case 1:
            printf("Ingrese el nombre a cambiar: \n");
            scanf("%s", &nom);
            strcpy(Aux->dato.nombre, nom);
            break;
        case 2:
            printf("Ingrese el nombre del proveedor a cambiar: \n");
            scanf("%s", &prov);
            strcpy(Aux->dato.prov, prov);
            break;
        case 3:
            printf("Ingrese el codigo a cambiar: \n");
            scanf("%d", &cod);
            Aux->dato.cod = cod;
            break;
        default:
            break;
        }
        printf("Hay algun otro dato para modificar? (1. Si/2. No) \n");
        scanf("%d", &resp);
        }
        }
        Actual = Actual->psig;
    }
}

void MostrarLista(L *puntero){
    L Aux = *puntero;
    int i = 0;
    while (Aux != NULL)
    {
        i++;
        printf("------------------------------ \n");
        printf("El producto: %d \n", i);
        printf("Nombre: %s \n", Aux->dato.nombre);
        printf("Proveedor: %s \n", Aux->dato.prov);
        printf("Codigo: %d \n", Aux->dato.cod);
        printf("------------------------------ \n");
        Aux = Aux->psig;
    }
    printf("Se llego al final de la lista \n");

}


int main(){
    int resp;
    while (resp != 5)
    {
        printf("Bienvenido, Ingrese una opcion \n");
        printf("1. Si quiere cargar datos \n");
        printf("2. Si quiere eliminar un producto \n");
        printf("3. Si quiere modificar un producto \n");
        printf("4. Si quiere ver la lista \n");
        scanf("%d", &resp);
        switch (resp)
        {
        case 1:
            CargarProductos();
            break;
        case 2:
            EliminarxCod(&puntero);
            break;
        case 3:
            ModificarxCod(&puntero);
            break;
        case 4:
            MostrarLista(&puntero);
            break;
        default:
            break;
        }
    }
    return 0;
}

