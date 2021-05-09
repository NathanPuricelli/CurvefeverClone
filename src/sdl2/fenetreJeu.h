#ifndef _FENETRE_JEU_H
#define _FENETRE_JEU_H

#include "jeu.h"
#include <SDL.h>
#include <SDL_image.h>

class FenetreJeu
{
private:
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
    int origin_x, origin_y;
    Uint32 couleurFond;
    Uint32 couleurJ1;
    Uint32 couleurJ2;

public:
    FenetreJeu(int x, int y, int w = 1122, int h = 630);
    ~FenetreJeu();
    void couleurJoueurs(const Jeu &j); // doit etre appelée avant de lancer la partie
    void update();
    void draw(SDL_Renderer* renderer);
    void fillSurfaceOnMotion(const Jeu &j);
    void setPix(Uint32 color, int x, int y);

};

#endif