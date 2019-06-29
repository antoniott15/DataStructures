#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int partition(int, int, int);
void InsertionSort(int[], int, int);
int randPartition(int[], int, int);
void HeapSort(int *, int *);
void introsort(int[], int *, int *, int);

int main()
{
<<<<<<< HEAD
    int a[] = {3, 4, 12, 5, 83, 23, 43, 21, 42, 45, 62, 91};
=======
    int a[] = {3, 4, 12, 5, 83, 23, 43, 21, 42, 45, 62, 91};
>>>>>>> develop
    int n = sizeof(a) / sizeof(a[0]);
    int maxCValues = log(n) * 2;

    introsort(a, a, a + n - 1, maxCValues);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int pIndex = low;
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[high]);
    return pIndex;
}

void InsertionSort(int a[], int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int value = a[i];
        int j = i;
        while (j > low && a[j - 1] > value)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = value;
    }
}

int randPartition(int a[], int low, int high)
{
    int pivotIndex = rand() % (high - low + 1) + low;
    swap(a[pivotIndex], a[high]);
    return partition(a, low, high);
}

void HeapSort(int *begin, int *end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}

void introsort(int a[], int *begin, int *end, int maxCValues)
{
    if ((end - begin) < 16)
    {
        InsertionSort(a, begin - a, end - a);
    }
    else if (maxCValues == 0)
    {
        HeapSort(begin, end + 1);
    }
    else
    {
        int pivot = randPartition(a, begin - a, end - a);
        introsort(a, begin, a + pivot - 1, maxCValues - 1);
        introsort(a, a + pivot + 1, end, maxCValues - 1);
    }
}