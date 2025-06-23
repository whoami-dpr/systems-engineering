// Un restaurante desea llevar el control de lo consumido en cada una de sus 50 mesas.
// La atención se realiza de la siguiente manera: al llegar gente al local se le asigna una mesa;
// por cada comensal se cobra un “cubierto” o servicio de mesa y se agrega el monto correspondiente a cada pedido.
// Al retirarse del local, se le cobra el monto acumulado. 
// Debe considerarse la situación en que podría no haber mesas libres.

#include <conio.h>
#include <string.h>
#include <stdio.h>

#define MAXMESAS 50 //Definicion de constante para la cantidad maxima de mesas que tengo

int main(int argc, char const *argv[]) {
    int opcion = 1;
    int mesa,opcion1,comensales,bandera;
    float recaudMesas[MAXMESAS]; //Array donde se va a almacenar el gasto de la mesa
    float montoTotal[MAXMESAS];  //Array donde voy a acumular el monto total
    int disponibilidadMesas[MAXMESAS]; //Array bandera que va a tomar 0 si la mesa esta ocupada 1 si la mesa esta disponible
    float cubierto,montoVenta,total;

    for (int i = 0; i < MAXMESAS; i++) {

        recaudMesas[i]=0;
        disponibilidadMesas[i]=0;       //Inicializacion de los array 
        montoTotal[i]=0;

    }
    

    printf("Ingrese el valor del servicio de mesa del dia \r\n");
    scanf("%f",&cubierto);

    while (opcion != 0) {
        printf("===========RESTAURANTE DON PEPITO==========\r\n");
        printf("1-Asignar mesa\r\n");
        printf("2-Ingresar pedido\r\n");
        printf("3-Liberar mesa\r\n");
        printf("4-Ver recaudacion\r\n");
        printf("0-Salir\r\n");
        scanf("%d",&opcion);

        switch (opcion) {
        case 1:
        
            mesa = 0;
            for (int i = 0; i < MAXMESAS; i++) {
                if (disponibilidadMesas[i])  {
                    disponibilidadMesas[i] = 0;     
                    mesa = i+1;                     //Busco la primer mesa disponible
                    break;
                }
            }
            if (mesa) {

                printf("Bienvenido, su numero de mesa es %d\r\n",mesa);
                printf("Ingrese la cantidad de personas que ocupan la mesa \r\n");
                scanf("%d",&comensales);
                recaudMesas[mesa] += comensales * cubierto;                         

            }
            else {
                printf("No hay mesas disponibles\r\n");
            }
            
            break;
        
        case 2: //Agrego un nuevo pedido a la mesa

            printf("Ingrese el numero de mesa 1-50\r\n");
            scanf("%d",&mesa);
            printf("Ingrese el monto del nuevo pedido\r\n");
            scanf("%f",&montoVenta);

            if ((mesa > 0)&&(mesa <= MAXMESAS)) {
                recaudMesas[mesa-1] += montoVenta;
            }
            else {
                printf("Numero de mesa no valido, intente nuevamente\r\n");
            }
            break;
        
        case 3: //Cierro el gasto de la mesa y acumulo su gasto 

            printf("Ingrese el numero de mesa a liberar 1-50\r\n");
            scanf("%d",&mesa);
            
            if ((mesa > 0)&&(mesa <= MAXMESAS)) {

                printf("Mesa: %f\r\n",mesa);
                printf("TOTAL = %f\r\n",recaudMesas[mesa-1]);
                
                montoTotal[mesa-1] += recaudMesas[mesa-1];
                recaudMesas[mesa-1] = 0;
                disponibilidadMesas[mesa-1] = 1;
            }
            else {
                printf("Numero de mesa no valido, intente nuevamente\r\n");
            }

            break;

        case 4: //Como extra, muestro los totales que se va teniendo hasta el momento

            total = 0;
            printf("1-Total recaudado por mesa\r\n");
            printf("2-Total recaudado\r\n");
            scanf("%d",&opcion1);
            if (opcion1 == 1) {
                for (int i = 0; i < MAXMESAS; i++) {
                    printf("MESA: %d MONTO: %.2f\r\n",i+1,montoTotal[i]);
                }
                
            }
            else if (opcion1 == 2) {
                for (int i = 0; i < MAXMESAS; i++) {
                    total += montoTotal[i];
                }
                printf("El monto recaudado hasta el momento es de: %.2f\r\n",total);
            }
            else {
                printf("Numero de mesa no valido, intente nuevamente\r\n");
            }
            
            break;
        case 0: //Salgo del programa. Verifico que todas las mesas esten libres para salir
            bandera = 0;
             for (int i = 0; i < MAXMESAS; i++) {
                if (disponibilidadMesas[i])  {
                    bandera = 1;
                    break;
                }
            }

            if(bandera) {
                printf("Debera cerrar todas las mesas antes de salir");
                opcion = 1;
            }
            else {

                printf("Terminando ejecucion...\r\n");
            }
            
                
        default:
            printf("Opcion incorrecta, intente nuevamente\r\n");
            break;
        }
    
   }
    return 0;
}
