#ifndef _SERPENT
#define _SERPENT

#include <iostream>

struct Couleur
{
    unsigned char r, g, b;
};

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
    Couleur getCouleur();
    int getTeteX()const ;
    int getTeteY()const ;
    unsigned int getDirection()const ;
    void setDirection();
    void setTeteX();
    void setTeteY();
    void setCouleur(unsigned char r, unsigned char g, unsigned char b);

    bool VerifColision(const terrain &T) const;

};

#endif