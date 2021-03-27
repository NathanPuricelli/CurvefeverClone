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
    
public :
    /**
    @brief Constructeur de la classe, lance une partie avec 2 serpents et 1 terrain de jeu.
    */
    Jeu();

    /**
    @brief Constructeur de la classe, lance une partie avec 2 serpents et 1 terrain de jeu.
    */
    Jeu(unsigned int tailleX, unsigned int tailleY);
    
    /**
    @brief Destructeur de la classe.
    */
    ~Jeu();

    /**
    @brief Terrain de jeu de la partie.
    */
    Terrain t;

    /**
    @brief Actions qui se déroulent à chaque boucle
    */
    void actionsAutomatiques();

    /**
    @brief Réactions du jeu au touches pressées
    */
    void actionClavier(const char touche);
};

#endif
