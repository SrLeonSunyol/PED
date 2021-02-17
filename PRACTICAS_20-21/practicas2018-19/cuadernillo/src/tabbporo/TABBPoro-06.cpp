#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/************************************************************************/
/***************** INSERCION MULTIPLE (2) ; posible desborde de memoria */
/************************************************************************/
  
	TABBPoro a,b,c;

	TPoro p2(1,1,50, (char*) "amarillo");
	TPoro p3(1,10,100, (char*) "naranja");

	for(int i=1; i<=1; i++)
	{
		int num;
		for(num=1; num<=10; num++)
	//  for(num=1; num<=1000; num++)
		{
			TPoro p1(1,2,(double) num,(char *) "rojo");
			if(!a.Insertar(p1))
				cout << "Error NO INSERCION => ";
			p1.~TPoro();
			cout << a.Nodos() << endl;
		}
		cout << a.Inorden() << endl;

		for(num=1; num<=10; num++)
	//  for(num=1; num<=1000; num++)
		{
			TPoro p1(1,2,(double) num,(char *) "rojo");
			if(!a.Borrar(p1))
				cout << "Error NO BORRADO => ";
			p1.~TPoro();
			cout << a.Nodos() << endl;
		}
	}

	/*
	b.Insertar(p2);
	b.Insertar(p3);

	c = a + b;
	cout << c.Inorden() << endl;
	*/

	cout << a.Inorden() << endl;


cout << "CORRECTA INSERCION MULTIPLE" << endl;

return 1;
}

