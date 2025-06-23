#include <stdio.h>

int main() {
    float Total;
    float Nota;
    float Prom;
    int Cant_Aprob;
    int n, i;
    float Porc;

    Total = 0;
    Cant_Aprob = 0;

    printf("Ingrese la cantidad de notas a cargar: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Ingrese la nota del alumno %d: ", i);
        scanf("%f", &Nota);
        if (Nota >= 4) {
            Total = Total + Nota;
            Cant_Aprob = Cant_Aprob + 1;
        }
    }

    if (Cant_Aprob > 0) {
        Prom = Total / Cant_Aprob;
        Porc = (Cant_Aprob * 100) / n;
        printf("Promedio de aprobados: %.2f\n", Prom);
        printf("Porcentaje de aprobados sobre total: %.2f%%\n", Porc);
    } else {
        printf("No hay alumnos aprobados\n");
    }

    return 0;
}
