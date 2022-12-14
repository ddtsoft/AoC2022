#include <iostream>
#include <sstream>
#include <fstream>

#include "AoC2022.h"


// part 1 13760
// part 2 RFKZCPEF

using namespace std;


void AoC_Day10(void)
{

    int  signalSum = 0;
    string crt[6][40];
    fstream datafile;

    datafile.open("day10_data.txt", ios::in);
    if (!datafile) {
        cout << "Datafile not opened error!";
        exit(1);
    }
    else
    {
        unsigned long clock = 1;
        int xreg = 1, loop = 0, stopClock = 0;
        int row = 0, col = 0;
        string textRow;
        while (datafile.is_open() && datafile.peek() != EOF) {
            getline(datafile, textRow);
            if (textRow[0] != 'n') {
                loop = 1;
                stopClock = 1;
            }
            else {
                loop = 0;
            }
            do {
                switch (clock) {
                    case 20: 
                        signalSum += (20 * xreg);
                        break;
                    case 60: 
                        signalSum += (60 * xreg);
                        break;
                    case 100: 
                        signalSum += (100 * xreg);
                        break;
                    case 140: 
                        signalSum += (140 * xreg);
                        break;
                    case 180: 
                        signalSum += (180 * xreg);
                        break;
                    case 220: 
                        signalSum += (220 * xreg);
                        break;
                }
                crt[row][col] = ' ';
                if (col == xreg - 1) {
                    crt[row][col] = 219;
                }
                if (col == xreg) {
                    crt[row][col] = 219;
                }
                if (col == xreg+1) {
                    crt[row][col] = 219;
                }
                if (loop && stopClock == 0 ) {
                    xreg += stoi(textRow.substr(5));
                    loop = 0;
                }
                clock++;
                if (col < 39) {
                    col++;
                }
                else {
                    col = 0;
                    row++;
                }
                if (stopClock > 0) { stopClock--; }
            } while (loop);
        }
    }
    datafile.close();
    cout << endl << signalSum << endl;
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 39; c++) {
            cout << crt[r][c];
        }
        cout << endl;
    }
}


