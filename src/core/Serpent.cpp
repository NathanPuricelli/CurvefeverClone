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
    TeteX = 0;
    TeteY = 0;
    droite = false;
    gauche = false;
    vivant = true;
    score = 0;
    direction = 0;
    couleur = Couleur(0,0,0);
    CompteurTrous = 0;
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
    
    direction = (rand()%4) * 90; // pas valide en sdl
    
    couleur = Couleur(rand()%256, rand()%256, rand()%256);
    CompteurTrous = 0;

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

bool Serpent::getGauche()const
{
    return gauche;
}

bool Serpent::getDroite()const
{
    return droite;
}

unsigned int Serpent::getScore()const
{
    return score;
}

unsigned int Serpent::getDirection() const
{
    return direction;
}

Couleur Serpent::getCouleur()const
{
    return couleur;
}

void Serpent::setDirection(unsigned int dir)
{
    direction = dir;
}

void Serpent::setVivant(bool vie)
{
    vivant = vie;
}

void Serpent::setTeteX(unsigned int x)
{
    TeteX = x;
}


void Serpent::setTeteY(unsigned int y)
{
    TeteY = y;
}

//supprimre les if pour la version sdl
//cos de l'angle : valeur sur x
//sin : valeur sur y
void Serpent::avancerTXT(Terrain &t)
{
    if ((CompteurTrous%30) >= 6) t.tabCasesOccupees[TeteX][TeteY] = true;    
    if (direction == 0)
    {
        TeteY++;
    }
    else if (direction == 90)
    {
        TeteX++;
    }
    else if (direction == 180)
    {
        TeteY--;
    }
    else TeteX--;    
    CompteurTrous++;
}


void Serpent::avancerSDL(Terrain &t)
{
    if ((CompteurTrous%30) >= 6) t.tabCasesOccupees[TeteX][TeteY] = true;    
    if (direction == 0)
    {
        TeteY++;
    }
    else if (direction == 90)
    {
        TeteX++;
    }
    else if (direction == 180)
    {
        TeteY--;
    }
    else TeteX--;    
    CompteurTrous++;
}


// J'ai pas compris a quoi correspond la direction..

// C'est une valeur entre 0 et 360 (360 c'est à voir) qui determine l'orientation de la tete du serpent
// Dans la version texte ce sera surement 0, 90, 180, 270 seulement
// C'est la direction dans laquelle avancer quand une seconde passe et que le joueur ne tourne pas

bool Serpent::VerifColision(const Terrain &t) const
{
    return ((TeteX==0) || (TeteX>=t.getTailleX()) || (TeteY==0) || (TeteY>=t.getTailleY()) || (t.tabCasesOccupees[TeteX][TeteY]));
}
