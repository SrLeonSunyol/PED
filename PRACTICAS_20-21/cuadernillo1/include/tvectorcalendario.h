#ifndef _TVectorCalendario_
#define _TVectorCalendario_

#include <iostream>
#include <string.h>
#include <tcalendario.h>

using namespace std;

class TVectorCalendario
{
    friend ostream &operator<<(ostream &, const TVectorCalendario &);

private:
    /* data */
    int tamano;
    TCalendario *c;
    TCalendario error;

public:
    TVectorCalendario();
    TVectorCalendario(int);
    TVectorCalendario(const TVectorCalendario &);
    ~TVectorCalendario();
    TVectorCalendario &operator=(const TVectorCalendario &);

    bool operator==(TVectorCalendario &) const;
    bool operator!=(TVectorCalendario &) const;
    TCalendario &operator[](int);
    TCalendario operator[](int) const;

    int Tamano() { return this->tamano; }
    int Ocupadas();
    bool ExisteCal(TCalendario &);
    void MostrarMensajes(int, int, int);
    bool Redimensionar(int);
};

#endif