#include <iostream>
#include "tlistaporo.h"
using namespace std;

int main(){
	TListaPoro lista;

	lista.Insertar(TPoro(3,3,3,NULL));
	lista.Insertar(TPoro(5,5,5,NULL));
	lista.Insertar(TPoro(1,1,1,NULL));
	lista.Insertar(TPoro(4,4,4,NULL));
	lista.Insertar(TPoro(5,5,5,"pollito"));
	cout << lista << endl;

	TListaPosicion p;

	p = lista.Ultima();
	cout << lista.Borrar(p) << endl;
	cout << lista << endl;

	p = lista.Primera();
	cout << lista.Borrar(p) << endl;
	cout << lista << endl;

	p = lista.Primera();
	p = p.Siguiente();
	cout << lista.Borrar(p) << endl;
	cout << lista << endl;
			

	
	cout << lista.Borrar(TPoro(6,6,6, NULL)) << endl;
	
	return 0;
}
