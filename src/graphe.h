#ifndef _GRAPHE
#define _GRAPHE

#include <iostream>
#include <cassert>
#include <ctime>
#include "pixel.h"

#include <cstdio>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //exit

class Graphe
{
    public:
    int Hauteur;
    int Largeur;
    Pixel TabPixel[Hauteur*Largeur];

    Graphe();
};


#endif