/**
@brief Module gérant les serpents.

Le module Serpent permet de gérer un serpent et ses informations.

@file Serpent.h
@author : Aymeric Leto, Benoît Briguet, Nathan Puricelli
@date : Mars 2021
*/
#ifndef BONUS_H
#define BONUS_H

#include <iostream>
#include <string>
#include "Terrain.h"

using namespace std;

class Bonus
{
private :
    float x, y;
    bool estApparu;
public :
    Bonus();
    ~Bonus();

};

#endif
