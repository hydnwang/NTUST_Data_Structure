#ifndef BST_H
#define BST_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

template <class T>
class BST; // forward declaration

template <class T>
class Node
{
    friend class BST<T>;

  public:
    Node(T v) : value(v), leftSize(1), leftChild(0), rightChild(0){};
    Node(T v, Node<T> *left, Node<T> *right)
        : value(v), leftSize(1), leftChild(left), rightChild(right){};

  private:
    T value;
    T leftSize;
    Node<T> *leftChild;
    Node<T> *rightChild;
};

template <class T>
class BST
{
  public:
    void Print()
    {
        int *rank = new int;
        if (root)
        {
            cout << "|----------------------------|" << endl;
            cout << left << setw(9) << "| Element ";
            cout << left << setw(12) << "| Left Size ";
            cout << left << setw(8) << "| Rank |";
            cout << endl;
            cout << "|" << right << setw(8) << "---------";
            cout << "|" << right << setw(10) << "-----------";
            cout << "|" << right << setw(5) << "------" << "|";
            cout << endl;
            print(root, rank);
            cout << "|" << right << setw(8) << "---------";
            cout << "|" << right << setw(10) << "-----------";
            cout << "|" << right << setw(5) << "------" << "|";
            cout << endl;
        }
        else
        {
            cout << "> Empty tree";
            cout << endl;
        }
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
                cout << "> Element already existed(" << value << ")" << endl;
        }
        return;
    }

    void Delete(T value)
    {
        if (!root)
        { 
            cout << "> Empty tree" << endl; 
            return; 
        }
        int result = deleteNode(NULL, root, value);

        if (!result)
            cout << "> No match(" << value << ")" << endl;
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

    void Avg(int l, int u)
    {
        int *count = new int;
        int *sum = new int;
        int range = u - l + 1;
        int foundElement[range];
        sumByRank(root, l, u, count, sum, foundElement);
        
        int result = *sum/range;
        for (int i = 0; i < range; i++)
        {
            if (i == 0) cout << "( ";
            cout << foundElement[i];
            if(i < range - 1)
                cout << " + ";
            else
                cout << " ) ";
        }
        cout << "/ " << range << " = " << result << endl;
    }

  private:
    void print(Node<T> *current, int *rank)
    {
        if (!current)
            return;
        print(current->leftChild, rank);
        *rank += 1;
        cout << "|" << right << setw(8) << current->value;
        cout << " |" << right << setw(10) << current->leftSize;
        cout << " |" << right << setw(5) << *rank << " |";
        cout << endl;
        print(current->rightChild, rank);
    };

    int insert(Node<T> *current, const T value)
    {
        if (value < current->value)
        {
            current->leftSize++;
            if (current->leftChild)
            {
                return insert(current->leftChild, value);
            }
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

        int left_result = deleteNode(current, current->leftChild, value);
        int right_result = deleteNode(current, current->rightChild, value);

        if(left_result != 0)
            current->leftSize--;
        
        return left_result || right_result;
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

    void sumByRank(Node<T> *current, const int l, const int u, int *count, int *sum, int foundElement[])
    {
        if(current)
        {
            sumByRank(current->leftChild, l, u, count, sum, foundElement);

            *count += 1;
            if(*count >= l && *count <= u)
            {
                *sum += current->value;
                foundElement[*count-l] = current->value;
            }
            sumByRank(current->rightChild, l, u, count, sum, foundElement);
        }
    }

  private:
    Node<T> *root;
};

#endif
