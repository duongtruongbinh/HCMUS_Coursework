#include <iostream>
using namespace std;
int SequentialSearch(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
        if (a[i] == k)
            return i;
    return -1;
}
int SequentialSearchwithSentinel(int a[], int n, int k)
{
    int temp;
    if (a[n - 1] == k)
        return n - 1;
    else
    {
        temp = a[n - 1];
        a[n - 1] = k;
    }
    for (int i = 0; i < n; i++)
        if (a[i] == k)
        {
            a[n - 1] = temp;
            if (n - 1 == i)
                return -1;
            else
                return i;
        }
    return -1;
}
int BinarySearch(int a[], int n, int k)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] == k)
            return mid;
        else if (k < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int InterpolationSearch(int a[], int n, int k)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (k - a[left]) * (right - left) / (a[right] - a[left]) + left;
        if (a[mid] == k)
            return mid;
        else if (k < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int RecursiveBinarySearch(int a[], int n, int k, int left, int right)
{
    int mid = (left + right) / 2;
    if (a[mid] == k)
        return mid;
    if (a[mid] > k)
        return RecursiveBinarySearch(a, n, k, left, mid - 1);
    return RecursiveBinarySearch(a, n, k, mid + 1, right);
}
void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
            if (a[min] > a[j])
                min = j;
        swap(a[min], a[i]);
    }
}
void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j > 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void BubbleSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
}
void InterchangeSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
}
void InsertionSortwithSentinel(int a[], int n)
{
    int temp = a[0];
    a[0] = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    int j = 1;
    while (temp > a[j])
    {
        a[j - 1] = a[j];
        j++;
    }
    a[j - 1] = temp;
}
void BinaryInsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int left = 0, right = i - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (key > a[mid - 1] && key < a[mid])
            {
                for (int j = i - 1; j >= mid; j--)
                    a[j + 1] = a[j];
                a[mid] = key;
                break;
            }
            if (key > a[mid])
                left = mid + 1;
            else
                right = mid;
        }
    }
}
void ImproveBubbleSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int count = 0;
        for (int j = n - 1; j >= i; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                count++;
            }
        }
        if (count == 0)
            return;
    }
}
void ShakerSort(int a[], int n)
{
    int left = 1, right = n - 1, k;
    do
    {
        for (int j = right; j >= left; j--)
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                k = j;
            }
        left = k + 1;
        for (int j = left; j <= right; j++)
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                k = j;
            }
        right = k - 1;
    } while (left <= right);
}
int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    ShakerSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}