#include <iostream>
#include "tlistaporo.h"
#include "tporo.h"
using namespace std;

int main(){
	TListaPoro lista;

	lista.Insertar(TPoro(1, 3, 2, NULL));
	lista.Insertar(TPoro(1, 5, 4, NULL));
	lista.Insertar(TPoro(1, 1, 1, NULL));
	lista.Insertar(TPoro(1, 1, 3, NULL));

	cout << lista << endl;

	return 0;
}


