#ifndef _Terrain
#define _Terrain 

#include <vector>
using namespace std;

class Terrain
{
public : 
    bool* tabCasesOccupees; //tableau de booléens
    int tailleX;
    int tailleY;
    Terrain();
    Terrain(int tailleX, int tailleY);
    ~Terrain();
};






#endif