/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

void updateValue(int &value, double after, int maxValue)
{
    int ceiledValue = ceil(after); // Round up
    if (ceiledValue > maxValue)
        value = maxValue;
    else if (ceiledValue < 0)
        value = 0;
    else
        value = ceiledValue;
}

///////////////////////////////////////////////////////////// 1
int firstMeet(int &EXP1, int &EXP2, const int &E1)
{
    if (E1 < 0 || E1 > 999)
        return -999;

    updateValue(EXP1, EXP1, 900);
    updateValue(EXP2, EXP2, 900);

    // Stage 1
    if (E1 >= 0 && E1 <= 399)
    {
        if (E1 >= 0 && E1 <= 49)
            updateValue(EXP2, EXP2 + 25, 900); // 1
        else if (E1 >= 50 && E1 <= 99)
            updateValue(EXP2, EXP2 + 50, 900); // 2
        else if (E1 >= 100 && E1 <= 149)
            updateValue(EXP2, EXP2 + 85, 900); // 3
        else if (E1 >= 150 && E1 <= 199)
            updateValue(EXP2, EXP2 + 25 + 50, 900);
        else if (E1 >= 200 && E1 <= 249)
            updateValue(EXP2, EXP2 + 25 + 85, 900);
        else if (E1 >= 250 && E1 <= 299)
            updateValue(EXP2, EXP2 + 50 + 85, 900);
        else if (E1 >= 300 && E1 <= 399)
            updateValue(EXP2, EXP2 + 25 + 50 + 85, 900);

        if (E1 % 2 == 1)
            updateValue(EXP1, EXP1 + E1 / 10.0, 900);
        else
            updateValue(EXP1, EXP1 - E1 / 5.0, 900);
    }

    // Stage 2
    if (E1 >= 400 && E1 <= 999)
    {
        if (E1 >= 400 && E1 <= 499)
            updateValue(EXP2, EXP2 + (E1 / 7.0 + 9), 900); // 1
        else if (E1 >= 500 && E1 <= 599)
            updateValue(EXP2, EXP2 + (E1 / 9.0 + 11), 900); // 2
        else if (E1 >= 600 && E1 <= 699)
            updateValue(EXP2, EXP2 + (E1 / 5.0 + 6), 900); // 3
        else if (E1 >= 700 && E1 <= 799)
        {
            updateValue(EXP2, EXP2 + (E1 / 7.0 + 9), 900);
            if (EXP2 > 200)
                updateValue(EXP2, EXP2 + (E1 / 9.0 + 11), 900);
        }
        else if (E1 >= 800 && E1 <= 999)
        {
            updateValue(EXP2, EXP2 + (E1 / 7.0 + 9) + (E1 / 9.0 + 11), 900);
            if (EXP2 > 600)
            {
                updateValue(EXP2, EXP2 + (E1 / 5.0 + 6), 900);
                updateValue(EXP2, EXP2 + EXP2 * 0.15, 900);
            }
        }
        updateValue(EXP1, EXP1 - E1 * 0.1, 900);
    }

    return EXP1 + EXP2;
}

