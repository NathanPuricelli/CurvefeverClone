/**
@brief Module gérant le jeu.

Le module Jeu permet de gérer le jeu et les différentes actions.

@file Jeu.h
@author : Aymeric Leto, Benoît Briguet, Nathan Puricelli
@date : Mars 2021
*/
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
    @brief Terrain de jeu de la partie.
    */
    Terrain t;
    
    /**
    @brief Constructeur par défaut de la classe.
    */
    Jeu();

    /**
    @brief Constructeur de la classe, lance une partie avec 2 serpents et 1 terrain de jeu de taille tailleX x tailleY.
    @warning tailleX, tailleY doivent être assez grand pour accueillir les 2 serpents aux coordonnées (x, y) respectives (10, 10) et (tailleX-10, tailleY-10) : pour assurer la jouabilité on prendra tailleX et tailleY supérieurs à 30.
    @param[in] tailleX Hauteur du terrain.
    @param[in] tailleY Largeur du terrain.
    */
    Jeu(unsigned int tailleX, unsigned int tailleY, Couleur couleur1, Couleur couleur2);
    
    /**
    @brief Destructeur de la classe.
    */
    ~Jeu();

    /**
    @brief Accesseur : Récupère l'adresse du premier serpent.
    */
    Serpent& getS1();

    /**
    @brief Accesseur : Récupère l'adresse du deuxième serpent.
    */
    Serpent& getS2();

    /**
    @brief Accesseur : Récupère l'adresse du premier serpent en const.
    */
    const Serpent& getConstS1() const;

    /**
    @brief Accesseur : Récupère l'adresse du premier serpent en const.
    */
    const Serpent& getConstS2() const;

    /**
    @brief Actions qui se déroulent à chaque boucle
    */
    void actionsAutomatiquesTXT();

    void actionsAutomatiquesSDL();

    /**
    @brief Réactions du jeu au touches pressées
    @param[in] touche Touche du clavier pressée qui détermine ainsi l'action.
    */
    void actionClavierTXT(const char touche);

    void actionClavierSDL(const char touche);
};

#endif
