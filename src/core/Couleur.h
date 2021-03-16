/**
@brief Module gérant les couleurs des joueurs

Le module Couleur permet de gérer les couleurs des serpents et de leur trace.

@file Couleur.h
@author : Aymeric Leto, Benoît Briguet, Nathan Puricelli
@date : Mars 2021
*/
#ifndef COULEUR_h
#define COULEUR_h


class Couleur
{
public :
    /**
    @brief Quantité de rouge dans la couleur.
    */
    unsigned int r;
    
    /**
    @brief Quantité de vert dans la couleur.
    */
    unsigned int g;
    
    /**
    @brief Quantité de bleu dans la couleur.
    */
    unsigned int b;
    
private :
    /**
    @brief Constructeur par défaut de la classe : initialise le couleur en noir.
    */
    Couleur();

    /**
    @brief Constructeur de la classe: initialise le pixel avec les couleurs R G B fournies.
    @warning nr, ng et nb doivent être compris entre 0 et 255 inclus
    @param[in] nr Valeur de la composante rouge de la couleur
    @param[in] ng Valeur de la composante verte de la couleur
    @param[in] nb Valeur de la composante bleue de la couleur
    */
    Couleur(unsigned int nr, unsigned int ng, unsigned int nb);
    
    /**
    @brief Destructeur de la classe.
    */
    ~Couleur();

    /**
    @brief Accesseur : récupère la couleur.
    */
    Couleur getCouleur() const;
    
    /**
    @brief Mutateur : modifie la couleur.
    @warning nr, ng et nb doivent être compris entre 0 et 255 inclus
    @param[in] nr Valeur de la composante rouge de la couleur
    @param[in] ng Valeur de la composante verte de la couleur
    @param[in] nb Valeur de la composante bleue de la couleur
    */
    void setCouleur(unsigned int nr, unsigned int ng, unsigned int nb);

};

#endif /* Couleur_h */
