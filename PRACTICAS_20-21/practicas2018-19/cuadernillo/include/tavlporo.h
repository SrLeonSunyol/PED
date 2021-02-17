#ifndef _TAVLPoro_
#define _TAVLPoro_

#include <tporo.h>
#include <tvectorporo.h>
#include <tlistaporo.h>

#include <iostream>

using namespace std;

class TNodoAVL;

class TAVLPoro {
    friend ostream & operator << (ostream &, const TAVLPoro &);
    friend class TNodoAVL;
    private:
        TNodoAVL *raiz;
        void InordenAux (TVectorPoro &, int &) const;
        void PreordenAux (TVectorPoro &, int &) const;
        void PostordenAux (TVectorPoro &, int &) const;

        void copiarPoros (const TAVLPoro &);
        bool compareAVL (const TAVLPoro &) const;

        bool insertarPoro (const TPoro &, bool &);
        TNodoAVL * crearNodo (const TPoro &);
        bool equilibrarIz (bool &);
        bool equilibrarDe (bool &);

        bool borrarPoro (const TPoro &, bool &);
        bool equilibrarBorradoIz (bool &);
        bool equilibrarBorradoDe (bool &);
        void mover(TNodoAVL *&, TAVLPoro &);

        TPoro getMaxIzq (const TAVLPoro &) const;
        void enraizar (TAVLPoro &, TPoro &, TAVLPoro &);
        TAVLPoro operator + (const TAVLPoro &);
        int getNodos () const;
        int getHojas () const;

    public: 
        TAVLPoro ();
        TAVLPoro (const TAVLPoro &);
        ~TAVLPoro ();
        TAVLPoro & operator = (const TAVLPoro &);
        bool operator == (const TAVLPoro &) const;
        bool operator != (const TAVLPoro &) const;
        bool EsVacio () const;
        bool Insertar (const TPoro &);
        bool Buscar (const TPoro &) const;
        bool Borrar (const TPoro &);
        int Altura () const;
        TPoro Raiz () const;
        int Nodos () const;
        int NodosHoja () const;
        TVectorPoro Inorden () const;
        TVectorPoro Preorden () const;
        TVectorPoro Postorden () const;
}; 

class TNodoAVL {
    friend class TAVLPoro;
    private:
        TPoro item;
        TAVLPoro iz;
        TAVLPoro de;
        int fe;
    public:

        TNodoAVL ();
        TNodoAVL (const TNodoAVL &);
        ~TNodoAVL ();
        TNodoAVL & operator = (const TNodoAVL &);
};
#endif