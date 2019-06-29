#include "tester.h"

void integersBubble(void *elements, int first, int second)
{
    int *array = (int *)elements;
    if (array[first] > array[second])
    {
        swap(array[first], array[second]);
    }
}

void integersInsert(void *elements, int first, int second)
{
    int *array = (int *)elements;
    if (array[first] > array[second])
    {
        swap(array[first], array[second]);
    }
}

void integersSelect(void *elements, int first, int second)
{
    int *array = (int *)elements;
    if (second != first)
    {
        swap(array[first], array[second]);
    }
}

void integerShell(void *elements, int first, int second)
{
    int *array = (int *)elements;
}

void integerQuick(void *elements, int first, int second)
{
    int *array = (int *)elements;
}
Sort *Tester::getSort(Algorithm sort, void *array, size_t size)
{
    switch (sort)
    {
    case bubblesort:
        return new BubbleSort(array, size);
    case insertsort:
        return new InsertSort(array, size);
    case selectsort:
        return new SelectSort(array, size);
    case shellsort:
        return new ShellSort(array, size); /*
    case quicksort:
        return new QuickSort(array, size); 
    case mergesort:
        return new MergeSort(array, size);*/
    default:
        throw invalid_argument("Not a valid sort");
    }
}

fptr Tester::getCompare(Algorithm sort)
{
    switch (sort)
    {
    case bubblesort:
        return &integersBubble;
    case insertsort:
        return &integersInsert;
    case selectsort:
        return &integersSelect;
    case shellsort:
        return &integerShell;
        /* case quicksort:
        return &integerQuick;*/
    default:
        throw invalid_argument("Not a valid comparer");
    }
}

void Tester::integerSorts(int *array, size_t size)
{
    Sort *sort;
    int temp[size];

    Algorithm algorithm[] = {bubblesort, insertsort, selectsort, shellsort /*, quicksort ,mergesort */};
    size_t numberOfAlgorithms = sizeof(algorithm) / sizeof(algorithm[0]);

    for (int i = 0; i < numberOfAlgorithms; i++)
    {
        copy(array, array + size, temp);
        sort = getSort(algorithm[i], temp, size);
        sort->execute(getCompare(algorithm[i]));
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}
