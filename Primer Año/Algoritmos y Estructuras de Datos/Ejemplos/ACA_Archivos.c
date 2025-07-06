/* En el ACA (Automovil Club Argentino) se realizan services a vehículos de clientes. Al comenzar el día se tiene un archivo c:\turnos.dat con los turnos de los clientes a ser atendidos, con la siguiente información:
--Patente y Tipo de service (1- Service general, 2- Cambio de aceite, 3- Reparación mecánica).

El ACA cuenta con la siguiente información de cada cliente en un archivo c:\clientes.dat:
--Patente, Marca, Modelo, DNI, Nombre, Apellido.

Al comenzar el día se va atendiendo a los clientes según la cola de turnos. Luego de ser atendido cada cliente, se deja registrado un listado final en forma ordenada por DNI con la siguiente información para la facturación:
--Patente, DNI, Nombre, Apellido, Tipo de Service, Importe a pagar

1. Desarrollar toda la operatoria del día
2. Al finalizar el día se desea obtener de la lista final, en forma recursiva, el monto recaudado del día.
3. Generar un archivo c:\final.dat con todos los datos de la lista final
*/

// Archivo Turnos: c:\turnos.dat
// Archivo Clientes Info: c:\clientes.dat
// Archivo Final: c:\final.dat

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Facturas {
    int Patente;
    int Dni;
    char Nombre [50];
    char Apellido [50];
    int tipoService;
    float importeTotal;
};

struct listaFacturas {
    struct Facturas dato;
    struct listaFacturas *psig;
};

struct listaFacturas *F = NULL;

void insertarFacturas(struct listaFacturas **F, struct Facturas fa){
    struct listaFacturas *Aux = malloc(sizeof(struct listaFacturas));
    Aux->dato = fa;
    Aux->psig = NULL;
    if(*F == NULL){
        *F = Aux;
    } else {
        struct listaFacturas *ant = NULL;
        struct listaFacturas *act = *F;
        while((act->psig !=NULL) && (act->dato.Dni <= fa.Dni)){
            ant = act;
            act = act->psig;
        }
        if(ant == NULL){
            act->psig = act;
            *F = Aux;
        } else {
            ant->psig = Aux;
            Aux->psig = act;
        }
    }
}

struct Turnos {
    int Patente;
    int tipoService;
};

struct Clientes {
    int Patente; 
    char Marca [50]; 
    int Modelo; 
    int DNI; 
    char Nombre [50]; 
    char Apellido [50]; 
};

FILE *ArchivoTurnos;
FILE *ArchivoClientes;

void atender(struct Facturas *fa){
    struct Turnos t;
    struct Clientes c;
    ArchivoTurnos = fopen("c:\turnos.dat", "rb");
    ArchivoClientes = fopen("c:\clientes.dat","rb");
    if((ArchivoTurnos == NULL) || (ArchivoClientes == NULL)){
        printf("Error al abrir alguno de los archivos... \n");
    } else {
        while(fread(&t, sizeof(struct Turnos), 1, ArchivoTurnos)){
            while(fread(&c, sizeof(struct Clientes), 1, ArchivoClientes)){
                if(t.Patente == c.Patente){
                    fa->Patente = t.Patente;
                    strcpy(fa->Nombre, c.Nombre);
                    strcpy(fa->Apellido, c.Apellido);
                    fa->tipoService = t.tipoService;
                    fa->Dni = c.DNI;
                    printf("Ingrese el Importe total a cargar por el usuario: %s", fa->Nombre);
                    scanf("%f", &fa->importeTotal);
                    insertarFacturas(&F, *fa);
                }
            }
    }
    }
    fclose(ArchivoTurnos);
    fclose(ArchivoClientes);
}


void totalRecursivamente(struct listaFacturas *F, float *total){
    if (F == NULL){
        printf("Lista de facturas Vacia \n");
        return;
    } else {
        *total = *total + F->dato.importeTotal;
        totalRecursivamente(F->psig, total);
    }
}

void generarArchivoFinal(FILE *ArchivoFinal, struct listaFacturas *F){
    struct Facturas fa;
    struct listaFacturas *temp = F;
    if(F == NULL){
        printf("Lista Vacia \n");
    }
    while(temp != NULL){
        fa = temp->dato;
        fwrite(&fa, sizeof(struct Facturas), 1, ArchivoFinal);
        temp = temp->psig;
    }
}


int main(){
    float total = 0;
    struct Facturas fa;

    FILE *ArchivoFinal;

    atender(&fa);
    totalRecursivamente(F, &total);
    printf("El total es de: %.2f", total);

    ArchivoFinal = fopen("c:\final.dat", "wb");
    if(ArchivoFinal == NULL){
        printf("Error al abrir el archivo Final");
    } else {
        generarArchivoFinal(ArchivoFinal, F);
    }

    fclose(ArchivoFinal);
}