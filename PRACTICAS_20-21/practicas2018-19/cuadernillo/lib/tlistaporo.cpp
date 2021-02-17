#include <tlistaporo.h>

/**
 * TlistaNodo
 */
TListaNodo::TListaNodo () {
    anterior = NULL;
    siguiente = NULL;
}

TListaNodo::TListaNodo (const TListaNodo &nodo): e(nodo.e){
    anterior = nodo.anterior;
    siguiente = nodo.siguiente;
}

TListaNodo::~TListaNodo () {
    anterior = NULL;
    siguiente = NULL;
    e.~TPoro();
}

TListaNodo & TListaNodo::operator = (const TListaNodo &nodo) {
    if (this != &nodo) {
        (*this).~TListaNodo();
        e = nodo.e;
        anterior = nodo.anterior;
        siguiente = nodo.siguiente;
        
    }
    return (*this);
} 

/**
 * TListaPosicion
 */
TListaPosicion::TListaPosicion () {
    pos = NULL;
}

TListaPosicion::TListaPosicion (const TListaPosicion &posicion) {
    pos = posicion.pos;
}

TListaPosicion::~TListaPosicion () {
    pos = NULL;
}

TListaPosicion & TListaPosicion::operator = (const TListaPosicion &posicion) {
    if (this != &posicion) {
        (*this).~TListaPosicion();
        pos = posicion.pos;
    }
    return (*this);
}

bool TListaPosicion::operator == (const TListaPosicion &posicion) const {
    return (pos == posicion.pos)
        ? true
        : false;
}

TListaPosicion TListaPosicion::Anterior () {
    TListaPosicion aux;
    return (pos -> anterior == NULL)
        ? aux
        : CopiaPosicionAnterior(aux, pos);
}

TListaPosicion TListaPosicion::Siguiente () {
    TListaPosicion aux; 
    return (pos -> siguiente == NULL)
        ? aux
        : CopiaPosicionSiguiente(aux, pos);
}

bool TListaPosicion::EsVacia () const {
    return (pos == NULL)
        ? true
        : false;
}

TListaPosicion TListaPosicion::CopiaPosicionAnterior (TListaPosicion posicion, TListaNodo *nodo) {
    posicion.pos = nodo -> anterior;
    return posicion;
}

TListaPosicion TListaPosicion::CopiaPosicionSiguiente (TListaPosicion posicion, TListaNodo *nodo) {
    posicion.pos = nodo -> siguiente;
    return posicion;
}

/**
 * TListaPoro
 */
//declaración en lineaTListaPoro::TListaPoro () : primero(NULL), ultimo(NULL) {}
TListaPoro::TListaPoro () {
    primero = NULL;
    ultimo = NULL;
}

TListaPoro::TListaPoro (TListaPoro &lista) {
    primero = lista.primero;
    ultimo = lista.ultimo;
    CopiarLista(lista);
}

TListaPoro::~TListaPoro () {
    TListaPosicion p, q;
    q = Primera();
    while (!q.EsVacia()) {
        p = q;
        q = q.Siguiente();
        delete p.pos;
        p.pos = NULL;
    }
    primero = NULL;
    ultimo = NULL;
}

TListaPoro & TListaPoro::operator = (const TListaPoro &lista) {
    if (this != &lista) {
        (*this).~TListaPoro();
        CopiarLista(lista);
    }
    return (*this);
}

bool TListaPoro::operator == (const TListaPoro &lista) const {
    return (Longitud() == lista.Longitud())
        ? (lista.EsVacio() && EsVacio())
            ? true
            : (CompararListas(lista))
                ? true
                : false
        : false;
}

