#ifndef SDLJEU_H
#define SDLJEU_H
#include "Jeu.h"
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

class Image {

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;

public:
    Image () ;
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};

class sdlJeu
{
public:
    sdlJeu(int tailleX, int tailleY);
    ~sdlJeu();
    void sdlAff(); //private ?
    void sdlBoucle();    
    bool gameRunning; //private ?

private:
    Jeu jeu;
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Surface * surfaceJeu;
    SDL_Texture * textureJeu;
    TTF_Font* font32;
    void renderCenterText(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor);
    void surfaceToTexture();
    void setPixel(SDL_Surface *screen, int x, int y, Couleur color);
    void sdlActionsAutomatiques();
};


#endif