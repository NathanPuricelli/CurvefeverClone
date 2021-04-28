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

}

Terrain::Terrain(int tX, int tY)
{
    cout<<"ok ?"<<endl;
    assert(tX>=0);
    assert(tY>=0);
    tailleX = tX;
    tailleY = tY;

    tabCasesOccupees = new bool* [tX];

    for (int i = 0; i < tX; i++)
    {
        tabCasesOccupees[i] = new bool [tY];
        for (int j = 0; j < tY; j++)
        {
            
            tabCasesOccupees[i][j] = false;
        }
    }

    cout<<"Construction Terrain : Check"<<endl;
}

Terrain::~Terrain() {

}

int Terrain::getTailleX() const
{
    return tailleX;
}

int Terrain::getTailleY() const
{
    return tailleY;
}

void Terrain::setTailleX(int x)
{
    tailleX = x;
}

void Terrain::setTailleY(int y)
{
    tailleY = y;
}

bool Terrain::estPositionValide(const int x, const int y)const
{
    return ((x>0) && (x<tailleX) && (y>0) && (y<tailleY) && (!tabCasesOccupees[x][y]));
}