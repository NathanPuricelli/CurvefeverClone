#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"
#include "Jeu.h"

void txtAff(WinTXT & win, const Jeu & jeu) {
	const Serpent& s1 = jeu.getConstS1();
	const Serpent& s2 = jeu.getConstS2();

	win.clear();

    // Affichage de la grille et des serpents
	for(unsigned int x=0;x<jeu.t.getTailleX();++x)
	{
		for(unsigned int y=0;y<jeu.t.getTailleY();++y)
		{
			if(jeu.t.tabCasesOccupees[x][y])
			{
				win.print(x,y,'*');
			}
			else win.print(x,y,' ');
		}
	}			

    // Affichage du serpent 1
	win.print(s1.getTeteX(),s1.getTeteY(),'1');
	// Affichage du serpent 2
	win.print(s2.getTeteX(),s2.getTeteY(),'2');

	win.draw();
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.t.getTailleX(),jeu.t.getTailleY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(10);
		#else
		usleep(100000);
        #endif // WIN32

		jeu.actionsAutomatiquesTXT();

		c = win.getCh();
		switch (c) {
			case 'q':
				jeu.actionClavierTXT('q');
				break;
			case 'd':
				jeu.actionClavierTXT('d');
				break;
			case 'k':
				jeu.actionClavierTXT('k');
				break;
			case 'm':
				jeu.actionClavierTXT('m');
				break;
			case 'e':
				ok = false;
				break;
		}

	} while (ok && jeu.getConstS1().getVivant() && jeu.getConstS2().getVivant());

}
