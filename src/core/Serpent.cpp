/**
@brief Implémentation de la classe serpent

@file Serpent.cpp
@author : Aymeric Leto, Benoît Briguet, Nathan Puricelli
@date : Mars 2021
*/
const float PI = 3.1415926535;

#include "Serpent.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <math.h> 
using namespace std;

Serpent::Serpent() {
    TeteX = 0;
    TeteY = 0;
    vivant = true;
    score = 0;
    direction = 0;
    couleur = Couleur(0,0,0);
    CompteurTrous = 0;
}

Serpent::Serpent(float x,float y)
{   
    srand((unsigned int)time(0));

    //assert(x>=0 && x<=t.getTailleX());
    //assert(y>=0 && y<=t.getTailleY());

    TeteX = x;
    TeteY = y;
    //t[y*(t.getTailleX())+x]=!&t[y*(t.getTailleX())+x];
    //Je n'y suis pas arrivé, il faudrait changer la valeur du booléen du tableau alloué (terrain) lorqu'on créer le serpent..

    vivant = true;
    score = 0;
    
    direction = (rand()%4) * 90; // pas valide en sdl
    
    couleur = Couleur(rand()%256, rand()%256, rand()%256);
    CompteurTrous = 0;

    cout<<"Construction Serpent en "<<x<<" "<<y<<": Check"<<endl;
}


Serpent::~Serpent()
{
    //Pas sur que tout ça soit nécessaire (A)
    vivant = true;
    score = 0;
    couleur.~Couleur();
}


float Serpent::getTeteX()const
{
    return TeteX;
}

float Serpent::getTeteY()const
{
    return TeteY;
}

bool Serpent::getVivant()const
{
    return vivant;
}

int Serpent::getScore()const
{
    return score;
}

float Serpent::getDirection() const
{
    return direction;
}

Couleur Serpent::getCouleur()const
{
    return couleur;
}

void Serpent::setDirection(float dir)
{
    direction = dir;
}

void Serpent::setVivant(bool vie)
{
    vivant = vie;
}

void Serpent::setTeteX(float x)
{
    TeteX = x;
}

void Serpent::setTeteY(float y)
{
    TeteY = y;
}

void Serpent::augmenterScore(int s) {
    score+=s;
}

//supprimre les if pour la version sdl
//cos de l'angle : valeur sur x
//sin : valeur sur y
void Serpent::avancerTXT(Terrain &t)
{
    if ((CompteurTrous%30) >= 6) t.tabCasesOccupees[(int) TeteX][(int) TeteY] = true;    
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
    if ((CompteurTrous%30) >= 5) t.tabCasesOccupees[(int) TeteX][(int) TeteY] = true;    

    float avanceeX = 1.42 * cos(direction * PI / 180);
    float avanceeY = 1.42 * sin(direction * PI / 180);
    /*avanceeX = (int) avanceeX;
    avanceeY = (int) avanceeY;*/
    if (avanceeX > 1) avanceeX = 1;
    if (avanceeX < -1) avanceeX = -1;

    if (avanceeY > 1) avanceeY = 1;
    if (avanceeY < -1) avanceeY = -1;
    TeteX += avanceeX;
    TeteY += avanceeY;


    CompteurTrous++;
}


// J'ai pas compris a quoi correspond la direction..

// C'est une valeur entre 0 et 360 (360 c'est à voir) qui determine l'orientation de la tete du serpent
// Dans la version texte ce sera surement 0, 90, 180, 270 seulement
// C'est la direction dans laquelle avancer quand une seconde passe et que le joueur ne tourne pas

bool Serpent::VerifColision(const Terrain &t) const
{
    //Vérifie les cases à gauche et à droite de la tête du serpent, ce qui dépent donc de sa direction.
    //On vérifie les déplacements dans cet ordre : droite haut gauche bas
    if ((direction > 315 || direction <= 45) || (direction > 135 && direction <= 225)) //droite ou gauche
        return ((TeteX==0) || (TeteX>=t.getTailleX()) || (TeteY==0) || (TeteY>=t.getTailleY()) 
            || (t.tabCasesOccupees[(int) TeteX][(int) TeteY])
            || (t.tabCasesOccupees[(int) TeteX][(int) TeteY + 1]) || (t.tabCasesOccupees[(int) TeteX][(int) TeteY - 1]));

    if ((direction > 45 && direction <= 135) || (direction > 225 && direction <= 315)) //haut ou bas
        return ((TeteX==0) || (TeteX>=t.getTailleX()) || (TeteY==0) || (TeteY>=t.getTailleY()) 
            || (t.tabCasesOccupees[(int) TeteX][(int) TeteY])
            || (t.tabCasesOccupees[(int) TeteX + 1][(int) TeteY]) || (t.tabCasesOccupees[(int) TeteX - 1][(int) TeteY]));

    return ((TeteX==0) || (TeteX>=t.getTailleX()) || (TeteY==0) || (TeteY>=t.getTailleY()) 
            || (t.tabCasesOccupees[(int) TeteX][(int) TeteY]));
}