TListaPoro TListaPoro::operator + (const TListaPoro &lista) const {
    TListaPoro lista_nueva;
    TListaPosicion p, p_aux;
    p = Primera();
    p_aux = lista.Primera();

    while (!p.EsVacia()) {
        lista_nueva.Insertar(Obtener(p));
        p = p.Siguiente();
    }
    while (!(p_aux.EsVacia())) {
        if (!lista_nueva.Buscar(lista.Obtener(p_aux))) {
            lista_nueva.Insertar(lista.Obtener(p_aux));
        } 
        p_aux = p_aux.Siguiente();
    }
    return lista_nueva;
}

TListaPoro TListaPoro::operator - (const TListaPoro &lista) const {
    TListaPoro lista_nueva;
    TListaPosicion p;
    p = Primera();

    while (!p.EsVacia()) {
        if (!lista.Buscar(Obtener(p))) {
            lista_nueva.Insertar(Obtener(p));
            p = p.Siguiente();
        }
        p = p.Siguiente();
    }
    return lista_nueva;
}

bool TListaPoro::EsVacio () const {
    return (primero == NULL && ultimo == NULL) 
        ? true
        : false;
}

bool TListaPoro::Insertar (const TPoro &poro){
    TListaPosicion p;
    p = Primera();

    if (EsVacio()) {
        TListaNodo *nodo_aux = new TListaNodo();
        nodo_aux -> e = poro;
        primero = nodo_aux;
        ultimo = nodo_aux;
        nodo_aux -> anterior = NULL;
        nodo_aux -> siguiente = NULL;
        return true;
    } else {
        if (Buscar(poro))//poro exists in the list
            return false;
        else {
            TListaNodo *nodo_aux = new TListaNodo();
            while (!p.EsVacia()) { 
                nodo_aux -> e = poro;
                if (p.pos -> e.Volumen() == poro.Volumen()) {      
                    if (p.pos -> siguiente == NULL) {
                        nodo_aux -> siguiente = NULL;
                        nodo_aux -> anterior = p.pos;
                        p.pos -> siguiente = nodo_aux;
                        ultimo = nodo_aux;
                        return true;
                    } else {
                        nodo_aux -> anterior = p.pos;
                        nodo_aux -> siguiente = p.pos -> siguiente;
                        p.pos -> siguiente -> anterior = nodo_aux;
                        p.pos -> siguiente = nodo_aux;
                        return true;
                    }
                    return true;
                } else if (p.pos -> e.Volumen() > poro.Volumen()) {
                    if (p.pos -> anterior == NULL) { 
                        nodo_aux -> anterior = NULL;
                        nodo_aux -> siguiente = p.pos;
                        p.pos -> anterior = nodo_aux;
                        primero = nodo_aux;
                        return true;
                    } else { 
                        nodo_aux -> siguiente = p.pos;
                        p.pos -> anterior -> siguiente = nodo_aux;
                        nodo_aux -> anterior = p.pos -> anterior;
                        p.pos -> anterior = nodo_aux;
                        return true;
                    }             
                } else if (p.pos -> e.Volumen() < poro.Volumen() && p.pos == ultimo) {
                    nodo_aux -> siguiente = NULL;
                    nodo_aux -> anterior = ultimo;
                    ultimo -> siguiente = nodo_aux;
                    ultimo = nodo_aux;
                    return true;
                } else 
                    p = p.Siguiente();
            }
        }
    }  
} 

bool TListaPoro::Borrar (const TPoro &poro) {
    if (Buscar(poro) && !EsVacio()) {
        TListaPosicion p;
        p = Primera();
        while (!p.EsVacia()) {
            if (p.pos -> e == poro) 
                return Borrar(p);
            
            p = p.Siguiente();
        }   
    } else 
        return false;
}

