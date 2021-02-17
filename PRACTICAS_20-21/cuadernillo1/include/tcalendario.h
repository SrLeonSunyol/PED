#ifndef _TCalendario_
#define _TCalendario_

#include <iostream>
#include <string.h>

using namespace std;

class TCalendario {
  friend ostream & operator << (ostream &, const TCalendario &);
  private:
    /* data */
    int dia, mes, anyo;
    char *mensaje;

    void CopiaParametros(int, int, int);
    void CopiaMensaje(const char *);

  public:
    TCalendario();
    TCalendario(int, int, int, const char *);
    TCalendario(const TCalendario &);
    ~TCalendario();  
    TCalendario & operator = (const TCalendario &);

    TCalendario & operator + (const int);
    TCalendario & operator - (const int);
    TCalendario & operator ++ (const int);
    TCalendario & operator ++ ();
    TCalendario operator -- (int);
    TCalendario & operator -- ();

    bool operator == (const TCalendario &) const;
    bool operator != (const TCalendario &) const;

    bool ModFecha(int, int, int);
    bool ModMensaje (const char *);

    bool operator > (const TCalendario &);
    bool operator < (const TCalendario &); 


    bool EsVacio() const;
    int Dia() { return this -> dia; };
    int Mes() { return this -> mes; };
    int Anyo() { return this -> anyo; };
    char * Mensaje() { return this -> mensaje; };
};

#endif