/**
File Name: Colosseum.h
Author: Paul Charles
Date: 09.07.2015
Purpose: .h file that contains public functions and private variables to run the Colosseum
**/
#ifndef COLOSSEUM_H
#define COLOSSEUM_H
#include "Pokemon.h"
#include "Dice.h"
class Colosseum
{
    public:

        Colosseum();
        void userBuild(Pokemon& p);
        bool attack(const Pokemon& attacker, Pokemon& defender);
        void play(Pokemon& p1, Pokemon& p2);

        //virtual ~Colosseum();
        int hp1;
    protected:
    private:
        Dice d20;
        Dice d6;
};

#endif // COLOSSEUM_H