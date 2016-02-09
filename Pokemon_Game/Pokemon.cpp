/**
File Name: Pokemon.cpp
Author: Paul Charles
Date: 09.07.2015
Purpose: Program that contains the variables for the Pokemon creation and applications
**/

#include <iostream>
#include "Colosseum.h"
#include "Pokemon.h"

using namespace std;

Pokemon::Pokemon() //constructor
{
    Pokemon::m_hp=0;
    Pokemon::m_attackLevel=0;
    Pokemon::m_defenseLevel=0;
    Pokemon::m_name="";
}

string Pokemon::get_name()const //get function for name
{

    return m_name;
}

void Pokemon::set_name(string name) //set function for name
{
    cin >> name;
    m_name=name;

}

int Pokemon::get_hp()const //get function for hp
{
    return m_hp;
}

void Pokemon::set_hp(int hp) //set function for hp
{
    cin >> hp;
    m_hp=hp;
}
int Pokemon::get_attackLevel()const //get function for attack level
{
    return m_attackLevel;
}

void Pokemon::set_attackLvl(int att) //set function for attack level
{
    cin >> att;
    m_attackLevel=att;

}

int Pokemon::get_defLevel()const //get function for defense level
{

    return m_defenseLevel;
}

void Pokemon::set_deflvl(int def) //set function for defense level
{
    cin >> def;
    m_defenseLevel=def;

}

void Pokemon::reduceHP(int amount) //function used to reduce hit points when attack hits
{
        m_hp=m_hp-amount;
}
