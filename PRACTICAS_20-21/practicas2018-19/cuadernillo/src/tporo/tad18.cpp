#include <iostream>
using namespace std;
#include "tporo.h"

/*4 casos de EsVacio() TRUE : 
- "TPoro a;"
- "b(a)" y "b=a"
- "b.~TPoro();"
*/


int
main(void)
{
  TPoro a;
  TPoro b(0, 0, 0, NULL);
  TPoro c(a);
  TPoro d;
  d=b;
  TPoro e(0, 0, 0, NULL);
  e.~TPoro();

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(b.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(c.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(d.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(e.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;
}
