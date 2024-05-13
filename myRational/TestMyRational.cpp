//
// Created by navykid75 on 2024-05-13.
//
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "myRational.h"
using namespace std;

long num, den;
vector<myRational> result;

void testSimpleCase();
void testDataFromFile();
int main()
{
    testSimpleCase();
    testDataFromFile();
}
void testSimpleCase()
{
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
    cout << frac1 << " " << frac2 << " " << frac3 << " "
         << frac4 << " " << frac5 << endl;
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
    // Check arithmetic operators
    cout << frac1 * frac2 << " "
         << frac1 + frac3 << " "
         << frac2 - frac1 << " "
         << frac3 / frac2 << endl;
    // Check comparison operators
    cout << ((frac1 < frac2) ? 1 : 0) << " "
         << ((frac1 <= frac2) ? 1 : 0) << " "
         << ((frac1 > frac2) ? 1 : 0) << " "
         << ((frac1 >= frac2) ? 1 : 0) << " "
         << ((frac1 == frac2) ? 1 : 0) << " "
         << ((frac1 != frac2) ? 1 : 0) << " "
         << ((frac2 < frac3) ? 1 : 0) << " "
         << ((frac2 <= frac3) ? 1 : 0) << " "
         << ((frac2 > frac3) ? 1 : 0) << " "
         << ((frac2 >= frac3) ? 1 : 0) << " "
         << ((frac2 == frac3) ? 1 : 0) << " "
         << ((frac2 != frac3) ? 1 : 0) << endl;
    cout << (frac6 = frac3) << " ";
    cout << (frac6 += frac3) << " ";
    cout << (frac6 -= frac3) << " ";
    cout << (frac6 *= frac3) << " ";
    cout << (frac6 /= frac3) << endl;
    cout << -frac6 << endl;
    frac6 = (++frac4) + 2;
    frac7 = 2 + (frac4++);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    cout << 2 * frac3 << " " << frac3 * 2 << " "
         << 2 / frac3 << " " << frac3 / 2 << endl;
}
void testDataFromFile()
{
    ifstream inStream;
    int t, n;
    inStream.open("input.txt");
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }

    inStream >> t;

    while(t--){
        inStream >> n;
        result.clear();
        for(int i = 0; i < n; i++){
            inStream >> num >> den;
            result.push_back(myRational(num, den));
        }
            sort(result.begin(), result.end());

        for(const auto& rational : result){
            cout << rational << " ";
        }
        cout << "\n";
    }
}