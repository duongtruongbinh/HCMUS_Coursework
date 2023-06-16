#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream input1;
    input1.open("input1.txt");
    ofstream output1;
    output1.open("output1.txt");
    int n;
    input1 >> n;
    for (int j = 0; j < n; j++)
    {
        double a, b;
        char c;
        input1 >> a;
        input1 >> c;
        input1 >> b;
        switch (c)
        {
        case '+':
            output1 << a + b << endl;
            break;
        case '-':
            output1 << a - b << endl;
            break;
        case '*':
            output1 << a * b << endl;
            break;
        default:
            output1 << a / b << endl;
            break;
        }
    }
    output1.close();
    input1.close();
    return 0;
}