#include "fenetreJeu.h"

fenetreJeu::fenetreJeu(int x, int y, int w, int h)
{
    surface = NULL;
    texture = NULL;
    surface = SDL_CreateRGBSurface(0,w,h,32,0,0,0,0);
    Uint32 color = SDL_MapRGB(surface->format,50,50,50);
    SDL_FillRect(surface, NULL, color);
    rect = surface->clip_rect;

    origin_x = 0;
    origin_y = 0;

    rect.x = x - origin_x;
    rect.y = y - origin_y;
}

fenetreJeu::~fenetreJeu()
{
    SDL_FreeSurface(surface);
    texture = NULL;
}

void fenetreJeu::draw(SDL_Renderer* renderer)
{
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}