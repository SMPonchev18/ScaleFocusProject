#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <vector>
#include <stdio.h> 
#include <time.h> 
using namespace std;

bool showMainMenu = true;

struct OPTION2PLAYERS
{
    string codewriterusername;
    string codebreakerusername;

    vector<char> cordinates;

    int codewriterpoints = 100;
};

void checkM(int& a)
{
    while (1)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            cout << "Incorrect Input!" << endl;
            cout << "Try again ->: "; cin >> a;
        }
        if (!cin.fail()) break;
    }
}

void exit()
{
    system("CLS");
    cout << endl;
    cout << "|-----------------------|" << endl;
    cout << "Exit process remaining.." << endl;
    cout << "|-----------------------|" << endl;
}

//-------------------------------- Option 1 --------------------------------

//====================================Task1====================================

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

void germanQote(bool& flag, bool flag2, vector <char> German, vector <int>& var)
{
    int counter = 0;
    char wrongElements[26] = { '!', '"', '#', '$','%','&','(',')','*','+',',','-','`','~','.',';',':','<','>','=','_','@','?','|','/','^' };

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
                cout << "|-------------------------------------|" << endl;
                cout << "You repeate one of the entered numbers." << endl;
                cout << "     Do not repeate them!" << endl;
                cout << "|-------------------------------------|" << endl;
                cout << endl;
            }
        }
        else
        {
            cout << endl;
            cout << "|------------------------------|" << endl;
            cout << "You enter a number out of range!" << endl;
            cout << "     Do not do it again!" << endl;
            cout << "|------------------------------|" << endl;
            cout << endl;
        }

        flag2 = true;
        cout << endl;
    }
    else
    {
        cout << "There is a problem you enter a letter or a wrong character!" << endl;
    }
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
                element = codeBreaker[i] - '0';
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

//====================================Task2====================================

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
            elements = germanRepeatable[i] - '0';
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

void repeatFunctionsTask2(OPTION2PLAYERS* player, int option1counter, vector <int> var, int& counterTries1, int& option1CordinatesCounter)
{
    counterTries1 = 0;

    bool flag = false;
    bool flagRange = true;

    cout << endl;
    cout << "============================" << endl;
    cout << "Entering in task 2" << endl;
    cout << "============================" << endl;
    cout << endl;


    while (flag == false)
    {
        cout << "Please enter your cordinates for the ship: ";
        player[option1CordinatesCounter].cordinates = inputGerman();
        germanQoteTask2(flag, flagRange, player[option1CordinatesCounter].cordinates, var);
        if (flag == false)
            var.clear();
    }
    option1CordinatesCounter++;

    flag = false;

    while (flag == false)
    {
        cout << endl;
        cout << "Enter your guess: ";
        vector<char>codeBreakerRepeatable = inputCodeBreaker();
        checkingCoordinatesTask2(flag, codeBreakerRepeatable, var, player->codewriterpoints, counterTries1);
        if (counterTries1 == 13)
        {
            cout << endl;
            cout << "You have reached your limits of attempt. You lost!" << endl;
            //flag = true;
            // Tuka da che codebreakera e zagubil a codewriter e spechelil
        }
    }

    //Tuk produljavame s dopulnenieto...
    cout << "Tochki: " << player->codewriterpoints;

}

void storeInHtmlUk(OPTION2PLAYERS* player, int option1counter, vector <int> var, int counterTries1, int option1CordinatesCounter)
{
    system("CLS");
    bool flag = false;  bool flag2 = true;

    ofstream web3;
    web3.open("HtmlCss\\index3.html");

    for (int i = 0; i < option1counter; i++)
    {
        web3 << "<!DOCTYPE html>"
            "<html lang=\"en\">"
            "   <head>"
            "       <meta charset=\"utf-8\">"
            "       <title>Welcome to my website</title>"
            "       <link rel=\"stylesheet\" href=\"style.css\">"
            "   </head>"
            "   <body class =\"body3\">"
            "       <div class =\"container\">"
            "           <h1>" << "Hello, " << player[i].codebreakerusername << " !" << "</h1>"
            "           <p1>"
            "               Your role is to help UK to find and destroy Germans battleship!"
            "               The Germans have placed a coordinates of their Battleship!"
            "               You have 13 tries in which you have to guess the combination of 4 numbers."
            "               The numbers are in the range from 0 to 7 and you have to guess the position of the number too."
            "               There is a timer which is going to start counting your time BY closing the browser."
            "               If your time is good you will earn points, if its not you will lose points!"
            "               Hurry up we are losing them! Good Luck!"
            "           </p1>"
            "           <pre></pre>"
            "           <p1><u>Close the browser to continue the game..</u></p1>"
            "           <iframe width=\"0\" height=\"0\" src=\"Music\\Uk.mp3\" frameborder=\"0\" allowfullscreen></iframe>"
            "       </div>"
            "   </body>"
            "</html>";
    }
    web3.close();
    system("HtmlCss\\index3.html");


    while (flag == false)
    {
        cout << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "Please enter your guess: ";
        vector <char> codeBreaker = inputCodeBreaker();
        cout << "|------------------------------------------------|" << endl;
        checkingCoordinates(flag, codeBreaker, player[option1CordinatesCounter].cordinates, var, player->codewriterpoints, counterTries1);
        if (counterTries1 == 13)
        {
            cout << endl;
            cout << "You have reached your limits of attempt. You lost!" << endl;
            //flag = true;
            //flagLost = false;
            // Tuka da che codebreakera e zagubil a codewriter e spechelil
        }
    }
    var.clear();

    repeatFunctionsTask2(player, option1counter, var, counterTries1, option1CordinatesCounter);

}

