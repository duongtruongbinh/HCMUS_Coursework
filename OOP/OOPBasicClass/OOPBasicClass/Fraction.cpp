#include "Fraction.h"
#include <string>
#include <sstream>
using namespace std;

Fraction::Fraction() {
    _num = 0;
    _den = 1;
}

Fraction::Fraction(int num, int den) {
    this->_num = num;
    this->_den = den;
}

/// <summary>
/// Chuyển phân số thành chuỗi
/// </summary>
/// <returns>Phân số ở dạng a/b</returns>
string Fraction::toString() const{
    stringstream builder;
    builder << _num << "/" << _den;

    string result = builder.str();
    return result;
}
