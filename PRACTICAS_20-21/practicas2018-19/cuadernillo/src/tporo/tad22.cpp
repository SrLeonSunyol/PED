#include <iostream>
using namespace std;
#include "tporo.h"

/*CHEQUEO DE COLOR*/

int
main(void)
{
  TPoro a(1,1,0,NULL);
  TPoro b(2,2,20,"aZULmariNo");

  
  b.Color("VerDe");

  
    cout << b.Color() << endl;
}
