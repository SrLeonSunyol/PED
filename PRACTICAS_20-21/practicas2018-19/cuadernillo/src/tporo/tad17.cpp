#include <iostream>
using namespace std;
#include "tporo.h"

int
main(void)
{
  TPoro a(-10,-20,3,NULL);

  cout << "PosicionX: " << a.PosicionX() << endl;
  cout << "PosicionY: " << a.PosicionY() << endl;
  cout << "Volumen: " << a.Volumen() << endl;
  cout << a << endl;
}
