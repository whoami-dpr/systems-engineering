#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
    int codigo;
    char nombre[50];
    int stock;
};

struct Lista {
    struct Producto dato;
    struct Lista* ps;
};

typedef struct Lista* L;

L puntero = NULL;

void insertarEnLaLista(L* puntero, int cod, char nombre[50], int stock) {
    L Aux;
    Aux = malloc(sizeof(struct Lista));
    Aux->dato.codigo = cod;
    strcpy(Aux->dato.nombre, nombre);
    Aux->dato.stock = stock;
    Aux->ps = *puntero;
    *puntero = Aux;
};

void MostrarLista(L *puntero){
    L Aux;
    char nom[50];
    int cod, stock;
    printf("Ingrese el nombre del alumno que quiere buscar \n");
    scanf("%s", &nom);
    if (Aux->dato.nombre == nom)
    {
        Aux->dato.codigo = cod;
        Aux->dato.stock = stock;
        printf("El codigo es: %d \n Stock: %d \n del alumno %s", cod, stock, nom);
    }
    

};

int main() {
    int cod, stock;
    char nombre[50];

    printf("Ingrese el codigo del producto: ");
    scanf("%d", &cod);

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombre);

    printf("Ingrese el stock del producto: ");
    scanf("%d", &stock);

    insertarEnLaLista(&puntero, cod, nombre, stock);
    MostrarLista(&puntero);

    return 0;
}