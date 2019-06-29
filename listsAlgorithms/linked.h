#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include <iostream>
#include <stdexcept>

using namespace std;
template <typename T>
class LinkedList : public List<T>
{
private:
    Node<T> *head;
    Node<T> *tail;
    int countingElements = 0;

public:
    LinkedList() : List<T>() {}

    T front()
    {
        if (head != nullptr)
        {
            return head->data;
        }
        else
        {
            throw out_of_range("Invalid in T front");
        }
    }

    T back()
    {
        if (tail != nullptr)
        {
            return tail->prev->data;
        }
        else
        {
            throw out_of_range("Invalid in T back");
        }
    }

    void push_front(T value)
    {
        Node<T> *temp = new Node<T>;
        temp->data = value;
        if (head)
        {
            temp->next = head;
            temp->prev = head->prev;
            temp->prev->next = temp;
            temp->next->prev = temp;
            head = temp;
        }
        else
        {
            head = temp;
            temp->next = head;
            temp->prev = head;
        }
        countingElements++;
    }

    void push_back(T value)
    {
        Node<T> *temp = new Node<T>;
        temp->data = value;
        if (head)
        {
            temp->next = head;
            temp->prev = head->prev;
            temp->prev->next = temp;
            temp->next->prev = temp;
        }
        else
        {
            head = temp;
            temp->next = head;
            temp->prev = head;
        }
        countingElements++;
    }

    void pop_front()
    {
        if (head)
        {
            Node<T> *temp_head;
            head->next->prev = head->prev;
            head->prev->next = head->next;
            temp_head = head->next;
            delete head;

            if (head == temp_head)
            {
                head = nullptr;
                temp_head = nullptr;
            }
            else
            {
                head = temp_head;
                temp_head = nullptr;
            }
            countingElements--;
        }
    }

    void pop_back()
    {
        if (head)
        {
            if (head == head->prev)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                Node<T> *temp_prev;
                temp_prev = head->prev;

                head->prev->prev->next = head;
                head->prev = head->prev->prev;
                delete temp_prev;
                temp_prev = nullptr;
            }
            countingElements--;
        }
    }

    T operator[](int index)
    {
        Node<T> *temp;
        temp = head;
        for (int i = 0; i < index; ++i)
        {
            if (temp->next == nullptr)
            {
                throw out_of_range("Invalid in T index");
            }
            temp->next = temp;
        }
        return temp->data;
    }

    bool empty()
    {
        return countingElements == 0 ? true : false;
    }

    int size()
    {
        return countingElements;
    }

    void clear()
    {
        while (head != nullptr)
        {
            pop_front();
        }
    }

    void sort()
    {
        if (empty())
        {
            throw out_of_range("Invalid empty in sort");
        }
        else
        {
            Node<T> *i, *j;
            int temp;
            for (i = head; i->next != nullptr; i = i->next)
            {
                for (j = i->next; j != nullptr; j = j->next)
                {
                    if (i->data > j->data)
                    {
                        temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }
        }
    }

    void reverse()
    {
        for (int i = size(); i > 0; --i)
        {
            cout << operator[](i - 1) << "\n";
        }
    }

    string name()
    {
        return "Linked List";
    }

    BidirectionalIterator<T> begin()
    {
        if (empty())
        {
            throw out_of_range("Invalid in BidirectionalIterator begin");
        }
        return head;
    };
    BidirectionalIterator<T> end()
    {
        if (empty())
        {
            throw out_of_range("Invalid int BidirectionalIterator end");
        }
        return tail;
    };

    void merge(LinkedList<T> list)
    {
        if (empty())
        {
            head = list.head;
            tail = list.tail;
        }
        else if (!list.empty())
        {
            tail->next = list.head;
            list.head = head->prev;
            tail = list.tail;
        }
    }
};

#endif