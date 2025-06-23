/*
 Se cuenta con dos matrices M1 y M2 de 8x10 posiciones. Se desea realizar
 una solución que cuente con un procedimiento que se encargue de la carga de 
 las matrices (números reales en el intervalo [1,100]), y con una función que
 determine si la suma de todas las posiciones de la Matriz M1 es igual a la
 suma de todas las posiciones de la Matriz M2.
 */
#include <stdio.h>

void carga(float MG[3][2]);
float suma(float MG[3][2]);

int main(){
float M1[3][2];
float M2[3][2];

// Carga de datos
printf("Ingrese los datos de M1 > \n");
carga(M1);
printf("Ingrese los datos de M2 > \n");
carga(M2);


// Informe
float acuM1, acuM2;
acuM1 = suma(M1);
acuM2 = suma(M2);

if (acuM1 == acuM2){
    printf("\nSon iguales\n");
} else {
    printf("\nSon distintos\n");
}

    return 0;
}

void carga(float MG[3][2])
{
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            printf("Ingrese fila %d, columna %d >",i + 1,j + 1);
            scanf("%f", &MG[i][j]);       
            }
    }
}
float suma(float MG[3][2])
{
    float acumulado;
    acumulado = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            acumulado = acumulado + MG[i][j];
        }
        }
    return acumulado;

}