#include "sdlJeu.h"
/*v2904 Stable
CAD :
Jouable à deux, score et écran de mort
*/
int main(int argc, char* argv[])
{
    sdlJeu sjeu(140,72);
    sjeu.sdlBoucle();
    return 0;
}