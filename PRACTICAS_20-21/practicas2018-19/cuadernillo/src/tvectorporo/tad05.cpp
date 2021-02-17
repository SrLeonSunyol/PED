#include <iostream>

using namespace std;

#include "tporo.h"
#include "tvectorporo.h"

int
main(void)
{
  TPoro a(1, 2, 3, "rojo");
  TVectorPoro v(10);

  
  v[1] = a;
  v[2] = a;
  v[3] = a;
  v[4] = a;
  v[5] = a;
  v[6] = a;
  v[7] = a;
  v[8] = a;
  v[9] = a;
  v[10] = a;
  

  //cout << a << endl;
  cout << v << endl;
}
