#include <tcalendario.h>

#pragma region Constructors

TCalendario::TCalendario()
{
  dia = 1;
  mes = 1;
  anyo = 1900;
  mensaje = NULL;
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
  dia = 0;
  mes = 0;
  anyo = 0;
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

bool TCalendario::EsVacio() const
{
  return (dia == 1 && mes == 1 && anyo == 1)
             ? (mensaje == NULL)
                   ? true
                   : false
             : false;
}

void TCalendario::CopiaParametros(int dia, int mes, int anyo)
{
  this->dia = dia;
  this->mes = mes;
  this->anyo = anyo;
  this->mensaje = NULL;
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
  return (mes >= 1 && mes <= 12)
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
             : false;
}

#pragma endregion
