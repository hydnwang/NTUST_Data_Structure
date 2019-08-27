//
//  main.cpp
//
//  Created by Li-Yan Wang, 2017/11/21.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "func.cpp"
#include "poly.h"

using namespace std;

int main()
{
    Poly *poly = new Poly();
    int coef, ex, ey, ez;
    string polyno, p;
    
    cout << "Construct a polynomial using 4 digits separated by single space: " << endl;
    while(1)
    {
        cout << "> Enter coefficient and exponents (coef, ex, ey, ez), or q to quit: ";
        getline(cin, polyno);

        const int ARG_NUM = 4;
        std::vector<std::string> result = split(polyno, ' ');

        if(polyno == "q") { break; }
        else if(result.size() == ARG_NUM)
        {
            for(int i = 0; i < ARG_NUM; i++)
            {
                switch(i)
                {
                    case 0:
                        coef = stoi(result[i]);
                        break;
                    case 1:
                        ex = stoi(result[i]);
                        break;
                    case 2:
                        ey = stoi(result[i]);
                        break;
                    case 3:
                        ez = stoi(result[i]);
                        break;
                }
            }
            poly->insertNode(coef, ex, ey, ez);
        }
        else
        {
            cout << "wrong number of argument." << endl;
        }
    }

    // Print polynomials
    // p = poly->printPoly();
    // cout << p << endl;

    char choose;
    while(1)
    {
        cout << "=> Choose a function to execute:" << endl;
        cout << "1) retCoeff(ex, ey, ez) => Return a coefficent" << endl;
        cout << "2) Mulf(ex, ey, ez) => Multiply polynomial by exponents" << endl;
        cout << "q) Quit" << endl;
        cin >> choose;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if (choose == '1')
        {
            int ex, ey, ez, coef;
            cout << "> Enter exponents (ex, ey, ez), or q to quit: ";

            getline(cin, polyno);

            const int RET_ARG_NUM = 3;
            std::vector<std::string> result = split(polyno, ' ');

            if (polyno == "q")
            {
                break;
            }
            else if (result.size() == RET_ARG_NUM)
            {
                for (int i = 0; i < RET_ARG_NUM; i++)
                {
                    switch (i)
                    {
                    case 0:
                        ex = stoi(result[i]);
                        break;
                    case 1:
                        ey = stoi(result[i]);
                        break;
                    case 2:
                        ez = stoi(result[i]);
                        break;
                    }
                }
                coef = poly->retCoeff(ex, ey, ez);
                if (coef != -1)
                    cout << "retCoeff(" << ex << ", " << ey << ", " << ez << "): " << coef << endl;
                else
                    cout << "nothing found." << endl;
            }
            else
            {
                cout << "wrong argument number." << endl;
            }
        }
        else if (choose == '2')
        {
            int ex, ey, ez, coef;
            cout << "> Enter exponents (ex, ey, ez), or q to quit: ";

            getline(cin, polyno);

            const int MUL_ARG_NUM = 3;
            std::vector<std::string> result = split(polyno, ' ');

            if (polyno == "q")
            {
                break;
            }
            else if (result.size() == MUL_ARG_NUM)
            {
                for (int i = 0; i < MUL_ARG_NUM; i++)
                {
                    switch (i)
                    {
                    case 0:
                        ex = stoi(result[i]);
                        break;
                    case 1:
                        ey = stoi(result[i]);
                        break;
                    case 2:
                        ez = stoi(result[i]);
                        break;
                    }
                }
                poly->Mulf(ex, ey, ez);
            }
            else
            {
                cout << "wrong argument number." << endl;
            }
        }
        else if (choose == 'q')
            break;
        else
            continue;
        cout << endl;
    }
    return 0;
}
