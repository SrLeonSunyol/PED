#include <iostream>

using namespace std;

#include "tporo.h"
#include "tvectorporo.h"

int
main(void)
{
  TPoro a1(10, 10, 2.55, "Blanco");
  TPoro a2(10, 10, 2.55, "Blanco");
  TPoro vacio;
  TVectorPoro v(5);


  v[1] = a1;
  v[2] = vacio;
  v[3] = a2;

  v[11] = a1;
  v[200] = vacio;
  v[3000] = a2;


  cout << v << endl;
 
}
