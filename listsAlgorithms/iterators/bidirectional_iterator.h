#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T>
class BidirectionalIterator : public Iterator<T>
{
private:
    Node<T> *curr;

public:
    BidirectionalIterator() : Iterator<T>(){};
    BidirectionalIterator(Node<T> *node) : Iterator<T>(node){};

    BidirectionalIterator<T> operator=(BidirectionalIterator<T> other)
    {
        return curr = other.curr;
    }

    bool operator!=(BidirectionalIterator<T> other)
    {
        return curr != other.curr;
    }

    BidirectionalIterator<T> operator++()
    {
        curr = curr->next;
        return *this;
    }

    BidirectionalIterator<T> operator--()
    {
        curr = curr->prev;
        return *this;
    }

    T operator*()
    {
        return curr->data;
    }
};

#endif