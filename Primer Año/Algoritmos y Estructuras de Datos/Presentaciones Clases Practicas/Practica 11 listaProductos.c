// Diseñar un algoritmo que permita cargar y modificar una lista de Productos.

// Un producto se compone por:
// Nombre
// Proveedor
// Codigo
// Precio unitario

// El ejercicio consiste en:
// cargar productos
// Eliminar un producto dado el código
// Modificar un producto dado el código
// Mostrar la lista de productos en forma recursiva.

// Como detalle extra, se mostrara la cantidad numerica de productos cargados.

#include <string>
#include <stdio.h>

void cargarProductos(struct Nodo **l);
void eliminarProducto(struct Nodo **l, int codigo);
void modificarProducto(struct Nodo **l, int codigo);
void mostrarProductosRecursivo(struct Nodo *l);
void mostrarProductos(struct Nodo *l);
void mostrarCantidadProductos(struct Nodo *l);

struct Producto
{
    char nombre[50];
    char proveedor[50];
    int codigo;
    float precio;
};

struct Nodo
{
    struct Producto producto;
    struct Nodo *siguiente;
};

int main()
{

    struct Nodo *lista;
    int opcion, codigo;

    opcion = 0;
    lista = 0;

    while (opcion != 6)
    {
        printf("1. Cargar productos\n");
        printf("2. Eliminar producto\n");
        printf("3. Modificar producto\n");
        printf("4. Mostrar productos\n");
        printf("5. Mostrar cantidad de productos\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            cargarProductos(&lista);
            break;
        case 2:
            printf("Ingrese el codigo del producto a eliminar: ");
            scanf("%d", &codigo);
            eliminarProducto(&lista, codigo);
            break;
        case 3:
            printf("Ingrese el codigo del producto a modificar: ");
            scanf("%d", &codigo);
            modificarProducto(&lista, codigo);
            break;
        case 4:
            mostrarProductos(lista);
            break;
        case 5:
            mostrarCantidadProductos(lista);
            break;
        }
    }
    return 0;
}

void cargarProductos(struct Nodo **l)
{
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    printf("Ingrese el nombre del producto: ");
    scanf("%s", nuevo->producto.nombre);
    printf("Ingrese el proveedor del producto: ");
    scanf("%s", nuevo->producto.proveedor);
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &nuevo->producto.codigo);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &nuevo->producto.precio);
    nuevo->siguiente = *l;
    *l = nuevo;
}

void eliminarProducto(struct Nodo **l, int codigo)
{
    struct Nodo *aux, *ant;
    aux = *l;
    ant = NULL;
    while (aux != NULL && aux->producto.codigo != codigo)
    {
        ant = aux;
        aux = aux->siguiente;
    }
    if (aux == NULL)
    {
        printf("No se encontro el producto\n");
        return;
    }
    if (ant == NULL)
    {
        *l = aux->siguiente;
    }
    else
    {
        ant->siguiente = aux->siguiente;
    }
    free(aux);
}

void modificarProducto(struct Nodo **l, int codigo)
{
    struct Nodo *aux;
    aux = *l;
    while (aux != NULL && aux->producto.codigo != codigo)
    {
        aux = aux->siguiente;
    }
    if (aux == NULL)
    {
        printf("No se encontro el producto\n");
        return;
    }
    printf("Ingrese el nombre del producto: ");
    scanf("%s", aux->producto.nombre);
    printf("Ingrese el proveedor del producto: ");
    scanf("%s", aux->producto.proveedor);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &aux->producto.precio);
}

void mostrarProductosRecursivo(struct Nodo *l)
{
    if (l == 0)
    {
        return;
    }
    printf("Nombre: %s\n", l->producto.nombre);
    printf("Proveedor: %s\n", l->producto.proveedor);
    printf("Codigo: %d\n", l->producto.codigo);
    printf("Precio: %.2f\n", l->producto.precio);
    mostrarProductos(l->siguiente);
}

void mostrarProductos(struct Nodo *l)
{
    while (l != 0)
    {
        printf("Nombre: %s\n", l->producto.nombre);
        printf("Proveedor: %s\n", l->producto.proveedor);
        printf("Codigo: %d\n", l->producto.codigo);
        printf("Precio: %.2f\n", l->producto.precio);
        l = l->siguiente;
    }
}

void mostrarCantidadProductos(struct Nodo *l)
{
    int cantidad = 0;
    while (l != NULL)
    {
        cantidad++;
        l = l->siguiente;
    }
    printf("Cantidad de productos: %d\n", cantidad);
}