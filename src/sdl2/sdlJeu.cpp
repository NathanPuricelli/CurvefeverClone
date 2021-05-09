#include "sdlJeu.h"
#include <cassert>

#define fps 15
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

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }


    font32 = TTF_OpenFont("data/fonts/cocogoose.ttf", 32);
    if (font32 == NULL)
        font32 = TTF_OpenFont("../data/fonts/cocogoose.ttf", 32);
    if (font32 == NULL) {
            cout << "Erreur lors du chargement de cocogoose.ttf! SDL_TTF Error: " << SDL_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}

    font64 = TTF_OpenFont("data/fonts/cocogoose.ttf", 64);
    if (font64 == NULL)
        font64 = TTF_OpenFont("../data/fonts/cocogoose.ttf", 64);
    if (font64 == NULL) {
            cout << "Erreur lors du chargement de cocogoose.ttf! SDL_TTF Error: " << SDL_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}

    blanc = { 255, 255, 255 };

    //chargement des images;
    imageTitreJeu.loadFromFile("data/img/imTitreJeu.png", renderer);
    imageDroiteJeu.loadFromFile("data/img/imDroiteJeu.png", renderer);
    imQuitterPresse.loadFromFile("data/img/imQuitterPresse.png", renderer);
    imQuitter.loadFromFile("data/img/imQuitter.png", renderer);
    imRecommencerPresse.loadFromFile("data/img/imRecommencerPresse.png", renderer);
    imRecommencer.loadFromFile("data/img/imRecommencer.png", renderer);
    gameRunning = false;
    fenetreJeu.couleurJoueurs(jeu);
}

sdlJeu::~sdlJeu()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::renderCenterText(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor)
{
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended( font, p_text, textColor);
	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = surfaceMessage->w;
	src.h = surfaceMessage->h; 

	SDL_Rect dst;
	dst.x = 1122/2 - src.w/2 + p_x;
	dst.y = 630/2 - src.h/2 + p_y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, message, &src, &dst);
	SDL_FreeSurface(surfaceMessage);
}

bool sdlJeu::isIn(int x, int y, int w, int h, int souris_x, int souris_y)
{
    return (((souris_x - x) <= w) && ((souris_x - x) >= 0) && ((souris_y - y) <= h) && ((souris_y - y) >= 0)) ;
    
}

void sdlJeu::renderText(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor)
{
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended( font, p_text, textColor);
	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = surfaceMessage->w;
	src.h = surfaceMessage->h; 

	SDL_Rect dst;
	dst.x = p_x;
	dst.y = p_y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, message, &src, &dst);
	SDL_FreeSurface(surfaceMessage);
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

void sdlJeu::sdlAff(bool boutonRecommencer, bool boutonQuitter)
{
    //Remplir l'écran de noir
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //Affichage de la fenetre de jeu
    fenetreJeu.draw(renderer);

    //Affichage de la barre du dessus avec le titre
    imageTitreJeu.draw(renderer,0,0);
    imageDroiteJeu.draw(renderer,1122, 90);

    if (boutonRecommencer) imRecommencerPresse.draw(renderer, 1151, 400);
    else imRecommencer.draw(renderer, 1151, 400);

    if (boutonQuitter) imQuitterPresse.draw(renderer, 1151, 600);
    else imQuitter.draw(renderer, 1151, 600);



    //Affichage du score des joueurs

    
}

void sdlJeu::sdlBoucle()
{
    gameRunning = true;
    int x, y = 0; // pour les coordonnées de la souris
    bool bouttonQuitter = false;
    bool bouttonRecommencer = false;
    bool J1GaucheAppuye = false;
    bool J1DroiteAppuye = false;
    bool J2GaucheAppuye = false;
    bool J2DroiteAppuye = false;


    Uint32 starting_ticks = SDL_GetTicks(), ticks;
    SDL_Event events;

    
    while(gameRunning)
    {
        if (jeu.getConstS1().getVivant() && jeu.getConstS2().getVivant()) {
            ticks = SDL_GetTicks();
            if (ticks - starting_ticks > 1000 / fps)
            {
                sdlActionsAutomatiques();

                jeu.actionClavierSDL(J1GaucheAppuye, J1DroiteAppuye, J2GaucheAppuye, J2DroiteAppuye);
                starting_ticks = ticks;

                bouttonRecommencer=isIn(1151, 400, 100, 50, x, y);
                bouttonQuitter=isIn(1151,600,100,50,x,y);

                sdlAff(bouttonRecommencer, bouttonQuitter);
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
                    case SDL_MOUSEMOTION:
                        SDL_GetMouseState(&x, &y);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        std::cout << x <<"  :  " << y << std::endl;
                        if (bouttonQuitter) {gameRunning=false; exit(0);}
                        if (bouttonRecommencer) 
                        {
                            fenetreJeu.clearSurface();
                            recommencerPartie();
                            J1GaucheAppuye = false;
                            J1DroiteAppuye = false;
                            J2GaucheAppuye = false;
                            J2DroiteAppuye = false;
                            SDL_SetRenderDrawColor(renderer, 20, 20, 50, 255);
                            SDL_RenderClear(renderer);
                            jeu.getS1().augmenterScore(- (jeu.getS1().getScore()));
                            jeu.getS2().augmenterScore(- (jeu.getS2().getScore()));
                        }

                }
            }
            
        } else {
            if (!jeu.getConstS1().getVivant()) {
                renderCenterText(0, -20, "Joueur 1 est mort", font32, blanc);
                jeu.getS2().augmenterScore(1);
            } else {
                renderCenterText(0, -20, "Joueur 2 est mort", font32, blanc);
                jeu.getS1().augmenterScore(1);
            }
            renderCenterText(0, 10, "Appuyez sur espace pour continuer", font32, blanc);
            SDL_RenderPresent(renderer);
            bool reprendrePartie = false;
            while (!reprendrePartie) {
                while(SDL_PollEvent(&events)) {
                    if (events.type == SDL_QUIT) {
                        gameRunning = false;        // Si l'utilisateur a clique sur la croix de fermeture
                        reprendrePartie = true;
                    }
                    else if (events.type == SDL_KEYDOWN && events.key.keysym.sym == SDLK_SPACE) {
                        fenetreJeu.clearSurface();
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