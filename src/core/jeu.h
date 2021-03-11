#ifndef _JeuH
#define _JeuH

#include "Serpent.h"
#include "Terrain.h"
class Jeu
{
private :
    Serpent s1;
    Serpent s2;
    Terrain t;
public : 
    Jeu();
    ~Jeu();
};

#endif