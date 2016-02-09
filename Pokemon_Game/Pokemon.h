/**
File Name: Pokemon.h
Author: Paul Charles
Date: 09.07.2015
Purpose: .h file that contains public functions and private variables to build the Pokemon
**/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>
using namespace std;

class Pokemon
{
    public:
        Pokemon();
        string get_name()const;
        void reduceHP(int amount);
        int get_hp()const;
        int get_attackLevel()const;
        int get_defLevel()const;

        void set_hp(int hp);
        void set_attackLvl(int att);
        void set_deflvl(int def);
        void set_name(string name);
    private:
        int m_hp;
        int m_attackLevel;
        int m_defenseLevel;
        string m_name;
        //string m_name;
};

#endif // POKEMON_H