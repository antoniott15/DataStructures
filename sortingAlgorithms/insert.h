#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort
{
  public:
    InsertSort(void *elements, size_t size) : Sort(elements, size) {}

    void execute(void (*compare)(void *, int, int))
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i; j > 0; j--)
            {
                compare(elements, j - 1, j);
            }
        }
    }

    inline string name() { return "InsertSort"; }
};

#endif