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
  TPoro error;
  TVectorPoro v(3);

  v[1]=a1;
  v[2]=a2;
  v[3]=a3;


  TVectorPoro p(v);

  if (p == v)
     cout << "CORRECTO" << endl;
  else
     cout << "INCORRECTO" << endl; 
}
