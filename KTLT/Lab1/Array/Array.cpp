#include <iostream>
#include <math.h>
using namespace std;
void inputArray(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}
void printArray(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
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
int countArrayPrime(float a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
            count++;
    }
    return count;
}
float sumArray(float a[], int n)
{
    float sum;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}
bool isIncreasing(float a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            return 0;
    }
    return 1;
}
bool isDecreasing(float a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
            return 0;
    }
    return 1;
}
int main()
{
    float a[100];
    int n;cin>>n;
    inputArray(a, n);
    cout << countArrayPrime(a, n) << endl
         << sumArray(a, n) << endl
         << isIncreasing(a, n) << endl
         << isDecreasing(a, n);
    return 0;
}