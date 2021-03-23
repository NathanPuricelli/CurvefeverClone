/**
@brief Implémentation de la classe serpent


@file Serpent.cpp
@author : Aymeric Leto, Benoît Briguet, Nathan Puricelli
@date : Mars 2021
*/

#include "Serpent.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;


Serpent::Serpent(unsigned int x,unsigned int y)
{
    srand((unsigned int)time(0));
    //unsigned int r =
    
    t = Terrain(50, 50);
    assert(x>=0 && x<=t.getTailleX());
    assert(y>=0 && y<=t.getTailleY());
    TeteX = x;
    TeteY = y;
    //t[y*(t.getTailleX())+x]=!&t[y*(t.getTailleX())+x];
    //Je n'y suis pas arrivé, il faudrait changer la valeur du booléen du tableau alloué (terrain) lorqu'on créer le serpent..
    
    droite = false;
    gauche = false;
    vivant = true;
    score = 0;
    
    //direction = ;
    
    couleur = Couleur(rand()%255 +0, rand()%255 +0, rand()%255 +0);
}


Serpent::~Serpent()
{
    if (t != NULL) //Je me suis mélangé pour le terrain du serpent, j'ai du confondre avec un pointeur.. Bref c'est faux
    {
        delete[] t; // ici aussi
        t = NULL;   // ici aussi du coup
    }
    TeteX = NULL;
    TeteY = NULL;
    droite = false;
    gauche = false;
    vivant = true;
    score = 0;
    couleur.~Couleur();
}


unsigned int Serpent::getTeteX()const
{
    return TeteX;
}


unsigned int Serpent::getTeteY()const
{
    return TeteY;
}


bool Serpent::getVivant()const
{
    return vivant;
}


unsigned int Serpent::getScore()const
{
    return score;
}


void Serpent::setTeteX(unsigned int x)
{
    TeteX = x;
}


void Serpent::setTeteY(unsigned int y)
{
    TeteY = y;
}


// J'ai pas compris a quoi correspond la direction..


bool Serpent::VerifColision(const Terrain &T) const
{
    if (TeteX==0 || TeteY==0)
    {
        return true;
    }
    // Autres cas à faire..
}
