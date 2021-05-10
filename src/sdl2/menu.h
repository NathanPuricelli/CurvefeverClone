#ifndef MENU_H
#define MENU_H

#include "Couleur.h"
#include "Image.h"
#include <iostream>

#ifdef _WIN32
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#elif __linux__
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#endif

class Menu
{
private:
    Image imMenuPresse;
    Image imMenu;
	SDL_Window* window; //pour la fenetre principale du menu
	SDL_Renderer* renderer; //pour les affichages de la fenetre principale
	SDL_Event event;
	TTF_Font* font;
	SDL_Color font_color1; //couleur de police du joueur 1
    SDL_Color font_color2; //couleur de police du joueur 2

public:
    Menu();
    ~Menu();
    void menuAff(bool sourisSurJoueur);
    void boucleRemplissage();
    bool isIn(int x, int y, int w, int h, int souris_x, int souris_y);
    Couleur couleurJ1;
    Couleur couleurJ2;
};

#endif