#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

template <class T>
class BST; // forward declaration

template <class T>
class Node
{
    friend class BST<T>;

  public:
    Node(T v) : value(v), leftChild(0), rightChild(0){};
    Node(T v, Node<T> *left, Node<T> *right)
        : value(v), leftChild(left), rightChild(right){};

  private:
    T value;
    Node<T> *leftChild;
    Node<T> *rightChild;
};

template <class T>
class BST
{
  public:
    void Print()
    {
        if (root)
            print(root);
        else
            cout << "empty tree";
        cout << endl;
    }

    void Insert(T value)
    {
        int result;
        if (!root)
            root = new Node<T>(value);
        else
        {
            result = insert(root, value);
            if (!result)
                cout << "element already existed(" << value << ")" << endl;
        }
        return;
    }

    void Delete(T value)
    {
        if (!root)
        { 
            cout << "empty tree" << endl; 
            return; 
        }
        int result = deleteNode(NULL, root, value);
        if (!result)
            cout << "no match(" << value << ")" << endl;
    }

    void MinElement(T threshold)
    {
        int *found = new int;
        int *sum = new int;
        bool *found_flag = new bool();

        min_element(root, threshold, found, found_flag, sum);

        if(*found_flag)
            cout << "Minimum element: " << *found << endl;
        else
            cout << "no such element" << endl;
    }

  private:
    void print(Node<T> *current)
    {
        if (!current)
            return;
        print(current->leftChild);
        cout << current->value << ' ';
        print(current->rightChild);
    };

    int insert(Node<T> *current, const T value)
    {
        if (value < current->value)
        {
            if (current->leftChild)
                return insert(current->leftChild, value);
            else
            {
                current->leftChild = new Node<T>(value);
                return 1;
            }
        }
        else if (value > current->value)
        {
            if (current->rightChild)
                return insert(current->rightChild, value);
            else
            {
                current->rightChild = new Node<T>(value);
                return 1;
            }
        }
        else // element existed.
            return 0;
    };

    int deleteNode(Node<T> *parent, Node<T> *current, T value)
    {
        if (!current) return 0;
        if (current->value == value)
        {
            // case 1: leaf node
            // case 2: node with only one leaf node
            if (current->leftChild == NULL || current->rightChild == NULL)
            {
                // determine which child exits.
                Node<T> *child;
                if (current->leftChild)
                    child = current->leftChild;
                else
                    child = current->rightChild;
                
                // detemine which child of current node's parent it is
                if (parent)
                {
                    if (parent->leftChild == current)
                        parent->leftChild = child;
                    else
                        parent->rightChild = child;
                }
                else
                    root = child;

                delete current;
            }
            else // case 3: node with both children exiting, replace node with min node from right.
            {
                // find minimum node from node's right subtree.
                Node<T> *next = current->rightChild;
                while (next->leftChild)
                    next = next->leftChild;

                T temp = current->value;
                current->value = next->value;
                next->value = temp;
                return deleteNode(current, current->rightChild, temp);
                
                delete next;
            }
            return 1;
        }
        return deleteNode(current, current->leftChild, value) ||
               deleteNode(current, current->rightChild, value);
    };

    void min_element(Node<T> *current, const int threshold, int *found, bool *found_flag, int *sum)
    {
        if (current)
        {
            min_element(current->leftChild, threshold, found, found_flag, sum);

            // cout << "sum before add: " << *sum << endl;
            *sum += current->value;
            // cout << "current value: " << current->value << endl;
            // cout << "sum: " << *sum << endl;
            if (*found == 0 && *sum >= threshold)
            {
                *found = current->value;
                *found_flag = true;
            }

            min_element(current->rightChild, threshold, found, found_flag, sum);
        }
    }

  private:
    Node<T> *root;
};

#endif
