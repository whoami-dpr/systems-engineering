// En obra social “OSDE”, los trámites fuera de horarios se toman vía teléfono, y se apilan para su posterior procesamiento guardando un
// registro por trámite con la siguiente descripción:
//  cod_afiliado, tipo_tramite (reintegro o consulta) y cod_tramite.
// Se cuenta ademas con informacion de los afiliados en una lista ordenada por cod_afiliado con los siguientes campos:
//  cod_afiliado, Plan(210,310,410 o 510) y apyNom.

// Se desea procesar esta información para organizar las tareas administrativas correspondientes:

//  1) De la pila, tomar los trámites correspondientes a los reintegros y obtener una lista con el siguiente detalle:

//      -cod_afiliado
//      -Plan
//      -dni
//      -apYNom
//      -cod_tramite

//  2) Recorrer la lista de reintegros en forma recursiva y obtener el Total de tramites Plan 210

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para los afiliados
struct Afiliado
{
    int cod_afiliado;
    int plan;
    char apyNom[100];
};

// Estructura para los trámites
struct Tramite
{
    int cod_afiliado;
    char tipo_tramite[20];
    int cod_tramite;
};

struct Reintegro
{
    int cod_afiliado;
    int plan;
    char dni[20];
    char apyNom[100];
    int cod_tramite;
};

struct ListaAfiliados
{
    struct Afiliado dato;
    struct ListaAfiliados *psig;
};

struct PilaTramites
{
    struct Tramite dato;
    struct PilaTramites *psig;
};

struct ListaReintegros
{
    struct Reintegro dato;
    struct ListaReintegros *psig;
};

// Función para crear una lista de afiliados
void crearListaAfiliados(struct ListaAfiliados **l)
{
    *l = NULL;
}

// Función para crear una lista de trámites
void crearPilaTramites(struct PilaTramites **l)
{
    *l = NULL;
}

// Funcion para crear la lista de reintegros
void crearListaReintegros(struct ListaReintegros **l)
{
    *l = NULL;
}

// Función para apilar un trámite
void apilarTramites(struct PilaTramites **l, struct Tramite registro)
{
    struct PilaTramites *nuevo = (struct PilaTramites *)malloc(sizeof(struct PilaTramites));
    nuevo->dato = registro;
    nuevo->psig = *l;
    *l = nuevo;
}

// Función para desapilar un trámite
void desapilarTramites(struct PilaTramites **l, struct Tramite *registro)
{
    struct PilaTramites *aux;
    aux = *l;
    *registro = aux->dato;
    *l = aux->psig;
    free(aux);
}

// Función para insertar un afiliado ordenado por código
void insertarOrdenadoAfiliados(struct ListaAfiliados **l, struct Afiliado registro)
{
    struct ListaAfiliados *nuevo = (struct ListaAfiliados *)malloc(sizeof(struct ListaAfiliados));
    struct ListaAfiliados *ant;
    struct ListaAfiliados *act;

    nuevo->dato = registro;
    act = *l;
    ant = NULL;
    while ((act != NULL) && (act->dato.cod_afiliado < registro.cod_afiliado))
    {
        ant = act;
        act = act->psig;
    }
    if (ant != NULL)
    {
        ant->psig = nuevo;
        nuevo->psig = act;
    }
    else
    {
        nuevo->psig = *l;
        *l = nuevo;
    }
}

// funcion para crear un nuevo afiliado y agregarlo a la lista
void nuevoAfiliado(struct ListaAfiliados **l)
{
    struct Afiliado afiliado;
    printf("Ingrese el codigo de afiliado\n");
    scanf("%d", &afiliado.cod_afiliado);
    printf("Ingrese el plan del afiliado\n");
    scanf("%d", &afiliado.plan);
    printf("Ingrese el nombre y apellido del afiliado\n");
    scanf("%s", afiliado.apyNom);
    insertarOrdenadoAfiliados(l, afiliado);
}

// Funcion para buscar un afiliado por codigo_afiliado
void buscarAfiliado(struct ListaAfiliados *l, int cod_afiliado, struct Afiliado *afiliado)
{
    struct ListaAfiliados *aux;
    aux = l;
    while ((aux != NULL) && (aux->dato.cod_afiliado != cod_afiliado))
    {
        aux = aux->psig;
    }
    if (aux != NULL)
    {
        *afiliado = aux->dato;
    }
    else
    {
        printf("No se encontro el afiliado\n");
    }
}

// Funcion para insertar un nuevo reintegro
void insertarReintegro(struct ListaReintegros **l, struct Reintegro reintegro)
{
    struct ListaReintegros *nuevo = (struct ListaReintegros *)malloc(sizeof(struct ListaReintegros));
    nuevo->dato = reintegro;
    nuevo->psig = *l;
    *l = nuevo;
}

// Funcion para recorrer la lista de reintegros en forma recursiva y obtener el total de tramites plan 210
int totalTramitesPlan210(struct ListaReintegros *l)
{
    if (l == NULL)
    {
        return 0;
    }
    else
    {
        if (l->dato.plan == 210)
        {
            return 1 + totalTramitesPlan210(l->psig);
        }
        else
        {
            return totalTramitesPlan210(l->psig);
        }
    }
}

int main()
{
    struct ListaAfiliados *listaAfiliados;
    struct PilaTramites *pilaTramites;
    struct ListaReintegros *listaReintegros;
    struct Afiliado afiliado;
    struct Tramite tramite;
    struct Reintegro reintegro;
    int opcion;

    crearListaAfiliados(&listaAfiliados);
    crearPilaTramites(&pilaTramites);
    crearListaReintegros(&listaReintegros);

    do
    {
        printf("1) Ingresar un nuevo afiliado\n");
        printf("2) Apilar un tramite\n");
        printf("3) Crear la lista de reintegros\n");
        printf("4) Recorrer la lista de reintegros en forma recursiva y obtener el total de tramites plan 210\n");
        printf("0) Salir\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            nuevoAfiliado(&listaAfiliados);
            break;
        case 2:
            printf("Ingrese el codigo de afiliado\n");
            scanf("%d", &tramite.cod_afiliado);
            printf("Ingrese el tipo de tramite\n");
            scanf("%s", tramite.tipo_tramite);
            printf("Ingrese el codigo de tramite\n");
            scanf("%d", &tramite.cod_tramite);
            apilarTramites(&pilaTramites, tramite);
            break;
        case 3:
            while (pilaTramites != 0)
            {
                desapilarTramites(&pilaTramites, &tramite);
                if (strcmp(tramite.tipo_tramite, "reintegro") == 0)
                {
                    buscarAfiliado(listaAfiliados, tramite.cod_afiliado, &afiliado);
                    if (afiliado.cod_afiliado != 0)
                    {
                        reintegro.cod_afiliado = tramite.cod_afiliado;
                        reintegro.cod_tramite = tramite.cod_tramite;
                        reintegro.plan = afiliado.plan;
                        printf("Ingrese el dni del afiliado\n");
                        scanf("%s", reintegro.dni);
                        strcpy(reintegro.apyNom, afiliado.apyNom);
                        insertarReintegro(&listaReintegros, reintegro);
                    }
                }
            }
            break;
        case 4:
            printf("El total de tramites plan 210 es: %d\n", totalTramitesPlan210(listaReintegros));
            break;

        case 0:
            printf("Gracias por utilizar nuestro sistema de informacion\n");
            break;

        default:
            printf("Opcion incorrecta\n");
            break;
        }
    } while (opcion != 0);

    return 0;
}
