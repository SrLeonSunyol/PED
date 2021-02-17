#include <tavlporo.h>

//TNodoAVL
TNodoAVL::TNodoAVL () { fe = 0; }

TNodoAVL::TNodoAVL (const TNodoAVL &n_avl) :item(n_avl.item), iz(n_avl.iz), de(n_avl.de) {}

TNodoAVL::~TNodoAVL () { fe = 0; }

TNodoAVL & TNodoAVL::operator = (const TNodoAVL &n_avl) {
    if (this != &n_avl) {
        (*this).~TNodoAVL();
        item = n_avl.item;
        iz = n_avl.iz;
        de = n_avl.de;
        fe = n_avl.fe;
    }
    return (*this);
}

//TAVLPoro
void TAVLPoro::InordenAux (TVectorPoro &v, int &i) const {
    if (!EsVacio()) {
        (raiz -> iz).InordenAux(v, i);
        v[i] = raiz -> item;
        i++;
        (raiz -> de).InordenAux(v, i);
    }
}
void TAVLPoro::PreordenAux (TVectorPoro &v, int &i) const {
    if (!EsVacio()) {
        v[i] = raiz -> item;
        i++;
        (raiz -> iz).PreordenAux(v, i);
        (raiz -> de).PreordenAux(v, i);
    }
}
void TAVLPoro::PostordenAux (TVectorPoro &v, int &i) const {
    if (!EsVacio()) {
        (raiz -> iz).PostordenAux(v, i);
        (raiz -> de).PostordenAux(v, i);
        v[i] = raiz -> item;
        i++;
    }
}

TAVLPoro::TAVLPoro () {
    raiz = NULL;
}

TAVLPoro::TAVLPoro (const TAVLPoro &avl_p) {
    raiz = NULL;
    copiarPoros(avl_p);
}

TAVLPoro::~TAVLPoro () {
    if (raiz != NULL) {
        delete raiz;
        raiz = NULL;
    }
}

TAVLPoro & TAVLPoro::operator = (const TAVLPoro &avl_p) {
    if (this != &avl_p) {
        (*this).~TAVLPoro();
        copiarPoros(avl_p);
    }
    return (*this);
}

bool TAVLPoro::operator == (const TAVLPoro &avl_p) const {
    return compareAVL(avl_p);
}

bool TAVLPoro::operator != (const TAVLPoro &avl_p) const {
    return !compareAVL(avl_p);
}

bool TAVLPoro::EsVacio () const {
    return (raiz == NULL)
        ? true
        : false;
}

bool TAVLPoro::Insertar (const TPoro &p) {
    bool crece = false;
    return (Buscar(p))
        ? false
        : insertarPoro(p, crece);
}

//miercoles ped
bool TAVLPoro::insertarPoro (const TPoro &p, bool &crece) {
    bool creceIz, creceDe;
    if (EsVacio()) {
        raiz = crearNodo(p);
        crece = true;
    } else {
        crece = creceIz = creceDe = false;
        if (raiz -> item.Volumen() > p.Volumen()) {
            (raiz -> iz).insertarPoro(p, creceIz);
            crece = creceIz;
        } else { 
            (raiz -> de).insertarPoro(p, creceDe);
            crece = creceDe;
        }

        if (crece) {
            if ((creceIz && raiz -> fe == 1) || (creceDe && raiz -> fe == -1)) {
                crece = false;
                raiz -> fe = 0;
            } else if (creceIz && raiz -> fe == 0) { 
                raiz -> fe = -1;
            } else if (creceDe && raiz -> fe == 0) {
                raiz -> fe = 1;
            } else if (creceIz && raiz -> fe == -1) {
                equilibrarIz(crece);
            } else /*if (creceDe && raiz -> fe == 1*/{
                equilibrarDe(crece);
            }
        } 
    }
}

TNodoAVL * TAVLPoro::crearNodo (const TPoro &p) {
    TNodoAVL *newNodo = new TNodoAVL();
    newNodo -> item = p;
    return newNodo;
}

