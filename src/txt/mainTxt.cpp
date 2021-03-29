#include <winTxt.h>
#include <txtJeu.h>

int main (int argc, char** argv){
    termClear();
    Jeu jeu(110,60);
    txtBoucle(jeu);
    termClear();
    return 0;
}
