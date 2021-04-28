#include "jeu.h"
#include <SDL.h>
#include <SDL_image.h>

class fenetreJeu
{
private:
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
    int origin_x, origin_y;
    Uint32 couleurFond;

public:
    fenetreJeu(int x, int y, int w = 1120, int h = 630);
    ~fenetreJeu();
    void update();
    void draw(SDL_Renderer* renderer);
    void fillSurfaceOnMotion(const Jeu &j);
    void setPix(Uint32 color, int x, int y);

};