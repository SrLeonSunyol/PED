#include <iostream>

using namespace std;

#include "tcalendario.h"

int main(void)
{
    cout << "Operadores aritmetico" << endl;
    
    TCalendario a(26, 7, 1996, NULL);
    TCalendario b(28, 12, 1996, NULL);
    cout << a << " compare " << b << endl;
    cout << (a > b) << endl;
    cout << (a < b) << endl;
    cout << (b < a) << endl;
    cout << (b > a) << endl;
    cout << (a == b) << endl;
    cout << (a != b) << endl;

    TCalendario c(26, 7, 1996, "");
    cout << c << " compare " << a << endl;
    cout << (a < c) << endl;  //1
    cout << (a > c) << endl;  //0
    cout << (c > a) << endl;  //1
    cout << (c < a) << endl;  //0
    cout << (a == c) << endl; //0 
    cout << (a != c) << endl; //1
    cout << (a == a) << endl;

    TCalendario d(26, 7, 1996, " ");
    cout << d << " compare " << c << endl;
    cout << (c < d) << endl; //1
    cout << (c > d) << endl; //0
    cout << (d > c) << endl; //1
    cout << (d < c) << endl; //0
    cout << (d == c) << endl;
    cout << (d != c) << endl;
    cout << (d == d) << endl;

    TCalendario e(26, 7, 1996, "Hola Adrian");
    cout << e << " compare " << d << endl;
    cout << (d < e) << endl; //1
    cout << (e > d) << endl; //1
    cout << (e < d) << endl; //0
    cout << (d > e) << endl; //0
    cout << (d == e) << endl;
    cout << (d != e) << endl;
    cout << (e == e) << endl;
}
