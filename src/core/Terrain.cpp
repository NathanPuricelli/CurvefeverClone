/**
@brief Implémentation de la classe terrain


@file Terrain.cpp
@author : Aymeric Leto, Benoît Briguet, Nathan Puricelli
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
    for (int i = 0; i< TAILLETERRAIN; i++)
    {
        for (int j = 0; j<TAILLETERRAIN; j++)
        {
            tabCasesOccupees[i][j] = false;
        }
    }
}

Terrain::Terrain(unsigned int tX, unsigned int tY)
{
    assert(tX>=0);
    assert(tY>=0);
    tailleX = tX;
    tailleY = tY;
    for (int i = 0; i< TAILLETERRAIN; i++)
    {
        for (int j = 0; j<TAILLETERRAIN; j++)
        {
            tabCasesOccupees[i][j] = false;
        }
    }
}

Terrain::~Terrain() {}

unsigned int Terrain::getTailleX()const
{
    return tailleX;
}

unsigned int Terrain::getTailleY()const
{
    return tailleY;
}

void Terrain::setTailleX(unsigned int x)
{
    tailleX = x;
}

void Terrain::setTailleY(unsigned int y)
{
    tailleY = y;
}

bool Terrain::estPositionValide(const int x, const int y)const
{
    return ((x>=0) && (x<tailleX) && (y>=0) && (y<tailleY) && (!tabCasesOccupees[x][y]));
}