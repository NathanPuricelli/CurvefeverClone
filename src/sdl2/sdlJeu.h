#ifndef SDLJEU_H
#define SDLJEU_H
#include "Jeu.h"
#include "fenetreJeu.h"
#include <iostream>

#ifdef _WIN32
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#elif __linux__
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#endif


class sdlJeu
{
public:
    sdlJeu(unsigned int tailleX, unsigned int tailleY, Couleur couleur1, Couleur couleur2);
    ~sdlJeu();
    void sdlAff(); //private ?
    void sdlBoucle();    
    bool gameRunning; //private ?

private:
    Jeu jeu;
    FenetreJeu fenetreJeu;
    SDL_Window * window;
    SDL_Renderer * renderer;
    void surfaceToTexture();
    void sdlActionsAutomatiques();
};


#endif