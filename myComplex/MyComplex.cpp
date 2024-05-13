//
// Created by navykid75 on 2024-05-13.
//
#include "MyComplex.h"
// Constructor
myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}

// Copy constructor
myComplex::myComplex(const myComplex& number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}

// Accessor functions
int myComplex::getRealPart() const
{
    return realPart;
}

int myComplex::getImaginaryPart() const
{
    return imaginaryPart;
}

// Mutator functions
void myComplex::setRealPart(int real)
{
    realPart = real;
}

void myComplex::setImaginaryPart(int imag)
{
    imaginaryPart = imag;
}

void myComplex::set(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}

// Overloaded binary operators
myComplex myComplex::operator +(const myComplex& number) const
{
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return myComplex(newReal, newImag);
}

myComplex myComplex::operator +(int value) const
{
    return myComplex(value) + (*this);
}

myComplex myComplex::operator -(const myComplex &number) const{
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return myComplex(newReal, newImag);
}

myComplex myComplex::operator-(int value) const{
    return -myComplex(value) + (*this);
}

myComplex myComplex::operator*(const myComplex &number) const{
    int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
    int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
    return myComplex(newReal, newImag);
}

myComplex myComplex::operator*(int value) const{
    int newReal = realPart * value;
    int newImag = imaginaryPart * value;
    return myComplex(newReal, newImag);
}


// Assignment operators
myComplex& myComplex::operator =(const myComplex& number)
{
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}

myComplex& myComplex::operator =(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}

myComplex& myComplex::operator+=(const myComplex &number){
    realPart += number.realPart;
    imaginaryPart += number.imaginaryPart;
    return *this;
}

myComplex& myComplex::operator-=(const myComplex& number){
    realPart -= number.realPart;
    imaginaryPart -= number.imaginaryPart;
    return *this;
}

myComplex& myComplex::operator*=(const myComplex &number){
    int newReal = realPart * number.realPart - imaginaryPart * number.imaginaryPart;
    int newImag = realPart * number.imaginaryPart + imaginaryPart * number.realPart;
    this -> realPart = newReal, this -> imaginaryPart = newImag;
    return *this;
}

// Overloading comparison operators
bool myComplex::operator ==(const myComplex& number) const
{
    return (realPart == number.realPart) &&
           (imaginaryPart == number.imaginaryPart);
}

bool myComplex::operator !=(const myComplex &number) const
{
    return (realPart != number.realPart) || (imaginaryPart != number.imaginaryPart);
}


bool myComplex::operator >(const myComplex& number) const
{
    return norm() > number.norm();
}

bool myComplex::operator >=(const myComplex& number) const
{
    return norm() >= number.norm();
}

bool myComplex::operator <(const myComplex& number) const
{
    return norm() < number.norm();
}

bool myComplex::operator <=(const myComplex& number) const
{
    return norm() <= number.norm();
}

// Overloaded unary operators
myComplex myComplex::operator -() // unary minus
{
    return myComplex(-realPart, -imaginaryPart);
}

myComplex myComplex::operator ~()
{
    return myComplex(realPart, -imaginaryPart);
}

myComplex myComplex::operator ++()
{
    realPart++;
    return *this;
}

myComplex myComplex::operator ++(int){
    myComplex tmp(realPart, imaginaryPart);
    ++(*this);
    return tmp;
}

myComplex myComplex::operator --(){
    realPart--;
    return *this;
}

myComplex myComplex::operator --(int){
    myComplex tmp(realPart, imaginaryPart);
    --(*this);
    return tmp;
}

// private function
double myComplex::norm() const
{
    return realPart * realPart + imaginaryPart * imaginaryPart;
}

// stream function

ostream &operator <<(ostream &os, const myComplex& number)
{
    os << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return os;
}
istream &operator >>(istream &is, myComplex& number)
{
    is >> number.realPart >> number.imaginaryPart;
    return is;
}

// friend function

myComplex operator +(int value, const myComplex& number){
    return number + value;
}

myComplex operator -(int value, const myComplex& number){
    return -(number - value);
}

myComplex operator *(int value, const myComplex& number){
    return number * value;
}