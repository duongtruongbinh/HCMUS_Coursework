#include <iostream>
#include <fstream>
using namespace std;
struct node
{
    int key;
    node *next;
};
int sum(int n)
{
    if (n == 1)
        return 1;
    return sum(n - 1) + n;
}
int factorial(int n)
{
    if (n == 1)
        return 1;
    return factorial(n - 1) * n;
}
int power(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    return power(x, n - 1) * x;
}
int countDigit(int n)
{
    if (n < 10)
        return 1;
    return countDigit(n / 10) + 1;
}
int countOddDigit(int n)
{
    if (n < 10)
        return n % 2;
    return countOddDigit(n / 10) + ((n % 10) % 2);
}
bool isAllDigitEven(int n)
{
    if (n < 10)
        return !(n % 2);
    return isAllDigitEven(n / 10) && !(n % 2);
}
int countCommonDivisor(int a, int b, int x = 1)
{
    if (x > a || x > b)
        return 0;
    return countCommonDivisor(a, b, x + 1) + int(!(a % x) && !(b % x));
}
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int LCM(int a, int b, int x = 2)
{
    if (a > b)
        swap(a, b);
    if (x == b)
        return a * b;
    return !((a * x) % b) ? a * x : LCM(a, b, x + 1);
}
int Reverse(int n)
{
    if (n < 10)
        return n;
    return (n % 10) * power(10, countDigit(n) - 1) + Reverse(n / 10);
}
int ConvertintoBinary(int n, int x = 0)
{
    if (n <= 2)
        return (n % 2) * power(10, x);
    return ConvertintoBinary(n / 2, x + 1) + (n % 2) * power(10, x);
}
int Fibonacci(int n)
{
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
void permutation(string a, int l, int r)
{
    if (l == r)
        cout << a << " ";
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[i], a[l]);

            permutation(a, l + 1, r);

            swap(a[i], a[l]);
        }
    }
}
node *createNode(int n)
{
    node *temp = new node;
    temp->key = n;
    temp->next = nullptr;
    return temp;
}
node *createList(int a[], int n, int i = 0)
{
    if (i == n)
        return nullptr;
    node *temp = createNode(a[i]);
    temp->next = createList(a, n, i + 1);
    return temp;
}
void print(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->key << " ";
        temp = temp->next;
    }
}
void removeNode(node *head, int k)
{
    if (!head)
        return;
    if (head->key == k)
    {
        head->key = head->next->key;
        node *temp = head->next;
        head->next = temp->next;
        delete temp;
        return;
    }
    if (!head->next->next && head->key != k)
    {
        if (head->next->key == k)
        {
            node *temp = head->next;
            head->next = nullptr;
            delete temp;
            return;
        }
    }
    else
        removeNode(head->next, k);
}
int main()
{
    int a[4] = {5, 3, 9, 2};
    node *head = createList(a, 4);
    fstream an("a.txt", ios::binary);
    int n;
    an.read(reinterpret_cast<char *>(&n), sizeof(n));
    print(head);
    return 0;
}