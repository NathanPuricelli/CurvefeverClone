#include "fenetreJeu.h"
#define TAILLE_SPRITE 6
FenetreJeu::FenetreJeu(int x, int y, int w, int h)
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
    couleurFond = SDL_MapRGB(surface->format, 50,50,50);
}

void FenetreJeu::couleurJoueurs(const Jeu &j)
{
    couleurJ1 = SDL_MapRGB(surface->format, j.getConstS1().getCouleur().getRouge(), j.getConstS1().getCouleur().getVert(), j.getConstS1().getCouleur().getBleu());
    couleurJ2 = SDL_MapRGB(surface->format, j.getConstS2().getCouleur().getRouge(), j.getConstS2().getCouleur().getVert(), j.getConstS2().getCouleur().getBleu());
}


FenetreJeu::~FenetreJeu()
{
    SDL_FreeSurface(surface);
    texture = NULL;
}

void FenetreJeu::setPix(Uint32 color, int x, int y)
{    
    SDL_Rect pixel;
    pixel.w = TAILLE_SPRITE, pixel.h = TAILLE_SPRITE;
    pixel.x = x * TAILLE_SPRITE, pixel.y = y* TAILLE_SPRITE; 
    SDL_FillRect(surface, &pixel, color);
}

void FenetreJeu::fillSurfaceOnMotion(const Jeu &j)
{
    if (j.t.tabCasesOccupees[j.getConstS1().x_precedent][j.getConstS1().y_precedent] == 0) setPix(couleurFond, j.getConstS1().x_precedent, j.getConstS1().y_precedent);
    if (j.t.tabCasesOccupees[j.getConstS2().x_precedent][j.getConstS2().y_precedent] == 0) setPix(couleurFond, j.getConstS2().x_precedent, j.getConstS2().y_precedent);
    setPix(couleurJ1, j.getConstS1().getTeteX(), j.getConstS1().getTeteY());
    setPix(couleurJ2, j.getConstS2().getTeteX(), j.getConstS2().getTeteY());
}

void FenetreJeu::draw(SDL_Renderer* renderer)
{
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}