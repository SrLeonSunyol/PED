#include <iostream>
#include "tlistaporo.h"
using namespace std;

int main(){
	TListaPoro lista;

	lista.Insertar(TPoro(3,3,3,NULL));
	lista.Insertar(TPoro(5,5,5,NULL));
	lista.Insertar(TPoro(1,1,1,NULL));
	lista.Insertar(TPoro(4,4,4,NULL));
	lista.Insertar(TPoro(4,2,4,NULL));
	lista.Insertar(TPoro(2,3,5,NULL));//deberiía de ponerlo después del último poro con mismo volumen??
	lista.Insertar(TPoro(5,5,5,"pollito"));


	//TListaPoro lista_aux = lista;
	//cout << lista_aux << endl;
	//cout << lista << endl;
	TListaPoro copia1(lista);
	//TListaPoro copia2(copia1);

	//cout << lista << endl;
	//cout << copia1 << endl;
	//cout << copia2 << endl;
	/*
	cout << lista.ExtraerRango(2, 2) << endl;
	cout << lista;

	cout << "-------------" << endl;
	
	cout << copia1.ExtraerRango(-2, 2) << endl;
	cout << copia1 << endl;
	
	cout << "-------------" << endl;

	cout << copia2.ExtraerRango(3, 100) << endl;
	cout << copia2 << endl;

	cout << "-------------" << endl;
	*/
}

