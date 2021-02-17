#ifndef _TListaPoro_
#define _TListaPoro_

#include <iostream>
#include <tporo.h>
#include <tvectorporo.h>
#include <tabbporo.h>
using namespace std;

class TListaNodo {
    friend class TListaPoro;
    friend class TListaPosicion;
    friend class TABBPoro;
    private:
        TPoro e;
        TListaNodo *anterior;
        TListaNodo *siguiente;
    
    public:
        TListaNodo ();
        TListaNodo (const TListaNodo &);
        ~TListaNodo ();
        TListaNodo & operator = (const TListaNodo &);
};

class TListaPosicion {
    friend class TListaPoro;
    friend class TABBPoro;
    private:
        TListaNodo *pos;

    public:
        TListaPosicion ();
        TListaPosicion (const TListaPosicion &);
        ~TListaPosicion ();
        TListaPosicion & operator = (const TListaPosicion &);

        bool operator == (const TListaPosicion &) const;
        TListaPosicion Anterior ();
        TListaPosicion Siguiente ();
        bool EsVacia () const;
        TListaPosicion CopiaPosicionAnterior (TListaPosicion, TListaNodo *);
        TListaPosicion CopiaPosicionSiguiente (TListaPosicion, TListaNodo *);
};

class TListaPoro {
    friend ostream & operator << (ostream &, const TListaPoro &);
    friend class TListaPosicion;
    friend class tABBPoro;
    private:
        TListaNodo *primero;
        TListaNodo *ultimo;

    public:
        TListaPoro ();
        TListaPoro (TListaPoro &);
        ~TListaPoro ();
        TListaPoro & operator = (const TListaPoro &);

        bool operator == (const TListaPoro &) const;
        TListaPoro operator + (const TListaPoro &) const;
        TListaPoro operator - (const TListaPoro &) const;
        bool EsVacio () const;
        bool Insertar (const TPoro &);
        bool Borrar (const TPoro &); //Busca y borra el elemento
        bool Borrar (const TListaPosicion &);
        TPoro Obtener (const TListaPosicion &) const;
        bool Buscar (const TPoro &) const;
        int Longitud () const;
        TListaPosicion Primera () const;
        TListaPosicion Ultima () const;
        TListaPoro ExtraerRango (int, int);
        void CopiarLista (const TListaPoro &);
        bool CompararListas (const TListaPoro &) const;
        TListaPosicion AsignarPosicion (TListaNodo *) const;
        //void InsertarNodoMedio (TPoro &poro, TListaNodo *nodo, TListaPosicion p1, TListaPosicion p2);
};

#endif 