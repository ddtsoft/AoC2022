// awsers 
// part1 7917
// part2 2585


#include <iostream>
#include <sstream>
#include <fstream>
#include "AoC2022.h"

using namespace std;
int part1(void);
int part2(void);

void AoC_Day3(void)
{

    cout << " Total priority in part one are : " << part1() << endl ;
    cout << " Total priority in part two are : " << part2() << endl;
}

int part2() {

    fstream datafile;
    string textRow;
    int totalPriority = 0;

    datafile.open("day3_data.txt", ios::in);
    if (!datafile) {
        cout << "Datafile not opened error!";
        exit(1);
    }
    else
    {
        while (datafile.is_open() && datafile.peek() != EOF) {
            char* textRows[3]{};
            int row = 0, pos = 0;
            int stopPos;

            for (row = 0; row < 3; row++) {
                getline(datafile, textRow);
                stopPos = textRow.length();
                textRows[row] = (char*)malloc(stopPos);

                for (pos = 0; pos < stopPos; pos++) {
                    textRows[row][pos] = textRow[pos];
                }
                textRows[row][stopPos] = '\0';
            }
            pos = 0;
            stopPos = strlen(textRows[0]);
            while (pos < stopPos) {
                if (strchr(textRows[1], textRows[0][pos]) != 0) {
                    if (strchr(textRows[2], textRows[0][pos]) != 0)
                        break;
                }
                pos++;
            }
            //char commonLetter = textRows[0][pos];
            char* foundLetter = strchr(textRows[2], textRows[0][pos]);

            int value = foundLetter[0];
            if (value > 64 && value < 91) {
                value = value - 64 + 26;
                totalPriority += value;
            }
            else
            {
                value -= 96;
                totalPriority += value;
            }
        }
    }
    datafile.close();
    return totalPriority;
}

int part1() {

    fstream datafile;
    string textRow;
    int totalPriority = 0;

    datafile.open("day3_data.txt", ios::in);
    if (!datafile) {
        cout << "Datafile not opened error!";
        exit(1);
    }
    else
    {
        while (datafile.is_open() && datafile.peek() != EOF) {
            string textRow;
            getline(datafile, textRow);
            int pos = 0, stopPos = textRow.length() / 2;
            char* compart1, * compart2;
            compart1 = (char*)malloc(stopPos);
            compart2 = (char*)malloc(stopPos);
            for (int post = 0; post < stopPos; post++) {
                compart1[post] = textRow[post];
                compart2[post] = textRow[post + stopPos];
            }
            compart1[stopPos] = '\0';
            compart2[stopPos] = '\0';
            while (pos < stopPos) {
                if (strchr(compart1, compart2[pos]) != 0) { break; }
                pos++;
            }
            char foundLetter = compart2[pos];
            int value = foundLetter;
            if (value > 64 && value < 91) {
                value = value - 64 + 26;
                totalPriority += value;
            }
            else
            {
                value -= 96;
                totalPriority += value;
            }
        }
    }
    datafile.close();
    return totalPriority;
}
