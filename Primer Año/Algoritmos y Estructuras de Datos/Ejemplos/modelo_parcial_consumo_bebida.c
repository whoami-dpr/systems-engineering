#include <conio.h>
#include <stdio.h>

void carga_inicial_pueblos(float mp[100][8]);
void carga_consumos_pueblos(float mp[100][8]);
void consumo_tipo_bebidas(float mp[100][8], float vtp[8]);
void carga_bebidas_alcoholicas(int vba[8]);
void consumo_alcohol_pueblos(float mp[100][8],float vp[100], int vba[8]);
int maximo_tipo_bebida(float vtp[8]);
int maximo_bebida_alcoholica(float vtp[8], int vba[8]);
int maximo_consumoXalcohol_pueblo(float vp[100]);

int main(void){
    float pueblosXbebidas[100][8], consumoXbebida[8], consumoXpueblo[100]; //matriz de consumos de cada bebida en cada pueblo; vector de consumo total de cada bebida; vector de consumo total de alcohol en cada pueblo
    int bebidas_alcoholicas[8], aux; //vector que identifica las bebidas con alcholo; auxiliar para la impresion de los valores retornados por las funciones

    aux = 0;

    carga_inicial_pueblos(pueblosXbebidas); //Inicializacion en 0 de los consumos de bebidas en cada pueblo.
    carga_consumos_pueblos(pueblosXbebidas); //Carga de los litros de consumo, por cada bebida, en cada pueblo.
    consumo_tipo_bebidas(pueblosXbebidas, consumoXbebida); //Calculo del total consumido en todos los pueblos, por tipo de bebida (8).
    
    aux = maximo_tipo_bebida(consumoXbebida); //Obtencion del tipo de bebida que mayor consumo tuvo en todos los pueblos.

    _clrscr();
    printf("El tipo de bebida mas consumida en los pueblos es la bebida %d\n\n", aux);
    _getch();

    carga_bebidas_alcoholicas(bebidas_alcoholicas); //Identificacion de las bebidas que tienen alcohol.

    aux = maximo_bebida_alcoholica(consumoXbebida, bebidas_alcoholicas); //Obtencion del tipo de bebida ALCOHOLICA que mayor consumo tuvo.
    _clrscr();
    printf("El tipo de bebida alcoholica mas consumida es la bebida %d\n\n", aux);
    _getch();

    consumo_alcohol_pueblos(pueblosXbebidas, consumoXpueblo, bebidas_alcoholicas); //Calculo del total de litros de bebidas ALCOHOLICAS consumidos, por cada pueblo (100).

    _clrscr();
    aux = maximo_consumoXalcohol_pueblo(consumoXpueblo); //Obtencion del pueblo que mas consumo de bebidas alcoholicas tuvo. 
    printf("El pueblo con mayor consumo de alcohol es el pueblo %d", aux);
    _getch();

    return 0;
}

void carga_inicial_pueblos(float mp[100][8]){

    for(int i = 0; i < 100 ; i++){
        for(int j = 0; j < 8 ; j++){
            mp[i][j] = 0;  //inicializo las posiciones de cada celda de la matriz en 0
        }
    }
}

void carga_consumos_pueblos(float mp[100][8]){
    int tipo;
	float litros;

    _clrscr();
    printf("Recoleccion de los datos de consumo del pueblo.\n\n");
    printf("Para indicar la finalizacion de la carga de datos de un pueblo, ingrese -1 en el tipo de bebida.\n\n");
    for(int i = 0; i < 100; i++){
        tipo = 0; //inicializo dentro del bucle for reiniciandolo para controlar cada pueblo
        printf("Pueblo Nro %d\n", (i+1));
        while(tipo != -1){
            printf("TIPO DE BEBIDA [0-7]:");
            scanf("%d", &tipo);
            printf("\n");
            printf("LITRAJE DE CONSUMO:");
            scanf("%f", &litros);
            printf("\n\n");
            if(tipo != -1){    //solo almaceno los litros de consumo si no es el final de la carga (-1)
                mp[i][tipo] = litros;
            }
        }
    }
    printf("Fin de la carga de datos de consumo en los pueblos.");
    _getch();
}

void consumo_tipo_bebidas(float mp[100][8], float vtp[8]){

    for(int i = 0; i < 8; i++){
        vtp[i] = 0; //inicializo porque lo uso como acumulador en el bucle for siguiente
        for(int j = 0; j < 100; j++){
            vtp[i] += mp[j][i]; //recorro la matriz por filas (por cada pueblo) y acumulo el consumo de esa bebida
        }
    }
}

void carga_bebidas_alcoholicas(int vba[8]){
    int tipo = 0, cant_bebidas = 1;

    for(int i = 0; i < 8; i++){
        vba[i] = 0; //inicializo para mantener el 0 en aquellas bebidas que no son alcoholicas (no ingresadas por el usuario en la carga siguiente)
    }

    _clrscr();

    printf("A continuacion enumerara los tipos de bebidas que son alcoholicas. Para finalizar, ingrese -1.\n\n");
    while((tipo != -1)&&(cant_bebidas <= 8)){ //doble condicion: mientras no sea el final de la carga (-1) y en caso de que el usuario ingrese los numeros de las 8 bebidas (todas son alcoholicas) y "tipo" nunca fuera -1
        printf("Ingrese el tipo de bebida alcoholica [0-7]:");
        scanf("%d", &tipo);
        printf("\n");
        if(tipo != -1){
            vba[tipo] = 1;
            cant_bebidas += 1; //incremento el contador manual, para actualizar la condicion de salida del bucle mientras
        }
    }
    printf("\n");
    printf("Finalizo el registo de bebidas alcoholicas.");
    _getch();
}

void consumo_alcohol_pueblos(float mp[100][8],float vp[100], int vba[8]){

    for(int i = 0; i < 100; i++){
        vp[i] = 0; //inicializo porque lo uso como acumulador en el bucle for siguiente
        for(int j = 0; j < 8; j++){
            if(vba[j] == 1){  //controlo que la bebida sea alcoholica, solo acumulamos el consumo de alcohol en cada pueblo
                vp[i] += mp[i][j]; //acumulo, recorriendo la matriz por columnas (tipo de bebida)
            }
        }
    }
}

int maximo_tipo_bebida(float vtp[8]){
    int max = 0, tipo = 0;

    for(int i = 0; i < 8; i++){
        if(vtp[i] > max){
            max = vtp[i];
            tipo = i; //necesitamos retornar el numero del tipo de bebida, no su litraje de consumo
        }
    }

    return tipo;
}


int maximo_bebida_alcoholica(float vtp[8], int vba[8]){
    int tipo = 0, max = 0;

    for(int i = 0; i < 8; i++){
        if(vba[i] == 1){  //controlo que la bebida sea alcoholica
            if(vtp[i] > max){
                max = vtp[i];
                tipo = i; //necesitamos retornar el numero del tipo de bebida, no su litraje de consumo
            }
        }
    }

    return tipo;
}

int maximo_consumoXalcohol_pueblo(float vp[100]){
    int max = 0, pueblo = 0;

    for(int i = 0; i < 100; i++){
        if(vp[i] > max){
            max = vp[i];
            pueblo = i;  //necesitamos retornar el numero de pueblo, no su litraje de consumo
        }
    }

    return pueblo;
}


