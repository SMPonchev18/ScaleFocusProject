#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

//Task 1
void Names(string& codebreakerName, string& commanderName)
{
    cout << "Enter the code breaker name: ";
    cin >> codebreakerName;
    cout << "Enter the name for the German commander: ";
    cin >> commanderName;
}

vector <char> inputGerman()
{
    char numberGerman;
    vector <char> vGerman = {};
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

void germanQote(bool& flag, bool flag2, vector <char> German, vector <int>& var)
{
    int counter = 0;
    char wrongElements[26] = { '!', '"', '#', '$','%','&','(',')','*','+',',','-','`','~','.',';',':','<','>','=','_','@','?','|','/','^' };

    for (int i = 0; i < 4; i++)
    {
        cout << German[i] << " ";
    }

    int counterRepeate = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (German[i] == wrongElements[j])
            {
                counter++;
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if ((German[i] >= 'a' and German[i] <= 'z') or (German[i] >= 'A' and German[i] <= 'Z'))
        {
            counter++;
            break;
        }
    }
    if (counter == 0)
    {
        int elements = 0;

        for (int i = 0; i < 4; i++)
        {
            elements = German[i] - '0';
            var.push_back(elements);
        }


        for (int i = 0; i < 4; i++)
        {
            if (var[i] < 0 or var[i] > 7)
            {
                flag2 = false;
                break;
            }
        }


        int nextElement = 0;
        for (int i = 0; i < 4; i++)
        {
            elements = German[i] - '0';
            for (int j = i + 1; j < 4; j++)
            {

                nextElement = German[j] - '0';
                if (elements == nextElement)
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
                cout << "| Ohh there is a problem. You repeate one of the number from the cordinates or enter a letter. Do not repeate them!|" << endl;
                cout << endl;
            }
        }
        else
        {
            cout << endl;
            cout << "| Ohh there is a problem. You enter a number out of range or enter a letter. Do not do it again!|" << endl;
            cout << endl;
        }

        flag2 = true;

        cout << endl;

    }
    else
    {
        cout << "There is a problem you enter a letter or a wrond character!" << endl;
    }
}
void greatingCodeBreaker(char nonVisibleCode[], string& codebreakerName)
{
    for (int i = 0; i < 50; i++)
    {
        cout << endl;
    }

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
    cout << "|  So your first task is to break this code. Know that the numbers in the code aren't repeatable|";
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

vector <char> inputCodeBreaker()
{
    char numberCodeBreaker;
    vector <char> vCodeBreaker = {};
    for (int i = 0; i < 4; i++)
    {
        cin >> numberCodeBreaker;
        vCodeBreaker.push_back(numberCodeBreaker);
    }
    cin.ignore(INT_MAX, '\n');

    return vCodeBreaker;
}

void checkingCoordinates(bool& flag, vector <char> codeBreaker, vector <char> German, vector <int>& var, int& points, int& counterTries1)
{

    char wrongElements[26] = { '!', '"', '#', '$','%','&','(',')','*','+',',','-','`','~','.',';',':','<','>','=','_','@','?','|','/','^' };
    int checkingNumbers[5] = { 9,9,9,9,9 };
    int checkingPosition[5] = { 9,9,9,9,9 };
    int counter = 0;
    bool flagProblem = true;

    vector <int> numbersOfTheChar;
    int counter1 = 0;
    for (int i = 1; i <= 10; i++)
    {
        if (counterTries1 == i)
        {
            points = points - 1;
        }
    }

    if (counterTries1 == 13)
    {
        cout << "You have reached your limits of attempt. You lost!" << endl;
    }
    else
    {

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (codeBreaker[i] == wrongElements[j])
                {
                    counter1++;
                    break;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if ((codeBreaker[i] >= 'a' and codeBreaker[i] <= 'z') or (codeBreaker[i] >= 'A' and codeBreaker[i] <= 'Z'))
            {
                counter1++;
                break;
            }
        }
        if (counter1 == 0)
        {
            int element = 0;
            for (int i = 0; i < 4; i++)
            {
                element = codeBreaker[i] - '0';              //rabotiiiii trqa smenq nadolu s vector var2
                numbersOfTheChar.push_back(element);
            }

            for (int i = 0; i < 4; i++)
            {
                if (numbersOfTheChar[i] < 0 or numbersOfTheChar[i] > 7)
                {
                    cout << "Please enter 4 numbers from the range of 0-7 !" << endl;
                    flagProblem = false;
                    break;
                }
            }

            if (flagProblem)
            {

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (numbersOfTheChar[i] == var[j])
                        {
                            checkingNumbers[i] = numbersOfTheChar[i];

                        }
                    }

                }
                for (int i = 0; i < 4; i++)
                {
                    if (numbersOfTheChar[i] == var[i])
                    {
                        checkingPosition[i] = numbersOfTheChar[i];
                        counter++;
                    }
                }
                if (counter != 4)
                {
                    counterTries1++;
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
                }
                else
                {
                    cout << endl;
                    cout << "|Congratulations you guessed the coordinates! Great job! I knew you can do it.|" << endl;
                }
                if (counter == 4)
                {
                    flag = true;
                }
                counter = 0;
                cout << endl;
            }
        }
        else
        {
            cout << "Problem you enter a letter or a wrong character!";
        }
    }
}
//Task 2
void germanQoteTask2(bool& flag, bool flagRange, vector <char> germanRepeatable, vector <int>& varRepeatable)
{
    char wrongElements[26] = { '!', '"', '#', '$','%','&','(',')','*','+',',','-','`','~','.',';',':','<','>','=','_','@','?','|','/','^' };

    flagRange = true;
    int counter = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (germanRepeatable[i] == wrongElements[j])
            {
                counter++;
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if ((germanRepeatable[i] >= 'a' and germanRepeatable[i] <= 'z') or (germanRepeatable[i] >= 'A' and germanRepeatable[i] <= 'Z'))
        {
            counter++;
            break;
        }
    }
    if (counter == 0)
    {
        int elements = 0;

        for (int i = 0; i < 4; i++)
        {
            elements = germanRepeatable[i] - '0';              //rabotiiiii trqa smenq nadolu s vector var2
            varRepeatable.push_back(elements);
        }


        for (int i = 0; i < 4; i++)
        {
            if (varRepeatable[i] < 0 or varRepeatable[i] > 7)
            {
                flagRange = false;
                break;
            }
        }



        if (flagRange == false)
        {
            cout << endl;
            cout << "| Ohh there is a problem. You enter a number out of range. Do not do it again!|" << endl;
            cout << endl;
        }
        else
        {
            flag = true;
        }

        cout << endl;
    }
    else
    {
        cout << "There is a problem you enter a letter or a wrond character!" << endl;
    }
}
void greatingCodeBreaker2(char nonVisibleCode[], string& codebreakerName)
{
    for (int i = 0; i < 50; i++)
    {
        cout << endl;
    }

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
    cout << "| TASK2                                                                                         |" << endl;
    cout << "|                                                                                               |" << endl;
    cout << "|  Hello " << codebreakerName << ",";
    for (int i = codebreakerName.size(); i < 86; i++)
    {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|  We need you for this mission. We need to win the war!                                        |";
    cout << endl;
    cout << "|  So your first task is to break this code. Know that the numbers in the code ARE repeatable.  |";
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

void checkingCoordinatesTask2(bool& flag, vector <char> codeBreakerRepeatable, vector <int>& varRepeatable, int& points, int& counterTries2)
{
    char wrongElements[26] = { '!', '"', '#', '$','%','&','(',')','*','+',',','-','`','~','.',';',':','<','>','=','_','@','?','|','/','^' };

    int checkingNumbers[5] = { 9,9,9,9,9 };
    int checkingPosition[5] = { 9,9,9,9,9 };
    int counter = 0;
    bool flagProblem = true;

    vector <int> numbersOfTheChar2;
    int counter1 = 0;

    for (int i = 1; i <= 13; i++)
    {
        if (counterTries2 == i)
        {
            points = points - 2;
        }
    }

    if (counterTries2 == 13)
    {
        cout << "You have reached your limits of attempt. You lost!" << endl;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (codeBreakerRepeatable[i] == wrongElements[j])
                {
                    counter++;
                    break;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if ((codeBreakerRepeatable[i] >= 'a' and codeBreakerRepeatable[i] <= 'z') or (codeBreakerRepeatable[i] >= 'A' and codeBreakerRepeatable[i] <= 'Z'))
            {
                counter++;
                break;
            }
        }

        if (counter == 0)
        {
            int element = 0;
            for (int i = 0; i < 4; i++)
            {
                element = codeBreakerRepeatable[i] - '0';
                numbersOfTheChar2.push_back(element);
            }



            for (int i = 0; i < 4; i++)
            {
                if (numbersOfTheChar2[i] < 0 or numbersOfTheChar2[i] > 7)
                {
                    cout << "Please enter 4 numbers from the range of 0-7 !" << endl;
                    flagProblem = false;
                    break;
                }
            }

            if (flagProblem)
            {

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (numbersOfTheChar2[i] == varRepeatable[j])
                        {
                            checkingNumbers[i] = numbersOfTheChar2[i];

                        }
                    }

                }
                for (int i = 0; i < 4; i++)
                {
                    if (numbersOfTheChar2[i] == varRepeatable[i])
                    {
                        checkingPosition[i] = numbersOfTheChar2[i];
                        counter++;
                    }
                }
                if (counter != 4)
                {
                    counterTries2++;
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
                }
                else
                {
                    cout << endl;
                    cout << "|Congratulations you guessed the coordinates! Great job! I knew you can do it.|" << endl;
                }
                if (counter == 4)
                {
                    flag = true;
                }
                counter = 0;
                cout << endl;
            }
        }
        else
        {
            cout << "There is a problem you enter a letter or a wrond character!" << endl;
        }
    }
}
int main()
{
    int points = 100;

    //Task 1(level 1)
    vector <char> German;
    vector <int> var;
    vector <char> codeBreaker;
    char nonVisibleCode[10];
    bool flag = false;
    bool flag2 = true;
    string codebreakerName, commanderName;
    int counterTries1 = 0;
    //Task 2(level 1)
    vector<char> germanRepeatable, codeBreakerRepeatable;
    vector <int> varRepeatable;
    bool flagRange = true;
    int counterTries2 = 0;
    //Task 1(level 2)


    //Task 2(level 2)















    Names(codebreakerName, commanderName);
    cout << endl;
    cout << "(Note: If you enter more than 4 digits our game will take only the first 4 digits, so don't do it!)" << endl;
    cout << endl;








    //Task 1(level 1)
    cout << endl;
    cout << "|Level 1/Task 1|" << endl;
    cout << endl;
    greatingGerman(codebreakerName);

    while (flag == false)
    {
        cout << "Please enter your cordinates for the ship: ";
        German = inputGerman();
        germanQote(flag, flag2, German, var);
        if (flag == false)
            var.clear();
    }
    clock_t time;
    time = clock();

    greatingCodeBreaker(nonVisibleCode, codebreakerName);

    flag = false;

    cout << "Please enter 4 numbers from the range of 0-7 ! Keep in mind that the numbers can't repeate." << endl;
    cout << "(Note: If you enter more than 4 digits our game will take only the first 4 digits, so don't do it!)" << endl;

    while (flag == false)
    {
        cout << endl;
        cout << "Enter your guess: ";
        codeBreaker = inputCodeBreaker();
        checkingCoordinates(flag, codeBreaker, German, var, points, counterTries1);
    }

    cout << endl;
    cout << "Now is your time to take the second task. Keep in mind that the German CAN repeate the numbers of the coordinates." << endl;
    cout << endl;
    cout << "|Task 2|" << endl;
    cout << endl;




    //Task 2 (level 1)
    flag = false;

    while (flag == false)
    {
        cout << "Please enter your cordinates for the ship: ";
        germanRepeatable = inputGerman();
        germanQoteTask2(flag, flagRange, germanRepeatable, varRepeatable);
        if (flag == false)
            varRepeatable.clear();
    }

    greatingCodeBreaker2(nonVisibleCode, codebreakerName);

    flag = false;

    cout << "Please enter 4 numbers from the range of 0-7 ! Keep in mind that the numbers CAN repeate." << endl;
    cout << "(Note: If you enter more than 4 digits our game will take only the first 4 digits, so don't do it!)" << endl;

    while (flag == false)
    {
        cout << endl;
        cout << "Enter your guess: ";
        codeBreakerRepeatable = inputCodeBreaker();
        checkingCoordinatesTask2(flag, codeBreakerRepeatable, varRepeatable, points, counterTries2);
    }

    cout << endl;
    cout << "Now is your time to Level 2. Keep in mind that you played this time against the computer. And the numbers can't repeate in the first task." << endl;
    cout << endl;
    cout << "|Level 2/Task 1|" << endl;
    cout << endl;









    time = clock() - time;
    int sec = (int)time / CLOCKS_PER_SEC;
    int min = 0;
    int hr = 0;
    min = sec / 60;
    hr = min / 60;

    cout << endl;
    cout << endl;
    cout << "Your time is: " << int(hr) << " hr " << int(min % 60) << " min " << int(sec % 60) << " sec ";
    cout << endl;
    cout << "Your points are: " << points << " p.";
}