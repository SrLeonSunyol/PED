#include <iostream>
#include "tabbporo.h"

int main (void) {
    TABBPoro a,b;

    TPoro p1(1,2,25, (char *) "azul");
    TPoro p2(1,2,20, (char *) "azul");
    TPoro p3(1,2,40, (char *) "azul");
    TPoro p4(1,2,15, (char *) "azul");
    TPoro p5(1,2,24, (char *) "azul");
    TPoro p6(1,2,27, (char *) "azul");
    TPoro p7(1,2,45, (char *) "azul");
    TPoro p8(1,2,19, (char *) "azul");
    TPoro p9(1,2,41, (char *) "azul");
    TPoro p10(1,2,46, (char *) "azul");
    TPoro p11(1,2,18, (char *) "azul");

    a.Insertar(p1);
    a.Insertar(p2);
    a.Insertar(p3);
    a.Insertar(p4);
    a.Insertar(p5);
    a.Insertar(p6);
    a.Insertar(p7);
    a.Insertar(p8);
    a.Insertar(p9);
    a.Insertar(p10);
    a.Insertar(p11);

    b.Insertar(p5);
    b.Insertar(p7);
    b.Insertar(p1);
    b.Insertar(p2);
    b.Insertar(p11);

    cout << a.Inorden() << endl;
    cout << a.Postorden() << endl;
    cout << a.Preorden() << endl;
    cout << a.Niveles() << endl;

    cout << a << endl;

    cout << b.Inorden() << endl;
    cout << b.Postorden() << endl;
    cout << b.Preorden() << endl;
    cout << b.Niveles() << endl;

    cout << b << endl;

    TABBPoro c;
    cout << c << endl;

    if ((a - b + b) == (a - b + b))
        cout << "son iguales a y b" << endl;
    else
        cout << "correcto porque no son iguales" << endl;

    cout << (a - b)  << endl;
    cout << a + b << endl;

    return 1;
}