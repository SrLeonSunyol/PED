#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 1, 1), q(2, 2, 2), r(3, 3, 3);
  TListaPoro a, b, c;

  cout << a.Longitud() << endl;
  cout << b.Longitud() << endl;
  cout << c.Longitud() << endl;

  
  a.Insertar(p);
  b.Insertar(p); b.Insertar(q);
  c.Insertar(p); c.Insertar(q); c.Insertar(r);
  
  if (a == b)
    cout << "son iguales" << endl;
  else 
    cout << "son distintos" << endl;
  
  cout << a.Longitud() << endl;
  cout << b.Longitud() << endl;
  cout << c.Longitud() << endl;
}
