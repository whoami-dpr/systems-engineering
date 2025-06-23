/****************************************************************************
 *                                                                          *
 * Filename: 20-cola.c             			                       			*
 *                                                                          *
 * Purpose : Ejemplo de uso de listas tipo cola en Standard C.              *
 *                                                                          *
 * History : Fecha                                                          *
 *           18-05-2018                                                     *
 *																			*
 * By: Federico Moradillo                                                   *
 *                                                                          *
 ****************************************************************************/

//Similar al ejemplo anterior, en este ejercicio veremos como operar una lista bajo el modo de acceso FIFO, es decir,
//una cola.
//
//Recordando las operaciones de una cola:
//
//	- Encolar		-> Inserta un elemento al principio de la cola.
//	- Desencolar	-> Desencola el ultimo elemento de la cola.
// 	- Es vac�a		-> Retorna TRUE si la cola no tiene elementos, FALSE caso contrario.
//	- Copiar cola	-> Genera una copia de la cola de trabajo.
//
//Como dato para la cola, usaremos un registro "proceso" con sus respectivos datos.
//
//
//Recordar que, con el uso del free() para librera nodos, la cola siempre debe ser usada como referencia, ya que
//cualquier operacion sobre la misma debera usar un desencolar y, por ende, otro encolar para no perderla.

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct Proceso{			//El proceso que almacena la cola
	int id;
	char nombre[20];
	char prioridad[15];
	char estado[15];
};

struct lCola{			//Definicion de la lista de la cola
	struct Proceso dato;
	struct lCola *ps;
};

struct Cola{			//El registro que maneja los punteros de cola
	struct lCola *pini;	// - Puntero al inicio
	struct lCola *pfin;	// - Puntero al final
};


//Operaciones de pila
void inicializarCola(struct Cola *c);
void encolar(struct Cola *c, struct Proceso p);
void desencolar(struct Cola *c, struct Proceso *p);
int esVacia(struct Cola c);
void copiarCola(struct Cola *cola1, struct Cola *cola2);

int main(){
	struct Cola c;			//La cola de trabajo

}

void inicializarCola(struct Cola *c){
	c->pini=0;
	c->pfin=0;
}

void encolar(struct Cola *c, struct Proceso p){
	struct lCola *nuevo=malloc(sizeof(struct lCola));	//Genera nuevo nodo
	nuevo->dato= p;
	nuevo->ps= 0;
	if (c->pini == 0){		//Es el primer elemento que se agrega a la cola
		c->pini= nuevo;		//Agrego al puntero inicial tambien
	}
	else{
		c->pfin->ps= nuevo;	//No es el primer elemento, el ultimo apunta a nuevo
	}
	c->pfin= nuevo;			//Y nuevo ahora es el ultimo
}

void desencolar(struct Cola *c, struct Proceso *p){
	struct lCola *aux=malloc(sizeof(struct lCola));	//Defino aux
	*p= c->pini->dato;		//Retorno el dato del primer nodo
	aux= c->pini;			//Guardo el nodo en aux para poder borrarlo
	c->pini= c->pini->ps;	//Muevo el puntero inicial al siguiente nodo
	if (c->pini == 0){		//Ya no quedan elementos en la cola			
		c->pfin= 0;			//pfin deberia ser nil tambien
	}
	free(aux);		//Elimino el ultimo nodo
}

int esVacia(struct Cola c){
	int vacia;
	if (c.pini==0){
		vacia= 1;	//Es vacia = TRUE
	}
	else{
		vacia= 0;	//Es vacia = FALSE
	}
	return vacia;
}

void copiarCola(struct Cola *cola1, struct Cola *cola2){
	struct Cola aux;	//Declaro cola auxiliar
	struct Proceso p;
	inicializarCola(&aux);
	if (esVacia(*cola2)){
		printf("La cola esta vacia");
	}
	else{
		while (!esVacia(*cola2)){	//Desapilo pila original y apilo en aux
			desencolar(cola2, &p);
			encolar(cola1, p);
			encolar(&aux, p);
		}
		*cola2= aux;	//Reensamblo la cola original
	}
}

