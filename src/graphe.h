#ifndef _GRAPHE
#define _GRAPHE

#include <iostream>
#include <cassert>
#include <ctime>
#include "pixel.h"

#include <cstdio>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //exit

void litFichierEntiers(const char * nomFichier);

//---------------------------------Classe Graphe---------------------------------
class Graphe
{
    public:
    int Hauteur;
    int Largeur;
    Pixel * TabPixel;

    Graphe();
};


#endif