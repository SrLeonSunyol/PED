/************************************************************
** CONSTRUCTORES, = CON ARBOLES VACIOS
*************************************************************/
#include <iostream>
#include "tavlporo.h"

using namespace std;

int
main(void)
{
  /*TAVLPoro a,c;
  TAVLPoro b(a);

  c=b;
  cout << "No hace nada" << endl;
  */
  TAVLPoro a,b,c;
  TPoro p1(1,2,1,(char *) "amarrillo");
  TPoro p2(1,2,2,(char *) "azul");
  TPoro p3(1,2,3,(char *) "rojo");
  TPoro p4(1,2,4,(char *) "marron");
  TPoro p5(1,2,5,(char *) "azul");
  TPoro p6(1,2,6,(char *) "naranjita");
  TPoro p7(1,2,7,(char *) "morado");
  TPoro p8(1,2,8,(char *) "carmelita");
  TPoro p9(1,2,9,(char *) "amarillito");
  TPoro p10(1,2,10,(char *) "azulceleste");
  TPoro p11(1,2,11,(char *) "morado");
  TPoro p12(1,2,12,(char *) "carmelita");
  TPoro p13(1,2,13,(char *) "amarillito");
  TPoro p14(1,2,14,(char *) "azulceleste");
  TPoro p15(1,2,15,(char *) "castaño");
  
  /*
  b.Insertar(p3);
  b.Insertar(p2);
  b.Insertar(p1);
  b.Insertar(p5);
  b.Insertar(p6);
  b.Insertar(p7);
  b.Insertar(p15);
  b.Insertar(p10);

  b.Borrar(p6);
  b.Borrar(p1);
  b.Borrar(p3);
  b.Borrar(p2);
 
  cout << b.Inorden() << endl;
  cout << b.Postorden() << endl;
  cout << b.Preorden() << endl;
  cout << b.Altura() << endl;*/
  
  cout << "EStO ES ID" << endl;

  a.Insertar(p10);
  a.Insertar(p6);
  a.Insertar(p7);
  a.Insertar(p4);
  a.Insertar(p2);
  a.Insertar(p3);
  /*a.Insertar(p1);*/

  cout << a.Preorden() << endl;

  a.Borrar(p2);
  a.Borrar(p3);
  a.Borrar(p1);
  a.Borrar(p6);

  cout << a.Inorden() << endl;
  cout << a.Preorden() << endl;
  cout << a.Postorden() << endl;
  cout << a.Altura() << endl;

  return 0;
}
