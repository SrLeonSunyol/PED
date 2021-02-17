#include <tabbporo.h>

/**
 * TNodoABB
 */
TNodoABB::TNodoABB () {}   

TNodoABB::TNodoABB (const TNodoABB &nodo) :item(nodo.item), iz(nodo.iz), de(nodo.de) {}

TNodoABB::~TNodoABB () {}

TNodoABB & TNodoABB::operator = (const TNodoABB &nodo) {
    if (this != &nodo) {
        (*this).~TNodoABB();
        item = nodo.item;
        iz = nodo.iz;
        de = nodo.de;
    }
    return (*this);
}

/**
 * TABBPoro
 */
void TABBPoro::InordenAux (TVectorPoro &v, int &i) const {
    if (!EsVacio()) {
        (nodo -> iz).InordenAux(v, i);
        v[i] = nodo -> item;
        ++i;
        (nodo -> de).InordenAux(v, i);
    } 
}

void TABBPoro::PreordenAux (TVectorPoro &v, int &i) const {
    if (!EsVacio()) {
        v[i] = nodo -> item;
        i++;
        (nodo -> iz).PreordenAux(v, i);
        (nodo -> de).PreordenAux(v, i);
    }
}

void TABBPoro::PostordenAux (TVectorPoro &v, int &i) const {
    if (!EsVacio()) {
        (nodo -> iz).PostordenAux(v, i);
        (nodo -> de).PostordenAux(v, i);
        v[i] = nodo -> item;
        i++;
    }
}

TABBPoro::TABBPoro () {
    nodo = NULL;
}

TABBPoro::TABBPoro (const TABBPoro &abb) {
    nodo = NULL; //porque
    //nodo = abb.nodo;
    copiarPoros(abb);
}

TABBPoro::~TABBPoro () {
    if (nodo != NULL) {
        delete nodo;
        nodo = NULL;
    }
}   

TABBPoro & TABBPoro::operator = (const TABBPoro &poro) {
    if (this != &poro) {
        (*this).~TABBPoro();
        copiarPoros(poro);
    }
    return (*this);
}

bool TABBPoro::operator == (const TABBPoro &abb) const {
    return compareABB(abb);
}

bool TABBPoro::EsVacio () const {
    return (nodo == NULL)
        ? true
        : false;
}

bool TABBPoro::Insertar (const TPoro &poro) {
    return (Buscar(poro))
        ? false
        : insertarPoro(poro);
}

bool TABBPoro::Borrar (const TPoro &poro) {
    return (Buscar(poro))
        ? borrarPoro(poro)
        : false;
}

bool TABBPoro::Buscar (const TPoro &poro) const {
    if (!EsVacio()){
        if (nodo -> item == poro) 
            return true;   
        else 
            return ((nodo -> iz).Buscar(poro) || (nodo -> de).Buscar(poro));
    } 
    return false;
}

TPoro TABBPoro::Raiz () const {
    return (EsVacio())
        ? TPoro()
        : nodo -> item;
}

int TABBPoro::Altura () const {
    int a1, a2;
    if (!EsVacio()) {
        a1 = (nodo -> iz).Altura();
        a2 = (nodo -> de).Altura();
        return (1 + (a1 < a2 ? a2 : a1));
    } else 
        return 0;
}

int TABBPoro::Nodos () const {
    return (EsVacio())
        ? 0
        : getNodos();
}

int TABBPoro::NodosHoja () const {
    return (EsVacio())
        ? 0
        : getHojas();
}

TVectorPoro TABBPoro::Inorden () const {
    int posicion = 1;
    TVectorPoro v(Nodos());
    InordenAux(v, posicion);
    return v;
}

TVectorPoro TABBPoro::Preorden () const {
    int posicion  = 1;
    TVectorPoro v(Nodos());
    PreordenAux(v, posicion);
    return v;
}

TVectorPoro TABBPoro::Postorden () const {
    int posicion = 1;
    TVectorPoro v(Nodos());
    PostordenAux(v, posicion);
    return v;
}

TVectorPoro TABBPoro::Niveles () const {
    queue <TABBPoro> niveles;                       
    return nivelesAux(*this, niveles);
}

TVectorPoro TABBPoro::nivelesAux (TABBPoro origin, queue <TABBPoro> &niveles) const {
    TVectorPoro v(Nodos());
    if (!origin.EsVacio()) {
        niveles.push(origin);
        TABBPoro aux;
        int pos = 1;

        while (!niveles.empty()) {
            aux = niveles.front();
            v[pos] = aux.nodo -> item;
            niveles.pop();
            if (!aux.nodo -> iz.EsVacio())
                niveles.push(aux.nodo -> iz);
            if (!aux.nodo -> de.EsVacio())
                niveles.push(aux.nodo -> de); 
            pos++;
        }
    }
    return v;
}


TABBPoro TABBPoro::operator + (const TABBPoro &abb) {
    TABBPoro arbol(*this);
    TVectorPoro v = abb.Inorden();
    for (int i = 1; i <= v.Longitud(); i++) {
        arbol.Insertar(v[i]);
    }
    return arbol;
}

TABBPoro TABBPoro::operator - (const TABBPoro &abb) {
    if (abb.EsVacio()) {
        return (*this);
    }

    TABBPoro new_arbol;
    TVectorPoro abb_iz(Inorden());

    if ((*this).EsVacio())
        return new_arbol;

    for (int i = 1; i <= abb_iz.Longitud(); i++) {
        if (!abb.Buscar(abb_iz[i])) 
            new_arbol.Insertar(abb_iz[i]);
    }

    return new_arbol;
}

