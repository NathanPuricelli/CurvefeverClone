#include "sdlJeu.h"
#include <cassert>

#define fps 20
const int TAILLE_SPRITE = 10;
const int WIDTH = 140;
const int HEIGHT = 72;

//commencer avec une fenetre avec terrain vide et mettre des points à la main dans le main.

// ============= CLASS IMAGE =============== //

Image::Image () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return texture;}

void Image::setSurface(SDL_Surface * surf) {surface = surf;}

// ============= CLASS SDLJEU =============== //

sdlJeu::sdlJeu(int tailleX, int tailleY):jeu(tailleX, tailleY)
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
    window = SDL_CreateWindow("Curvefever !", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH*TAILLE_SPRITE, HEIGHT*TAILLE_SPRITE, SDL_WINDOW_SHOWN);
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


    font32 = TTF_OpenFont("res/fonts/cocogoose.ttf", 32);
    if (font32 == NULL)
        font32 = TTF_OpenFont("../res/fonts/cocogoose.ttf", 32);
    if (font32 == NULL) {
            cout << "Erreur lors du chargement de cocogoose.ttf! SDL_TTF Error: " << SDL_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}

    //chargement de l'image du jeu
    textureJeu = NULL;
    gameRunning = true;

    blanc = { 255, 255, 255 };

    cout<<"Construction sdlJeu : Check"<<endl;
}

sdlJeu::~sdlJeu()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font32);
    textureJeu = NULL;
    SDL_Quit();
}

void sdlJeu::setPixel(SDL_Surface *screen, int x, int y, Couleur color)
{
    Uint32 couleur = SDL_MapRGB(screen->format, color.getRouge(), color.getBleu(), color.getVert());
    
    SDL_Rect pixel;
    pixel.w = TAILLE_SPRITE, pixel.h = TAILLE_SPRITE;
    pixel.x = x * TAILLE_SPRITE, pixel.y = y* TAILLE_SPRITE; 
    SDL_FillRect(screen, &pixel, couleur);
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
	dst.x = (WIDTH*TAILLE_SPRITE)/2 - src.w/2 + p_x;
	dst.y = (HEIGHT*TAILLE_SPRITE)/2 - src.h/2 + p_y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, message, &src, &dst);
	SDL_FreeSurface(surfaceMessage);
}

void sdlJeu::recommencerPartie() {
    for (int i = 0; i < jeu.t.getTailleX(); i++) {
        for (int j = 0; j < jeu.t.getTailleY(); j++) {
            jeu.t.tabCasesOccupees[i][j] = false;
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
    /*setPixel(surfaceJeu, jeu.getConstS1().getTeteX(), jeu.getConstS1().getTeteY(), jeu.getConstS1().getCouleur());
    setPixel(surfaceJeu, jeu.getConstS2().getTeteX(), jeu.getConstS2().getTeteY(), jeu.getConstS2().getCouleur());
    SDL_UpdateWindowSurface(window);*/
}

void sdlJeu::sdlAff()
{
    //Remplir l'écran de noir
    SDL_SetRenderDrawColor(renderer, 20, 20, 50, 255);
    SDL_RenderClear(renderer);

    SDL_Rect px;
    px.h = TAILLE_SPRITE;
    px.w = TAILLE_SPRITE;
    SDL_SetRenderDrawColor(renderer, 100, 0, 100, 255);

    for (int i = 0; i < jeu.t.getTailleX(); i++) {
        for (int j = 0; j < jeu.t.getTailleY(); j++) {
            if(jeu.t.tabCasesOccupees[i][j]) {
                px.x = i*TAILLE_SPRITE;
                px.y = j*TAILLE_SPRITE;
                SDL_RenderFillRect(renderer, &px);
            }
        }
    }

    // AFFICHAGE BONUS : TETES DES SERPENTS //
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    px.x = jeu.getConstS1().getTeteX()*TAILLE_SPRITE;
    px.y = jeu.getConstS1().getTeteY()*TAILLE_SPRITE;
    SDL_RenderFillRect(renderer, &px);
    px.x = jeu.getConstS2().getTeteX()*TAILLE_SPRITE;
    px.y = jeu.getConstS2().getTeteY()*TAILLE_SPRITE;
    SDL_RenderFillRect(renderer, &px);

    /*
    //convertir notre surface représentant notre jeu en texture affichable et l'afficher
    int ok;
    surfaceJeu = SDL_ConvertSurfaceFormat(surfaceJeu, SDL_PIXELFORMAT_ARGB8888, 0);
    ok = SDL_UpdateTexture(textureJeu,NULL,surfaceJeu->pixels,surfaceJeu->pitch);
    assert(ok == 0);
    ok = SDL_RenderCopy(renderer,textureJeu,NULL,NULL);
    assert(ok == 0);*/
}

void sdlJeu::sdlBoucle()
{
    Uint32 starting_ticks = SDL_GetTicks(), ticks;
    SDL_Event events;
    while(gameRunning)
    {
        if (jeu.getConstS1().getVivant() && jeu.getConstS2().getVivant()) {
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
        } else {
            if (!jeu.getConstS1().getVivant()) {
                renderCenterText(0, -20, "Joueur 1 est mort", font32, blanc);
            } else {
                renderCenterText(0, -20, "Joueur 2 est mort", font32, blanc);
            }
            renderCenterText(0, 10, "Cliquez pour continuer", font32, blanc);
            SDL_RenderPresent(renderer);
            bool reprendrePartie = false;
            while (!reprendrePartie) {
                while(SDL_PollEvent(&events)) {
                    if (events.type == SDL_QUIT) {
                        gameRunning = false;        // Si l'utilisateur a clique sur la croix de fermeture
                        reprendrePartie = true;
                    }
                    else if (events.type == SDL_MOUSEBUTTONDOWN) {
                        reprendrePartie = true;
                        recommencerPartie();
                        SDL_SetRenderDrawColor(renderer, 20, 20, 50, 255);
                        SDL_RenderClear(renderer);
                    }
                }
            }
        }

    }
}