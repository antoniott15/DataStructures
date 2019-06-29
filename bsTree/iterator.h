#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator
{
private:
    Node<T> *current;

public:
    Iterator()
    {
        current = nullptr;
    };

    Iterator(Node<T> *node)
    {
        current = node;
    }

    Iterator<T> operator=(Iterator<T> other)
    {
        if (current)
        {
            current = other.current;
        }

        return other;
    }

    bool operator!=(Iterator<T> other)
    {
        Iterator<T> current = new Iterator<T>;
        return current != other.current;
    }
    /*
    Iterator<T> *operator++()
    {
    }
   
    Iterator<T> operator--()
    {
        // TODO
    }
*/
    T operator*()
    {
        return current->data;
    }
};

#endif
