#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort
{
  public:
    SelectSort(void *elements, size_t size) : Sort(elements, size) {}

    void execute(void (*compare)(void *, int, int))
    {
        int *array = (int *)elements;
        for (int i = 0; i < size - 1; i++)
        {
            int Mininum = i;
            for (int j = i + 1; j < size; j++)
            {
                if (array[j] < array[Mininum])
                {
                    Mininum = j;
                }
            }
            compare(elements, i, Mininum);
        }
    }

    inline string name() { return "SelectSort"; }
};

#endif