//
//  main.cpp
//
//  Created by Li-Yan Wang, 2017/11/28
//

#include <iostream>
#include "func.cpp"
#include "bst.h"

using namespace std;

int main()
{
    BST<int> *bst = new BST<int>();

    char choose;
    string input;
    bool flag = true;

    while (flag)
    {
        cout << "=> Choose a function to execute:" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Delete" << endl;
        cout << "3) Minelement" << endl;
        cout << "4) Print tree" << endl;
        cout << "5) Construct tree by massive input" << endl;
        cout << "q) Quit" << endl;
        cin >> choose;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        switch (choose)
        {
        case '1':
            cout << "> Insert element node(q: quit): ";
            getline(cin, input);
            if (input == "q")
                flag = false;
            else
                bst->Insert(stoi(input));
            break;
        case '2':
            cout << "> Delete element node(q: quit): ";
            getline(cin, input);
            if (input == "q") flag = false;
            else
                bst->Delete(stoi(input));
            break;
        case '3':
            cout << "> Threshold value(q: quit): ";
            getline(cin, input);
            if (input == "q") flag = false;
            else
                bst->MinElement(stoi(input));
            break;
        case '4':
            bst->Print();
            break;
        case '5':
            cout << "> Insert a sequence of element node(q: quit): ";
            getline(cin, input);
            if (input == "q") flag = false;
            else
            {
                std::vector<std::string> result = split(input, ' ');
                for (int i = 0; i < result.size(); i++)
                    bst->Insert(stoi(result[i]));
            }
            break;
        case 'q':
            flag = false;
            break;
        default:
            break;
        }

        cout << endl;
    }

    return 0;
}