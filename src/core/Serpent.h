#ifndef SERPENT_H
#define SERPENT_H

#include <iostream>
#include "Couleur.h"

using namespace std;

class Serpent
{
private :
    int TeteX, TeteY;
    bool droite, gauche;
    int score;
    unsigned int direction; 
    Couleur couleur;

public : 
    Serpent();
    Serpent(int x, int y); // voir pour couleur, direction.
    ~Serpent(); // destructeur
    int getTeteX()const ;
    int getTeteY()const ;
    unsigned int getDirection()const ;
    void setDirection();
    void setTeteX();
    void setTeteY();
    bool VerifColision(const terrain &T) const;

};

#endif
