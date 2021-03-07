#ifndef _TCalendario_
#define _TCalendario_

#include <iostream>
#include <string.h>

using namespace std;

class TCalendario
{
  friend ostream &operator<<(ostream &, const TCalendario &);

private:
  /* data */
  int dia, mes, anyo;
  char *mensaje;

  void SetFechaDefecto();
  void CopiaParametros(int, int, int);
  void CopiaMensaje(const char *);
  void SumaDia();
  void RestaDia();
  const bool EsBisiesto(int anyo);
  const bool Es31Mes(int mes)
  {
    return mes == 1 || mes == 3 || mes == 5 ||
           mes == 7 || mes == 8 || mes == 10 || mes == 12;
  }

public:
  TCalendario();
  TCalendario(int, int, int, const char *);
  TCalendario(const TCalendario &);
  ~TCalendario();
  TCalendario &operator=(const TCalendario &);

  TCalendario operator+(const int);
  TCalendario operator-(const int);
  TCalendario &operator++();
  TCalendario operator++(int);
  TCalendario &operator--();
  TCalendario operator--(int);

  bool operator==(TCalendario &) const;
  bool operator!=(TCalendario &) const;

  bool ModFecha(int, int, int);
  bool ModMensaje(const char *);

  bool operator>(TCalendario &) const;
  bool operator<(TCalendario &) const;

  bool EsVacio() const;
  int Dia() { return this->dia; };
  int Mes() { return this->mes; };
  int Anyo() { return this->anyo; };
  char *Mensaje() { return this->mensaje; };
  bool const EsFechaCorrecta(int dia, int mes, int anyo);
  bool SetFecha(int dia, int mes, int anyo);
  bool MensajesIguales(char *) const;
  bool FechaIguales(int, int, int) const;
  bool EsPosterior(int dia, int mes, int anyo) const;
  bool MensajeMayor(char *) const;
};

#endif