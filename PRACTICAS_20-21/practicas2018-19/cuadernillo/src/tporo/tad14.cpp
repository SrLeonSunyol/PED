#include <iostream>
using namespace std;
#include "tporo.h"

/*CHEQUEO DE = Y EL DESTRUCTOR*/
int
main(void)
{
  TPoro a;
  TPoro b(2,2,20,NULL);
  TPoro c(0,0,0,NULL);

  b.~TPoro();
  if(a==b)
    cout << "IGUALES" << endl;
  else
    cout << "DISTINTOS" << endl;

  b=c;
  if(a==b)
    cout << "IGUALES" << endl;
  else
    cout << "DISTINTOS" << endl;
}
