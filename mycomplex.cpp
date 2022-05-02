#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;
/*!
@brief Конструктор класса
@param aRe Действительная составляющая
@param aIm Мнимая составляющая
*/
Complex :: Complex (double aRe, double aIm)
{
 Re=aRe;
 Im=aIm;
}
/*!
@brief Обозначает комплексные числа
*/
Complex :: Complex (const Complex & aRval)
{
 Re=aRval.Re;
 Im=aRval.Im;
}
/*!
@brief Деструктор класса
*/
Complex :: ~Complex()
{
 Re=0.0;
 Im=0.0;
}
/*!
@brief Присваивание Re значения перемнной aRe и Im соответст. aIm
*/
void Complex :: Set (double aRe, double aIm)
{
 Re=aRe;
 Im=aIm;
}
/*!
@brief Возвращает модуль комплексного числа
@return Модуль комплексного числа
*/
Complex :: operator double()
{
 return abs();
}
/*!
@brief Возвращает корень суммы квадратов Re и Im
@return Корень суммы квадратов Re и Im
*/
double Complex :: abs()
{
 return sqrt(Re * Re + Im * Im);
}
/*!
@brief Возвращает сумму  Re и aRval.Re записывая результат в Result.* , аналогично Im
@return сумма  Re и aRval.Re записывая результат в Result.* , аналогично Im
*/
Complex Complex :: operator +(const Complex & aRval)
{
 Complex Result;
 Result.Re = Re + aRval. Re;
 Result.Im = Im + aRval.Im ;
 return Result;
}
/*!
@brief Возвращает разность  Re и aRval.Re записывая результат в Result.* , аналогично Im
@return разность  Re и aRval.Re записывая результат в Result.* , аналогично Im
*/
 Complex Complex :: operator -(const Complex & aRval)
{
 Complex Result;
 Result.Re = Re - aRval.Re;
 Result.Im = Im - aRval.Im;
 return Result;
}
/*!
@brief Возвращает сумму переменных Re и aRval в перменную result.Re и result.Im присваивает значение Im
@return  Сумма переменных Re и aRval в перменную result.Re и result.Im присваивает значение Im
*/
Complex Complex :: operator +(const double & aRval)
{
 Complex result;
 result.Re = Re + aval;
 result.Im = Im;
 return Result;
}
/*!
@brief Возвращает разность  Re и aRval записывая результат в Result.Re
@return разность  Re и aRval записывая результат в Result.Re
*/
Complex Complex :: operator -(const double & aRval)
{
 Complex Result(*this);
 Result.Re = Re - aRval;
 return Result;
}
/*!
@brief Возвращает разность и сумму произведений Re, aRval.Re и Im, aRval.Im
@return разность и сумм произведений Re, aRval.Re и Im, aRval.Im
*/
Complex Complex :: operator *(const Complex & aRval)
{
 Complex Result;
 Result.Re = Re * aRval.Re-Im*aRval.Im;
 Result.Im = Re * aRval.Im+Im*aRval.Re;
 return Result;
}
/*!
@brief Возвращает произведение Re, aRval и Im, aRval в Result.*
@return разность Re, aRval и Im, aRval в Result.*
*/
Complex Complex :: operator *(const double & aRval)
{
 Complex Result;
 Result.Re = Re * aRval;
 Result.Im = Im * aRval;
 return Result;
}
/*!
@brief Возвращает частное Re, aRval и Im, aRval в Result.*
@return частное Re, aRval и Im, aRval в Result.*
*/
Complex Complex :: operator /(const double & aRval)
{
 Complex Result;
 Result.Re = Re / aRval;
 Result.Im = Im / aRval;
 return Result;
}
/*!
@brief Возвращает сумму Re, arval.Re и Im, arval.Im в Result.*
@return сумму Re, arval.Re и Im, arval.Im в Result.*
*/
Complex & Complex :: operator +=(const Complex & arval)
{
 Re += arval.Re;
 Im += arval.Im;
 return *this;
}
/*!
@brief Возвращает разность Re, arval.Re и Im, arval.Im в Result.*
@return разность Re, arval.Re и Im, arval.Im в Result.*
*/
Complex & Complex :: operator -=(const Complex & aRval)
{
 Re -= aRval.Re;
 Im -= aRval.Im;
 return *this;
}
/*!
@brief Возвращает разность произведений Re, aRval.Re и Im, aRval.Im и сумму произведений aRval.Re, Im и tmpRe, aRval.Im
@return разность произведений Re, aRval.Re и Im, aRval.Im и сумму произведений aRval.Re, Im и tmpRe, aRval.Im
*/
Complex&Complex :: operator *=(const Complex & aRval)
{
 double tmpRe = Re;
 Re = Re * aRval.Re - Im * aRval.Im;
 Im = Im * aRval.Re + tmpRe * aRval.Im;
 return *this;
}
/*!
@brief Возвращает сумму Re, aRval
@return сумму Re, aRval
*/
Complex & Complex :: operator +=(const double & aRval)
{
 Re += aRval;
 return *this;
}
/*!
@brief Возвращает разность Re, aRval
@return разность Re, aRval
*/
Complex & Complex :: operator -=(const double & aRval)
{
 Re -= aRval;
 return *this;
}
/*!
@brief Возвращает произведение Re, aRval
@return произведение Re, aRval
*/
Complex & Complex :: operator *=(const double & aRval)
{
 Re *= aRval;
 Im *= aRval;
 return *this;
}
/*!
@brief Возвращает частное Re, aRval
@return частное Re, aRval
*/
Complex & Complex :: operator /=(const double & aRval)
{
 Re /= aRval;
 Im /= aRval;
 return *this;
}
/*!
@brief Возвращает Re значения перемнной aRe и Im соответст. aIm
@return возвращая Im, Re
*/
Complex & Complex :: operator =(const Complex & aRval)
{
 Re = aRval.Re;
 Im = aRval.Im;
 return *this;
}
/*!
@brief Возвращает Re значения перемнной aRval и обнуляет Im
@return Re значения перемнной aRval и обнуляет Im
*/
Complex & Complex :: operator =(const double & aRval)
{
 Re = aRval;
 Im = 0.0;
 return *this;
}
/*!
@brief Оператор ввода данных
*/
istream & operator >>(iostream & stream, Complex & a)
{
 char tmp[256]
 stream >> a.Re >> a.Im >> tmp;
 return stream;
}
/*!
@brief Оператор вывода данных
*/
ostream & operator <<(ostream & stream, Complex & a)
{
  stream << a.Re;
  if( !(a.Im < 0) )
  stream << '+';
  stream << a.Im << 'i';
  return stream;
}
/*!
@brief Возвращает переменной Result.* сумму aLval, aRval.Re и значение aRval.Im соответ.
@return переменной Result.* сумму aLval, aRval.Re и значение aRval.Im соответ.
*/
Complex operator +(const double & aLval, const Complex & aRval)
{
 Complex Result;
 Result.Re = aLval+aRval.Re;
 Result.Im = aRval.Im;
 return Result;
}
/*!
@brief Возвращает разность aLval, aRval.Re и отрицательную переменную -aRval.Im в result.*
@return разность aLval, aRval.Re и отрицательную переменную -aRval.Im в result.*
*/
Complex operator -(const double & aLval, const Complex & aRval)
{
 Complex Result;
 Result.Re = aLval - aRval.Re;
 Result.Im = -aRval.Im;
 return Result;
}
/*!
@brief Возвращает произведение aLval, a.Re и aLval * a.Im соответственно r.*
@return произведение aLval, a.Re и aLval * a.Im соответственно r.*
*/
Complex operator *(const double & aLval, const Complex & a)
{
 Complex r;
 r.Re = aLval * a.Re;
 r.Im = aLval * a.Im;
 return r;
}
