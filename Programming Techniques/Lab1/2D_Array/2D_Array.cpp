#include <iostream>
#include <math.h>
using namespace std;
void input2DArray(float a[][100], int m, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
}
void print2DArray(float a[][100], int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
void rotate2DArray(float a[][100], int m, int n)
{
    for (int i = 0; i < n >> 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            int temp = a[i][j];
            a[i][j] = a[n - 1 - j][i];
            a[n - 1 - j][i] = a[n - 1 - i][m - 1 - j];
            a[n - 1 - i][m - 1 - j] = a[j][m - 1 - i];
            a[j][m - 1 - i] = temp;
        }
    }
}
void sum2DArray(float a[][100], float b[][100], float result[][100], int m, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            result[i][j] = a[i][j] + b[i][j];
}
bool isDiagonalMatrix(float a[][100], int m, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i != j)
                if (a[i][j] != 0)
                    return false;
        }
    return 1;
}
bool isLowerTriangleMatrix(float a[][100], int m, int n)
{
    for (int k = 1; k <= n - 1; k++)
        for (int i = 0; i <= n - 1 - k; i++)
            if (a[i][i + k] != 0)
                return 0;
    return 1;
}
bool isUpperTriangleMatrix(float a[][100], int m, int n)
{
    for (int k = 1; k <= n - 1; k++)
        for (int i = 0; i <= n - 1 - k; i++)
            if (a[i + k][i] != 0)
                return 0;
    return 1;
}
int main()
{
    float a[100][100];
    float b[100][100];
    float c[100][100];
    int n, m;
    cin >> n >> m;
    input2DArray(a, m, n);
    input2DArray(b, m, n);
    print2DArray(a, m, n);
    print2DArray(b, m, n);
    sum2DArray(a, b, c, m, n);
    print2DArray(c,m,n);
    return 0;
}