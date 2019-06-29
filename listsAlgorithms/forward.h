#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"
#include <iostream>
template <typename T>
class ForwardList : public List<T>
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    ForwardList() : List<T>() {}

    T front()
    {
        if (head != nullptr)
        {
            return head->data;
        }
        else
        {
            throw out_of_range("List empty, no front exists.");
        }
    }

    T back()
    {
        if (tail != nullptr)
        {
            return tail->data;
        }
        else
        {
            throw out_of_range("List empty, no tail exists.");
        }
    }

    void push_front(T value)
    {
        Node<T> *NewData = new Node<T>;
        if (empty())
        {
            NewData->data = value;
            NewData->next = nullptr;
            head = NewData;
            tail = NewData;
        }
        else
        {
            NewData->data = value;
            NewData->next = head;
            head = NewData;
        }
        countElements++;
    }

    void push_back(T value)
    {
        Node<T> *NewData = new Node<T>;
        NewData->data = value;
        NewData->next = nullptr;
        NewData->prev = nullptr;

        if (head == nullptr)
        {
            head = NewData;
            if (tail == nullptr)
            {
                tail = head;
            }
        }
        else
            tail->prev = NewData;
    }

    void pop_front()
    {

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node<T> *temp = head->next;
            delete head;
            head = nullptr;
            head = temp;
        }
        else
        {
            Node<T> *temp = head->next;
            delete head;
            head = nullptr;
            head = temp;
        }
        countElements--;
    }

    void pop_back()
    {
        if (empty())
        {
            cout << "empty list" << endl;
        }
        else
        {
            Node<T> *nodeToDelete = tail;
            tail = tail->prev;

            if (tail)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }

            delete nodeToDelete;
        }
    }

    T operator[](int index)
    {
        Node<T> *temp;
        temp = head;
        for (int i = 0; i <= index; i++)
        {
            throw out_of_range("Index out of range");
        }
        Node<T> *curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr->data;
    }

    bool empty()
    {
        return (size() == 0 ? true : false);
    }

    int size()
    {
        Node<T> *temp;
        temp = head;
        int count;
        if (empty())
        {
            count = 0;
            while (temp->next != nullptr)
            {
                count++;
            }
        }
        return count;
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
            cout << "list empty";
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
        return "Forward List";
    }

    ForwardIterator<T> begin()
    {
        if (empty())
        {
            cout << "list empyty";
        }
        return head;
    };

    ForwardIterator<T> end()
    {
        if (empty())
        {
            cout << "list empyty";
        }
        return tail;
    };

    void merge(ForwardList<T> list)
    {
        if (empty())
        {
            head = list.head;
            tail = list.tail;
        }
        return head;
    };

    ForwardIterator<T> end()
    {
        if (empty())
        {
            tail->next = list.head;
            tail = list.tail;
        }
        return tail;
    };

    void merge(ForwardList<T> list)
    {
        for (int i = 0; i < list.nodes; i++)
            push_back(list[i]);
    }
};

#endif