///////////////////////////////////////////////////////////// 2
int investigateScene(int &EXP1, int &EXP2, int &HP2, int &M2, const int &E2)
{
    if (E2 < 0 || E2 > 999)
        return -999;

    updateValue(EXP1, EXP1, 900);
    updateValue(EXP2, EXP2, 900);
    updateValue(HP2, HP2, 999);
    updateValue(M2, M2, 2000);

    // Stage 1
    if (E2 >= 0 && E2 <= 299)
    {
        updateValue(EXP2, EXP2 + E2 / 9.0 + 10, 900);
        updateValue(EXP1, EXP1 + (E2 / 9.0 + 10) / 3.0, 900);
    }
    else if (E2 >= 300 && E2 <= 499)
    {
        updateValue(EXP2, EXP2 + E2 / 9.0 + 10, 900);
        updateValue(EXP1, EXP1 + (E2 / 9.0 + 10) / 3.0, 900);

        updateValue(EXP2, EXP2 + E2 * 0.35, 900);
        updateValue(EXP1, EXP1 + (E2 * 0.35) / 3.0, 900);
    }
    else if (E2 >= 500 && E2 <= 999)
    {
        updateValue(EXP2, EXP2 + E2 / 9.0 + 10, 900);
        updateValue(EXP1, EXP1 + (E2 / 9.0 + 10) / 3.0, 900);

        updateValue(EXP2, EXP2 + E2 * 0.35, 900);
        updateValue(EXP1, EXP1 + (E2 * 0.35) / 3.0, 900);

        updateValue(EXP2, EXP2 + (E2 / 9.0 + 10 + E2 * 0.35) * 0.17, 900);
        updateValue(EXP1, EXP1 + (E2 / 9.0 + 10 + E2 * 0.35) * 0.17 / 3.0, 900);
    }

    // Stage 2
    updateValue(HP2, HP2 - (pow(E2, 3) / pow(2, 23)), 999);
    if (E2 % 2 == 0)
        updateValue(M2, M2 + pow(E2, 2) / 50.0, 2000);

    return EXP2 + HP2 + M2 + EXP1;
}
///////////////////////////////////////////////////////////// 3
int traceLuggage(int &HP1, int &EXP1, int &M1, const int &E3)
{
    if (E3 < 0 || E3 > 999)
        return -999;

    updateValue(HP1, HP1, 999);
    updateValue(EXP1, EXP1, 900);
    updateValue(M1, M1, 2000);

    // Road 1 ///////////////////////////////////////
    int n1 = 9;
    int P1[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    bool isFound1 = false;

    for (int i = 0; i < n1; i++)
    {
        P1[i] = (P1[i] + E3) % 26 + 65;

        if (P1[i] == 80)
        {
            isFound1 = true;
            updateValue(HP1, HP1 - 80 * (i + 1) * 2, 999);
            updateValue(EXP1, EXP1 + ((1000 - 80 * (i + 1)) % 101), 900);
            updateValue(M1, M1 - (i + 1) * E3 / 9.0, 2000);
            break;
        }
    }

    if (!isFound1)
        updateValue(M1, M1 - n1 * n1 * E3 / 9.0, 2000);

    // Road 2 ///////////////////////////////////////
    int n2 = 7;
    int P2[] = {2, 3, 5, 7, 11, 13, 17};
    int s = 0;
    bool isFound2 = false;

    for (int i = 0; i < n2; i++)
    {
        P2[i] = (P2[i] + E3) % 26;
        s += P2[i];
    }
    int m = ceil(s / (double)n2);
    for (int i = 0; i < n2; i++)
    {
        P2[i] = (P2[i] + s + m) % 26 + 65;

        if (P2[i] == 80)
        {
            isFound2 = true;
            updateValue(HP1, HP1 - 80 * (i + 1) * 2, 999);
            updateValue(EXP1, EXP1 + ((1000 - 80 * (i + 1)) % 101), 900);
            updateValue(M1, M1 - (i + 1) * E3 / 9.0, 2000);
            break;
        }
    }

    if (!isFound2)
        updateValue(M1, M1 - n2 * n2 * E3 / 9.0, 2000);

    // Road 3 ///////////////////////////////////////
    int n3 = 20;
    int P3[n3];
    int max = 0;
    bool isFound3 = false;
    for (int i = 0; i < n3; i++)
    {
        P3[i] = ((i + 1) * 2) * ((i + 1) * 2);
        P3[i] = (P3[i] + E3 * E3) % 113;
        if (P3[i] > max)
            max = P3[i];
    }
    for (int i = 0; i < n3; i++)
    {

        P3[i] = ((int)ceil(((double)P3[i] + (double)E3) / (double)max) % 26) + 65;
        if (P3[i] == 80)
        {
            isFound3 = true;
            updateValue(HP1, HP1 - 80 * (n3 - i) * 3, 999);
            updateValue(EXP1, EXP1 + ((3500 - 80 * (n3 - i)) % 300), 900);
            updateValue(M1, M1 - (n3 - i) * E3 / 9.0, 2000);
            break;
        }
    }

    if (!isFound3)
        updateValue(M1, M1 - n3 * n3 * E3 / 9.0, 2000);

    // Road 4 ///////////////////////////////////////
    int n4 = 12;
    int P4[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isFound4 = false;
    int min = 10000;
    int min_idx = 0;
    for (int i = 0; i < n4; i++)
    {
        P4[i] = (P4[i] + (int)pow(ceil((double)E3 / 29.0), 3)) % 9;
        if (P4[i] < min)
        {
            min = P4[i];
            min_idx = i + 1;
        }
    }

    for (int i = 0; i < n4; i++)
    {
        int n = (P4[i] + E3) * ceil((min / (double)min_idx));
        P4[i] = n % 26 + 65;
    }

    for (int i = n4 - 1; i >= 0; i--)
    {
        if (P4[i] == 80)
        {
            cout << n4 - i << " ";
            isFound4 = true;
            updateValue(HP1, HP1 - 80 * (n4 - i) * 4, 999);
            updateValue(EXP1, EXP1 + ((4500 - 80 * (n4 - i)) % 400), 900);
            updateValue(M1, M1 - (n4 - i) * E3 / 9.0, 2000);
            break;
        }
    }

    if (!isFound4)
        updateValue(M1, M1 - n4 * n4 * E3 / 9.0, 2000);

    // Finally /////////////////////////////////////////
    if (!isFound1 && !isFound2 && !isFound3 && !isFound4)
    {
        updateValue(HP1, HP1 - (59 * E3) % 900, 999);
        updateValue(EXP1, EXP1 - (79 * E3) % 300, 900);
        return -1;
    }
    return HP1 + EXP1 + M1;
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
