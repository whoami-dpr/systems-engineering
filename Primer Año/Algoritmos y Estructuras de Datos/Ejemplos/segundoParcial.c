#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct pedidos {
    int cod_prod;
    int cantidad;
    int zona;
};

struct colaPedidos{
    struct pedidos dato;
    struct colaPedidos *psig;
};

struct colaPedidos *P = NULL;
struct colaPedidos *U = NULL;

struct productos {
    int cod_prod;
    char desc [50];
    int stock;
    float precio;
};

struct listaProductos{
    struct productos dato;
    struct listaProductos *psig;
};

struct listaProductos *PR = NULL;

struct final {
    int cod_prod;
    int zona;
    int total;
};

struct listaFinal{
    struct final dato;
    struct listaFinal *psig;
};

struct listaFinal *F = NULL;

void encolar(struct colaPedidos **P, struct colaPedidos **U, struct pedidos pe){
    struct colaPedidos *Aux = malloc(sizeof(struct colaPedidos));
    Aux->dato = pe;
    Aux->psig  = NULL;
    if(*P == NULL){
        *P = Aux;
    } else {
        (*U)->psig = Aux;
    }
    *U = Aux;
}

void cargarPedidos(struct pedidos *pe){
    int resp = 1;
    while (resp == 1){
        printf("Ingrese el codigo del producto \n");
        scanf("%d", &pe->cod_prod);
        printf("Ingrese la Cantidad a comprar \n");
        scanf("%d", &pe->cantidad);
        printf("Ingrese la zona (1. Norte /2. Sur /3. Este /4. Oeste) \n");
        scanf("%d", &pe->zona);
        encolar(&P, &U, *pe);
        printf("Hay otro pedido para cargar? (1. Si/ 2.No) \n");
        scanf("%d", &resp);
    }
}

void insertarProductos(struct listaProductos **PR, struct productos po){
    struct listaProductos *Aux = malloc(sizeof(struct listaProductos));
    Aux->dato = po;
    Aux->psig = *PR;
    *PR = Aux;
}

void cargarProductos(struct productos *po){
    int resp = 1;
    while (resp == 1){
        printf("Ingrese el codigo del producto \n");
        scanf("%d", &po->cod_prod);
        printf("Ingrese la descripcion del Producto \n");
        scanf("%s", po->desc);
        printf("Ingrese el stock del producto \n");
        scanf("%d", &po->stock);
        printf("Ingrese el precio del producto");
        scanf("%d", &po->precio);
        insertarProductos(&PR, *po);
        printf("Hay otro pedido para cargar? (1. Si/ 2.No) \n");
        scanf("%d", &resp);
    }
}

void desencolar(struct colaPedidos **P, struct colaPedidos **U, struct pedidos *pe){
    if(*P == NULL){
        printf("La cola esta Vacia \n");
        *U = NULL;
    } else {
        struct colaPedidos *temp = *P;
        *pe = temp->dato; 
        *P = temp->psig;
        free(temp);
    }
}

void insertarFinal(struct listaFinal **F, struct final fn){
          struct listaFinal *Aux = malloc(sizeof(struct final));
          Aux->dato = fn;
          Aux->psig = *F; 
          if(F == NULL){
             *F = Aux;
         } else {
           struct listaFinal *temp= *F;
           while ((temp != NULL) && (temp->dato.cod_prod != fn.cod_prod)){
                     temp = temp->psig;
           }
           if((temp->dato.cod_prod == fn.cod_prod) && (temp->dato.zona == fn.zona)){
               temp->dato.total += fn.total;
            } else {
             *F = Aux;
        }
    }
}

void BuscaryActualizar(struct productos *po, struct pedidos pe){
    struct listaProductos *temp = PR;
    if(temp == NULL){
        printf("Lista Vacia \n");
    } else {
        while((temp != NULL) && (temp->dato.cod_prod != pe.cod_prod)){
            temp = temp->psig;
        }
        if(temp->dato.cod_prod == pe.cod_prod){
            temp->dato.stock -= pe.cantidad;
            *po = temp->dato;
        }
    }
}

void generarTicket(struct final *fn){
    struct pedidos pe;
    struct productos po;
    while(P != NULL){
        desencolar(&P, &U, &pe);
        BuscaryActualizar(&po, pe);
        fn->cod_prod = pe.cod_prod;
        fn->zona = pe.zona;
        fn->total += pe.cantidad; // posible error
        printf("------------------------------------- \n");
        printf("                TICKET                \n");
        printf("CODIGO: %d", fn->cod_prod);
        printf("DESCRIPCION: %s", po.desc);
        printf("ZONA: (1. Norte /2. Sur /3. Este /4. Oeste) %d", fn->zona);
        printf("CANTIDAD: %d", pe.cantidad);
        printf("TOTAL: %.2f", (po.precio * pe.cantidad));
        insertarFinal(&F, *fn);
    }
}

void recursivoZona(struct listaFinal *F, int *zona[4]){
    if(F == NULL){
        return;
    } else {
        *zona[F->dato.zona] += F->dato.total;
        recursivoZona(F->psig, zona[4]);
    }
}

void recursivoTotal(struct listaFinal *F, int *total){
    if(F == NULL){
        return;
    } else {
        *total += F->dato.total;
        recursivoZona(F->psig, total);
    }
}
