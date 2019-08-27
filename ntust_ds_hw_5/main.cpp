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

    cout << "===================================" << endl;
    cout << "* Construct binary tree (q: quit) *" << endl;
    cout << "===================================" << endl;
    cout << "> ";
    getline(cin, input);
    if (input == "q")
        return 0;
    else
    {
        std::vector<std::string> result = split(input, ' ');
        for (int i = 0; i < result.size(); i++)
            bst->Insert(stoi(result[i]));
        cout << endl;
    }

    while (flag)
    {
        cout << "==================================" << endl;
        cout << "*  Choose a function to execute  *" << endl;
        cout << "==================================" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Delete" << endl;
        cout << "3) Minelement" << endl;
        cout << "4) Print tree" << endl;
        // cout << "5) Construct tree by massive input" << endl;
        cout << "5) Avg" << endl;
        cout << "q) Quit" << endl;
        cout << "==================================" << endl;
        cout << "> ";
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
            {
                cout << "> ";
                bst->MinElement(stoi(input));
            }
            break;
        case '4':
            cout << "> Printing..." << endl;
            bst->Print();
            break;
        // case '5':
        //     cout << "> Insert a sequence of element node(q: quit): ";
        //     getline(cin, input);
        //     if (input == "q") flag = false;
        //     else
        //     {
        //         std::vector<std::string> result = split(input, ' ');
        //         for (int i = 0; i < result.size(); i++)
        //             bst->Insert(stoi(result[i]));
        //     }
        //     break;
        case '5':
            cout << "> enter rank range(l,u) (q: quit): ";
            getline(cin, input);
            if (input == "q")
                flag = false;
            else
            {
                std::vector<std::string> result = split(input, ',');
                if(result.size() >= 2)
                {
                    int l, u;
                    for (int i = 0; i < 2; i++)
                    {
                        if (i == 0)
                            l = stoi(result[i]);
                        else
                            u = stoi(result[i]);
                    }
                    if(l > u)
                    {
                        cout << "[warning] input range is wrong, please try again";
                        cout << endl << endl;
                        continue;
                    }
                    cout << "> ";
                    bst->Avg(l, u);
                }
                else
                {
                    cout << "[warning] not enough argument(s), please try again";
                    cout << endl << endl;
                    continue;
                }
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