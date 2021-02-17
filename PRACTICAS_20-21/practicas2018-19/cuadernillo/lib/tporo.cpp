#include <tporo.h>

TPoro::TPoro () {
    x = 0;
    y = 0;
    volumen = 0;
    color = NULL;
}

TPoro::TPoro (int x, int y, double volumen) {
    CopiaParametros(x, y, volumen);
}

TPoro::TPoro (int x, int y, double volumen, const char *color) {
    CopiaParametros (x, y, volumen);
     (color);
}

TPoro::TPoro (const TPoro &poro) {
    CopiaParametros(poro.x, poro.y, poro.volumen);
    CopiaColor(poro.color);
}

TPoro::~TPoro () {
    x = 0;
    y = 0;
    volumen = 0;
    if (color != NULL) {
        delete[] color;
        color = NULL;
    } else
        color = NULL;
}

TPoro & TPoro::operator = (const TPoro & poro) {
    if (this != &poro) {
        (*this).~TPoro();
        CopiaParametros(poro.x, poro.y, poro.volumen);
        CopiaColor(poro.color);
    } 
    return (*this);
}

bool TPoro::operator == (const TPoro &poro) const {
    return (x == poro.x && y == poro.y) 
        ? (volumen == poro.volumen)  
            ? (color != NULL && poro.color != NULL)
                ? (CompararColor(poro.color)) 
                    ? true
                    : false
                : (color == NULL && poro.color == NULL)
                    ? true
                    : false
            : false
        : false;
}

bool TPoro::operator != (const TPoro &poro) const {
    return ((*this) == poro) 
        ? false
        : true;
}

void TPoro::Color (const char *color) {
    CopiaColor(color);
}

bool TPoro::EsVacio () const {
    return (x == 0 && y == 0)
        ? (volumen == 0)
            ? (color == NULL) 
                ? true
                : false
            : false
        : false;
}

ostream & operator << (ostream &os, const TPoro &poro) {
    if (!poro.EsVacio()) {
        os.setf(ios::fixed);
        os.precision( 2 );
        os << "(" << poro.x << ", " << poro.y << ") " << poro.volumen << " ";
        if (poro.color != NULL)
            os << poro.color;
        else
            os << "-";
    }
    else
        os << "()";
    return os;
}

/**
 * #######################################
 * #
 * #:::::::::FUNCIONES AUXILIARES:::::::::
 * #######################################
 */

void TPoro::CopiaParametros (int x, int y, double volumen) {
    this -> x = x;
    this -> y = y;
    this -> volumen = volumen;
    this -> color = NULL;
}

void TPoro::CopiaColor (const char* color) {
    if (color != NULL) {
        if (this -> color != NULL)
            delete[] this -> color;
        this -> color = new char[strlen(color) + 1];
        strcpy(this -> color, color); 
        for (int i = 0; i < strlen(this -> color); i++) 
            this -> color[i] = tolower(color[i]);
    } else 
        this -> color = NULL;
}

bool TPoro::CompararColor (const char* color) const {
    for (int i = 0; i < strlen(this -> color); i++)
        if (this -> color[i] != color[i])
            return false;
    return true;
}