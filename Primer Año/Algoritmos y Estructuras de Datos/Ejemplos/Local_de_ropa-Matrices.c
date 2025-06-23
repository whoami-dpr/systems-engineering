#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int stock[5][2], codigo, talle, cantidad, opc;
    float precios[5], acumulado[5], total;

    _clrscr();
    printf("Carga inicial de arreglos\n");
    printf("===== ======= == ========\n\n");
    for(int i = 0; i < 5; i++){
        acumulado[i] = 0;
        printf("Ingrese el precio del producto %d: ", (i+1));
        scanf("%f", &precios[i]);
        printf("\n\n");
        for(int j = 0; j < 2; j++){
            printf("Ingrese el stock del producto %d - talle %d: ", (i+1), (j+1));
            scanf("%d", &stock[i][j]);
            printf("\n");
        }
        _clrscr();
    }

    printf("Comienzo del dia laboral...\n\n");
    _getch();
    opc = 1; 
    while(opc != 2){
        printf("MENU DE OPCIONES\n");
        printf("===== == =======\n\n");
        printf("1-Realizar venta.\n");
        printf("2-Finalizar proceso.\n\n");
        printf("Opcion -> ");
        scanf("%d", &opc);
        _clrscr();
        switch(opc){
            case 1: printf("Registro de venta\n");
                    printf("======== == ======\n\n");
                    printf("Ingrese el codigo del producto a vender (1-5):");
                    scanf("%d", &codigo);
                    printf("\n");
                    printf("Ingrese el talle del producto a vender (1-2):");
                    scanf("%d", &talle);
                    printf("\n");
                    printf("Ingrese la cantidad de unidades a vender:");
                    scanf("%d", &cantidad);
                    printf("\n");
                    printf("PROCESANDO VENTA...");
                    _getch();
                    _clrscr();
                    codigo = codigo-1;
                    talle = talle-1;
                    if(stock[codigo][talle] >= cantidad){
                        stock[codigo][talle] = stock[codigo][talle]-cantidad;
                        printf("TICKET DE VENTA\n");
                        printf("======= == =====\n\n");
                        printf("Codigo de producto -------> %d\n", (codigo+1));
                        printf("Talle de prenda ----------> %d\n", (talle+1));
                        printf("Cantidad de unidades -----> %d\n", cantidad);
                        printf("Importe total de venta ---> %.2f\n", (precios[codigo]*cantidad));
                        acumulado[codigo] += (precios[codigo]*cantidad);
                    } else {
                        printf("No hay stock suficiente para realizar la venta...\n");
                    }
                    _getch();
                    _clrscr();
                    break;
            case 2: printf("Finalizando dia laboral...\n");
                    _getch();
                    _clrscr();
                    break;
            default: printf("Opcion incorrecta. Reintente...\n");
                     _getch();
                     _clrscr();
                     break;
        }
    }

    opc = 1;
    total = 0;
    while(opc != 4){
        printf("MENU DE OPCIONES\n");
        printf("===== == =======\n\n");
        printf("1-Impresion de reporte de ventas totales por producto.\n");
        printf("2-Calcular importe total de ventas.\n");
        printf("3-Impresion de listado de productos que requieran reposicion.\n");
        printf("4-Salir\n\n");
        printf("Opcion -> ");
        scanf("%d", &opc);
        _clrscr();
        switch(opc){
            case 1: printf("Ventas totales por producto\n");
                    printf("======= ====== === ========\n\n");
                    total = 0;
                    for(int i = 0; i < 5; i++){
                        printf("Producto %d - Ventas:$%.2f\n", (i+1), acumulado[i]);
                        total += acumulado[i];
                    }
                    _getch();
                    _clrscr();
                    break;
            case 2: printf("Importe total de ventas\n");
                    printf("======= ===== == ======\n\n");
                    printf("TOTAL ---> $%.2f", total);
                    _getch();
                    _clrscr();
                    break;
            case 3: printf("Productos para reposicion\n");
                    printf("========= ==== ==========\n\n");
                    for(int i = 0; i < 5; i++){
                        for(int j = 0; j < 2; j++){
                            if(stock[i][j] == 0){
                                printf("--> Producto %d - Talle %d\n", (i+1), (j+1));
                            }
                        }
                    }
                    _getch();
                    _clrscr();
                    break;
            case 4: printf("Finalizando ejecucion...\n");
                    _getch();
                    _clrscr();
                    break;
            default: printf("Opcion incorrecta. Reintente...\n");
                     _getch();
                     _clrscr();
                    break;
        }
    }

}
