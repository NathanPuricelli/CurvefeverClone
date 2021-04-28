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

public:
    fenetreJeu(int x, int y, int w = 960, int h = 540);
    ~fenetreJeu();
    void update();
    void draw(SDL_Renderer* renderer);

};