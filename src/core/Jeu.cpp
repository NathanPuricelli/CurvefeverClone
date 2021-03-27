/**
@brief Implémentation de la classe jeu


@file Terrain.cpp
@author : Aymeric Leto, Benoît Briguet, Nathan Puricelli
@date : Mars 2021
*/

#include "jeu.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
using namespace std;

Jeu::Jeu() {

}

Jeu::Jeu(unsigned int tailleX, unsigned int tailleY) {
    t = Terrain(tailleX, tailleY);
}

Jeu::~Jeu() {
    
}

void Jeu::actionsAutomatiques() {

}

void Jeu::actionClavier(const char touche) {
    //Premiers essais avec q & d, k & m (A)

}