bool TListaPoro::Borrar (const TListaPosicion &posicion) {
    if (posicion.pos -> anterior == NULL && posicion.pos -> siguiente == NULL) {
        delete posicion.pos;
        primero = NULL;
        ultimo = NULL;
    } else if (posicion.pos -> anterior == NULL) { 
        posicion.pos -> siguiente -> anterior = NULL;
        primero = posicion.pos -> siguiente;
        delete posicion.pos;
    } else if (posicion.pos -> siguiente == NULL) {
        posicion.pos -> anterior -> siguiente = NULL;
        ultimo = posicion.pos -> anterior;
        delete posicion.pos;
    } else { 
        posicion.pos -> anterior -> siguiente = posicion.pos -> siguiente;
        posicion.pos -> siguiente -> anterior = posicion.pos -> anterior;
        delete posicion.pos;
    }

    return true;
}

TPoro TListaPoro::Obtener (const TListaPosicion &posicion) const {
    return (posicion.pos == NULL)
        ? TPoro()
        : posicion.pos -> e;    
}

bool TListaPoro::Buscar (const TPoro &poro) const {
    TListaPosicion p;
    p = Primera();

    while (!(p.EsVacia())) { 
        if (Obtener(p) == poro) 
            return true;
        p = p.Siguiente();
    }   
    return false;
}

int TListaPoro::Longitud () const {
    int cantidad = 0;

    if (EsVacio())
        return 0;
    else {
        TListaPosicion p;
        p = Primera();
        while (!(p.EsVacia())) {
            cantidad++;
            p = p.Siguiente();
        }
    }
    return cantidad;
}

TListaPosicion TListaPoro::Primera () const {
    return (EsVacio())
        ? TListaPosicion()
        : AsignarPosicion(primero);
}

TListaPosicion TListaPoro::Ultima () const {
    return (EsVacio())
        ? TListaPosicion()
        : AsignarPosicion(ultimo);
}

TListaPoro TListaPoro::ExtraerRango (int n1, int n2) {
    TListaPoro lista;

    if (n1 > n2) 
        return lista;//lista vacia
    else {
        TListaPosicion p;
        p = Primera();      
        while (!(p == Ultima()) || n1 != 0 || n2 != 0){
            if (n1 == n2 && n1 == 1) {
                lista.Insertar(Obtener(p));
                return lista;
            }  else if (n1 < n2 && n1 == 1) {
                lista.Insertar(Obtener(p));
                p = p.Siguiente();
                n1 = 1;
                n2--;
            } else {
                p = p.Siguiente();
                n1--;
                n2--;
            }
        }
    }
}

ostream & operator << (ostream &os, const TListaPoro &lista) {
    if (lista.EsVacio())
        os << "()";
    else {
        TListaPosicion p;
        p = lista.Primera();
        os << "(";
        while (!(p == lista.Ultima())) {
            os << lista.Obtener(p);
            p = p.Siguiente();
            os << " ";
        }
        os << lista.Obtener(lista.Ultima());
        os << ")";
    }
    return os;
}

void TListaPoro::CopiarLista (const TListaPoro &lista) {
    TListaPosicion p;
    p = lista.Primera();
    while (!p.EsVacia()) {
        Insertar(lista.Obtener(p));
        p = p.Siguiente();
    }  
}

bool TListaPoro::CompararListas (const TListaPoro &lista) const{
    if (lista.EsVacio() && EsVacio())
        return true;
    else {
        TListaPosicion p;
        p = Primera();
        while (!(p.EsVacia())) {        
            if (Obtener(p) != lista.Obtener(p)) //imaginemos que las listas tienen la misma dimensión
                return false;
            p = p.Siguiente();
        }
        return true;
    }
}

TListaPosicion TListaPoro::AsignarPosicion (TListaNodo *nodo) const {
    TListaPosicion posicion;
    posicion.pos = nodo;
    return posicion;
}

/*void TListaPoro::InsertarNodoMedio (TPoro &poro, TListaNodo *nodo, TListaPosicion anterior, TListaPosicion siguiente) {
    nodo -> e = poro;

    anterior.pos -> siguiente = nodo;
    siguiente.pos -> anterior = nodo;
    nodo -> anterior = anterior.pos;
    nodo -> siguiente = siguiente.pos;
}*/



