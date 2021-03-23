#ifndef JEU_H
#define JEU_H

#include "Serpent.h"
#include "Terrain.h"
class Jeu
{
private :
    /**
    @brief Permier serpent de la partie (celui du joueur 1).
    */
    Serpent s1;
    
    /**
    @brief Second serpent de la partie (celui du joueur 2).
    */
    Serpent s2;
    
    /**
    @brief Terrain de jeu de la partie.
    */
    Terrain t;
    
public :
    /**
    @brief Constructeur de la classe, lance une partie avec 2 serpents et 1 terrain de jeu.
    */
    Jeu();
    
    /**
    @brief Destructeur de la classe.
    */
    ~Jeu();
};

#endif
