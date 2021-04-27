/**
@brief Implémentation de la classe jeu

@file Terrain.cpp
@author : Aymeric Leto, Benoît Briguet, Nathan Puricelli
@date : Mars 2021
*/

#include "Jeu.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
using namespace std;

Jeu::Jeu() {}

Jeu::Jeu(unsigned int tailleX, unsigned int tailleY) {
    assert(tailleX>=30);
    assert(tailleY>=30);
    t = Terrain(tailleX, tailleY);
    s1 = Serpent(10,10);
    s2 = Serpent(t.getTailleX() - 10, t.getTailleY() -10);
    s1.setDirection(0);
    s2.setDirection(180);
}

Jeu::~Jeu() {}

Serpent& Jeu::getS1() {return s1;}

Serpent& Jeu::getS2() {return s2;}

const Serpent& Jeu::getConstS1() const {return s1;}

const Serpent& Jeu::getConstS2() const {return s2;}


void Jeu::actionsAutomatiquesTXT() {
    s1.avancerTXT(t);
    s2.avancerTXT(t);
    if(s1.VerifColision(t))
    {
        s1.setVivant(false);
    }
    if(s2.VerifColision(t))
    {
        s2.setVivant(false);
    }

}

void Jeu::actionsAutomatiquesSDL() {
    s1.avancerSDL(t);
    s2.avancerSDL(t);
    if(s1.VerifColision(t))
    {
        s1.setVivant(false);
    }
    if(s2.VerifColision(t))
    {
        s2.setVivant(false);
    }

}

void Jeu::actionClavierTXT(const char touche) {
    //Serpent 1 utilise q et d
    //Serpent 2 utilise k et m
    switch (touche)
    {
    case 'q':
        s1.setDirection((s1.getDirection() + 90 ) % 360);
        break;
    case 'd':
        s1.setDirection((s1.getDirection() + 270 ) % 360);
        break;
    case 'k':
        s2.setDirection((s2.getDirection() + 90 ) % 360);
        break;
    case 'm':
        s2.setDirection((s2.getDirection() + 270 ) % 360);    
    }
}

void Jeu::actionClavierSDL(const char touche)
{
    //Serpent 1 utilise q et d
    //Serpent 2 utilise k et m
    switch (touche)
    {
    case 'q':
        s1.setDirection((s1.getDirection() + 90 ) % 360);
        break;
    case 'd':
        s1.setDirection((s1.getDirection() + 270 ) % 360);
        break;
    case 'k':
        s2.setDirection((s2.getDirection() + 90 ) % 360);
        break;
    case 'm':
        s2.setDirection((s2.getDirection() + 270 ) % 360);    
    }
}

