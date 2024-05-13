#ifndef _MYRATIONAL_H_
#define _MYRATIONAL_H_
#include <iostream>
using namespace std;
class myRational
{
public:
    // constructor
    myRational(long num = 0, long den = 1);
    myRational(const myRational &rat);

    // Access Functions
    long getNumerator() const;
    long getDenominator() const;

    // Member Functions
    myRational reciprocal() const;

    // Overloaded Operators
    myRational operator +(const myRational &other) const;
    myRational operator +(int value) const;
    myRational operator -(const myRational &other) const;
    myRational operator -(int value) const;
    myRational operator *(const myRational &other) const;
    myRational operator *(int value) const;
    myRational operator /(const myRational &other) const;
    myRational operator /(int value) const;

    // Overloaded Unary Operators
    myRational operator -(); // unary minus
    myRational& operator ++();
    myRational operator ++(int);
    myRational& operator --();
    myRational operator --(int);

    // Overloading relational operators
    bool operator ==(const myRational& other) const;
    bool operator !=(const myRational& other) const;
    bool operator >(const myRational& other) const;
    bool operator >=(const myRational& other) const;
    bool operator <(const myRational& other) const;
    bool operator <=(const myRational& other) const;

    // Overloaded assignment operators
    myRational& operator =(const myRational& other);
    myRational& operator =(int value);
    myRational& operator +=(const myRational& other);
    myRational& operator +=(int value);
    myRational& operator -=(const myRational& other);
    myRational& operator -=(int value);
    myRational& operator *=(const myRational& other);
    myRational& operator *=(int value);
    myRational& operator /=(const myRational& other);
    myRational& operator /=(int value);

    // Overloaded stream operators
    friend ostream& operator <<(ostream& os, const myRational& number);
    friend istream& operator >>(istream& is, myRational& number);
    friend myRational operator +(int value, const myRational& number);
    friend myRational operator -(int value, const myRational& number);
    friend myRational operator *(int value, const myRational& number);
    friend myRational operator /(int value, const myRational& number);


private:
    // 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다.
    long _num; // numerator
    long _den; // denominator
    long gcd(long m, long n); // 최대공약수
    void reduce();
};
#endif