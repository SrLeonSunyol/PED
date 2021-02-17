#include <iostream>

using namespace std;

#include "tlistaporo.h"

int
main(void)
{
  TPoro p(1, 2, 3, "rojo");
  TPoro q(1, 3, 2, "azul");
  TPoro s(1, 4, 5, "amarillo");
  TListaPoro a, b;
  TPoro k;
  TPoro i;

  TPoro u(1, 2, 3);

  TListaPosicion pos;

  a.Insertar(p);
  a.Insertar(s);
  b.Insertar(p); b.Insertar(q); b.Insertar(s);
  cout << a << endl;
  cout << b << endl;

  cout << "operando de asignación" << endl;
  b = a;
  cout << "resultado" << endl;
  cout << a << endl;
  cout << b << endl;

  cout << "destruimos la lista original, que pasará con la copia, debería permanecer" << endl;
  a.~TListaPoro();
  cout << a << endl;
  cout << b << endl;
  /*
  cout << "vemos que tal funciona borrar" << endl;
  if (a.Insertar(p))
    cout << "esto no deberia pasar" << endl;
  else 
    cout << "biennnn no lo ha insertado porque está repetido" << endl;
  */

  a = b;
  (a.Insertar(q))
    ? cout << "correct" << endl
    :cout << "Error el poro ya existe" << endl;

  (a.Insertar(s))
    ? cout << "correct" << endl
    : cout << "error el poro ya existe" << endl;
  
  /*
  if (k == i)
    cout << "son iguales los punteros vacios" << endl;
  
  if (k == u)
    cout << "error" << endl;
  else 
    cout << "son distintos un poro vacio con un poro sin color" << endl;

  if (p == u)
    cout << "error" << endl;
  else
    cout << "son ditintos por el color" << endl;
  */
  a.Borrar(a.Primera().Siguiente());
  cout << a << endl;
  a.Borrar(a.Primera().Siguiente());
  cout << a << endl;

}
