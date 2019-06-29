#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename Tr>
class List
{
public:
    typedef typename Tr::T T;
    typedef typename Tr::Operation Operation;

private:
    Node<T> *head;
    Operation cmp;
    int countingElements = 0;

public:
    List() : head(nullptr){};

    bool find(T search, Node<T> **&pointer)
    {
        pointer = &head;
        while (*pointer && cmp(search, (*pointer)->data))
        {

            if (search == (*pointer)->data)
            {
                return true;
            }
            pointer = &((*pointer)->next);
        }
        return false;
    }

    bool insert(T data)
    {
        Node<T> **pointer;
        Node<T> *newNode = new Node<T>(data);

        if (find(data, pointer))
        {
            countingElements++;
            newNode->next = *pointer;
            (*pointer) = newNode;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(T item)
    {
        Node<T> *temp;
        Node<T> **pointer;

        if (find(item, pointer))
        {
            countingElements--;
            temp = *pointer;
            (*pointer) = (*pointer)->next;
            delete temp;
            return true;
        }
        else
        {
            return false;
        }
    }

    int size()
    {
        if (countingElements >= 0)
        {
            return countingElements;
        }
        else
            throw out_of_range("Invalid in size");
    }

    T operator[](int index)
    {
        if ((index < 0) | (index >= countingElements))
            throw out_of_range("Out of range!");
        else
        {
            Node<T> **ptr = &head;
            for (int i = 0; i <= index; i++)
                ptr = &((*ptr)->next);
            return (*ptr)->data;
        }
    }

    ~List()
    {
        if (head)
        {
            head->killSelf();
        }
    }
};

#endif