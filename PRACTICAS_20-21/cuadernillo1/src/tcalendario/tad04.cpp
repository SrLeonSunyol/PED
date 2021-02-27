#include <tcalendario.h>
#include <iostream>

using namespace std;

//Suma dias test
int main(void)
{
    TCalendario a(26, 7, 1996, "PED");
    cout << ++a << endl;
    cout << ++a << endl;

    TCalendario b(31, 12, 1996, "test paso de anyo");
    cout << b++ << endl;
    cout << b << endl;

    TCalendario c(31, 6, 1996, "fecha incorrecta deberia de ser 2/1/1900");
    cout << ++c << endl;
    cout << c << endl;

    TCalendario d(28, 2, 1996, "bisiesto");
    cout << d++ << endl;
    cout << d++ << endl;
    cout << d << endl;

    cout << "resta" << endl;

    cout << a << endl;
    cout << --a << endl;
    cout << --a << endl;

    cout << b << endl;
    cout << b-- << endl;
    cout << b << endl;

    cout << c << endl;
    cout << --c << endl;
    cout << c-- << endl;

    cout << d << endl;
    cout << --d << endl;
    cout << --d << endl;

    TCalendario e(1012, 12, 19900, "");
    cout << --e << endl;

    //Se debria de llamar al constructor por defecto
    //Y deberia de tener un EsFechaCorrecta()
    TCalendario f(1, 1, 1900, "MENSAJE");
    cout << --f << endl;
}
  