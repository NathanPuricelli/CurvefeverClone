#ifndef SDLJEU_H
#define SDLJEU_H
#include "Jeu.h"
#include "Image.h"
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
    void sdlAff(bool boutonRecommencer, bool boutonQuitter); //private ?
    void sdlBoucle();    
    bool gameRunning; //private ?
    

private:
    Jeu jeu;
    FenetreJeu fenetreJeu;
    Image imageTitreJeu;
    Image imageDroiteJeu;
    Image imQuitterPresse;
    Image imQuitter;
    Image imRecommencerPresse;
    Image imRecommencer;
    TTF_Font * font32;
    TTF_Font * font64;
    SDL_Color blanc;
    SDL_Window * window;
    SDL_Renderer * renderer;
    bool isIn(int x, int y, int w, int h, int souris_x, int souris_y);
    void renderCenterText(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor);
    void renderText(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor);
    void surfaceToTexture();
    void sdlActionsAutomatiques();
    void recommencerPartie();
};


#endif