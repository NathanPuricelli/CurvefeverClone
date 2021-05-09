#include "sdlJeu.h"
#include <cassert>

#define fps 30
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
    fenetreJeu.draw(renderer);
    
}

void sdlJeu::sdlBoucle()
{
    gameRunning = true;
    Uint32 starting_ticks = SDL_GetTicks(), ticks;
    SDL_Event events;
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

    }
}