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
  TVectorPoro w(v);


  cout << v << endl;

  cout << w << endl;
 
}
