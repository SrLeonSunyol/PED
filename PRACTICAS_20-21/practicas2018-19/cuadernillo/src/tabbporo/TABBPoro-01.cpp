#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/*******************************************************************/
/***************** CONSTR. COPIA , "=" ; posible copia de punteros */
/*******************************************************************/
  
  TABBPoro a, d;

  TPoro p1(1,2,6,(char *) "rojo");
  TPoro p2(1,2,3,(char *) "verde");
  TPoro p3(1,2,8, (char *) "fosforito");
  TPoro p4(1,2,1,(char *) "naranja");
  TPoro p5(1,2, 5, (char* ) "amarillo");
  TPoro p6(1,1,7,(char *) "morado");
  TPoro p7(1,1,10,(char *) "amarillo");

  d.Insertar(p1);
  d.Insertar(p2);
  d.Insertar(p3);
  d.Insertar(p4);
  d.Insertar(p5);
  d.Insertar(p6);
  d.Insertar(p7);

  TListaPoro l;
  l.Insertar(p4);
  l.Insertar(p1);
  l.Insertar(p3);
  TPoro p25(1,2,15,(char*) "rojo");
  l.Insertar(p25);  

  int* vector = d.BuscaAVL(l);

  for (int i = 0; i<l.Longitud(); i++)
    cout << vector[i] << endl;


  /*
  a.Insertar(p1);
  a.Insertar(p2);

  TABBPoro b(a);
  //cout << "Altura: " << b.Altura() << endl;
  //cout << "Raiz: " << b.Raiz() << endl;
  //cout << "Nodos hoja: " << b.NodosHoja() << endl;
  TABBPoro c;
  c=b;
  c.Insertar(p2);
  //cout << "Altura: " << c.Altura() << endl;
  //cout << "Raiz: " << c.Raiz() << endl;
  //cout << "Nodos hoja: " << c.NodosHoja() << endl;

  
  a.Insertar(p3);
  a.Insertar(p4);
  a.Insertar(p5);
  a.Insertar(p6);

  cout << a.Inorden() << endl;
  cout << "POSTORDEN" << endl;
  cout << a.Postorden() << endl;
  cout << "PREORDEN" << endl;
  cout << a.Preorden() << endl;
  

  if( a.Inorden() == b.Inorden() )
        cout << "MAL! SE HAN COPIADO PUNTEROS" << endl;
  else
	cout << "CORRECTO CONSTRUCTOR DE COPIA" << endl;
  
 
  b.Insertar(p4);*/
  /*TVectorPoro v;
  v = b.Inorden();
  for (int i = 1; i <= v.Longitud(); i++)
    cout << v[i] << endl;
  cout << b.Inorden() << endl;
  cout << b.Postorden() << endl;
  cout << b.Preorden() << endl; //solo este va aocmo tiene que ir;

  */
  //cout << b.Inorden() << endl;
  //cout << c.Inorden() << endl;
  
  /*if( b.Inorden() == c.Inorden() )
        cout << "MAL! SE HAN COPIADO PUNTEROS" << endl;
  else
	cout << "CORRECTA ASIGNACION" << endl;
  */
  return 1;
}
