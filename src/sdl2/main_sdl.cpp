#include "sdlJeu.h"
/*v0605
CAD : -Menu
- Trajectoire corrigées
- Résolution bug serpent qui traverse l'autre au calme
- Nouveau dessins de serpents, à partir de cercles

*/
int main(int argc, char* argv[])
{
    sdlJeu sjeu(140,72);
    sjeu.sdlBoucle();
    return 0;
}