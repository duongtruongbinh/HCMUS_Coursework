#include <bits/stdc++.h>
#include <ctime>
using namespace std;
void heapRebuild(int start, int a[], int n)
{
    int leftChild = 2 * n + 1;
    if (leftChild >= n)
        return;
    int largerChild = leftChild;
    int rightChild = 2 * n + 2;
    if (rightChild < n)
        if (a[rightChild] > a[largerChild])
            largerChild = rightChild;
    if (a[start] < a[largerChild])
    {
        swap(a[start], a[largerChild]);
        heapRebuild(largerChild, a, n);
    }
}

void HeapSort(int a[], int n)
{
    for (int i = n / 2; i >= 0; i--)
        heapRebuild(i, a, n);
    swap(a[0], a[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1)
    {
        heapRebuild(0, a, n);
        heapSize--;
        swap(a[0], a[heapSize]);
    }
}

void merge(int a[], int first, int mid, int last)
{
    int first1 = first, last1 = mid, first2 = mid + 1, last2 = last;
    int temp[1000];
    int i = 0;
    while (first1 <= last1 && first2 <= last2)
    {
        if (a[first1] < a[first2])
            temp[i++] = a[first1++];
        else
            temp[i++] = a[first2++];
    }
    while (first1 <= last1)
        temp[i++] = a[first1++];
    while (first2 <= last2)
        temp[i++] = a[first2++];
    for (int i = first; i <= last; i++)
        a[i] = temp[i];
}

void MergeSort(int a[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        MergeSort(a, first, mid);
        MergeSort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}

void QuickSort1(int a[], int first, int last)
{
    int pivot = a[(last + first) / 2];
    int i = first, j = last;
    do
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (j > first)
        QuickSort1(a, first, j);
    if (i < last)
        QuickSort1(a, i, last);
}

int sortFirstMiddleLast(int a[], int first, int last)
{
    int mid = first + (last - first) / 2;
    if (a[first] > a[mid])
        swap(a[first], a[last]);
    if (a[mid] > a[last])
        swap(a[last], a[mid]);
    if (a[first] > a[mid])
        swap(a[first], a[mid]);
    return mid;
}

int partition(int a[], int first, int last)
{
    int pivotIndex = sortFirstMiddleLast(a, first, last);
    int indexFromLeft = first + 1, indexFromRight = last - 2;
    swap(a[pivotIndex], a[last - 1]);
    pivotIndex = last - 1;
    int pivot = a[pivotIndex];
    do
    {
        while (a[indexFromLeft] < pivot)
            indexFromLeft++;
        while (a[indexFromRight] > pivot)
            indexFromRight--;
        if (indexFromLeft < indexFromRight)
        {
            swap(a[indexFromLeft], a[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
        }
    } while (indexFromLeft < indexFromRight);
    swap(a[indexFromLeft], a[pivotIndex]);
    pivotIndex = indexFromLeft;
    return pivotIndex;
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void binaryInsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int last = i - 1, first = 0;
        while (first <= last)
        {
            int mid = (last + first) / 2;
            if (key > a[mid])
                first = mid + 1;
            else
                last = mid - 1;
        }
        for (int j = i - 1; j >= first; j--)
        {
            a[j + 1] = a[j];
        }
        a[first] = key;
    }
}

void BubbleSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}

void ImprovedBubbleSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool flag = true;
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1])
            {
                flag = false;
                swap(a[j], a[j - 1]);
            }
        if (flag)
            break;
    }
}

void ShakerSort(int a[], int n)
{
    int left = 0, right = n - 1, k = n - 1;
    while (left <= right)
    {
        for (int i = right; i >= left; i--)
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        left = k + 1;
        for (int i = left; i <= right; i++)
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        right = k - 1;
    }
}

void QuickSort2(int a[], int first, int last)
{
    if (last - first + 1 < 3)
        insertionSort(a + first, last - first + 1);
    else
    {
        int pivotIndex = partition(a, first, last);
        QuickSort2(a, first, pivotIndex - 1);
        QuickSort2(a, pivotIndex + 1, last);
    }
}

void radixSort(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];
    int digit = 0;
    do
    {
        digit++;
        max /= 10;
    } while (max > 0);

    int **tempArray = new int *[10];
    for (int i = 0; i < n; i++)
        tempArray[i] = new int[n];
    int tempCount[10];

    for (int i = 0; i < digit; ++i)
    {
        int exp = pow(10, i);
        for (int j = 0; j < 10; ++j)
            tempCount[j] = 0;
        for (int j = 0; j < n; ++j)
        {
            int idx = (a[j] / exp) % 10;
            tempArray[idx][tempCount[idx]++] = a[j];
        }
        int idx = 0; // combine groups
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < tempCount[j]; ++k)
                a[idx++] = tempArray[j][k];
    }
}

void countingSort(int a[], int n, int u)
{
    int *f = new int[u + 1]{0};
    for (int i = 0; i < n; i++)
        f[a[i]]++;
    for (int i = 1; i <= u; i++)
        f[i] = f[i - 1] + f[i];
    int *b = new int[n];
    for (int i = n - 1; i >= 0; i--)
        b[f[a[i]] - 1] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = b[i];
    delete[] f;
}

int *createArray(int n)
{
    int *a = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
    return a;
}

int main()
{
    int n = 10;
    int *a = createArray(n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    countingSort(a, n, 100);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    delete[] a;
    return 0;
}