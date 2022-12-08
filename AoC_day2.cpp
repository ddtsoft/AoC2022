// AoC_day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// ownerproof-2606316-1670074440-250089fee72d
//

// Awnsers 
// part1 10624
// part2 14060

#include <iostream>
#include <sstream>
#include <fstream>
#include "AoC_Day2.h"

using namespace std;

char selection(char player1, char outcome) {
    char result;
    switch (player1) {
    case 'A': 
        if (outcome == 'Y') result='A';
        if (outcome == 'X') result='C';
        if (outcome == 'Z') result='B';
        break;
    case 'B': 
        if (outcome == 'Y') result = 'B';
        if (outcome == 'X') result = 'A';
        if (outcome == 'Z') result = 'C';
        break;
    case'C': 
        if (outcome == 'Y') result = 'C';
        if (outcome == 'X') result = 'B';
        if (outcome == 'Z') result = 'A';
        break;
    }
    return result;
}



void AoC_Day2(void)
{
    //  A   X   ROCK        1
    //  B   Y   PAPER       2
    //  C   Z   SISSORS     3
    // WIN 6 point
    // DRAW 3 points
    // LOSE 0 points
    // Total score = selected score + match outcome

    //  X   ->  LOSE
    //  Y   ->  DRAW
    //  Z   ->  WIN

    int  totalScore = 0;
    fstream datafile;
    datafile.open("day2_data.txt", ios::in);
    if (!datafile) {
        cout << "Datafile not opened error!";
        exit(1);
    }
    else
    {
        char player1, player2;
        int score=0;
        string filedata;
        while (datafile.is_open() && datafile.peek() != EOF) {
            
            getline(datafile, filedata);
            player1 = filedata[0];
            player2 = selection( player1, filedata[filedata.length() - 1] );
            switch (player1) {
            case 'A':
                switch (player2) {
                case 'A': score += 3; break;
                case 'B': score += 6; break;
                case 'C': score += 0; break;
                }
                break;
            case 'B':
                switch (player2) {
                case 'A': score += 0; break;
                case 'B': score += 3; break;
                case 'C': score += 6; break;
                }
                break;
            case 'C':
                switch (player2) {
                case 'A': score += 6; break;
                case 'B': score += 0; break;
                case 'C': score += 3; break;
                }
                break;
            }
            switch (player2) {
            case 'A': score += 1; break;
            case 'B': score += 2; break;
            case 'C': score += 3; break;
            }
            totalScore += score;
            score = 0;
        }
    }
    datafile.close();
    cout << "total score was " << totalScore << endl;
}