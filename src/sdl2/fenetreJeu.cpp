#include "fenetreJeu.h"
#define TAILLE_SPRITE 4
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
    couleurFond = SDL_MapRGB(surface->format, 50,50,50);
}



fenetreJeu::~fenetreJeu()
{
    SDL_FreeSurface(surface);
    texture = NULL;
}

void fenetreJeu::setPix(Uint32 color, int x, int y)
{    
    SDL_Rect pixel;
    pixel.w = TAILLE_SPRITE, pixel.h = TAILLE_SPRITE;
    pixel.x = x * TAILLE_SPRITE, pixel.y = y* TAILLE_SPRITE; 
    SDL_FillRect(surface, &pixel, color);
}

void fenetreJeu::fillSurfaceOnMotion(const Jeu &j)
{
    Uint32 couleur1 = SDL_MapRGB(surface->format, j.getConstS1().getCouleur().getRouge(), j.getConstS1().getCouleur().getVert(), j.getConstS1().getCouleur().getBleu());
    Uint32 couleur2 = SDL_MapRGB(surface->format, j.getConstS2().getCouleur().getRouge(), j.getConstS2().getCouleur().getVert(), j.getConstS2().getCouleur().getBleu());
    /*
    for (int i = 0; i < j.t.getTailleX(); i++) {
        for (int k = 0; k < j.t.getTailleY(); k++) {
            if(j.t.tabCasesOccupees[i][k] == 1) {
                setPix(couleur1, i, k);
            }
            else if(j.t.tabCasesOccupees[i][k] == 2)
            {
                setPix(couleur2, i, k);
            }
        }
    }*/
    setPix(couleur1, j.getConstS1().getTeteX(), j.getConstS1().getTeteY());
    setPix(couleur2, j.getConstS2().getTeteX(), j.getConstS2().getTeteY());
    if (j.t.tabCasesOccupees[j.getConstS1().x_precedent][j.getConstS1().y_precedent] == 0) setPix(couleurFond, j.getConstS1().x_precedent, j.getConstS1().y_precedent);
    if (j.t.tabCasesOccupees[j.getConstS2().x_precedent][j.getConstS2().y_precedent] == 0) setPix(couleurFond, j.getConstS2().x_precedent, j.getConstS2().y_precedent);
    
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