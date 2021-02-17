#include <iostream>
#include "tlistaporo.h"
using namespace std;

int main(){
	TListaPoro lista;

	lista.Insertar(TPoro(3,3,3,NULL));
	lista.Insertar(TPoro(5,5,5,NULL));
	lista.Insertar(TPoro(1,1,1,NULL));
	lista.Insertar(TPoro(4,4,4,NULL));
	cout << lista << endl;

	cout << lista.Borrar(TPoro(5,5,5, NULL)) << endl;
	cout << lista << endl;
	cout << lista.Borrar(TPoro(3,3,3, NULL)) << endl;
	cout << lista << endl;	
	cout << lista.Borrar(TPoro(1,1,1, NULL)) << endl;

	
	cout << lista.Borrar(TPoro(6,6,6, NULL)) << endl;
	
	return 0;
}
