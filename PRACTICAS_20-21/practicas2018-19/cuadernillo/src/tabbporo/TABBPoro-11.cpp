#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/**********************************************/
/***************** ALTURA, NODOS, NODOSHOJA   */
/**********************************************/
  
  TABBPoro a;
  TABBPoro b;

  TPoro p100(1,2,100,(char *) "rojo");
  TPoro p50(1,2,50,(char *) "rojo");
  TPoro p20(1,2,20,(char *) "rojo");
  TPoro p110(1,2,110,(char *) "rojo");
  TPoro p70(1,2,70,(char *) "amarillo");

  TPoro p25(1,2,25, (char *) "azul");
  TPoro p17(1,2,17, (char *) "azul");
  TPoro p27(1,2,27, (char *) "azul");
  TPoro p15(1,2,15, (char *) "azul");
  TPoro p22(1,2,22, (char *) "azul");
  TPoro p30(1,2,30, (char *) "azul");
  TPoro p12(1,2,12, (char *) "azul");
  TPoro p21(1,2,21, (char *) "azul");
  TPoro p24(1,2,24, (char *) "azul");
  TPoro p28(1,2,28, (char *) "azul");


  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(p100);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(p50);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(p20);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(p110);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Borrar(p110);
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  a.Insertar(p70);
  cout << "Altura: " << a.Altura() << endl;
  cout << "Nodos: " << a.Nodos() << endl;
  cout << "NodosHoja: " << a.NodosHoja() << endl;
  cout << "Raiz: " << a.Raiz() << endl;


  
  cout << b.Insertar(p25) << endl;
  cout << b.Insertar(p17) << endl;
  cout << b.Insertar(p27) << endl;
  cout << b.Insertar(p15) << endl;
  cout << b.Insertar(p22) << endl;
  cout << b.Insertar(p30) << endl;
  cout << b.Insertar(p12) << endl;
  cout << b.Insertar(p21) << endl;
  cout << b.Insertar(p24) << endl;
  cout << b.Insertar(p28) << endl;

  cout << "Altura: " << b.Altura() << endl;
  cout << "Nodos: " << b.Nodos() << endl;
  cout << "NodosHoja: " << b.NodosHoja() << endl;
  cout << "Raiz: " << b.Raiz() << endl;
  cout << a.Insertar(p100) << endl;
  cout << a.Insertar(p110) << endl;
  
  cout <<"Altura: "<<a.Altura()<<endl;
  cout <<"Nodos: "<<a.Nodos()<<endl;
  cout <<"NodosHoja: "<<a.NodosHoja()<<endl;
  cout <<"Raiz: "<<a.Raiz()<<endl;

  cout << a.Borrar(p100) << endl;

  cout << a.Raiz() << endl;
  return 1; 
}
