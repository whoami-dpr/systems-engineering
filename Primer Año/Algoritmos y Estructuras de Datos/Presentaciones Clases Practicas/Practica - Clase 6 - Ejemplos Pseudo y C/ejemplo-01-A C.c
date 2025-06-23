#include <stdio.h>

int main() {
   float Total;
   float Nota;
   float Prom;
   int i;

   Total = 0;
   Nota = 0;
   Prom = 0;

   for (i = 1; i <= 4; i++) {
      printf("Ingrese la nota del alumno %d > ", i);
      scanf("%f", &Nota);
      Total = Total + Nota;
   }

   Prom = (Total / 4) ;

   printf("Promedio: %f\n", Prom);

   return 0;
}
