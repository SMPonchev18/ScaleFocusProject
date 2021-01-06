
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;


void Names(string& codebreakerName, string& commanderName)
{
    cout << "Enter the code breaker name: ";
    cin >> codebreakerName;
    cout << "Enter the name for the German commander: ";
    cin >> commanderName;
}

vector <int> inputGerman()
{
    int numberGerman;
    vector <int> vGerman = {};
    for (int i = 0; i < 4; i++)
    {
        cin >> numberGerman;
        vGerman.push_back(numberGerman);
    }
    cin.ignore(INT_MAX, '\n');

    return vGerman;
}

void greatingGerman(string& commanderName)
{

    cout << "|----------------------------------------------------------------------------------------------------|" << endl;
    cout << "| Hello " << commanderName << ",";
    for (int i = commanderName.size(); i < 92; i++)
    {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|                                                                                                    |" << endl;
    cout << "| We need to send the ships on the correct spot.So we need your help to send us the coordinates.     |" << endl;
    cout << "| Please enter them and be very careful because the English codebreaker can decrypt your coordinates |" << endl;
    cout << "|----------------------------------------------------------------------------------------------------|" << endl;
}

void germanQote(bool& flag, bool flag2, vector <int> German)
{



    int counterRepeate = 0;

    for (int i = 0; i < 4; i++)
    {
        if (German[i] < 0 or German[i] > 7)
        {
            flag2 = false;
            break;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (German[i] == German[j])
            {
                counterRepeate++;
            }
        }
    }

    if (flag2)
    {
        if (counterRepeate == 0)
        {
            flag = true;
        }
        else
        {
            cout << endl;
            cout << "| Ohh there is a problem. You repeate one of the number from the cordinates. Do not repeate them!|" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << endl;
        cout << "| Ohh there is a problem. You enter a number out of range. Do not do it again!|" << endl;
        cout << endl;
    }

    flag2 = true;

    cout << endl;
}
void greatingCodeBreaker(bool& flag, char nonVisibleCode[], string& codebreakerName)
{
    for (int i = 0; i < 50; i++)
    {
        cout << endl;
    }
    if (flag)
    {
        for (int i = 0; i < 4; i++)
        {
            nonVisibleCode[i] = '*';
        }
        cout << "This are the cordinate of the German ship: ";
        for (int i = 0; i < 4; i++)
        {
            cout << nonVisibleCode[i];
        }
        cout << endl;
        cout << endl;
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        cout << "| TASK1                                                                                         |" << endl;
        cout << "|                                                                                               |" << endl;
        cout << "|  Hello " << codebreakerName << ",";
        for (int i = codebreakerName.size(); i < 86; i++)
        {
            cout << " ";
        }
        cout << "|" << endl;
        cout << "|  We need you for this mission. We need to win the war!                                        |";
        cout << endl;
        cout << "|  So your first task is to break this code. Know that the number in the code aren't repeatable.|";
        cout << endl;
        cout << "|  You need to guess minimum four numbers from the cordinates.                                  |";
        cout << endl;
        cout << "|  Know that the number is in the range from 0 to 7.                                            |";
        cout << endl;
        cout << "|                                                                                               |" << endl;
        cout << "|  Good luck!                                                                                   |";
        cout << endl;
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        cout << endl;
    }
}

vector <int> inputCodeBreaker()
{
    int numberCodeBreaker;
    vector <int> vCodeBreaker = {};
    for (int i = 0; i < 4; i++)
    {
        cin >> numberCodeBreaker;
        vCodeBreaker.push_back(numberCodeBreaker);
    }
    cin.ignore(INT_MAX, '\n');

    return vCodeBreaker;
}

void checkingCoordinates(bool& flag, vector <int> codeBreaker, vector <int> German)
{
    int checkingNumbers[5] = { 9,9,9,9,9 };
    int checkingPosition[5] = { 9,9,9,9,9 };
    int counter = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (codeBreaker[i] == German[j])
            {
                checkingNumbers[i] = codeBreaker[i];

            }
        }

    }
    for (int i = 0; i < 4; i++)
    {
        if (codeBreaker[i] == German[i])
        {
            checkingPosition[i] = codeBreaker[i];
            counter++;
        }
    }
    cout << "That are the numbers that you guess: ";
    for (int i = 0; i < 4; i++)
    {
        if (checkingNumbers[i] >= 0 and checkingNumbers[i] <= 7)
            if (checkingNumbers[i] != 9)
                cout << "'" << checkingNumbers[i] << "'" << " ";
    }
    cout << endl;
    cout << "That are the numbers and the right position that you guess: ";
    for (int i = 0; i < 4; i++)
    {
        if (checkingPosition[i] >= 0 and checkingPosition[i] <= 7)
            if (checkingPosition[i] != 9)
                cout << "'" << checkingPosition[i] << "'" << " ";
    }
    if (counter == 4)
    {
        flag = true;
    }
    counter = 0;
    cout << endl;
}

int main()
{
    vector <int> German, codeBreaker;
    char nonVisibleCode[10];
    bool flag = false;
    bool flag2 = true;
    string codebreakerName, commanderName;

    Names(codebreakerName, commanderName);
    clock_t time;
    time = clock();
    greatingGerman(codebreakerName);

    while (flag == false)
    {
        cout << "Please enter your cordinates for the ship: ";
        German = inputGerman();
        germanQote(flag, flag2, German);
    }

    greatingCodeBreaker(flag, nonVisibleCode, codebreakerName);

    flag = false;

    while (flag == false)
    {
        cout << "Please enter your guess: ";
        codeBreaker = inputCodeBreaker();
        checkingCoordinates(flag, codeBreaker, German);
    }



    time = clock() - time;
    int sec = (int)time / CLOCKS_PER_SEC;
    int min = 0;
    int hr = 0;
    min = sec / 60;
    hr = min / 60;

    cout << endl;
    cout << "Your time is: " << int(hr) << " hr " << int(min % 60) << " min " << int(sec % 60) << " sec ";

}