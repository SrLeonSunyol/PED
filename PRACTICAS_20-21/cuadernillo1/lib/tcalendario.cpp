#include <tcalendario.h>

#pragma region Constructors

TCalendario::TCalendario()
{
  SetFechaDefecto();
}

TCalendario::TCalendario(int dia, int mes, int anyo, const char *mens)
{
  if (EsFechaCorrecta(dia, mes, anyo))
  {
    CopiaParametros(dia, mes, anyo);
    CopiaMensaje(mens);
  }
  else
  {
    CopiaParametros(1, 1, 1900);
    (NULL);
  }
}

TCalendario::TCalendario(const TCalendario &c)
{
  CopiaParametros(c.dia, c.mes, c.anyo);
  CopiaMensaje(c.mensaje);
}

TCalendario::~TCalendario()
{
  dia = 1;
  mes = 1;
  anyo = 1900;
  if (mensaje != NULL)
  {
    delete[] mensaje;
    mensaje = NULL;
  }
  else
    mensaje = NULL;
}

#pragma endregion

#pragma region Operators

TCalendario &TCalendario::operator=(const TCalendario &c)
{
  if (this != &c)
  {
    (*this).~TCalendario();
    CopiaParametros(c.dia, c.mes, c.anyo);
    CopiaMensaje(c.mensaje);
  }
  return (*this);
}

TCalendario TCalendario::operator+(const int dia)
{
  TCalendario t((*this));
  t.SumaDia();
  return t;
}

TCalendario TCalendario::operator-(const int dia)
{
  TCalendario t(*this);
  t.RestaDia();
  if (!EsFechaCorrecta(t.dia, t.mes, t.anyo))
    t.SetFechaDefecto();
  return t;
}

//Pre
TCalendario &TCalendario::operator++()
{
  *this = *this + 1;
  return (*this);
}

//Post
TCalendario TCalendario::operator++(int dia)
{
  TCalendario t(*this);
  *this = *this + 1;
  return t;
}

TCalendario TCalendario::operator--(int dia)
{
  TCalendario t(*this);
  *this = *this - 1;
  return t;
}

TCalendario &TCalendario::operator--()
{
  *this = *this - 1;
  return (*this);
}

#pragma endregion

#pragma region Metodos

bool TCalendario::EsVacio() const
{
  return (dia == 1 && mes == 1 && anyo == 1)
             ? (mensaje == NULL)
                   ? true
                   : false
             : false;
}

bool TCalendario::ModFecha(int dia, int mes, int anyo)
{
  return (EsFechaCorrecta(dia, mes, anyo))
             ? SetFecha(dia, mes, anyo)
             : false;
}

bool TCalendario::ModMensaje(const char *mensaje)
{
  if (mensaje != NULL)
  {
    CopiaMensaje(mensaje);
    return true;
  }
  else
  {
    return false;
  }
}

bool TCalendario::operator==(TCalendario &c) const
{
  return (FechaIguales(c.dia, c.mes, c.anyo))
             ? MensajesIguales(c.mensaje)
             : false;
}

bool TCalendario::operator!=(TCalendario &c) const
{
  return !((*this) == c);
}

bool TCalendario::operator>(TCalendario &c) const
{
  return (EsPosterior(c.dia, c.mes, c.anyo)) //criterio 1
             ? true
             : (FechaIguales(c.dia, c.mes, c.anyo)) //criterio 2
                   ? (MensajeMayor(c.mensaje))
                   : false;
}

bool TCalendario::operator<(TCalendario &c) const
{
  return !((*this) > c);
}

ostream &operator<<(ostream &os, const TCalendario &c)
{
  if (!c.EsVacio())
  {
    os.setf(ios::fixed);
    os.precision(2);
    os << "" << c.dia << "/" << c.mes << "/" << c.anyo << " \"";
    if (c.mensaje != NULL)
      os << c.mensaje << "\"";
    else
      os << "\"";
  }
  else
  {
    os << "";
  }

  return os;
}

#pragma endregion

#pragma region Auxiliares

//Suma un dia a la fecha actual
void TCalendario::SumaDia()
{
  if (mes == 2)
  {
    if (EsBisiesto(anyo))
    {
      //29 dias
      if (dia == 29)
      {
        mes++;
        dia = 1;
      }
      else
        dia++;
    }
    else
    {
      //28 dias
      if (dia == 28)
      {
        mes++;
        dia = 1;
      }
      else
        dia++;
    }
  }
  else
  {
    if (Es31Mes(mes))
    {
      //31dias
      if (mes == 12)
      {
        if (dia == 31)
        {
          mes = 1;
          dia = 1;
          anyo++;
        }
        else
          dia++;
      }
      else
      {
        if (dia == 31)
        {
          mes++;
          dia = 1;
        }
        else
          dia++;
      }
    }
    else
    {
      //30dias
      if (dia == 30)
      {
        mes++;
        dia = 1;
      }
      else
        dia++;
    }
  }
}