void storeInHtmlGerman(OPTION2PLAYERS* player, int option1counter, vector <int> var, int counterTries1, int& option1CordinatesCounter)
{
    system("CLS");
    bool flag = false;  bool flag2 = true;

    ofstream web2;
    web2.open("HtmlCss\\index2.html");

    for (int i = 0; i < option1counter; i++)
    {
        web2 << "<!DOCTYPE html>"
            "<html lang=\"en\">"
            "   <head>"
            "       <meta charset=\"utf-8\">"
            "       <title>Welcome to my website</title>"
            "       <link rel=\"stylesheet\" href=\"style.css\">"
            "   </head>"
            "   <body class =\"body2\">"
            "       <div class =\"container\">"
            "           <h1>" << "Hello, " << player[i].codewriterusername << " !" << "</h1>"
            "           <p1>"
            "               Your role is to protect Germans!"
            "               The task is to set up a combination of 4 different numbers."
            "               These numbers are going to be the coordinates of your Battleship!"
            "               They should be in the range from 0 to 7 and they should not be repeated!"
            "               Come on! We don't have any time to waste.."
            "           </p1>"
            "           <pre></pre>"
            "           <p1><u>Close the browser to continue the game..</u></p1>"
            "           <iframe width=\"0\" height=\"0\" src=\"Music\\Germans.mp3\" frameborder=\"0\" allowfullscreen></iframe>"
            "       </div>"
            "   </body>"
            "</html>";
    }
    web2.close();
    system("HtmlCss\\index2.html");

    while (flag == false)
    {
        cout << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "Please enter your cordinates for the ship: ";
        player[option1CordinatesCounter].cordinates = inputGerman();         // Ima bug s cheka za bukvite!
        cout << "|------------------------------------------------|" << endl;
        germanQote(flag, flag2, player[option1CordinatesCounter].cordinates, var);
        if (flag == false)
            var.clear();
    }
    option1CordinatesCounter++;

    storeInHtmlUk(player, option1counter, var, counterTries1, option1CordinatesCounter);
}

void playersUsernames(OPTION2PLAYERS* player, int& option1counter, bool& flag, vector <int> var, int counterTries1, int option1CordinatesCounter)
{
    cout << endl;
    cin.ignore();
    cout << "/-----------------------------------\\" << endl;
    cout << "Please enter your username: " << endl;
    cout << "Example: Atanas_Burmov" << endl;
    cout << "Germany -> "; getline(cin, player[option1counter].codewriterusername);
    cout << "United Kingdom -> "; getline(cin, player[option1counter].codebreakerusername);
    cout << "\\-----------------------------------/" << endl;

    string str2 = " ";
    size_t found = player[option1counter].codewriterusername.find(str2);
    size_t found2 = player[option1counter].codebreakerusername.find(str2);

    if (found != string::npos)
    {
        cout << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "There is a problem with your usernames, try again!" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << endl;
    }
    else if (found2 != string::npos)
    {
        cout << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "There is a problem with your usernames, try again!" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << endl;
    }
    else
    {
        flag = true;

        option1counter++;
        storeInHtmlGerman(player, option1counter, var, counterTries1, option1CordinatesCounter);
    }
}

void enterPlayersUsernames(OPTION2PLAYERS* player, int& option1counter, vector <int> var, int counterTries1, int option1CordinatesCounter)
{
    bool flag = false;

    while (flag == false)
    {
        playersUsernames(player, option1counter, flag, var, counterTries1, option1CordinatesCounter);
    }
}

void twoPlayers(OPTION2PLAYERS* player, int& option1counter, vector <int> var, int counterTries1, int option1CordinatesCounter)
{
    cout << endl;
    system("CLS");
    system("HtmlCss\\index.html");

    enterPlayersUsernames(player, option1counter, var, counterTries1, option1CordinatesCounter);
}

bool mainMenu(OPTION2PLAYERS* player, int option1counter, vector <int> var, int counterTries1, int option1CordinatesCounter)
{
    cout << endl;
    cout << "/-----------------------------------\\" << endl;
    cout << "Welcome to Bletchley!" << endl;
    cout << "Choose your level:" << endl;
    cout << "(1) Level 1: Play with another player" << endl;
    cout << "(2) Level 2: Play with computer" << endl;
    cout << "(3) Exit" << endl;
    cout << "\\-----------------------------------/" << endl;

    int option;
    cout << "->: "; cin >> option;
    checkM(option);


    switch (option)
    {
    case 1:
        twoPlayers(player, option1counter, var, counterTries1, option1CordinatesCounter);
        break;

    case 2:
        //level2
        break;

    case 3:
        exit();
        return 0;

    default:
        cout << endl;
        cout << "|--------------------------|" << endl;
        cout << "Incorrect input, try again!" << endl;
        cout << "|--------------------------|" << endl;
        showMainMenu = false;
    }
    return true;
}


int main()
{
    OPTION2PLAYERS player[50];
    int option1counter = 0;
    int option1CordinatesCounter = 0;

    vector <int> var;
    int counterTries1 = 0;

    //bool flagLost = true;

    do {
        showMainMenu = mainMenu(player, option1counter, var, counterTries1, option1CordinatesCounter);
    } while (showMainMenu != false);
}