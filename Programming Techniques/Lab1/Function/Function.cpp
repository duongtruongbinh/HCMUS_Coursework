#include <iostream>
#include <math.h>
using namespace std;
void LinearEquation(int a, int b)
{
	if (a == 0)
	{
		if (b == 0)
			cout << "Vo so nghiem." << endl;
		else
			cout << "Vo nghiem." << endl;
	}
	else
		cout << "x = " << double(-b) / a << endl;
}
void QuadraticEquation(int a, int b, int c)
{
	if (a == 0)
		LinearEquation(b, c);
	else
	{
		double denta = b * double(b) - 4 * a * c;
		if (denta < 0)
		{
			cout << "Vo nghiem." << endl;
			return;
		}
		if (denta == 0)
		{
			cout << "x1 = x2 = " << -b / 2 * double(a) << endl;
			return;
		}
		cout << "x1 =" << (-b + sqrt(denta)) / (2 * a) << endl;
		cout << "x2 =" << (-b - sqrt(denta)) / (2 * a) << endl;
		return;
	}
}
bool isPrime(int a)
{
	if (a < 2)
		return 0;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0)
			return 0;
	}
	return 1;
}
int countPrime(int a, int b)
{
	int count = 0;
	for (int i = a; i <= b; i++)
		if (isPrime(i))
			count++;
	return count;
}
int sumDigits(int n)
{
	int sum = 0;
	n = abs(n);
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int countInteger(int n, int k)
{
	int count = 0;
	while (n > 1)
	{
		n--;
		if (n % k == 0)
			count++;
	}
	return count;
}
void Triangle(float a, float b, float c)
{
	if ((a + b > c) && (a + c > b) && (b + c > a))
		cout << "This is a triangle." << endl;
	else
	{
		cout << "This is not a triangle." << endl;
		return;
	}
	if (a == b && b == c && a == c)
		cout << "This is an equilateral triangle." << endl;
	else if ((a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) && (a == b || b == c || a == c))
		cout << "This is a right isosceles triangle." << endl;
	else if (a == b || b == c || a == c)
		cout << "This is an isosceles triangle." << endl;
	else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
		cout << "This is a right triangle." << endl;
	else
		cout << "This is a normal triangle." << endl;
}

int main()
{
	Triangle(3, 3, 4);
	return 0;
}