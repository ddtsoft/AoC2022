#include <iostream>
#include <sstream>
#include <fstream>
#include "AoC_Day4.h"

using namespace std;


int execute_part1(string textRow);
int execute_part2(string textRow);
void splitGroups(int* min1, int* min2, int* max1, int* max2, string textRow);


void AoC_Day4(bool part2run)
{

    fstream datafile;
    int seekedValue = 0,row=0;

    //bool part1=false;

    datafile.open("day4_data.txt", ios::in);
    if (!datafile) {
        cout << "Datafile not opened error!";
        exit(1);
    }
    else
    {
        string textRow;
        while (datafile.is_open() && datafile.peek() != EOF) {
            
            getline(datafile, textRow);
            if (part2run) {
                seekedValue += execute_part1(textRow);
            }
            else {
                seekedValue += execute_part2(textRow);
            }
         }
    }
    datafile.close();
    
    if (part2run) {
        cout << "in Part one Seeked value are " << seekedValue << endl;
    }
    else
    {
        cout << "in Part tw2 Seeked value are " << seekedValue << endl;
    }
}

void splitGroups(int* min1, int* min2, int* max1, int* max2, string textRow) {
    size_t location;
    char groupDivider = ',', rangeDivider = '-';

    location = textRow.find(groupDivider);
    string group1 = textRow.substr(0, location);
    string group2 = textRow.substr(location + 1);

    location = group1.find(rangeDivider);
    *min1 = stoi(group1.substr(0, location));
    *max1 = stoi(group1.substr(location + 1));

    location = group2.find(rangeDivider);
    *min2 = stoi(group2.substr(0, location));
    *max2 = stoi(group2.substr(location + 1));

}

int execute_part1(string textRow) {

    // 507
    int min1, min2, max1, max2,result =0;
    
    splitGroups( &min1, &min2, &max1, &max2, textRow);
    
    if ((max1 >= max2) && (min1 <= min2))  result= 1;
    if ((max1 <= max2) && (min1 >= min2)) result = 1;
    return result;
}

int execute_part2(string textRow) {
    //897
    int min1, min2, max1, max2, result = 1;

    splitGroups(&min1, &min2, &max1, &max2, textRow);
 
    if (max1 < min2) result = 0;
    if (min1 > max2) result = 0;

    return result;
}

