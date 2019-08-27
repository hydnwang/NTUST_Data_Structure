#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include "matrix.h"

// Use std lib.
using namespace std;

// Record path found in matrix accoding to the pattern given by user.
class Path
{
public:
    int row;
    int column;
    char value;
};

bool FindPattern(char* pattern, vector<vector<char> >& vec, Path* path, int row, int col, int pos, int pattSize, char reuse, int pathLength)
{
    bool result = false;
    int vec_row_size = vec.size();
    int vec_col_size = vec[0].size();

    path[pos].row = row;
    path[pos].column = col;
    path[pos].value = pattern[pos];
    pathLength += 1;
    pos += 1;

    if(pos >= pattSize)
    {
        return true;
    }
    
    // should be six cases: try up, right, down, left, move to next char or get the end of the pattern.    
    // try up element:
    if(row > 0 && pattern[pos] == vec[row-1][col])
    {
        bool used = false;
        if(!reuse)
        {
            for(int i = 0; i < pathLength; i++)
            {
                if(path[i].row == row-1 && path[i].column == col)
                {
                    used = true;
                }
            }
        }
        if(!used)
        {
            if(FindPattern(pattern, vec, path, row-1, col, pos, pattSize, reuse, pathLength))
            {
                result = true;
            }
        }        
    }

    // try right element:
    if(col < vec_col_size && pattern[pos] == vec[row][col+1])
    {
        bool used = false;
        if(!reuse)
        {
            for(int i = 0; i < pathLength; i++)
            {
                if(path[i].row == row && path[i].column == col+1)
                {
                    used = true;
                }
            }
        }
        if(!used)
        {
            if(FindPattern(pattern, vec, path, row, col+1, pos, pattSize, reuse, pathLength))
            {
                result = true;
            }
        }        
    }

    // try down element:
    if(row < vec_row_size-1 && pattern[pos] == vec[row+1][col])
    {
        bool used = false;
        if(!reuse)
        {
            for(int i = 0; i < pathLength; i++)
            {
                if(path[i].row == row+1 && path[i].column == col)
                {
                    used = true;
                }
            }
        }
        if(!used)
        {
            if(FindPattern(pattern, vec, path, row+1, col, pos, pattSize, reuse, pathLength))
            {
                result = true;
            }
        }
    }

    // try left element:
    if(col > 0 && pattern[pos] == vec[row][col-1])
    {
        bool used = false;
        if(!reuse)
        {
            for(int i = 0; i < pathLength; i++)
            {
                if(path[i].row == row && path[i].column == col-1)
                {
                    used = true;
                }
            }
        }
        if(!used)
        {
            if(FindPattern(pattern, vec, path, row, col-1, pos, pattSize, reuse, pathLength))
            {
                result = true;
            }
        }
    }
    
    return result;
};

int main()
{

    // Set constant parameters.
    int rowNumber = 10; // row number.
    int colNumber = 10; // column number.

    // Create Matrix.
    vector<vector<char> > vec = matrix(rowNumber, colNumber);

    char patt[10];
    bool reuse = true;
    char reuseInput = 'y';
    bool match = false;
    bool res = false;
    int pathLength = 0;

    printf("Find a pattern by entering no more than characters from a to z:\n");
    cin >> setw(10) >> patt;
    cin.clear();
    cin.ignore(32767,'\n');
    int pattSize = strlen(patt);

    bool all_alpha = false;
    while(!all_alpha)
    {
        all_alpha = true;
        for(int i = 0; i < pattSize; i++)
        {
            if(isalpha(patt[i]) == false)
            {
                printf("The pattern must be characters from a to z:\n");
                cin >> setw(10) >> patt;
                cin.clear();
                cin.ignore(32767,'\n');
                pattSize = strlen(patt);
                all_alpha = false;
            }
        }
    }
    
    // Lower the case
    // for(int i = 0; i < pattSize; i++)
    // {
    //     patt[i] = tolower(patt[i]);
    // }

    Path* path = new Path[pattSize+1];
    
    printf("Reuse characters found in matrix to match your pattern? (y/n, default:y):\n");
    cin >> reuseInput;
    if(reuseInput == 'n'){ reuse = false; }

    for (int i = 0; i < vec.size(); i++)
    {
        // auto it = find(vec[i].begin(), vec[i].end(), patt[0]);
        // if (it != vec[i].end())
        // {
        for(int j = 0; j < vec[i].size(); j++)
        {
            int row = i;
            // int col = distance(vec[i].begin(), it);
            int col = j;
            if(vec[i][j] == patt[0])
            {
                res = FindPattern(patt, vec, path, row, col, 0, pattSize, reuse, pathLength);
            }
            match = true;
            // only need to find the first element matched, so break the for loop.
            if(res == true)
            {
                break;
            }
        }
        // }
        if(res == true)
        {
            break;
        }
    }

    if(!match || !res)
    {
        cout << "No match" << endl;
    }
    else
    {
        std::string output = "";
        for(int p = 0; p < pattSize; p++)
        {
            // output += '(' + path[p].row + ',' + path[p].column + ')';
            if(p == 0) { cout << "Output: "; }
            cout << "(" << path[p].row << "," << path[p].column << ")";
            if(p < pattSize -1) { cout << ","; }
            if(p == pattSize-1) { cout << endl; }
        }
        // cout << output;
    }
    
    delete [] path;

    return 0;
};