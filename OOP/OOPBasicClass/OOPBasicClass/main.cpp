
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Cat.h"
#include "Fraction.h"
#include "RandomIntegerGenerator.h"


class FractionToDecimalUIConverter {
public:
    string convert(const Fraction& f);
};

class FractionToLowestTermUIConverter {
public:
    string convert(const Fraction& f);
};

class FractionToMixedConverter {
public:
    void convert(const Fraction& f);
};

class Integer {
public:
    /// <summary>
    /// Hàm tìm ước chung lớn nhất
    /// </summary>
    /// <param name="a">Số a</param>
    /// <param name="b">Số b</param>
    /// <returns>UCLN </returns>
    static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};

void FractionToMixedConverter::convert(const Fraction& f)
{
    if (f.numerator() < f.denominator()) cout<< f.toString();

    int num = f.numerator()/f.denominator();
    int less = f.numerator() - f.denominator() * num;

    cout << num << " + " << less << "/" << f.denominator();

}

string FractionToLowestTermUIConverter::convert(const Fraction& f) {
    stringstream builder;
    int gcd = Integer::gcd(f.numerator(), f.denominator());
    int num = f.numerator() / gcd;
    int den = f.denominator() / gcd;
    Fraction temp(num, den);

    builder << num << "/" << den;
    string result = builder.str();
    return result;
}

string FractionToDecimalUIConverter::convert(const Fraction& f) {
    stringstream builder;
    float value = f.numerator() * 1.0 / f.denominator();
    builder << value;

    string result = builder.str();
    return result;
}


int main()
{
    Fraction f(6, 4);

    // Cach hien thi thuong huong 3/2
    cout << f.toString() << endl;

    // Hien thi so thuc?
    FractionToDecimalUIConverter decimalConverter;
    cout << decimalConverter.convert(f) << endl;

    //Toi gian lowest term
    FractionToLowestTermUIConverter lowestTermConverter;
    cout << lowestTermConverter.convert(f) << endl;

    //string cv = decimalConverter.convert(f);
    FractionToMixedConverter mixedconvert;
    mixedconvert.convert(f);
}
