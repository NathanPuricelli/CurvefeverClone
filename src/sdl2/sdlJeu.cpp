#include "sdlJeu.h"
#include <cassert>

#define fps 60
#define window_width 1280
#define window_height 720

//commencer avec une fenetre avec terrain vide et mettre des points à la main dans le main.



// ============= CLASS SDLJEU =============== //

sdlJeu::sdlJeu(unsigned int tailleX, unsigned int tailleY, Couleur couleur1, Couleur couleur2):jeu(tailleX, tailleY, couleur1, couleur2), fenetreJeu(0,90)
{
    //Initialisation de la sdl : 
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (!(IMG_Init(IMG_INIT_PNG)) || (!(IMG_Init(IMG_INIT_JPG)))) {
        cout << "SDL_image could not initialize! SDL_image Error: " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    //creation de la fenetre : 
    window = SDL_CreateWindow("Curvefever !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    //creation du rendu : 
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        cout << "Erreur lors de la creation du renderer : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    //chargement de l'image du plateau de jeu
    gameRunning = false;
    fenetreJeu.couleurJoueurs(jeu);
}

sdlJeu::~sdlJeu()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::recommencerPartie() {
    for (unsigned int i = 0; i < jeu.t.getTailleX(); i++) {
        for (unsigned int j = 0; j < jeu.t.getTailleY(); j++) {
            jeu.t.tabCasesOccupees[i][j] = 0;
        }
    }
    jeu.getS1().setTeteX(10);
    jeu.getS1().setTeteY(10);
    jeu.getS1().setVivant(true);
    jeu.getS1().setDirection(0);
    
    
    jeu.getS2().setTeteX(jeu.t.getTailleX() - 10);
    jeu.getS2().setTeteY(jeu.t.getTailleY() - 10);
    jeu.getS2().setVivant(true);
    jeu.getS2().setDirection(180);

}


void sdlJeu::sdlActionsAutomatiques()
{
    jeu.actionsAutomatiquesSDL();
    fenetreJeu.fillSurfaceOnMotion(jeu);
}

void sdlJeu::sdlAff()
{
    //Remplir l'écran de noir
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //Affichage de la fenetre de jeu
    fenetreJeu.draw(renderer);

    //Affichage du score des joueurs

    //affichage de l'image de fond d'affichage des scores

    //Afichage des boutons recommencer la partie, quitter le jeu. 
    
}

void sdlJeu::sdlBoucle()
{
    gameRunning = true;
    bool J1GaucheAppuye = false;
    bool J1DroiteAppuye = false;
    bool J2GaucheAppuye = false;
    bool J2DroiteAppuye = false;


    Uint32 starting_ticks = SDL_GetTicks(), ticks;
    SDL_Event events;

    /*
    while(gameRunning && jeu.getConstS1().getVivant() && jeu.getConstS2().getVivant())
    {
        ticks = SDL_GetTicks();
        if (ticks - starting_ticks > 1000 / fps)
        {
            sdlActionsAutomatiques();
            starting_ticks = ticks;
        }

        while(SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT) gameRunning = false;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
				switch (events.key.keysym.sym) {
				case SDLK_q:
					jeu.actionClavierSDL('q');
                    break;
				case SDLK_d:
					jeu.actionClavierSDL('d');    
					break;
				case SDLK_k:
					jeu.actionClavierSDL('k');
					break;
				case SDLK_m:
					jeu.actionClavierSDL('m');
					break;
                case SDLK_ESCAPE:
                    gameRunning = false;
				default: break;
                }
            }
        }
        sdlAff();
        SDL_RenderPresent(renderer);

    }*/
    while(gameRunning)
    {
        if (jeu.getConstS1().getVivant() && jeu.getConstS2().getVivant()) {
            ticks = SDL_GetTicks();
            if (ticks - starting_ticks > 1000 / fps)
            {
                sdlActionsAutomatiques();

                jeu.actionClavierSDL(J1GaucheAppuye, J1DroiteAppuye, J2GaucheAppuye, J2DroiteAppuye);
                starting_ticks = ticks;

                sdlAff();
                SDL_RenderPresent(renderer);
            }

            while(SDL_PollEvent(&events)) {
                switch (events.type) {
                    case SDL_QUIT:
                        gameRunning = false;
                        break;
                    case SDL_KEYDOWN:
                        switch (events.key.keysym.sym) {
                            case SDLK_q:
                                J1GaucheAppuye = true;
                                break;
                            case SDLK_d:
                                  J1DroiteAppuye = true;
                                break;
                            case SDLK_k:
                                J2GaucheAppuye = true;
                                break;
                            case SDLK_m:
                                J2DroiteAppuye = true;
                                break;
                        }
                        break;
                    case SDL_KEYUP:
                        switch (events.key.keysym.sym) {
                            case SDLK_q:
                                J1GaucheAppuye = false;
                                break;
                            case SDLK_d:
                                J1DroiteAppuye = false;
                                break;
                            case SDLK_k:
                                J2GaucheAppuye = false;
                                break;
                            case SDLK_m:
                                J2DroiteAppuye = false;
                                break;
                        }
                        break;
                }
            }
            
        } else {
            if (!jeu.getConstS1().getVivant()) {
                //renderCenterText(0, -20, "Joueur 1 est mort", font32, blanc);
                jeu.getS2().augmenterScore(1);
            } else {
                //renderCenterText(0, -20, "Joueur 2 est mort", font32, blanc);
                jeu.getS1().augmenterScore(1);
            }
            //renderCenterText(0, 10, "Appuyez sur espace pour continuer", font32, blanc);
            SDL_RenderPresent(renderer);
            bool reprendrePartie = false;
            while (!reprendrePartie) {
                while(SDL_PollEvent(&events)) {
                    if (events.type == SDL_QUIT) {
                        gameRunning = false;        // Si l'utilisateur a clique sur la croix de fermeture
                        reprendrePartie = true;
                    }
                    else if (events.type == SDL_KEYDOWN && events.key.keysym.sym == SDLK_SPACE) {
                        reprendrePartie = true;
                        recommencerPartie();
                        J1GaucheAppuye = false;
                        J1DroiteAppuye = false;
                        J2GaucheAppuye = false;
                        J2DroiteAppuye = false;
                        SDL_SetRenderDrawColor(renderer, 20, 20, 50, 255);
                        SDL_RenderClear(renderer);
                    }
                }
            }
        }
    }


}