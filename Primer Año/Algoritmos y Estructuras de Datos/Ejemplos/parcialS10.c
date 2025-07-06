/* Almacén de Ramos Generales: se tiene una lista simplemente enlazada y ordenada de productos con la siguiente información:
 id del producto (elemento por el que se mantiene el listado ordenado), tipo de producto, precio y stock. 
 Al principio del día, viene el proveedor con productos para reponer, y mantiene la información en formato de pila. 
 Los elementos de la pila que están en la lista se actualizan (su stock solamente). No hay productos nuevos. Durante el dia se atiende a los clientes, cada 
 cliente hace un pedido no determinado de productos y al fnal del pedido se imprime un billete con el total(cliente puede llevar distintos productos y siempre habra stock)
Cada vez que se atiende un cliente se va a ctualizando el stock en tiempo real. Adicionalmente se va generando una lista separada de productos vendidos. tiene el
mismo formato que la lista original pero ahora el stock es reemplazado por las cantidades vendidas. al final del dia, recorrer recursivamente para
ver cuanto es el monto total vendido
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct productos{
    int id;
    int tipoProd;
    float precio;
    int stock;
};

struct listaProductos {
    struct productos dato;
    struct listaProductos *psig;
};

struct listaProductos *P = NULL;

void insertarProductos(struct listaProductos **P, struct productos pr){
    struct listaProductos *Aux = malloc(sizeof(struct listaProductos));
    Aux->dato = pr;
    Aux->psig = NULL;
    if(*P == NULL){
        *P = Aux;
    } else {
        struct listaProductos *ant = NULL;
        struct listaProductos *act = *P;
        while((act->psig != NULL) && (act->dato.id >= pr.id)){
            ant = act;
            act = act->psig;
        }
        if(ant == NULL){
            Aux->psig = act;
            *P = Aux;
        } else {
            Aux->psig = act;
            ant->psig = Aux;
        }
    }
}

void cargarProductos(struct productos *pr){
    int resp = 1;
    while(resp == 1){
        printf("Ingrese el ID del producto \n");
        scanf("%d", &pr->id);
        printf("Ingrese el Tipo del producto \n");
        scanf("%d", &pr->tipoProd);
        printf("Ingrese el Precio del producto \n");
        scanf("%f", &pr->precio);
        printf("Ingrese el Stock del producto \n");
        scanf("%d", &pr->stock);
        insertarProductos(&P, *pr);
        printf("Hay otro producto para cargar? (1. Si/2. No) \n");
        scanf("%d", &resp);
    }
}

struct Pila {
    struct productos dato;
    struct Pila *psig;
};

struct Pila *L = NULL;

void apilarProv(struct Pila **L, struct productos pr){
    struct Pila *Aux = malloc(sizeof(struct Pila));
    Aux->dato = pr;
    Aux->psig = *L;
    *L = Aux;
}

void cargarPila(struct productos *pr){
    int resp = 1;
    while(resp == 1){
        printf("Ingrese el ID del producto \n");
        scanf("%d", &pr->id);
        printf("Ingrese la cantidad a reponer \n");
        scanf("%d", &pr->stock);
        apilarProv(&L, *pr);
        printf("Hay otro producto para cargar? (1. Si/2. No) \n");
        scanf("%d", &resp);
    }
}

void desapilar(struct Pila **L, struct productos *pr){
    struct Pila *temp = *L;
    if(*L == NULL){
        printf("Pila Vacia \n");
    } else {
        *pr = temp->dato;
        *L = temp->psig;
        free(temp);
    }
}

void actualizarProductos(struct listaProductos **P, struct productos pr){
    struct Pila *pila = L;
    struct listaProductos *prod = *P;
    if(pila == NULL){
        printf("No hay productos para reponder... \n");
    } else if(prod == NULL){
        printf("La lista de productos esta Vacia... \n");
    } else {
        while(pila != NULL){
            desapilar(&pila, &pr);
            while((prod != NULL) && (prod->dato.id != pr.id)){
                prod = prod->psig;
            }
            prod->dato.stock += pr.stock;
        }
        printf("Productos Actualizados con Exito! \n");
    }
}

struct productosFinal{
    int id;
    int tipoProd;
    float precio;
    int cantidad;
};

struct listaFinal{
    struct productosFinal dato;
    struct listaFinal *psig;
};

struct listaFinal *F = NULL;

void insertarFinal(struct listaFinal **F, struct productosFinal pf){
    struct listaFinal *Aux = malloc(sizeof(struct listaFinal));
    Aux->dato = pf;
    Aux->psig = *F;
    if(*F == NULL){
        *F = Aux;
    } else {
        struct listaFinal *temp = *F;
        while((temp != NULL) && (temp->dato.id != pf.id)){
            temp = temp->psig;
        }
        if(temp->dato.id == pf.id){
            temp->dato.cantidad += pf.cantidad;
        } else {
            *F = Aux;
        }
    }
}

void buscarProducto(struct listaProductos **P, struct productosFinal *pf, struct productos *pr){
    struct listaProductos *temp = *P;
    if(temp == NULL){
        printf("La lista de productos esta Vacia \n");
    } else {
        while((temp != NULL) && (temp->dato.id != pf->id)){
            temp = temp->psig;
        }
        *pr = temp->dato;
        temp->dato.stock -= pf->cantidad;
        pf->tipoProd = temp->dato.tipoProd;
        pf->precio = temp->dato.precio;
    }
}

void atender(struct productosFinal *pf, struct productos pr){
    int resp, resp2 = 1;
    float total = 0;
    while (resp == 1){
        while(resp2 == 1){
            printf("Ingrese el ID del producto que quiere comprar \n");
            scanf("%d", &pf->id);
            printf("Ingrese la cantidad del producto a comprar \n");
            scanf("%d", &pf->cantidad);
            buscarProducto(&P, pf, &pr);
            total = total + (pf->cantidad * pr.precio);
            insertarFinal(&F, *pf);
            printf("Hay otro ID de producto diferente a comprar? \n");
            scanf("%d", &resp2);
        }
        printf("---------------------------------------------- \n");
        printf("                   TICKET                      \n");
        printf("TOTAL: %.2f", total);
        printf("---------------------------------------------- \n");
        total = 0;
        printf("Hay otro Cliente a atender? (1. Si/2. No) \n");
        scanf("%d", &resp);
    }
}


void totalRecursivo(struct listaFinal *F, float *total){
    if(F == NULL){
        printf("Lista recorrida con Exito! \n");
        return;
    } else {
        *total = *total + (F->dato.cantidad * F->dato.precio);
        totalRecursivo(F->psig, total);
    }
}

void menu(){
    int resp = 1;
    float total = 0;
    struct productosFinal pf;
    struct productos pr;

    while (resp != 5){
        printf("------------------------------------------------------ \n");
        printf("                  BIENVENIDO                           \n");
        printf("1. Si quiere cargar los Productos \n");
        printf("2. Si quiere cargar la Pila de Productos a reponer \n");
        printf("3. Si quiere Actualizar los Productos \n");
        printf("4. Si quiere Atender \n");
        printf("5. Si quiere ver el total acumulado generado recursivamente \n");
        printf("6. Si quiere Salir \n");
        printf("------------------------------------------------------ \n");
        scanf("%d", &resp);
        switch (resp)
        {
            case 1:
                cargarProductos(&pf);
                break;
            case 2:
                cargarPila(&pr);
                break;
            case 3:
                actualizarProductos(&P, pr);
                break;
            case 4:
                atender(&pf, pr);
                break;
            case 5:
                totalRecursivo(F, &total);
                printf("El total es de: %.2f \n", total);
                break;
            default:
                printf("Numero ingresado incorrecto, Intentelo de nuevo... \n");
                break;
        }
    }
}

int main(){
    menu();
}