//cambiar por *nodo
bool TAVLPoro::equilibrarIz (bool &crece) {
    TNodoAVL *j;   
    TNodoAVL *k;
    TAVLPoro *avl = new TAVLPoro();
    int e2 = 0;
    if ((*(*raiz).iz.raiz).fe == -1) { 
        mover(j, (*raiz).iz);
        mover((*raiz).iz.raiz, (*j).de);
        mover((*j).de.raiz, (*this));
        (*j).fe = 0;
        (*(*j).de.raiz).fe = 0;
        (*avl).raiz = j;
        mover(raiz, *avl);
    } else {
        mover(j, (*raiz).iz);
        mover(k, (*j).de);
        e2 = (*k).fe;
        mover((*raiz).iz.raiz, (*k).de);
        mover((*j).de.raiz, (*k).iz);
        (*avl).raiz = j;
        mover((*k).iz.raiz, *avl);
        mover((*k).de.raiz, (*this));
        (*k).fe = 0;

        switch (e2) {
            case -1: 
                (*(*k).iz.raiz).fe = 0;
                (*(*k).de.raiz).fe = 1;
                break;
            case 1:
                (*(*k).iz.raiz).fe = -1;
                (*(*k).de.raiz).fe = 0;
                break;
            case 0:
                (*(*k).iz.raiz).fe = (*(*k).de.raiz).fe = 0;
                break;
            default: 
                break;
        }  
        (*avl).raiz = k;
        mover(raiz, *avl);
    }
    crece = false;
    delete avl; 
    avl = NULL;
}

bool TAVLPoro::equilibrarDe (bool &crece) {
    TNodoAVL *j;
    TNodoAVL *k;
    TAVLPoro *avl = new TAVLPoro();
    int e2 = 0;
    if ((*(*raiz).de.raiz).fe == +1) { //DD
        mover(j, (*raiz).de);
        mover((*raiz).de.raiz, (*j).iz);
        mover((*j).iz.raiz, (*this));
        (*j).fe = 0;
        (*(*j).iz.raiz).fe = 0;
        (*avl).raiz = j;
        mover(raiz, *avl);
    } else { //DI
        mover(j, (*raiz).de);
        mover(k, (*j).iz);
        e2 = (*k).fe;
        mover((*raiz).de.raiz, (*k).iz);
        mover((*j).iz.raiz, (*k).de);
        (*avl).raiz = j;
        mover((*k).de.raiz, *avl);
        mover((*k).iz.raiz, (*this)); 
        (*k).fe = 0;
        switch (e2) {
            case -1: 
                (*(*k).iz.raiz).fe = 0;
                (*(*k).de.raiz).fe = 1;
                break;
            case 1:
                (*(*k).iz.raiz).fe = -1;
                (*(*k).de.raiz).fe = 0;
                break;
            case 0:
                (*(*k).iz.raiz).fe = (*(*k).de.raiz).fe = 0;
                break;
            default: 
                break;
        }  
        (*avl).raiz = k;
        mover(raiz, *avl);
    }
    crece = false;
    delete avl;
    avl = NULL;
}

bool TAVLPoro::Buscar (const TPoro &p) const {
    if (!EsVacio()) {
        if (raiz -> item == p) 
            return true;
        else 
            return ((raiz -> iz).Buscar(p) || (raiz -> de).Buscar(p));
    } 
    return false;
}

bool TAVLPoro::Borrar (const TPoro &p) {
    bool decrece = false;
    return (Buscar(p))
        ? borrarPoro(p, decrece)
        : false;
}

