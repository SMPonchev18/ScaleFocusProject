

#include <iostream>
using namespace std;
void enteringCordinates(bool &flag,bool flag2, int German[10])
{
    
    while (false == flag)
    {
        int counterRepeate = 0;
        cout << "Please enter your cordinates for your ship: ";
        for (int i = 0; i < 8; i++)
        {
            cin >> German[i];
        }
        for (int i = 0; i < 8; i++)
        {
            if (German[i] < 0 or German[i]>7)
            {
                flag2 = false;
                break;
            }
            else
            {
                flag2 = true;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = i + 1; j < 8; j++)
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
                cout << "|Ohh there is a problem. You repeate one of the number from the cordinates. Do not repeate them!|" << endl;
                cout << endl;
            }
        }
        else
        {
            cout << endl;
            cout << "|Ohh there is a problem. You enter a number out of range. Do not do it again! Please enter from 0-7.|" << endl;
            cout << endl;
        }
    }
}

void task1(bool &flag)
{
    char nonVisibleCode[10];
    if (flag)
    {
        for (int i = 0; i < 8; i++)
        {
            nonVisibleCode[i] = '*';
        }
        cout << endl;
        cout << "This are the cordinate of the German ship: ";
        for (int i = 0; i < 8; i++)
        {
            cout << nonVisibleCode[i];
        }
        cout << endl;
        cout << endl;
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
        cout << "| TASK1                                                                                         |" << endl;
        cout << "|                                                                                               |" << endl;
        cout << "|  Hello codeBreaker you need to break and guess the cordinates                                 |";
        cout << endl;
        cout << "|  We need you for this mission. We need to win the war!                                        |";
        cout << endl;
        cout << "|  So your first task is to break this code. Know that the number in the code aren't repeatable.|";
        cout << endl;
        cout << "|  You need to guess minimum four numbers from the cordinates.                                  |";
        cout << endl;
        cout << "|  Know that the number is in the range from 0 to 7.                                            |";
        cout << endl;
        cout << "|  Good luck!                                                                                   |";
        cout << endl;
        cout << "|-----------------------------------------------------------------------------------------------|" << endl;
    }
}

int main()
{
    int German[10];
    int codeBreaker;
    bool flag = false;
    bool flag2 = true;
    enteringCordinates(flag, flag2, German);
    task1(flag);
    
}