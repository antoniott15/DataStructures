#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"
#include <iostream>
using namespace std;
template <typename T>
class BSTree
{
private:
    Node<T> *root;
    unsigned int counter = 0;

public:
    BSTree() : root(nullptr){};

    bool find(T data)
    {
        Node<T> *temp = root;
        if (root == nullptr)
        {
            return false;
        }
        while (temp)
        {
            if (temp->data == data)
            {
                return true;
            }
            else if (temp->data > data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return true;
    }

    bool insert(T data)
    {
        Node<T> *newData = new Node<T>(data);
        if (!root)
        {
            root = newData;
            counter++;
            return true;
        }
        else
        {
            Node<T> *temp = root;
            while (!(temp->data == data))
            {

                if (data < temp->data)
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = newData;
                        counter++;
                        return true;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }

                else if (data > temp->data)
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = newData;
                        counter++;
                        return true;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
            return false;
        }
    }

    bool remove(T data)
    {
        Node<T> *newData = new Node<T>(data);
        Node<T> *temp = root;
        if (!data)
        {
            return false;
        }
        else
        {
            /*if (data < root->data)
            {
                counter--;
                return root->left;
            }
            else if (data > root->data)
            {
                counter--;
                return root->right;
            }
            else
            {*/
            if (root->left == nullptr && root->right == nullptr)
            {

                counter--;
                delete root;
                root = nullptr;
            }
            else if (root->left == nullptr)
            {
                counter--;
                root = root->right;

                delete root;
            }
            else if (root->right == nullptr)
            {
                counter--;
                root = root->left;

                delete root;
            }
            else
            {
                counter--;
                T tempo;
                tempo = temp->data;
                temp->data = temp->right->data;
                temp->right->data = tempo;
                temp = temp->right;
                delete temp;
            }
            // }
            return true;
        }
    }

    unsigned int size()
    {
        cout << counter << endl;
        return counter;
    }

    void printPreorder(Node<T> *nodo)
    {
        cout << nodo->data << " ";
        if (nodo->left)
        {
            print_preorder(nodo->left);
        }

        if (nodo->right)
        {
            print_preorder(nodo->right);
        }
    }
    void traversePreOrder()
    {
        if (!root)
        {
            cout << "Empty" << endl;
        }
        else
        {
            cout << endl
                 << "Preorder: ";
            printPreorder(root);
        }
    }
    void printInorder(Node<T> *nodo)
    {
        if (nodo->left)
        {
            print_inorder(nodo->left);
        }

        cout << nodo->data << " ";

        if (nodo->right)
        {
            print_inorder(nodo->right);
        }
    }
    void traverseInOrder()
    {
        if (!root)
        {
            cout << "Empty" << endl;
        }
        else
        {
            cout << endl
                 << "Inorder: ";
            printInorder(root);
        }
    }
    void printPostorder(Node<T> *nodo)
    {
        if (nodo->left)
        {
            print_postorder(nodo->left);
        }

        if (nodo->right)
        {
            print_postorder(nodo->right);
        }

        cout << nodo->data << " ";
    }

    void traversePostOrder()
    {
        if (!root)
        {
            cout << "Empty" << endl;
        }
        else
        {

            printPostorder(root);
        }
    }

    Iterator<T> begin()
    {
        return Iterator<T>(root);
    }

    Iterator<T> end()
    {
        return Iterator<T>(root);
    }
    /*
    ~BSTree() {
            // TODO
         }*/
};

#endif
