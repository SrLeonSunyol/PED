#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/*******************************************************************/
/********** ASIGNACION , "<<" ; posible problema de CONST 	   */
/*******************************************************************/
  
  TABBPoro a,b,c;

  TPoro p1(1,2,1,(char *) "rojo");

  cout << b.Insertar(p1) << endl;

  //cout << b << endl;

  cout << (a = b).Inorden() << endl;

  cout << (a = c).Inorden() << endl;


  return 1;
}
