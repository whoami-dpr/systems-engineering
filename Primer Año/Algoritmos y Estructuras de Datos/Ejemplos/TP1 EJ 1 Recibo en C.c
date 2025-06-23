#include <conio.h>
#include <stdio.h>

char nombre[30], apellido[30];
float sueldo_basico, monto_premio, monto_comida, monto_viaticos, monto_desc_ausente, monto_os, monto_jubilacion, monto_ley, sueldo_final, aux_calculo;
int dias_asuente;

int main(void){
    //_clrscr();
    printf("APLICACION DE RECIBO DE SUELDO\n");
    printf("========== == ====== == ======\n\n");
    printf("Ingrese el nombre del empleado:");
    scanf("%s", nombre);
    printf("\n");
    printf("Ingrese el apellido del empleado:");
    scanf("%s", apellido);
    printf("\n");
    printf("\n");
    printf("Ingrese el sueldo basico del empleado:$");
    scanf("%f", &sueldo_basico);
    printf("\n");
    printf("Ingrese el monto de bonificacion por premio del empleado:$");
    scanf("%f", &monto_premio);
    printf("\n");
    printf("Ingrese el monto de bonificacion por comida del empleado:$");
    scanf("%f", &monto_comida);
    printf("\n");
    printf("Ingrese el monto de bonificacion por viaticos del empleado:$");
    scanf("%f", &monto_viaticos);
    printf("\n");
    printf("Ingrese el monto fijo de descuento por ausencia del empleado:$");
    scanf("%f", &monto_desc_ausente);
    printf("\n");
    printf("Ingrese los dias de ausencia del empleado:");
    scanf("%d", &dias_asuente);
    printf("\n");
    printf("\n");
    //_clrscr();
    monto_os = (sueldo_basico*3)/100;
    monto_jubilacion = (sueldo_basico*11)/100;
    monto_ley = (sueldo_basico*3)/100;
    aux_calculo = monto_desc_ausente * dias_asuente;
    sueldo_final = sueldo_basico + monto_premio + monto_comida + monto_viaticos - monto_os - monto_jubilacion - monto_ley - aux_calculo;
    printf("Carga realizada con exito...");
    printf("\n");
    printf("\n");
    printf("Procesando los datos para la generacion del recibo...");
    _getch();
    //_clrscr();
    printf("IMPRESION DE RECIBO DE SUELDO\n");
    printf("========= == ====== == ======\n\n");
    printf("-> Nombre: %s",nombre);
    printf("\n");
    printf("-> Apellido: %s",apellido);
    printf("\n");
    printf("\n");
    printf("-> Sueldo basico: $%.2f",sueldo_basico);
    printf("\n");
    printf("-> Premio: $%.2f",monto_premio);
    printf("\n");
    printf("-> Viaticos: $%.2f",monto_viaticos);
    printf("\n");
    printf("-> Comida: $%.2f",monto_comida);
    printf("\n");
    printf("-> Dias de ausencia: %d",dias_asuente);
    printf("\n");
    printf("\n");
    printf("-> Desc. de ausencia p/dia: $%.2f",monto_desc_ausente);
    printf("\n");    
    printf("-> Desc. Obra social: $%.2f",monto_os);
    printf("\n");
    printf("-> Desc. Jubilacion: $%.2f",monto_jubilacion);
    printf("\n");
    printf("-> Desc. Ley 19032: $%.2f",monto_ley);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("-> SUELDO FINAL: $%.2f",sueldo_final);
    printf("\n");
    _getch();
    printf("\n");
    return 0;
}



