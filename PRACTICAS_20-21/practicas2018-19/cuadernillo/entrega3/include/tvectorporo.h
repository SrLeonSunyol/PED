#ifndef _TVectorPoro_
#define _TVectorPoro_

#include <iostream>
#include <tporo.h>

using namespace std;

class TVectorPoro {
    friend ostream & operator << (ostream &, const TVectorPoro &);
    private:    
        int dimension;
        TPoro *datos;
        TPoro error;

    public:
        TVectorPoro ();
        TVectorPoro (int);
        TVectorPoro (const TVectorPoro &);
        ~TVectorPoro ();
        TVectorPoro & operator = (const TVectorPoro &);

        bool operator == (const TVectorPoro &) const;
        bool operator != (const TVectorPoro &) const;
        TPoro & operator [] (int);
        TPoro operator [] (int) const;
        int Longitud () { return this -> dimension; }
        int Cantidad();
        bool Redimensionar (int);
        void CopiarPoros (const TPoro *);
        bool CompararPoros (const TPoro *) const;
        bool RedimensionarMasVector (int);
        bool RedimensionarMenosVector (int);
};

#endif