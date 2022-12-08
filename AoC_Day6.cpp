#include <iostream>
#include <sstream>
#include <fstream>
#include "AoC_Day6.h"

// 1655, 2665

using namespace std;

bool stringunique(string teststring);
int findToken(string textRow, int windowSize);

void AoC_Day6(bool part2run)
{

    fstream datafile;
    int seekedValue = 0, row = 0;

    datafile.open("day6_data.txt", ios::in);
    if (!datafile) {
        cout << "Datafile not opened error!";
        exit(1);
    }
    else
    {
        string textRow;
        while (datafile.is_open() && datafile.peek() != EOF) {


            getline(datafile, textRow);
             
            cout << "Part one start token are find after : " << findToken(textRow, 4) << endl;
            cout << "Part two message token are find after: " << findToken(textRow, 14) << "\n\n";
        }
    }
    datafile.close();
    
}

bool stringunique(string teststring) {
   
    for (int p = 0; p < teststring.length()-1; p++) {
        for (int q = p + 1; q < teststring.length(); q++) {      
            if (teststring[p] == teststring[q]) {
                return false;
            }
        }
    }
    return true;
}

int findToken(string textRow, int windowSize)
{
    int  pos;  
    for (pos = windowSize; pos < textRow.length() ; pos++) {
        string window = textRow.substr(pos-windowSize,windowSize );
        if (stringunique(window)) break;
    }
    return pos;
}
