#include <tvectorporo.h>

TVectorPoro::TVectorPoro () {
    dimension = 0;
    datos = NULL;
}
TVectorPoro::TVectorPoro (int dimension) {
    this -> dimension = dimension;
    error = TPoro();

    if (this -> dimension <= 0) {
        datos = NULL;       
    } else 
        datos = new TPoro[this -> dimension];
}

TVectorPoro::TVectorPoro (const TVectorPoro &vector) {
    dimension = vector.dimension;
    error = vector.error;
    if (vector.datos != NULL) {
        datos = new TPoro[dimension];
        CopiarPoros(vector.datos);
    }
}

TVectorPoro::~TVectorPoro () {
    dimension = 0;
    error.~TPoro();
    if (datos != NULL) {
        delete[] datos;
        datos = NULL;
    } else 
        datos = NULL;
        
} 

TVectorPoro & TVectorPoro::operator = (const TVectorPoro &vector) {
    if (this != &vector) {
        (*this).~TVectorPoro();
        dimension = vector.dimension;
        error = vector.error;
        datos = new TPoro[dimension];
        CopiarPoros(vector.datos);
    }
    return (*this);
}

bool TVectorPoro::operator == (const TVectorPoro &vector) const {
    return (dimension == vector.dimension) 
        ? (CompararPoros(vector.datos))
            ? true
            : false
        : false;
}

bool TVectorPoro::operator != (const TVectorPoro &vector) const {
    return (this == &vector)
        ? false
        : true;
}

//escritura
TPoro & TVectorPoro::operator [] (int pos) {
    return (pos > dimension || pos <= 0)
        ? error
        : datos[pos-1];
}

//solo lectura -> devuelve error o un poro vacio??
TPoro TVectorPoro::operator [] (int pos) const {
    return (pos > dimension || pos <= 0)
        ? error
        : datos[pos - 1];
}

int TVectorPoro::Cantidad () {
    int num = 0;
    for (int i = 0; i < dimension; i++) 
        if (!datos[i].EsVacio())
            num++;
    return num;
}

bool TVectorPoro::Redimensionar (int dimension) {
    return (dimension > 0)
        ? (this -> dimension != dimension)
            ? (dimension > this -> dimension) 
                ? RedimensionarMasVector(dimension)
                : RedimensionarMenosVector(dimension)
            : false
        : false;
}

ostream & operator << (ostream &os, const TVectorPoro &vector) {
    os << "[";
    for (int i = 0; i < vector.dimension; i++) {
        os << i+1 << " ";
        if (i != vector.dimension - 1) 
            os << vector.datos[i] << " ";
        else 
            os << vector.datos[i];
    }
    os << "]";
    return os;
}

/**
 * #######################################
 * #
 * #:::::::::FUNCIONES AUXILIARES:::::::::
 * #######################################
 */

void TVectorPoro::CopiarPoros (const TPoro *poros) {
    for (int i = 0; i < dimension; i++) 
        datos[i] = poros[i];
}

bool TVectorPoro::CompararPoros (const TPoro *poros) const {
    for (int i = 0; i < dimension; i++) 
        if (datos[i] != poros[i])
            return false;
    return true;
}

bool TVectorPoro::RedimensionarMasVector (int dimension) {
    TPoro *aux = new TPoro[dimension];
    for (int i = 0; i < this -> dimension; i++) 
        aux[i] = datos[i];
    for (int j = this -> dimension; j < dimension; j++)
        aux[j] = TPoro();

    (*this).~TVectorPoro();
    this -> dimension = dimension;
    datos = new TPoro[this -> dimension];
    CopiarPoros(aux);
    delete[] aux;
    return true;
}

bool TVectorPoro::RedimensionarMenosVector (int dimension) {
    TPoro *aux = new TPoro[dimension];
    for (int i = 0; i < dimension; i++) 
        aux[i] = datos[i];
        
    (*this).~TVectorPoro();
    this -> dimension = dimension;
    datos = new TPoro[this -> dimension];
    CopiarPoros(aux);
    delete[] aux;
    return true;
}

