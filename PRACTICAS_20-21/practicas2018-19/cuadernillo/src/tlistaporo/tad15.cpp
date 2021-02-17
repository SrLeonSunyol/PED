#include "tlistaporo.h"
#include <iostream>
using namespace std;


int main(){
	TListaPoro lista;

	lista.Insertar(TPoro(2, 2, 2, NULL));
	lista.Insertar(TPoro(3, 4, 4, NULL));
	lista.Insertar(TPoro(5, 5, 5, NULL));

	cout << lista << endl;

	// IMPORTANTE PARA EL EXAMEN.
	// COMO RECORRER UNA LISTA CON TListaPosicion
	// DESDE FUERA DE LA CLASE.	
	TListaPosicion p; // p.pos (puntero a un nodo de la lista)

	p = lista.Primera(); // devuelve un TListaPosicion con la direccion del primer nodo.
	while(p.EsVacia() == false){ // comprueba si p.pos == NULL
		// devuelve el contenido
		// del nodo al que apunta p.
		cout << lista.Obtener(p) << endl; // comprueba si la direccion del nodo pertenece a la lista
											// y si es asi devuelve el poro que esta dentro de ese nodo.
		p = p.Siguiente();
	}
	return 0;
}
