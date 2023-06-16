#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int *findMax(int *arr, int n)
{
    int *p = &arr[0];
    for (int i = 0; i < n; i++)
    {
        if (*p < arr[i])
            p = &arr[i];
    }
    return p;
}
int *copyArray(int *arr, int n)
{
    int *p = new int[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = arr[i];
    }
    return p;
}
int *countEvens(int *arr, int n, int *evens)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            count++;
    evens = new int(count);
    return evens;
}
int *genEvenSubarray(int *arr, int n, int *&count)
{
    int countEven = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            countEven++;
    }
    count = new int(countEven);
    int *p = new int[countEven];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            p[index++] = arr[i];
    }
    return p;
}
int **transposeMatrix(int **a, int length, int width)
{
    int **b = new int *[length];

    for (int i = 0; i < length; i++)
        b[i] = new int[width];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            b[j][i] = a[i][j];
    return b;
}
int **findSubmatrix(int **a, int length, int width, int &length_, int &width_)
{
    length_ = 0;
    int i_start, j_start, i_end, j_end, max = 0;
    width_ = 0;
    int **sum = new int *[width];
    for (int i = 0; i < width; i++)
        sum[i] = new int[length];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
        {
            if (i == 0 && j == 0)
            {
                sum[i][j] = a[i][j];
                continue;
            }
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + a[i][j] - sum[i - 1][j - 1];
        }
    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            if (max < sum[i][j] - sum[i - width][j] - sum[i][j - length] + sum[i - width][j - length])
            {
                max = sum[i][j] - sum[i - width][j] - sum[i][j - length] + sum[i - width][j - length];
                i_start = i - width + 1;
                j_start = j - length + 1;
                i_end = i;
                j_end = j;
            }

    int **p = new int *[i_end - i_start + 1];
    for (int i = 0; i < i_end - i_start; i++)
        p[i] = new int[j_end - j_start];

    for (int i = i_start; i <= i_end; i++)
        for (int j = j_start; j <= j_end; j++)
            p[i - i_start][j - j_start] = a[i][j];
    delete[] sum;
    return p;
}
int main()
{
    int n, m;
    srand(time(0));
    cin >> n >> m;
    int **a = new int *[n];

    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 10;
            cout << a[i][j];
        }
        cout << endl;
    }

    int **p = transposeMatrix(a, m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << p[i][j];
        cout << endl;
    }
    delete[] p, a;
    return 0;
}