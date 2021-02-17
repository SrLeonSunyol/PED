#ifndef _TABBPoro_
#define _TABBPoro_

#include <tporo.h>
#include <tlistaporo.h>
#include <tvectorporo.h>

#include <iostream>
#include <queue>


using namespace std;
using std::queue;

class TNodoABB;

class TABBPoro {
    friend ostream & operator << (ostream &, const TABBPoro &);
    friend class TNodoABB;
    friend class TListaPoro;
    friend class TPoro;
    friend class TListaPosicion;
    friend class TListaNodo;

    private:
        TNodoABB *nodo;
        void InordenAux (TVectorPoro &, int &) const;
        void PreordenAux (TVectorPoro &, int &) const;
        void PostordenAux (TVectorPoro &, int &) const;

        //void destroyTree (TABBPoro &);
        void copiarPoros (const TABBPoro &); 
        bool compareABB (const TABBPoro &) const;
        int getNodos () const;
        bool insertarPoro (const TPoro &poro);
        TNodoABB * crearNodo (const TPoro &);
        bool borrarPoro (const TPoro &poro);
        TPoro getMaxIzq (const TABBPoro &) const;
        TPoro getMinDer (const TABBPoro &) const;
        int getHojas () const;
        void enraizar (TABBPoro &, const TPoro, TABBPoro &);
        TVectorPoro nivelesAux (TABBPoro , queue <TABBPoro> &) const;
        TVectorPoro nivelesAuxIter (TABBPoro &, TVectorPoro &);
    

    public:
        TABBPoro ();
        TABBPoro (const TABBPoro &);
        ~TABBPoro ();
        TABBPoro & operator = (const TABBPoro &);

        bool operator == (const TABBPoro &) const;
        bool EsVacio () const;
        bool Insertar (const TPoro &);
        bool Borrar (const TPoro &);
        bool Buscar (const TPoro &) const;
        TPoro Raiz () const;
        int Altura () const;
        int Nodos () const;
        int NodosHoja () const;

        TVectorPoro Inorden () const;
        TVectorPoro Preorden () const;
        TVectorPoro Postorden () const;
        TVectorPoro Niveles () const;

        TABBPoro operator + (const TABBPoro &);
        TABBPoro operator - (const TABBPoro &);

        //examen julio 2015
        int* BuscaAVL (const TListaPoro &) const;
        bool esHijoIzq (TPoro,const TABBPoro &) const;
};

class TNodoABB {
    friend class TABBPoro;
    private:
        TPoro item;
        TABBPoro iz;
        TABBPoro de;
    public:
        TNodoABB ();
        TNodoABB (const TNodoABB &);
        ~TNodoABB ();
        TNodoABB & operator = (const TNodoABB &);
};

#endif