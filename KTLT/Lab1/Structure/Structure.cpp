#include <iostream>
#include <math.h>
using namespace std;
struct daytime
{
    int hour;
    int minute;
    int second;
};
void inputTime(daytime &a)
{
    cout << "Hour: ";
    cin >> a.hour;
    cout << "Minute: ";
    cin >> a.minute;
    cout << "Second: ";
    cin >> a.second;
    if (a.hour > 24 || a.minute > 60 || a.second > 60 || a.hour < 0 || a.minute < 0 || a.second < 0)
        cout << "Invalid time.";
}
void calculateTime(daytime a)
{
    cout << "Minute: " << a.minute + a.hour * 60 << endl;
    cout << "Second: " << a.second + a.minute * 60 + a.hour * 3600;
}
void checkTimeEarly(daytime a, daytime b)
{
    if (a.hour > b.hour)
        cout << "time2";
    else if (a.hour < b.hour)
        cout << "time1";
    else
    {
        if (a.minute > b.minute)
            cout << "time2";
        else if (a.minute < b.minute)
            cout << "time1";
        else
        {
            if (a.second > b.second)
                cout << "time2";
            else if (a.second < b.second)
                cout << "time1";
        }
    }
}
void calculateAddtime(daytime &a, int b)
{
    a.hour += b / 60;
    a.minute += b % 60;
    cout << a.hour << endl
         << a.minute << endl
         << a.second;
}
struct fraction
{
    int numerator;
    int denominator;
};
int GreatestCommonDivisor(int a, int b)
{
    if (a == 0 || b == 0)
        return a + b;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}
void simplifyFraction(fraction &a)
{
    int GCD = GreatestCommonDivisor(a.numerator, a.denominator);
    a.numerator /= GCD;
    a.denominator /= GCD;
}
void inputFraction(fraction &a)
{
    cout << "Numerator: ";
    cin >> a.numerator;
    cout << "Denominator: ";
    cin >> a.denominator;
    simplifyFraction(a);
    cout << "Numerator: " << a.numerator << endl;
    cout << "Denominator: " << a.denominator << endl;
}
int LeastCommonMultiple(int a, int b)
{
    return (a * b) / GreatestCommonDivisor(a, b);
}
void sumFraction(fraction a, fraction b)
{
    int lcm = LeastCommonMultiple(a.denominator, b.denominator);
    fraction sum;
    sum.denominator = lcm;
    sum.numerator = a.numerator * (lcm / a.denominator) + b.numerator * (lcm / b.denominator);
    int gcd = GreatestCommonDivisor(sum.denominator, sum.numerator);
    sum.denominator /= gcd;
    sum.numerator /= gcd;
    cout << sum.denominator << " // " << sum.numerator;
}
void compareFraction(fraction a, fraction b)
{
    double c, d;
    c = a.numerator / double(a.denominator);
    d = double(b.numerator) / b.denominator;
    if (c > d)
        cout << "a>b";
    else if (c == d)
        cout << "a=b";
    else
        cout << "b>a";
}
struct point2D
{
    double x;
    double y;
};
void whichQuadrant(point2D a)
{
    double x = a.x;
    double y = a.y;
    if (x == 0 && y == 0)
    {
        cout << "Is is O(0;0).";
        return;
    }
    else if (x == 0)
    {
        cout << "On Oy.";
        return;
    }
    else if (y == 0)
    {
        cout << "On Ox";
        return;
    }

    if (x > 0 && y > 0)
        cout << "Up-right.";
    else if (x > 0 && y < 0)
        cout << "Down-right.";
    else if (x < 0 && y > 0)
        cout << "Up-left";
    else
        cout << "Down-left.";
}
double Distance(point2D a, point2D b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void midPoint(point2D a, point2D b)
{
    cout << "x = " << (a.x + b.x) / 2 << endl;
    cout << "y = " << (a.y + b.y) / 2 << endl;
}
void isCollinear(point2D a, point2D b, point2D c)
{
    if ((c.x - a.x) / (b.x - a.x) == (c.y - a.y) / (b.y - a.y))
        cout << "Collinear.";
    else
        cout << "Not collinear.";
}
int main()
{
    point2D a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    isCollinear(a, b, c);

    return 0;
}