/**
@brief Implémentation de la classe terrain


@file Terrain.cpp
@author : Aymeric Leto, Benoît Brihuet, Nathan Puricelli
@date : Mars 2021
*/

#include "Terrain.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
using namespace std;

Terrain::Terrain()
{
    tailleX = 0;
    tailleY = 0;
    tabCasesOccupees = NULL;
}

Terrain::Terrain(unsigned int tX, unsigned int tY)
{
    assert(tX>=0);
    assert(tY>=0);
    tailleX = tX;
    tailleY = tY;
    tabCasesOccupees = new bool[tailleX * tailleY];
}

Terrain::~Terrain()
{
    if (tabCasesOccupees != NULL)
    {
        delete[] tabCasesOccupees;
        tabCasesOccupees = NULL;
    }
    tailleX = 0;
    tailleY = 0;
}
