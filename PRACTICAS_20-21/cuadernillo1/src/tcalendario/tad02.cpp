#include <iostream>

using namespace std;

#include "tcalendario.h"

int main(void)
{
    TCalendario a(26, 7, 1996, NULL);
    TCalendario b(30, 2, 1996, NULL); 
    TCalendario c(26, 24, 1996, NULL);
    TCalendario d(29, 2, 1996, NULL);

    TCalendario e(29, 2, 2000, NULL);
    TCalendario f(29, 2, 2100, NULL);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
}
