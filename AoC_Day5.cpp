#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>

#include "AoC2022.h"


// part one VGBBJCRMN

using namespace std;


void AoC_Day5(bool part2run)
{

    fstream datafile;
    int  row = 0, colums = 0;
    
    vector<char*> packs;
    
    vector<stack<char>> boxStacks;
    
    stack<char> scoope;

    datafile.open("day5_data.txt", ios::in);
    if (!datafile) {
        cout << "Datafile not opened error!";
        exit(1);
    }
    else
    {
        string textRow;
        while (datafile.is_open() && datafile.peek() != EOF) {

            getline(datafile, textRow);
            if (textRow[0] != 'm') {
                if (textRow.length() > 0 && textRow[1] != '1') {
                    colums = 1 + (textRow.length() + 1) / 4;
                    // current row of data to setup and clean
                    char* rowData = (char*) malloc(sizeof(char) * colums);
                    int i;
                    for (i = 0; i < colums; i++) {
                        rowData[i] = '_';
                    }
                    rowData[i - 1] = NULL;
                    
                    for (int r = 0; r < textRow.length() - 2; r++) {
                        if ((textRow[r] == '[') && (textRow[r + 2] == ']')) {
                    //         cout << textRow[r + 1] << " in stack " << (r + 1) / 4 << endl;
                            rowData[(r + 1) / 4] = textRow[r + 1];
                        }
                    }
                    packs.push_back(rowData);
                    row++;
                }
            
            // Rebulid the matrix to stacks of colums amount and fill from bottom of packs[row][col]
                // resize the vetor of stacks to size of colums -1  
                if (textRow.length() > 0 && textRow[1] == '1') {
                    boxStacks.resize(colums - 1);

                    for (int r = row; r > 0; r--) {
                        for (int c = 0; c < colums; c++) {
                            if (packs[r - 1][c] != '_') {
                                if (c < (colums - 1) ) {
                                    boxStacks[c].push(packs[r - 1][c]);
                                   // cout << "move " << boxStacks[c].top() << " to stack number " << c << endl;
                                }
                            }
                        }
                    }
                    packs.clear();
                }
                

                // all data has been read of start settings transfer it to to vector of stacks 
                // begining from bottom and work up to top row
                
                
            
            }
            else {
                
                // Read move instructions
                int amount =  stoi( textRow.substr(5,2) ) ; 
                int fromStack = stoi(textRow.substr(12,2) ) -1;
                int toStack =  textRow[textRow.length()-1] - 49;
                cout << "move " << amount << " from " << fromStack << " to " << toStack << endl;
                if (!part2run) {
                    while (amount-- >0) {
                        boxStacks[toStack].push(boxStacks[fromStack].top());
                        boxStacks[fromStack].pop();
                    }
                }
                else {
                    if (amount == 1) {
                        boxStacks[toStack].push(boxStacks[fromStack].top());
                        boxStacks[fromStack].pop();
                    }
                    else {
                        while (amount-- >0) {
                            scoope.push(boxStacks[fromStack].top());
                            boxStacks[fromStack].pop();
                        }
                        while (!scoope.empty()) {
                            boxStacks[toStack].push(scoope.top());
                            scoope.pop();
                        }
                    }
                }
            }
        }
    }
    datafile.close();
    for (int c = 0; c < colums-1; c++) {
        cout << boxStacks[c].top();
    }
    cout << endl;
}


