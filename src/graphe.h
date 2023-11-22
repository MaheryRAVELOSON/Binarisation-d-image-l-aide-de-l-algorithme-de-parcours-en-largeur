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

using namespace std;


//---------------------------------Classe Graphe---------------------------------
class Graphe
{
    public:
    int Hauteur;
    int Largeur;
    Pixel * TabPixel;

    void ouvrir(const string & filename);
    Graphe();
};


#endif