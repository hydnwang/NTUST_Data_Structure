#include <iostream>
#include <vector>
// This is start of the header guard.
#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

vector<vector<char> > matrix(int rowNumber, int colNumber)
{
    int termNumber = rowNumber*colNumber; // total term numbers equal to row * col.
    
    // Store characters with user input.
    char inputChar;
    string inputRow;

    printf("The size of the matrix is: %d\n", termNumber);
    
    // Form matrix of characters by user input.
    // printf("Please input single character from a to z at a time:\n");
    
    vector<vector<char> > vec;  // Declare a vector of vectors to store a matrix.

    for(int i = 0; i < rowNumber; i++)
    {
        // vector<char> vt;  // Temporary vector to insert.

        // for(int j = 0; j < colNumber; j++)
        // {
        //     cin >> inputChar;
        //     cin.ignore(32767, '\n'); // Prevent multiple input characters.
        //     while(isalpha(inputChar)==false) // Allow only alphabet characters.
        //     {
        //         printf("Please input only character from a to z:\n");
        //         cin >> inputChar;
        //         cin.ignore(32767, '\n');
        //     }
        //     printf("The character you input for [%d][%d]: %c\n", i, j, inputChar);
        //     vt.push_back(inputChar);
        // }
        printf("Please input a series of characters from a to z for row[%d] of the matrix:\n", i);
        cin >> inputRow;
        
        while(inputRow.length() < colNumber)
        {
            printf("[Warning] Input string is too short, string must be %d characters long, please try again:\n", colNumber);
            cin >> inputRow;
            cin.clear();
            cin.ignore(32767,'\n');
        }
        bool check_alphabet = false;
        while(!check_alphabet)
        {
            bool valid_string = true;
            for(int s = 0; s < inputRow.length(); s++)
            {
                if(isalpha(inputRow[s])==false)
                {
                    valid_string = false;
                }
            }
            if(valid_string)
            {
                check_alphabet = true;
            }
            else
            {
                printf("[Warning] Input string contains characters out of a to z, please try again:\n");
                cin >> inputRow;
                cin.clear();
                cin.ignore(32767,'\n');
            }
        }
        if(inputRow.length() > colNumber)
        {
            inputRow = inputRow.substr(0, colNumber);
        }
        // Lower the case
        transform(inputRow.begin(), inputRow.end(), inputRow.begin(), ::tolower);

        // cout << "Input string: " << inputRow << endl;
        vector<char> vt(inputRow.begin(), inputRow.end());

        // If you already have a vector and want to add the characters at the end, you need a back inserter:
        // std::copy(str.begin(), str.end(), std::back_inserter(data));

        vec.push_back(vt); // pushing back the temporary vector into the main vector 
        if(i == rowNumber - 1) { printf("\n"); }
    }
    
    printf("The matrix you just input is:\n");
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            if(j == 0) { cout << "| "; }
            cout << vec[i][j] << " ";
            if(j == vec[i].size() - 1) { cout << "|"; }
        }
        cout << endl;
    }
    printf("\n");
    return vec;
}

// This is the end of the header guard
#endif