ostream & operator << (ostream &os,const TABBPoro &abb) {
    TVectorPoro v(abb.Niveles());
    os << "[";
    for (int i = 1; i <= v.Longitud(); i++) {
        os << i << " ";
        if (i != v.Longitud()) 
            os << v[i] << " ";
        else 
            os << v[i];
    }
    os << "]";
    return os;
} 

//funciones auxiliares
/*void TABBPoro::destroyTree (TABBPoro &origin) {
    if (origin.nodo != NULL) {
        origin.nodo -> item.~TPoro();
        TABBPoro aux_iz, aux_de;
        aux_iz = origin.nodo -> iz;
        aux_de = origin.nodo -> de;
        delete origin.nodo;
        origin.nodo = NULL;
        destroyTree(aux_iz);
        destroyTree(aux_de);
    }
}*/

void TABBPoro::copiarPoros (const TABBPoro &origin) {
    if (!origin.EsVacio()) {
        Insertar(origin.nodo -> item);
        (nodo -> iz).copiarPoros(origin.nodo -> iz);
        (nodo -> de).copiarPoros(origin.nodo -> de);
    }
}

bool TABBPoro::compareABB (const TABBPoro &origin) const {
    if (!EsVacio()){
        if (nodo -> item == origin.nodo -> item) {
            return ((nodo -> iz).compareABB(origin.nodo -> iz) && (nodo -> de).compareABB(origin.nodo -> de));
        } else 
            return false;
    } else 
        return true;
}

int TABBPoro::getNodos () const {
    if (!EsVacio()) {
        return 1 + (nodo -> iz).getNodos() + (nodo -> de).getNodos();
    } else 
        return 0;
}

bool TABBPoro::insertarPoro (const TPoro &poro) {
    if (EsVacio()) {
        nodo = crearNodo(poro);
        return true;
    } else { 
        if (nodo -> item.Volumen() > poro.Volumen()) 
            (nodo -> iz).insertarPoro(poro);  
        else 
            (nodo -> de).insertarPoro(poro);           
    }  
}

TNodoABB * TABBPoro::crearNodo (const TPoro &poro) {
    TNodoABB *newNodo = new TNodoABB();
    newNodo -> item = poro;
    return newNodo;
}

bool TABBPoro::borrarPoro (const TPoro &poro) {
    if (!EsVacio()) {
        if (Raiz() == poro) { //esta en uno de los hijos
            if (nodo -> iz.EsVacio() && nodo -> de.EsVacio()) { //esta solo // nodo hoja
                delete nodo;
                nodo = NULL;
                return true;
            } else {
                if (!nodo -> iz.EsVacio() && !nodo -> de.EsVacio()) { //con 2 hijos
                    if ((nodo -> iz).Nodos() < (nodo -> de).Nodos()) {
                        TPoro p(getMaxIzq(nodo -> iz));
                        (nodo -> iz).Borrar(p);
                        enraizar(nodo -> iz, p, nodo -> de);
                    } else {
                        TPoro p(getMinDer(nodo -> de));
                        (nodo -> de).Borrar(p);
                        enraizar(nodo -> iz, p, nodo -> de);
                    }
                    return true;
                } else if (!nodo -> iz.EsVacio()) {
                    TABBPoro arbol(nodo -> iz);
                    delete nodo;
                    nodo = NULL;
                    (*this) = (*this) + arbol;
                    return true;
                } else {
                    TABBPoro arbol(nodo -> de);
                    delete nodo;
                    nodo = NULL;
                    (*this) = (*this) + arbol;
                    return true;
                }
            } 
        } else {
            return ((nodo -> iz).borrarPoro(poro) || (nodo -> de).borrarPoro(poro));
        }
    } else
        return false;
}

int TABBPoro::getHojas () const {
    if (EsVacio())
        return 0;
    else if (Nodos() == 1)
        return 1;
    else 
        return (nodo -> iz).getHojas() + (nodo -> de).getHojas(); 
}

TPoro TABBPoro::getMaxIzq (const TABBPoro &origin) const {
    TVectorPoro v(origin.Inorden());
    return v[v.Longitud()];
}

TPoro TABBPoro::getMinDer (const TABBPoro &origin) const {
    TVectorPoro v(origin.Inorden());
    return v[1];
}

void TABBPoro::enraizar (TABBPoro &iz, const TPoro poro, TABBPoro &de) {
    TNodoABB *aux = new TNodoABB();
    aux -> item = poro;
    (aux -> iz).nodo = iz.nodo;
    (aux -> de).nodo = de.nodo;
    iz.nodo = de.nodo = NULL;
    this -> ~TABBPoro();
    nodo = aux;
}

int* TABBPoro::BuscaAVL(const TListaPoro &l) const {
    int* v = NULL;
    if (l.EsVacio()) {
        return v;
    }

    v = new int[l.Longitud()];
    int pos = 0;
    if (!EsVacio()) {
        TListaPosicion p;
        p = l.Primera();
        while (!p.EsVacia()) {
            if (!Buscar(p.pos->e)) 
                v[pos] = 0;
            else if (Raiz() == p.pos->e)
                v[pos] = 3;
            else if (esHijoIzq(p.pos->e,(*this)))
                v[pos] = 1;
            else 
                v[pos] = 2;
            pos++;
            p = p.Siguiente();
        }
    }
    return v;
}

bool TABBPoro::esHijoIzq(TPoro p, const TABBPoro &abb) const {
    if (!abb.EsVacio()) {
        if (abb.nodo->iz.nodo->item == p) {
            return true;
        } else if (abb.nodo->de.nodo->item == p) {
            return false;
        } else
            if (abb.nodo->item.Volumen() > p.Volumen())
                esHijoIzq(p, abb.nodo->iz) ;
            else 
                esHijoIzq(p, abb.nodo->de);
    }  
}






















