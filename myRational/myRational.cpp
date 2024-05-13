#include "MyRational.h"

// Constructor
myRational::myRational(long num, long den)
{
    _num = num;
    _den = den;
    reduce();
}

myRational::myRational(const myRational &rat)
{
    _num = rat._num;
    _den = rat._den;
}

// Accessor

long myRational::getNumerator() const{
    return _num;
}

long myRational::getDenominator() const{
    return _den;
}

// Member Function

myRational myRational::reciprocal() const
{
    return myRational(_den, _num);
}

// Overloaded Operators
myRational myRational::operator+(const myRational &other) const
{
    int num = _num * other._den + _den * other._num;
    int den = _den * other._den;



    return myRational(num, den);
}

myRational myRational::operator+(int value) const
{
    int num = _num + _den * value;
    return myRational(num, _den);
}

myRational myRational::operator-(const myRational &other) const
{
    int num = _num * other._den - _den * other._num;
    int den = _den * other._den;
    return myRational(num, den);
}

myRational myRational::operator-(int value) const
{
    int num = _num - _den * value;
    return myRational(num, _den);
}

myRational myRational::operator*(const myRational &other) const
{
    int num = _num * other._num;
    int den = _den * other._den;
    return myRational(num, den);
}

myRational myRational::operator*(int value) const
{
    int num = _num * value;
    return myRational(num, _den);
}

myRational myRational::operator/(const myRational &other) const
{
    if (other._num == 0) return myRational(0);
    myRational number = other.reciprocal();
    int num = _num * number._num;
    int den = _den * number._den;
    return myRational(num, den);
}

myRational myRational::operator/(int value) const
{
    if(value == 0) return myRational(0);
    int den = _den * value;
    return myRational(_num, den);
}

// Overloaded Unary Operators

bool myRational::operator==(const myRational &other) const
{
    return (_num == other._num) && (_den == other._den);
}

bool myRational::operator!=(const myRational &other) const
{
    return (_num != other._num) || (_den != other._den);
}

bool myRational::operator<(const myRational &other) const
{
    return _num * other._den < other._num * _den;
}

bool myRational::operator<=(const myRational &other) const{
    return _num * other._den <= other._num * _den;
}

bool myRational::operator>(const myRational &other) const{
    return _num * other._den > other._num * _den;
}

bool myRational::operator>=(const myRational &other) const{
    return _num * other._den >= other._num * _den;
}

// Unary Operators
myRational myRational::operator -()
{
    return myRational(-_num, _den);
}

myRational& myRational::operator++(){
    _num += _den;
    return *this;
}

myRational myRational::operator++(int)
{
    myRational tmp = myRational(_num, _den);
    ++(*this);
    return tmp;
}

myRational& myRational::operator--()
{
    _num -= _den;
    return *this;
}

myRational myRational::operator--(int){
    myRational tmp = myRational(_num, _den);
    --(*this);
    return tmp;
}

// Assignment Operators

myRational& myRational::operator+=(const myRational &other)
{
    int num = _num * other._den + _den * other._num;
    int den = _den * other._den;
    this -> _num = num, this -> _den = den;
    reduce();
    return *this;
}

myRational& myRational::operator+=(int value)
{
    _num = _num + _den * value;
    reduce();
    return *this;
}

myRational& myRational::operator-=(const myRational &other)
{
    _num = _num * other._den - _den * other._num;
    _den = _den * other._den;
    reduce();
    return *this;
}

myRational& myRational::operator-=(int value)
{
    _num = _num - _den * value;
    reduce();
    return *this;
}

myRational& myRational::operator*=(const myRational &other)
{
    _num = _num * other._num;
    _den = _den * other._den;
    reduce();
    return *this;
}

myRational& myRational::operator*=(int value)
{
    _num = _num * value;
    reduce();
    return *this;
}

myRational& myRational::operator/=(const myRational &other)
{
    if(other._num == 0){
        _num = 0;
        _den = 1;
        return *this;
    }
    int num = _num * other._den;
    int den = _den * other._num;
    this -> _num = num, this -> _den = den;
    reduce();
    return *this;
}

myRational& myRational::operator/=(int value)
{
    if(value == 0){
        _num = 0;
        _den = 1;
        return *this;
    }
    int den = _den * value;
    this -> _den = den;
    reduce();
    return *this;
}

myRational& myRational::operator=(const myRational &other)
{
    this -> _num = other._num;
    this -> _den = other._den;
    return *this;
}

myRational& myRational::operator=(int value)
{
    _num = value;
    _den = 1;
    return *this;
}

myRational operator +(int value, const myRational& number) {
    return number + value;
}

myRational operator -(int value, const myRational& number)
{
    return -(number - value);
}

myRational operator *(int value, const myRational& number)
{
    return number * value;
}

myRational operator /(int value, const myRational& number)
{
    int num = value * number._den;
    int den = number._num;
    return myRational(num, den);
}

ostream &operator <<(ostream &outStream, const myRational& r)
{
    if (r._num == 0)
        outStream << 0;
    else if (r._den == 1)
        outStream << r._num;
    else
        outStream << r._num << "/" << r._den;
    return outStream;
}
istream &operator >>(istream &inStream, myRational& r)
{
    inStream >> r._num >> r._den;
    if (r._den == 0)
    {
        r._num = 0;
        r._den = 1;
    }
    r.reduce();
    return inStream;
}
long myRational::gcd(long m, long n)
{
    if (m == n)
        return n;
    else if (m < n)
        return gcd(m, n-m);
    else
        return gcd(m-n, n);
}
void myRational::reduce()
{
    if (_num == 0 || _den == 0)
    {
        _num = 0;
        _den = 1;
        return;
    }
    if (_den < 0)
    {
        _den *= -1;
        _num *= -1;
    }
    if (_num == 1)
        return;
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    _num /= g;
    _den /= g;
}