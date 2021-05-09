#include "sdlJeu.h"
#include "menu.h"

int main(int argc, char* argv[])
{
    Menu menu;
    menu.boucleRemplissage();
    sdlJeu sjeu(374,210, menu.couleurJ1, menu.couleurJ2);
    
    sjeu.sdlBoucle();
    return 0;
}