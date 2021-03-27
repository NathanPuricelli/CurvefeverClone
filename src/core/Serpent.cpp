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

Serpent::Serpent() {

}

Serpent::Serpent(unsigned int x,unsigned int y)
{   
    srand((unsigned int)time(0));

    //assert(x>=0 && x<=t.getTailleX());
    //assert(y>=0 && y<=t.getTailleY());

    TeteX = x;
    TeteY = y;
    //t[y*(t.getTailleX())+x]=!&t[y*(t.getTailleX())+x];
    //Je n'y suis pas arrivé, il faudrait changer la valeur du booléen du tableau alloué (terrain) lorqu'on créer le serpent..
    
    droite = false;
    gauche = false;
    vivant = true;
    score = 0;
    
    direction = rand()%360;
    
    couleur = Couleur(rand()%255 +0, rand()%255 +0, rand()%255 +0);
}


Serpent::~Serpent()
{
    //Pas sur que tout ça soit nécessaire (A)
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

// C'est une valeur entre 0 et 360 (360 c'est à voir) qui determine l'orientation de la tete du serpent
// Dans la version texte ce sera surement 0, 90, 180, 270 seulement
// C'est la direction dans laquelle avancer quand une seconde passe et que le joueur ne tourne pas

bool Serpent::VerifColision(const Terrain &T) const
{
    if (TeteX==0 || TeteY==0)
    {
        return true;
    }
    // Autres cas à faire..
}