bool TAVLPoro::borrarPoro (const TPoro &p, bool &decrece) {
    bool decreceIz, decreceDe;
    if (!EsVacio()) {
        if (raiz -> iz.EsVacio() && raiz -> de.EsVacio()) {
            delete raiz;
            raiz = NULL;
            decrece = true;
            return decrece;
        } else {
            decrece = decreceIz = decreceDe = false;          
            if (!raiz -> iz.EsVacio() && !raiz -> de.EsVacio()) {
                if (raiz->item == p) {
                    TPoro poro(getMaxIzq(raiz -> iz));
                    (raiz -> iz).borrarPoro(poro, decreceIz);
                    enraizar(raiz -> iz, poro, raiz -> de);
                    decrece = decreceIz;
                } else {
                    if (p.Volumen() > (*raiz).item.Volumen()) {
                        ((*raiz).de).borrarPoro(p, decreceDe);
                        decrece = decreceDe;
                    } else {
                        ((*raiz).iz).borrarPoro(p, decreceIz);
                        decrece = decreceIz;
                    }
                }
            } else if (!raiz -> iz.EsVacio()) {
                if (raiz->item == p) {
                    TAVLPoro arbol(raiz -> iz);
                    delete raiz;
                    raiz = NULL;
                    (*this) = (*this) + arbol;
                    decrece = true;
                    return decrece;
                } else {
                    (raiz->iz).borrarPoro(p, decreceIz);
                    decrece = decreceIz;
                }
            } else {//de
                if (raiz->item == p) {
                    TAVLPoro arbol(raiz -> de);
                    delete raiz;
                    raiz = NULL;
                    (*this) = (*this) + arbol;
                    decrece = true;
                    return decrece;
                } else {
                    (raiz->de).borrarPoro(p, decreceDe);
                    decrece = decreceDe;
                }
            }    
        } 

        if (decrece) {
            if (decreceIz && raiz->fe == 1) {
                equilibrarBorradoDe(decrece);
            } else if (decreceDe && raiz->fe == -1) {
                equilibrarBorradoIz(decrece);
            } else if (decreceIz && raiz->fe == 0) { 
                raiz -> fe = +1;
                decrece = false;
            } else if (decreceDe && raiz->fe == 0) {
                raiz -> fe = -1;
                decrece = false;
            } else if ((decreceIz && raiz->fe == -1) 
                || (decreceDe && raiz->fe == 1)) {
                raiz->fe = 0;
                decrece = true;
            } 
        }
    } 
}

bool TAVLPoro::equilibrarBorradoDe (bool &decrece) {
    TNodoAVL *j;
    TNodoAVL *k ;
    TAVLPoro *avl = new TAVLPoro();
    int e2;
    int _fe = (*(*raiz).de.raiz).fe;
    if (_fe == 0 || _fe == 1) {//dd (+2, +1) && (+2, +0)
        mover(j, (*raiz).de);
        mover((*raiz).de.raiz, (*j).iz);
        mover((*j).iz.raiz, (*this));

        if (_fe == 0) {
            (*j).fe = -1;
            (*(*j).iz.raiz).fe = 1;
        } else {
            (*j).fe = 0;
            (*(*j).iz.raiz).fe = 0;
            decrece = true;
        }
        (*avl).raiz = j;
        mover(raiz, *avl);
    } else { //DI (+2, -1)
        mover(j, (*raiz).de);
        mover(k, (*j).iz);
        e2 = (*k).fe;
        mover((*raiz).de.raiz, (*k).iz);
        mover((*j).iz.raiz, (*k).de);
        (*avl).raiz = j;
        mover((*k).de.raiz, *avl);
        mover((*k).iz.raiz, (*this));
        (*k).fe = 0;
        switch (e2) {
            case -1:
                (*(*k).iz.raiz).fe = 0;
                (*(*k).de.raiz).fe = 1;
                break;
            case 1:
                (*(*k).iz.raiz).fe = -1;
                (*(*k).de.raiz).fe = 0;
                break;
            case 0:
                (*(*k).iz.raiz).fe = (*(*k).de.raiz).fe = 0;
                decrece = true;
                break;
            default:
                break;
        }
        (*avl).raiz = k;
        mover(raiz, *avl);
    }
    delete avl;
    avl = NULL;
}

bool TAVLPoro::equilibrarBorradoIz (bool &decrece) {
    TNodoAVL *j;
    TNodoAVL *k;
    TAVLPoro *avl = new TAVLPoro();
    int e2;
    int _fe = (*(*raiz).iz.raiz).fe;
    if (_fe == 0 || _fe == -1) {//dd (+2, +1) && (+2, +0)
        mover(j, (*raiz).iz);
        mover((*raiz).iz.raiz, (*j).de);
        mover((*j).de.raiz, (*this));
        if (_fe == 0) {
            (*j).fe = +1;
            (*(*j).de.raiz).fe = -1;
        } else {
            (*j).fe = 0;
            (*(*j).de.raiz).fe = 0;
            decrece = true;
        }
        (*avl).raiz = j;
        mover(raiz, *avl);
    } else { //ID (-2, +1)
        mover(j, (*raiz).iz);
        mover(k, (*j).de);
        e2 = (*k).fe;
        mover((*raiz).iz.raiz, (*k).de);
        mover((*j).de.raiz, (*k).iz);
        (*avl).raiz = j;
        mover((*k).iz.raiz, *avl);
        mover((*k).de.raiz, (*this));
        (*k).fe = 0;
        switch (e2) {
            case -1:
                (*(*k).iz.raiz).fe = 0;
                (*(*k).de.raiz).fe = 1;
                break;
            case 1:
                (*(*k).iz.raiz).fe = -1;
                (*(*k).de.raiz).fe = 0;
                break;
            case 0:
                (*(*k).iz.raiz).fe = (*(*k).de.raiz).fe = 0;
                break;
            default:
                break;
        }
        (*avl).raiz = k;
        mover(raiz, *avl);
        decrece = false;
    }
    delete avl;
    avl = NULL;
}

