#include <iostream>
#include "tporo.h"
#include "tvectorporo.h"
#include "tavlporo.h"

using namespace std;

int
main(void)
{
/*******************************************************************/
/********** ASIGNACION , "<<" ; posible problema de CONST 	   */
/*******************************************************************/
  
  TAVLPoro a,b,c;

  TPoro p1(1,2,3,(char *) "rojo");
  TPoro p2(1,2,2,(char *) "azul");
  TPoro p3(1,2,1,(char *) "amarrillo");

  a.Insertar(p1);
  a.Insertar(p2);
  //a.Insertar(p3);

  cout << a.Inorden() << endl;


  return 1;
}
