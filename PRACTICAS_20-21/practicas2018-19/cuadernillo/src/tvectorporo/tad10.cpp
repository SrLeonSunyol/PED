#include <iostream>

using namespace std;

#include "tporo.h"
#include "tvectorporo.h"

int
main(void)
{
  TPoro a1(10, 10, 2.55, "Blanco");
  TPoro a2(10, 10, 2.55, "Blanco");
  TPoro a3(3, 4, 2.23456);
  TPoro vacio;
  TVectorPoro v(5);


  v[1] = a1;
  v[2] = vacio;
  v[3] = a2;
  v[4] = a3;
  v[5] = a1;

  cout << "Cantidad:" << v.Cantidad() << endl;
  cout << "Longitud:" << v.Longitud() << endl;
  cout << v << endl; 
}
