/**
@brief Implémentation de la classe couleur.


@file Couleur.cpp
@author : Aymeric Leto, Benoît Briguet, Nathan Puricelli
@date : Mars 2021
*/

#include "Couleur.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
using namespace std;

Couleur::Couleur()
{
    r = 0;
    g = 0;
    b = 0;
}

Couleur::Couleur(unsigned int nr, unsigned int ng, unsigned int nb)
{
    assert(nr>=0 && nr<=255);
    assert(ng>=0 && ng<=255);
    assert(nb>=0 && nb<=255);
    r = nr;
    g = ng;
    b = nb;
}

Couleur::~Couleur(){};

void Couleur::setCouleur(unsigned int nr, unsigned int ng, unsigned int nb)
{
    assert(nr>=0 && nr<=255);
    assert(ng>=0 && ng<=255);
    assert(nb>=0 && nb<=255);
    r = nr;
    g = ng;
    b = nb;
}
