#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;
int MajorElement1(int *a, int n, int &compare, int &assign)
{
    int *b = new int[n];

    assign = 1; // i=0
    compare = 0;
    for (int i = 0; i < n; i++)
    {
        b[i] = 0;
        assign += 2;
        ++compare;
    }
    ++compare;

    ++assign; // i=0
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        ++assign;

        if (++compare && b[i] == -1)
            continue;

        ++assign; // j=i+1
        for (int j = i + 1; j < n; j++)
        {
            if (++compare && a[i] == a[j])
            {
                count++;
                assign++;

                b[j] = -1;
                ++assign;
            }

            ++compare; // j<n
            ++assign;  // j++
        }
        ++compare;

        if (++compare && count > (n - 1) / 2)
        {
            delete[] b;
            return a[i];
        }
    }
    ++compare;

    delete[] b;
    return 0;
}
int MajorElement2(int a[], int n, int &compare, int &assign)
{
    int count = 1;
    compare = 0;
    assign++;

    sort(a, a + n);
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
            count++;
        else
        {
            if (count > n / 2)
                return a[i - 1];
            else
                count = 1;
        }
    }
    if (count > n / 2)
        return a[n - 1];
    return 0;
}

int *createArray(int n)
{
    int *a = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
    return a;
}

int GCD1(int a, int b)
{
    int c = min(a, b);
    for (int i = c; i >= 1; i--)
    {
        if (b % i == 0 && a % i == 0)
            return i;
    }
}

int GCD2(int a, int b)
{
    if (b == 0)
        return a;
    return GCD2(b, a % b);
}

void WorldCloudProblem1(string a[], int n, int w)
{
    int b[w] = {0};

    for (int i = 0; i < w; i++)
    {
        if (b[i] < 0)
            continue;
        int count = 1;
        for (int j = i + 1; j < w; j++)
            if (a[i] == a[j])
            {
                count++;
                b[j] = -1;
            }
        if (b[i] != -1)
        {
            b[i] = count;
            cout << a[i] << "=" << b[i] << endl;
        }
    }
}

void WorldCloudProblem2(string a[], int n, int w)
{
    sort(a, a + w);
    int count = 1;
    for (int i = 0; i < w; i++)
    {

        if (a[i] == a[i + 1])
            count++;
        else
        {
            cout << a[i] << "=" << count << endl;
            count = 1;
        }
    }
}

void SeeSawProblem1(int left, int right, int a[], int n, int &x, int &y)
{
    x = -1;
    y = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (left + a[i] == right + a[j] && i != j)
            {
                x = i;
                y = j;
                cout << i << " " << j;
                return;
            }
    }

    cout << "not possible";
}

void SeeSawProblem2(int left, int right, int a[], int n, int &x, int &y)
{
    
}
int main()
{
    // int a[] = {5, 3, 6, 5, 5, 5, 4, 5, 5, 9};
    // for (int i = 0; i < 10; i++)
    //     cout << a[i] << " ";
    // cout << endl;
    // int compare, assign;
    // MajorElement1(a, 10, compare, assign);
    // cout << compare << " " << assign;

    // string a[] = {"a", "basb", "the", "asdfasdf", "B", "a", "asfadsf", "and", "the", "the"};
    // WorldCloudProblem2(a, 10, 10);
    int x, y;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    SeeSawProblem2(3, 5, a, 10, x, y);
    return 0;
}