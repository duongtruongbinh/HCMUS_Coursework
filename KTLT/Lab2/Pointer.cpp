#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int *sum(int *a, int *b)
{
    int *p = new int;
    *p = *a + *b;
    return p;
}
void inputArray(int *&a, int &n)
{
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i];
}
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
int *findLargestTotalSubarray(int *a, int n, int &total, int &length)
{
    total = INT_MIN;
    int sum = 0, start = 0, end = n - 1, current_start = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] < a[i])
        {
            current_start = i;
            sum = a[i];
        }
        else
        {
            sum += a[i];
        }
        if (total < sum)
        {
            total = sum;
            start = current_start;
            end = i;
        }
    }
    length = end - start + 1;
    int *p = new int[length];
    for (int i = 0; i < length; i++)
        p[i] = a[start + i];
    return p;
}
int *findLongestAscendingSubarray(int *a, int n, int &length)
{
    length = 0;
    int count = 0, start = 0, end = 0, current_start = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            current_start = i;
            count = 0;
        }
        else
        {
            count++;
        }
        if (count + 1 > length)
        {
            start = current_start;
            end = i;
            length = count + 1;
        }
    }
    int *p = new int[length];
    for (int i = 0; i < length; i++)
        p[i] = a[start + i];
    return p;
}
void swapArrays(int *&a, int *&b, int &na, int &nb)
{
    swap(na, nb);
    int *temp = a;
    a = b;
    b = temp;
}
int *merge2Arrays(int *a, int *b, int na, int nb, int &nc)
{
    int *c = new int[na + nb];
    nc = na + nb;
    int i = 0, j = 0, index = 0;
    while (i < na || j < nb)
    {
        if (a[i] < b[j] || j >= nb)
            c[index++] = a[i++];
        if (b[j] < a[i] || i >= na)
            c[index++] = b[j++];
    }
    return c;
}
int *concatenate2Arrays(int *a, int *b, int na, int nb)
{
    int *p = new int[na + nb];
    for (int i = 0; i < na; i++)
        p[i] = a[i];
    for (int i = 0; i < nb; i++)
        p[i + na] = b[i];
    return p;
}
void generateMatrix1(int **&A, int &length, int &width)
{
    srand(time(NULL));

    A = new int *[length];
    for (int i = 0; i < width; i++)
        A[i] = new int[width];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            A[i][j] = rand() % 10;
}
int **generateMatrix2(int *a, int *b, int na, int nb)
{
    int **p = new int *[na];
    for (int i = 0; i < nb; i++)
        p[i] = new int[nb];

    for (int i = 0; i < na; i++)
        for (int j = 0; j < nb; j++)
            p[i][j] = a[i] * b[j];
    return p;
}
void swapRows(int **a, int length, int width)
{
    for (int i = 0; i <= width / 2; i++)
        for (int j = 0; j <= length; j++)
            swap(a[i][j], a[width - 1 - i][j]);
}
void swapColumns(int **a, int length, int width)
{
    for (int i = 0; i < length / 2; i++)
        for (int j = 0; j < width; j++)
            swap(a[j][i], a[j][length - 1 - i]);
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
int **concatenate2MatricesH(int **a, int **b, int length, int width)
{
    int **c = new int *[width];
    for (int i = 0; i < width; i++)
        c[i] = new int[length * 2];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
            c[i][j] = a[i][j];
        for (int j = 0; j < length; j++)
            c[i][j + length] = b[i][j];
    }
    return c;
}
int **concatenate2MatricesV(int **a, int **b, int length, int width)
{
    int **c = new int *[width * 2];
    for (int i = 0; i < width * 2; i++)
        c[i] = new int[length];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            c[i][j] = a[i][j];

    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            c[i + width][j] = b[i][j];
    return c;
}
bool multiple2Matrices(int **a, int **b, int lengtha, int widtha, int lengthb, int widthb)
{
    if (lengtha != widthb)
        return 0;
    for (int i = 0; i < widtha; i++)
    {
        for (int j = 0; j < lengthb; j++)
        {
            int sum = 0;
            for (int k = 0; k < widtha; k++)
                for (int l = 0; l < widthb; l++)
                    sum += a[k][l] * b[l][k];
            cout << sum << " ";
        }
        cout << endl;
    }
    return 1;
}
int **findSubmatrix(int **a, int length, int width, int &length_, int &width_)
{

    int i_start = 0, j_start = 0, i_end = 0, j_end = 0, max = 0;

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
            if (i == 0)
            {
                sum[i][j] = sum[i][j - 1] + a[i][j];
                continue;
            }
            if (j == 0)
            {
                sum[i][j] = sum[i - 1][j] + a[i][j];
            }
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + a[i][j] - sum[i - 1][j - 1];
        }
    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
        {
            if (i < width_ || j < length_)
                continue;
            if (max < sum[i][j] - sum[i - width_][j] - sum[i][j - length_] + sum[i - width_][j - length_])
            {
                max = sum[i][j] - sum[i - width_][j] - sum[i][j - length_] + sum[i - width_][j - length_];
                i_start = i - width_ + 1;
                j_start = j - length_ + 1;
                i_end = i;
                j_end = j;
            }
        }

    int **p = new int *[width_];
    for (int i = 0; i < width_; i++)
        p[i] = new int[length_];

    for (int i = 0; i < width_; i++)
        for (int j = 0; j < length_; j++)
            p[i][j] = a[i + i_start][j + j_start];

    delete[] sum;
    return p;
}
int main()
{
    int n = 5, m = 5;
    int c = 3, d = 3;
    // int *a = new int[n];
    // for (int i = 0; i < n; i++)
    // {
    //     a[i] = rand() % 10;
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // int *b = new int[m];
    // for (int i = 0; i < m; i++)
    // {
    //     b[i] = rand() % 10;
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    int **a, **b;
    generateMatrix1(a, m, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    // nhớ chỉnh lại cin vào size
    int **p = findSubmatrix(a, m, n, c, d);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << p[i][j] << " ";
        cout << endl;
    }
    delete[] a, p;
    return 0;
}