
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
using namespace std;

#include "DynamicArray.h"
#include "Utils.h"

class Fraction;

class Fraction {
public:
    inline static const string FRACTION_PATTERN = "\\d+/\\d+";
private:
    int _num;
    int _den;
public:
    int numerator() { return _num; }
    int denominator() { return _den; }
    void setNumerator(int value) { _num = value; }
    void setDenominator(int value) { _den = value; }

    Fraction();
    Fraction(int, int);
    string toString();

    static tuple<bool, Fraction, string> parse(string);
};
 
Fraction::Fraction() {
    _num = 0;
    _den = 1;
}

Fraction::Fraction(int num, int den) {
    this->_num = num;
    this->_den = den;
}

string Fraction::toString() {
    stringstream builder;
    builder << _num << "/" << _den;

    string result = builder.str();
    return result;
}

tuple<bool, Fraction, string> Fraction::parse(string buffer) {
    bool succeeded = true;
    string message = "";
    int num = 0;
    int den = 1;
    Fraction data;

    if (buffer.length() == 0) {
        succeeded = false;
        message = "Input value cannot be empty";
    }
    else {
        succeeded = true;
        auto tokens = Utils::String::split(buffer, "/");
        num = stoi(tokens[0]);
        den = stoi(tokens[1]);
        data = Fraction(num, den);
    }

    auto result = make_tuple(succeeded, data, message);
    
    return result;
}

int main()
{
    //DynamicArray<string> a;

    //a.push_back("A");
    //a.push_back("B");
    //a.push_back("C");
    //a.push_back("D");
    //a.push_back("E");

    //for (int i = 0; i < a.size(); i++) {
    //    cout << a[i] << " ";
    //}

    //cout << endl;

    //DynamicArray<string> b(a); // Sao chep ==> hàm tạo sao chép

    //for (int i = 0; i < b.size(); i++) {
    //    cout << b[i] << " ";
    //}
    //cout << endl;

    //DynamicArray<string> c; // Default constructor
    //c = a; // Toan tu bang copy assignment operator

    //for (int i = 0; i < c.size(); i++) {
    //    cout << c[i] << " ";
    //}
    //cout << endl;

    //cout << "Mang D:";
    //DynamicArray<string> d = a; // Copy constructor
    //for (int i = 0; i < c.size(); i++) {
    //    cout << c[i] << " ";
    //}

    //cout << endl;

    // ================================================
    /// TACH CHUOI
    //string haystack = "she sells seashells by the seashore";
    //string haystack2 = "the shells she sells are seashells";

    //string needle = "se";

    //int startPosition = 0;

    //int foundPos = haystack.find(needle, startPosition);
    ////cout << foundPos;

    //string fractionString = "145/13";
    //string separator = "/";

    //auto tokens = Utils::String::split(fractionString, separator);

    //for (int i = 0; i < tokens.size(); i++) {
    //    cout << tokens[i] << endl;
    //}
    // 
    // ==========================================
    // DOC GHI TAP TIN

    //string input = "input.txt";
    //ifstream reader("input.txt", ios::in);

    //string buffer;
    //getline(reader, buffer);
    //int count = stoi(buffer);

    //vector<int> a;
    //regex digitPattern("\\d+");

    //for (int i = 1; i <= count; i++) {
    //    getline(reader, buffer);

    //    if (regex_match(buffer, digitPattern)) {
    //        int number = stoi(buffer);
    //        a.push_back(number);
    //    }
    //}

    //reader.close();

    //// Thong bao ket qua
    //cout << "Reading input.txt" << endl;
    //cout << "Expecting to find " << count << " integers" << endl;
    //cout << "Found " << a.size() << " integers" << endl;

    //for (int i = 0; i < a.size(); i++) {
    //    cout << a[i] << " ";
    //}
    //cout << endl;

    //cin.get();
    /// ========================================

    // DOC GHI MANG PHAN SO
    string input = "fractions.txt";

    ifstream reader(input, ios::in);

    vector<Fraction> a;
    string buffer;

    getline(reader, buffer);
    int count = stoi(buffer);

    for (int i = 1; i <= count; i++) {
        getline(reader, buffer);

        // Neu khop dinh dang ==> parse
        regex pattern(Fraction::FRACTION_PATTERN);
        if (regex_match(buffer, pattern)) {
            // Fraction f(buffer); 
            auto [succeeded, f, message] = Fraction::parse(buffer);

            if (succeeded) {
                a.push_back(f);
            }
        }
    }

    cout << "Reading " << input << endl;
    cout << "Expecting to find " << count << " fractions" << endl;

    cout << "Found " << a.size() << " fractions: ";

    for (int i = 0; i < a.size(); i++) {
        cout << a[i].toString() << " ";
    }

    reader.close();
    cin.get();

    // =========================================
    
}

