#ifndef _Terrain
#define _Terrain 

#include <vector>
using namespace std;

class Terrain
{
private :
    /**
    @brief Les dimensions du terrain de jeu.
    */
    unsigned int tailleX, tailleY;
    
    /**
    @brief Tableau 1D de booléens indiquant si la case est occupée par la trace d'un joueur.
    */
    bool* tabCasesOccupees;
    
public :
    /**
    @brief Constructeur par défaut du terrain. Initialise tailleX et tailleY à 0.
    */
    Terrain();
    
    /**
    @brief Constructeur de la classe : initialise tailleX et tailleY (après vérification) puis alloue le tableau de booléen dans le tas.
    @warning tX et tY doivent être supérieurs ou égaux à 0
    @param[in] tX Hauteur du terrain de jeu
    @param[in] tY Largeur du terrain de jeu
    */
    Terrain(unsigned int tX, unsigned int tY);
    
    /**
    @brief Destructeur de la classe : déallocation de la mémoire du tableau de et mise à jour des champs tailleX et tailleY à 0.
    */
    ~Terrain();
};






#endif
