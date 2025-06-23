#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    //int totG = 0
    int a;
    int b = 0;
    int tot = 0;
    char nom[30];
    
    printf("Ingrese el primer valor a sumar: \r\n");
    scanf("%d",&a);
    printf("Ingrese el segundo valor a sumar: \r\n");
    scanf("%d",&b);    
    _clrscr();
    tot = a + b;

    //totG = tot;
    printf("El valor de la primera suma es = %d \r\n",tot);

    printf("Ingrese el primer valor a sumar: \r\n");
    scanf("%d",&a);
    printf("Ingrese el segundo valor a sumar: \r\n");
    scanf("%d",&b);
    _clrscr();
    tot = a + b;
    //totG = totG + tot;
    printf("El valor de la primera suma es = %d \r\n",tot);

    //pritf("El valor del total general es de = %d",totG);

    strcpy(nom,"Felix");
    printf("Profesor: %s \r\n",nom);

}
