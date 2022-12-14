#include <iostream>
#include <sstream>
#include <fstream>
#include "AoC2022.h"

using namespace std;

void AoC_Day1(void)
{
    int elfNumber = 1, elfcalories = 0;
    int elfMax[3] = { 1,1,1 }, elfMaxcalories[3] = { 0,0,0 };

    fstream datafile;

    datafile.open("Day1_data.txt", ios::in);
    if (!datafile) {
        cout << "Datafile not opened error!";
        exit(1);
    }
    else
    {
        string fileRowContent;
        while (datafile.is_open() && datafile.peek() != EOF) {

            getline(datafile, fileRowContent);
        
                if (fileRowContent.compare("")) {
                elfcalories += stoi(fileRowContent);
            }
            else {

            if ((elfcalories > elfMaxcalories[2]) && (elfcalories < elfMaxcalories[1])) {
                elfMax[2] = elfNumber;
                elfMaxcalories[2] = elfcalories;
            }
            if ((elfcalories > elfMaxcalories[1]) && (elfcalories < elfMaxcalories[0])) {
                elfMax[1] = elfNumber;
                elfMaxcalories[1] = elfcalories;
            }
            if (elfcalories > elfMaxcalories[0]) {

                elfMax[2] = elfMax[1];
                elfMax[1] = elfMax[0];
                elfMaxcalories[2] = elfMaxcalories[1];
                elfMaxcalories[1] = elfMaxcalories[0];

                elfMax[0] = elfNumber;
                elfMaxcalories[0] = elfcalories;
            }

            elfNumber++;
            elfcalories = 0;
            }

        }
    }
    datafile.close();


    cout << "Elf number " << elfMax[0] << " are carrying " << elfMaxcalories[0] << " of calories" << endl;
    cout << "Top three are carring together " << elfMaxcalories[0] + elfMaxcalories[1] + elfMaxcalories[2] << " amount of calories" << endl;
}
