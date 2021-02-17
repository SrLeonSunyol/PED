#include <tcalendario.h>

#pragma region Constructors

TCalendario::TCalendario() {
  dia = 0;
  mes = 0;
  anyo = 0;
  mensaje = NULL;
}

TCalendario::TCalendario(int dia, int mes, int anyo, const char *mens) {
  CopiaParametros(dia, mes, anyo);
  (mens);
}

TCalendario::TCalendario(const TCalendario &c) {
  CopiaParametros(c.dia, c.mes, c.anyo);
  CopiaMensaje(c.mensaje);
}

TCalendario::~TCalendario() {
  dia = 0;
  mes = 0;
  anyo = 0;
  if (mensaje != NULL) {
    delete[] mensaje;
    mensaje = NULL;
  } else 
    mensaje = NULL;
}

#pragma endregion

#pragma region Operators

TCalendario & TCalendario::operator = (const TCalendario & c) {
    if (this != &c) {
        (*this).~TCalendario();
        CopiaParametros(c.dia, c.mes, c.anyo);
        CopiaMensaje(c.mensaje);
    } 
    return (*this);
}

#pragma endregion 

#pragma region Auxiliares

void TCalendario::CopiaParametros (int dia, int mes, int anyo) {
  this -> dia = dia;
  this -> mes = mes;
  this -> anyo = anyo;
  this -> mensaje = NULL;
}

void TCalendario::CopiaMensaje(const char* mensaje) {
  if (mensaje != NULL) {
    if (this -> mensaje != NULL) 
      delete[] this -> mensaje;
    this -> mensaje = new char[strlen(mensaje) + 1];
    strcpy(this -> mensaje, mensaje);
    for (int i = 0; i < strlen(this -> mensaje); i++) 
      this -> mensaje[i] = tolower(mensaje[i]);
  } else 
    this -> mensaje = NULL;
}

#pragma endregion


