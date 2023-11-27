#ifndef _GRAPHE
#define _GRAPHE

#include <iostream>
#include <cassert>
#include <ctime>
#include "pixel.h"

#include <cstdio>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //exit
#include <string>
#include <fstream>
#include <math.h>
#include <cmath> // pour l'exposant

using namespace std;


//---------------------------------Classe Graphe---------------------------------
class Graphe
{
    public:
    int C;
    int L;
    Pixel * TabPixel;
//-------------------------------------------------------------------------------
    void ouvrir(const string & filename);
//-------------------------------------------------------------------------------
    void sauver(const string & filename);
//-------------------------------------------------------------------------------
    Pixel * GetAdPixel(const int i, const int j);
//-------------------------------------------------------------------------------
    int GetIndPixel(const int i, const int j);
//-------------------------------------------------------------------------------
    void InitVoisin();
//-------------------------------------------------------------------------------
    void SetCap();
//-------------------------------------------------------------------------------
    Graphe();
};


#endif