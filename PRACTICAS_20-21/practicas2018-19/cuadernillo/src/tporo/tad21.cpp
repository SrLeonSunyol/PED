#include <iostream>
using namespace std;
#include "tporo.h"

/*CONSTR. COPIA; */
int
main(void)
{
  TPoro a(2, 2, 20);
  TPoro b(2, 2, 20, NULL);
  TPoro c(b);

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

}
