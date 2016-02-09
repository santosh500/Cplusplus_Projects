/**
File Name: Colosseum.cpp
Author: Paul Charles
Date: 09.07.2015
Purpose: Source file that runs the logic of the Pokemon game
**/

#include <iostream>
#include "Colosseum.h"
#include "Pokemon.h"
#include "Dice.h"
using namespace std;

Colosseum::Colosseum() //Constructor for Colosseum class
{

    Colosseum::d6=Dice(6);
    Colosseum::d20=Dice(20);
}

void Colosseum::userBuild(Pokemon& p) //function used to build Pokemon
{
    cout << "Please name your Pokemon:" << endl;
     string name;
     p.set_name(name);
     cout << "How many hit points will it have? (1-50):" << endl;
     int hp;
     p.set_hp(hp);
     int hp1=p.get_hp();
     while(hp1>50 || hp1<1)
     {
         cout << "Sorry. The hit points should be between (1-50)" << endl;
         p.set_hp(hp);
         hp1=p.get_hp();
     }
     cout << "Split fifty points between attack level and defense level" << endl;
     cout << "Enter your attack level (1-49):" << endl;
     int att;
     p.set_attackLvl(att);
     int att1=p.get_attackLevel();

     while(att1>49 || att1<1)
     {
         cout << "Sorry. The attack level must be between 1 and 49)" << endl;
         p.set_attackLvl(att);
         att1=p.get_attackLevel();

     }
     int g=49-att1;
     cout << "Give a defense level (from 1 to " << g << "): " << endl;
     int def;
     p.set_deflvl(def);
     int def1=p.get_defLevel();
     while(g<def1 || def1<1)
     {
         cout << "Sorry. The defense level must be between 1 and " << g << ": " << endl;
         p.set_deflvl(def);
         def1=p.get_defLevel();
     }

}

bool Colosseum::attack(const Pokemon& attacker, Pokemon& defender) //function that deals with attacks and lowers hit points if hit
{
    bool returnValue=false;
    cout << attacker.get_name() << " is attacking " << defender.get_name() << endl;
    int attbonus=d20.roll();
    int defbonus=d20.roll();
    cout << attacker.get_name() << " rolls an attack bonus of " << attbonus << endl;
    cout << defender.get_name() << " rolls an defense bonus of " << defbonus << endl;
    int total_att=attbonus+attacker.get_attackLevel();
    int total_def=defbonus+defender.get_defLevel();
    int damage;
    if(total_att>total_def)
    {
        int roll1=d6.roll();
        int roll2=d6.roll();
        int roll3=d6.roll();
        damage=roll1+roll2+roll3;
        cout << "The attack hits dealing 3-D6 damage!" << endl;
        cout << "The rolls are: " << roll1 << " " << roll2 << " " << roll3 << " totalling: " << damage << " damage!" << endl;
        defender.reduceHP(damage);
        if(defender.get_hp() <=0 )
        {
            returnValue=true;
        }
        else
        {
            returnValue=false;
            cout << defender.get_name() << " has " << defender.get_hp() << " hit points left." << endl;
        }

    }
    else
    {
        damage=0;
        cout << "The attack is missed!" << endl;
    }
    return returnValue;

}

void Colosseum::play(Pokemon& p1, Pokemon& p2) //function that determines who goes first, when game is over, and constraints the game to 10 rounds
{

    int hp;
    Dice d;
    int j=d.roll();
    string position;
    if(j==1)
    {
        position="first";
    }
    else
    {
        position="second";
    }
    cout << p1.get_name() << " rolls a " << j << " and goes " << position << endl;
    if(position=="first")
    {
        for(int i=1; i<11; i++)
        {

            cout << "Round " << i << "!" << endl;
            if(attack(p1,p2)==true)
            {
                cout << p2.get_name() << " has been defeated!" << endl;
                break;
            }
            if(attack(p2,p1)==true)
            {
                cout << p1.get_name() << " has been defeated!" << endl;
                break;
            }
            if(i==10)
            {
              cout << "Game Over. It's a draw!" << endl;
            }


        }

    }
    else
    {
        for(int i=1; i<11; i++)
        {

            cout << "Round " << i << "!" << endl;
            if(attack(p2,p1)==true)
            {
                cout << p1.get_name() << " has been defeated!" << endl;
                break;
            }
            if(attack(p1,p2)==true)
            {
                cout << p2.get_name() << " has been defeated!" << endl;
                break;
            }
            if(i==10)
            {
              cout << "Game Over. It's a draw!" << endl;
            }

        }

    }

}
