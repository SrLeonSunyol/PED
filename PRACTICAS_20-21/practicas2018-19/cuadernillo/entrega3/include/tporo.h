#ifndef _TPoro_
#define _TPoro_

#include <iostream>
#include <string.h>

using namespace std;

class TPoro {
    friend ostream & operator << (ostream &, const TPoro &);
    private:
        /* data */
        int x;
        int y;
        double volumen;
        char* color;
        void CopiaParametros (int, int, double);
        void CopiaColor (const char *);
        void DeleteParametros ();
        bool CompararColor (const char *) const;

    public:
        TPoro ();
        TPoro (int, int, double);
        TPoro (int, int, double, const char *);
        TPoro (const TPoro &);
        ~TPoro ();
        TPoro & operator = (const TPoro &);

        bool operator == (const TPoro &) const;
        bool operator != (const TPoro &) const;
        void Posicion (int x, int y) { this -> x = x; this -> y = y; }
        void Volumen (double volumen) { this -> volumen = volumen; }
        void Color (const char *);
        int PosicionX () const { return this -> x; }
        int PosicionY () const { return this -> y; }
        double Volumen () const { return this -> volumen; }
        char * Color () { return this -> color; }
        bool EsVacio () const;
};

#endif