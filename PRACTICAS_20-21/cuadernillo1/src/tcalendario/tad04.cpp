#include <tcalendario.h>
#include <iostream>

using namespace std;

//Suma dias test
int main(void)
{
    TCalendario a(26, 7, 1996, "PED");
    
    cout << a + 10 << endl;
    cout << a + 100 << endl;
}