//Resta un dia a la fecha actual
void TCalendario::RestaDia()
{
  if (mes == 3)
  {
    if (EsBisiesto(anyo))
    {
      if (dia == 1)
      {
        mes--;
        dia = 29;
      }
      else
      {
        dia--;
      }
    }
    else
    {
      if (dia == 1)
      {
        mes--;
        dia = 28;
      }
      else
        dia--;
    }
  }
  else if (mes == 1)
  {
    if (dia == 1)
    {
      mes = 12;
      dia = 31;
      anyo--;
    }
    else
      dia--;
  }
  else
  {
    if (Es31Mes(mes))
    {
      if (mes == 8)
      {
        if (dia == 1)
        {
          dia == 31;
          mes--;
        }
        else
          dia--;
      }
      else
      {
        if (dia == 1)
        {
          dia = 30;
          mes--;
        }
        else
          dia--;
      }
    }
    else
    {
      if (dia == 1)
      {
        mes--;
        dia = 31;
      }
      else
        dia--;
    }
  }
}

void TCalendario::CopiaParametros(int dia, int mes, int anyo)
{
  this->dia = dia;
  this->mes = mes;
  this->anyo = anyo;
  this->mensaje = NULL;
}

//Compara dos mensajes distintos de NULL
//Puede ser cadena vacia
bool TCalendario::MensajesIguales(char *mensaje) const
{
  if (this->mensaje == NULL && mensaje == NULL)
    return true;
  else if (this->mensaje != NULL && mensaje != NULL)
  {
    for (int i = 0; i < strlen(this->mensaje); i++)
    {
      if (this->mensaje[i] != toupper(mensaje[i]))
        return false;
    }
    return true;
  }
  else
    return false;
}

void TCalendario::CopiaMensaje(const char *mensaje)
{
  if (mensaje != NULL)
  {
    if (this->mensaje != NULL && true)
      delete[] this->mensaje;
    this->mensaje = new char[strlen(mensaje) + 1];
    strcpy(this->mensaje, mensaje);
    for (int i = 0; i < strlen(this->mensaje); i++)
      this->mensaje[i] = toupper(mensaje[i]);
  }
  else
    this->mensaje = NULL;
}

bool const TCalendario::EsBisiesto(int anyo)
{
  return (anyo % 4 == 0)
             ? (anyo % 100 == 0)
                   ? (anyo % 400 == 0)
                         ? true
                         : false
                   : true
             : false;
}

bool const TCalendario::EsFechaCorrecta(int dia, int mes, int anyo)
{
  return (anyo >= 1900)
             ? (mes >= 1 && mes <= 12)
                   ? (dia >= 1)
                         ? (mes == 2)
                               ? (EsBisiesto(anyo))
                                     ? (dia <= 29)
                                           ? true
                                           : false
                                 : (dia <= 28)
                                     ? true
                                     : false
                           : (Es31Mes(mes))
                               ? (dia <= 31)
                                     ? true
                                     : false
                           : (dia <= 30)
                               ? true
                               : false
                         : false
                   : false
             : false;
}

void TCalendario::SetFechaDefecto()
{
  dia = 1;
  mes = 1;
  anyo = 1900;
  mensaje = NULL;
}

bool TCalendario::SetFecha(int dia, int mes, int anyo)
{
  this->dia = dia;
  this->mes = mes;
  this->anyo = anyo;
  return true;
}

bool TCalendario::FechaIguales(int dia, int mes, int anyo) const
{
  return (this->dia == dia)
             ? (this->mes == mes)
                   ? (this->anyo == anyo)
                   : false
             : false;
}

bool TCalendario::EsPosterior(int dia, int mes, int anyo) const
{
  return (this->anyo > anyo)
             ? true
         : (this->anyo == anyo)
             ? (this->mes > mes)
                   ? true
               : (this->mes == mes)
                   ? (this->dia > dia)
                         ? true
                         : false
                   : false
             : false;
}

bool TCalendario::MensajeMayor(char *mensaje) const
{
  if (this->mensaje == NULL && mensaje == NULL)
    return false;
  else if (this->mensaje != NULL && mensaje != NULL)
  {
    int res = strcmp(this->mensaje, mensaje);
    if (res > 0)
      return true;
    else
      return false;
  }
  else
    return (this->mensaje != NULL);
  return false;
}

#pragma endregion
