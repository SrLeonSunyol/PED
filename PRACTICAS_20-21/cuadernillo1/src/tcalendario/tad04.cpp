#include <tcalendario.h>
#include <iostream>

using namespace std;

//Suma dias test
int main(void)
{
    TCalendario a(26, 7, 1996, "PED");
    cout << a++ << endl;
    cout << a++ << endl;
    cout << a << endl;

    TCalendario b(31, 12, 1996, "test paso de anyo");
    cout << b++ << endl;

    TCalendario c(31, 6, 1996, "fecha incorrecta deberia de ser 2/1/1900");
    cout << c++ << endl;
}
