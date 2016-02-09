/**
File Name: main.cpp
Author: Paul Charles
Date: 09.07.2015
Purpose: Program that runs the source and .h files
**/

#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Colosseum.h"
#include "Dice.h"

using namespace std;
int main(int argc, char *argv[])
{
    Pokemon a;
    Pokemon b;
    Colosseum c;
    char playagain = 'y';

    do //This runs the game as many times until the user wants to end
    {
        c.userBuild(a);
        c.userBuild(b);
        c.play(a,b);
        cout << "Would you like to play again (y/n): " << endl;
        cin >> playagain;

    }while(playagain=='y');
    cout << "Thanks for playing!" << endl;
    return 0;
}
