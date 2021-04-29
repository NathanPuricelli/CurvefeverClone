/**
@brief Module gérant les serpents.

Le module Serpent permet de gérer un serpent et ses informations.

@file Serpent.h
@author : Aymeric Leto, Benoît Briguet, Nathan Puricelli
@date : Mars 2021
*/
#ifndef SERPENT_H
#define SERPENT_H

#include <iostream> 
#include "Couleur.h"
#include "Terrain.h"

using namespace std;

class Serpent
{
private :
    /**
    @brief La position de la tête du serpent, TeteX dans la hauteur et TeteY dans la largeur du terrain de jeu.
    */
    float TeteX, TeteY;
    
    /**
    @brief Booléens pour indiquer si le serpent est toujours en vie.
    */
    bool vivant;
    
    /**
    @brief Le score du joueur du serpent.
    */
    int score;
    
    /**
    @brief La direction du serpent.
    */
    float direction; // mettre un float car convertir en rad
    
    /**
    @brief La couleur du serpent.
    */
    Couleur couleur;

    /**
    @brief Variable servant à la gestion des trous dans la trace.
    */
    int CompteurTrous;

public :
    /**
    @brief Constructeur par défaut de la classe: initialise le serpent.
    */
    Serpent(); // pas hyper utile je pense
    
    /**
    @brief Constructeur de la classe: initialise le serpent à la position donnée par (x,y) dans un terrain de 50 par 50, avec une couleur aléatoire.
    @warning x, y doivent être compris dans l'aire du terrain de jeu.
    @param[in] x Coordonnée de la tête dans la hauteur du terrain.
    @param[in] y Coordonnée de la tête dans la largeur du terrain.
    */
    Serpent(float x, float y); // voir pour couleur, direction.
    
    /**
    @brief Destructeur de la classe:
    */
    ~Serpent(); // destructeur
    
    /**
    @brief Accesseur : récupère la valeur de la coordonnée TeteX (dans la hauteur) de la tête du serpent.
    */
    float getTeteX()const ;
    
    /**
    @brief Accesseur : récupère la valeur de la coordonnée TeteY (dans la largeur) de la tête du serpent.
    */
    float getTeteY()const ;
    
    /**
    @brief Accesseur : récupère le booléen indiquant si le serpent est encore vivant.
    */
    bool getVivant()const ;
    
    /**
    @brief Accesseur : récupère le score du joueur du serpent.
    */
    int getScore()const ;
    
    /**
    @brief Accesseur : récupère la direction du serpent
    */
    float getDirection()const ;

    /**
    @brief Accesseur : récupère la couleur du serpent
    */
    Couleur getCouleur()const ;
    
    /**
    @brief Mutateur : change la direction du serpent
    */
    void setDirection(float dir);

    /**
    @brief Mutateur : change la vie du serpent
    */
    void setVivant(bool vie);


    /**
    @brief Mutateur: change la valeur de la coordonnée TeteX de la tête du serpent.
    @warning x doit appartenir à l'aire du terrain de jeu.
    @param[in] x Position de la tête dans la hauteur.
    */
    void setTeteX(float x);
    
    /**
    @brief Mutateur: change la valeur de la coordonnée TeteY de la tête du serpent.
    @warning y doit appartenir à l'aire du terrain de jeu.
    @param[in] y Position de la tête dans la largeur.
    */
    void setTeteY(float y);

    void augmenterScore(int s);
    
    /**
    @brief Fait avancer le serpent et choisi la nouvelle position de la tete en fonction de la direction
    @warning Fonctions trigonométriques complexes pour des mouvements précis, à refaire avec SDL
    */
    void avancerTXT(Terrain &t);

    void avancerSDL(Terrain &t);
    
    
    /**
    @brief Vérifie si un serpent est rentré en collision avec une trace ou avec un mur.
    @param[in] T Terrain de jeu.
    */
    bool VerifColision(const Terrain &t) const;

};

#endif
