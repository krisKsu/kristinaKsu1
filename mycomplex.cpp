#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;
/*!
@brief ����������� ������
@param aRe �������������� ������������
@param aIm ������ ������������
*/
Complex :: Complex (double aRe, double aIm)
{
 Re=aRe;
 Im=aIm;
}
/*!
@brief ���������� ����������� �����
*/
Complex :: Complex (const Complex & aRval)
{
 Re=aRval.Re;
 Im=aRval.Im;
}
/*!
@brief ���������� ������
*/
Complex :: ~Complex()
{
 Re=0.0;
 Im=0.0;
}
/*!
@brief ������������ Re �������� ��������� aRe � Im ���������. aIm
*/
void Complex :: Set (double aRe, double aIm)
{
 Re=aRe;
 Im=aIm;
}
/*!
@brief ���������� ������ ������������ �����
@return ������ ������������ �����
*/
Complex :: operator double()
{
 return abs();
}
/*!
@brief ���������� ������ ����� ��������� Re � Im
@return ������ ����� ��������� Re � Im
*/
double Complex :: abs()
{
 return sqrt(Re * Re + Im * Im);
}
/*!
@brief ���������� �����  Re � aRval.Re ��������� ��������� � Result.* , ���������� Im
@return �����  Re � aRval.Re ��������� ��������� � Result.* , ���������� Im
*/
Complex Complex :: operator +(const Complex & aRval)
{
 Complex Result;
 Result.Re = Re + aRval. Re;
 Result.Im = Im + aRval.Im ;
 return Result;
}
/*!
@brief ���������� ��������  Re � aRval.Re ��������� ��������� � Result.* , ���������� Im
@return ��������  Re � aRval.Re ��������� ��������� � Result.* , ���������� Im
*/
 Complex Complex :: operator -(const Complex & aRval)
{
 Complex Result;
 Result.Re = Re - aRval.Re;
 Result.Im = Im - aRval.Im;
 return Result;
}
/*!
@brief ���������� ����� ���������� Re � aRval � ��������� result.Re � result.Im ����������� �������� Im
@return  ����� ���������� Re � aRval � ��������� result.Re � result.Im ����������� �������� Im
*/
Complex Complex :: operator +(const double & aRval)
{
 Complex result;
 result.Re = Re + aval;
 result.Im = Im;
 return Result;
}
/*!
@brief ���������� ��������  Re � aRval ��������� ��������� � Result.Re
@return ��������  Re � aRval ��������� ��������� � Result.Re
*/
Complex Complex :: operator -(const double & aRval)
{
 Complex Result(*this);
 Result.Re = Re - aRval;
 return Result;
}
/*!
@brief ���������� �������� � ����� ������������ Re, aRval.Re � Im, aRval.Im
@return �������� � ���� ������������ Re, aRval.Re � Im, aRval.Im
*/
Complex Complex :: operator *(const Complex & aRval)
{
 Complex Result;
 Result.Re = Re * aRval.Re-Im*aRval.Im;
 Result.Im = Re * aRval.Im+Im*aRval.Re;
 return Result;
}
/*!
@brief ���������� ������������ Re, aRval � Im, aRval � Result.*
@return �������� Re, aRval � Im, aRval � Result.*
*/
Complex Complex :: operator *(const double & aRval)
{
 Complex Result;
 Result.Re = Re * aRval;
 Result.Im = Im * aRval;
 return Result;
}
/*!
@brief ���������� ������� Re, aRval � Im, aRval � Result.*
@return ������� Re, aRval � Im, aRval � Result.*
*/
Complex Complex :: operator /(const double & aRval)
{
 Complex Result;
 Result.Re = Re / aRval;
 Result.Im = Im / aRval;
 return Result;
}
/*!
@brief ���������� ����� Re, arval.Re � Im, arval.Im � Result.*
@return ����� Re, arval.Re � Im, arval.Im � Result.*
*/
Complex & Complex :: operator +=(const Complex & arval)
{
 Re += arval.Re;
 Im += arval.Im;
 return *this;
}
/*!
@brief ���������� �������� Re, arval.Re � Im, arval.Im � Result.*
@return �������� Re, arval.Re � Im, arval.Im � Result.*
*/
Complex & Complex :: operator -=(const Complex & aRval)
{
 Re -= aRval.Re;
 Im -= aRval.Im;
 return *this;
}
/*!
@brief ���������� �������� ������������ Re, aRval.Re � Im, aRval.Im � ����� ������������ aRval.Re, Im � tmpRe, aRval.Im
@return �������� ������������ Re, aRval.Re � Im, aRval.Im � ����� ������������ aRval.Re, Im � tmpRe, aRval.Im
*/
Complex&Complex :: operator *=(const Complex & aRval)
{
 double tmpRe = Re;
 Re = Re * aRval.Re - Im * aRval.Im;
 Im = Im * aRval.Re + tmpRe * aRval.Im;
 return *this;
}
/*!
@brief ���������� ����� Re, aRval
@return ����� Re, aRval
*/
Complex & Complex :: operator +=(const double & aRval)
{
 Re += aRval;
 return *this;
}
/*!
@brief ���������� �������� Re, aRval
@return �������� Re, aRval
*/
Complex & Complex :: operator -=(const double & aRval)
{
 Re -= aRval;
 return *this;
}
/*!
@brief ���������� ������������ Re, aRval
@return ������������ Re, aRval
*/
Complex & Complex :: operator *=(const double & aRval)
{
 Re *= aRval;
 Im *= aRval;
 return *this;
}
/*!
@brief ���������� ������� Re, aRval
@return ������� Re, aRval
*/
Complex & Complex :: operator /=(const double & aRval)
{
 Re /= aRval;
 Im /= aRval;
 return *this;
}
/*!
@brief ���������� Re �������� ��������� aRe � Im ���������. aIm
@return ��������� Im, Re
*/
Complex & Complex :: operator =(const Complex & aRval)
{
 Re = aRval.Re;
 Im = aRval.Im;
 return *this;
}
/*!
@brief ���������� Re �������� ��������� aRval � �������� Im
@return Re �������� ��������� aRval � �������� Im
*/
Complex & Complex :: operator =(const double & aRval)
{
 Re = aRval;
 Im = 0.0;
 return *this;
}
/*!
@brief �������� ����� ������
*/
istream & operator >>(iostream & stream, Complex & a)
{
 char tmp[256]
 stream >> a.Re >> a.Im >> tmp;
 return stream;
}
/*!
@brief �������� ������ ������
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
@brief ���������� ���������� Result.* ����� aLval, aRval.Re � �������� aRval.Im �������.
@return ���������� Result.* ����� aLval, aRval.Re � �������� aRval.Im �������.
*/
Complex operator +(const double & aLval, const Complex & aRval)
{
 Complex Result;
 Result.Re = aLval+aRval.Re;
 Result.Im = aRval.Im;
 return Result;
}
/*!
@brief ���������� �������� aLval, aRval.Re � ������������� ���������� -aRval.Im � result.*
@return �������� aLval, aRval.Re � ������������� ���������� -aRval.Im � result.*
*/
Complex operator -(const double & aLval, const Complex & aRval)
{
 Complex Result;
 Result.Re = aLval - aRval.Re;
 Result.Im = -aRval.Im;
 return Result;
}
/*!
@brief ���������� ������������ aLval, a.Re � aLval * a.Im �������������� r.*
@return ������������ aLval, a.Re � aLval * a.Im �������������� r.*
*/
Complex operator *(const double & aLval, const Complex & a)
{
 Complex r;
 r.Re = aLval * a.Re;
 r.Im = aLval * a.Im;
 return r;
}
