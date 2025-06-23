// Programa para sumar y restar dos números dados
#include <stdio.h>

int restar(int Num1, int Num2) {
    return Num1 - Num2;
}

void sumar_restar(int *Resul_S, int *Resul_R, int Nro1, int Nro2) {
    *Resul_S = Nro1 + Nro2;
    *Resul_R = restar(Nro1, Nro2);
}

int main() {
    int RS, RR, N1, N2;

    printf("Ingrese el primer valor > ");
    scanf("%d", &N1);
    printf("Ingrese el segundo valor > ");
    scanf("%d", &N2);

    sumar_restar(&RS, &RR, N1, N2);

    printf("Resultado Suma --> %d\n", RS);
    printf("Resultado Resta --> %d\n", RR);

    return 0;
}
