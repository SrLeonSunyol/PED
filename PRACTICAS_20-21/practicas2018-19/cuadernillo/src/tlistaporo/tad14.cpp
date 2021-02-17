#include "tlistaporo.h"
#include "tporo.h"
#include <iostream>
using namespace std;

int main(){
	TListaPoro l;
	TListaPoro l2;

	l.Insertar(TPoro(2, 2, 2, NULL));
	l.Insertar(TPoro(5, 5, 5, NULL));
	l.Insertar(TPoro(4, 4, 4, NULL));
	l.Insertar(TPoro(1, 1, 1, NULL));
	l.Insertar(TPoro(7, 7, 7, "alejandrooor"));



	l2.Insertar(TPoro(2, 2, 2, NULL));
	l2.Insertar(TPoro(5, 5, 5, NULL));
	l2.Insertar(TPoro(4, 4, 4, NULL));
	l2.Insertar(TPoro(1, 1, 1, NULL));
	l2.Insertar(TPoro(7, 7, 7, "alejandrooor"));

	cout << l << endl;

	if(l.Buscar(TPoro(2, 2, 2, NULL)))
		cout << "encontrado" << endl;

	if(!l.Buscar(TPoro(2, 2, 2, "PUTA"))){
		cout << "no encontrado" << endl;
	}


	if(l == l2 && l2 == l){
		cout << "comoemdsakjlfdsak la pollla" << endl;
	}
	l2.Insertar(TPoro(3,3,3, NULL));
	if(l == l2){
		cout << "mal" << endl;
	}
	else{
		cout << "bien" << endl;
	}

	return 0;
}

