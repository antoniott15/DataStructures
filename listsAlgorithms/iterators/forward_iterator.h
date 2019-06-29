#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../iterator.h"

template <typename T>
class ForwardIterator : public Iterator<T>
{
private:
    Node<T> *curr;

public:
    ForwardIterator() : Iterator<T>(){};
    ForwardIterator(Node<T> *node) : Iterator<T>(node){};

    ForwardIterator<T> operator=(ForwardIterator<T> other)
    {
        return curr = other.curr;
    }

    bool operator!=(ForwardIterator<T> other)
    {
        return curr != other.curr;
    }

    ForwardIterator<T> operator++()
    {
        curr = curr->next;
        return *this;
    }

    T operator*()
    {
        return curr->data;
    }
};

#endif