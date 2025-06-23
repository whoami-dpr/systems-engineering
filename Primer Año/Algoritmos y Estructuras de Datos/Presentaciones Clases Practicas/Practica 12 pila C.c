	/****************************************************************************
 *                                                                          *
 * Filename: 19-pila.c 			                                            *
 *                                                                          *
 * Purpose : Ejemplo de uso de listas tipo pila en Standard C.              *
 *                                                                          *
 * History : Fecha                                                          *
 *           18-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//En este ejercicio veremos como operar una lista bajo el modo de acceso LIFO, es decir,
//una pila.
//
//Sera un ejemplo muy similar a los anteriores vistos, exceptuando que el manejo de puntero
//lo realizaremos mediante las funcionse predefinidas en la pila, a saber:
//
//	- Apilar		-> Inserta un elemento al principio de la pila.
//	- Desapilar		-> Desapila el primer elemento de la pila.
// 	- Es vac�a		-> Retorna TRUE si la pila tiene elementos, FALSE caso contrario.
//	- Copiar pila	-> Genera una copia de la pila de trabajo.
//
//Como dato para la pila, usaremos un registro "libro" con sus respectivos datos.
//

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Libro{			//El libro que almacena la pila
	int isbn;
	char titulo[20];
	char genero[15];
	char autor[15];
	float precio;
};

struct Pila{			//Definicion de pila
	struct Libro dato;
	struct Pila *ps;
};

//Operaciones de pila
void inicializarPila(struct Pila **p);
void apilar(struct Pila **p, struct Libro l);
void desapilar(struct Pila **p, struct Libro *l);
int esVacia(struct Pila *p);
void copiarPila(struct Pila **pila1, struct Pila **pila2);

int main(){
	struct Pila *p;			//La pila de trabajo

}

//Operaciones de pila
void inicializarPila(struct Pila **p){
	p=0;
}

void apilar(struct Pila **p, struct Libro l){
	struct Pila *nuevo=malloc(sizeof(struct Pila));	//Genera nuevo nodo
	nuevo->dato=l;		//Asigna libro a "nuevo"
	nuevo->ps=*p;		//Apunta el ps de "nuevo" a la cabecera de pila
	*p=nuevo;			//Apunta la cabecera de pila a "nuevo"
}

void desapilar(struct Pila **p, struct Libro *l){
	struct Pila *aux=*p; //Defino aux porque trabajando sobre **p no logra
	*l= aux->dato;	 	 //entenderse con dato a la derecha de ->
	//obtenerlibro(*p, l);
	*p=aux->ps;
	free(aux);
}

int esVacia(struct Pila *p){
	int vacia;
	if (p==0){
		vacia= 1;	//Es vacia = TRUE
	}
	else{
		vacia= 0;	//Es vacia = FALSE
	}

	return vacia;
}

void copiarPila(struct Pila **p1, struct Pila **p2){
	struct Pila *aux=0;	//Declaro aux de pila. Si no lo hacemos NIL, rompera mas abajo
	struct Libro l;
	if (esVacia(*p2)){
		printf("La pila esta vacia");
	}
	else{
		while (!esVacia(*p2)){	//Desapilo pila original y apilo en aux
			desapilar(p2, &l);
			apilar(&aux, l);
		}
		while (!esVacia(aux)){	//Desapilo aux y apilo en pila original y copia 
			desapilar(&aux, &l);
			apilar(p1, l);
			apilar(p2, l);
		}
		printf("Copia de pila realizada con exito");
	}
	_getch();
	_clrscr();
}