void TAVLPoro::mover(TNodoAVL *&n_avl, TAVLPoro &avl_p) {
    if (!avl_p.EsVacio()) {
        n_avl = avl_p.raiz;
        avl_p.raiz = NULL;
    } 
}

int TAVLPoro::Altura () const {
    int a1, a2;
     if (!EsVacio()) {
        a1 = (raiz -> iz).Altura();
        a2 = (raiz -> de).Altura();
        return (1 + (a1 < a2 ? a2 : a1));
    } else 
        return 0;
}

TPoro TAVLPoro::Raiz () const {
    return (EsVacio())
        ? TPoro()
        : raiz -> item;
}

int TAVLPoro::Nodos () const {
    return (EsVacio())
        ? 0
        : getNodos();
}

int TAVLPoro::NodosHoja () const {
    return (EsVacio())
        ? 0
        : getHojas();
}

TVectorPoro TAVLPoro::Inorden () const {
    int posicion = 1;
    TVectorPoro v(Nodos());
    InordenAux(v, posicion);
    return v;
}

TVectorPoro TAVLPoro::Preorden () const {
    int posicion = 1;
    TVectorPoro v(Nodos());
    PreordenAux(v, posicion);
    return v;
}

TVectorPoro TAVLPoro::Postorden () const {
    int posicion = 1;
    TVectorPoro v(Nodos());
    PostordenAux(v, posicion);
    return v;
}

ostream & operator << (ostream &os, const TAVLPoro &avl_p) {
    TVectorPoro v(avl_p.Inorden());
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

//auxiliares
void TAVLPoro::copiarPoros (const TAVLPoro &avl_p) {
    if (!avl_p.EsVacio()) {
        Insertar(avl_p.raiz -> item);
        (raiz -> iz).copiarPoros(avl_p.raiz -> iz);
        (raiz -> de).copiarPoros(avl_p.raiz -> de);
    }
}

bool TAVLPoro::compareAVL (const TAVLPoro &avl_p) const {
    if (!EsVacio()) {
        if (avl_p.Buscar((*raiz).item)) {
            return (((*raiz).iz.compareAVL(avl_p) && (*raiz).de.compareAVL(avl_p)));
        } else 
            return false;
    } else 
        return true;
}

TPoro TAVLPoro::getMaxIzq (const TAVLPoro &avl_p) const {
    TVectorPoro v(avl_p.Inorden());
    return v[v.Longitud()];
}

void TAVLPoro::enraizar (TAVLPoro &iz, TPoro &p, TAVLPoro &de) {
    TNodoAVL *aux = new TNodoAVL();
    aux -> item = p;
    (aux -> iz).raiz = iz.raiz;
    (aux -> de).raiz = de.raiz;
    iz.raiz = de.raiz = NULL;
    this -> ~TAVLPoro();
    raiz = aux;
}

TAVLPoro TAVLPoro::operator + (const TAVLPoro &avl_p) {
    TAVLPoro arbol(*this);
    TVectorPoro v(avl_p.Inorden());
    for (int i = 1; i <= v.Longitud(); i++)
        arbol.Insertar(v[i]);
    return arbol;
}

int TAVLPoro::getNodos () const {
    if (!EsVacio())
        return 1 + (raiz -> iz).getNodos() + (raiz -> de).getNodos();
    else 
        return 0;
}

int TAVLPoro::getHojas () const {
    if (EsVacio())
        return 0;
    else if (Nodos() == 1)
        return 1;
    else 
        return (raiz -> iz).getHojas() + (raiz -> de).getHojas();
}
