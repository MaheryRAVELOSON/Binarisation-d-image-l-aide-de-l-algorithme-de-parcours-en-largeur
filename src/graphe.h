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
#include <vector>
#include <cmath> // pour l'exposant

using namespace std;

//double ln(float x); //x doit être en float !

float ln(float x);
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
//-------------------------------------------------------------------------------
    int ParcoursLargeur();
//-------------------------------------------------------------------------------
    int IndiceTab(Pixel * AdPixel);

//-------------------------------------------------------------------------------
int FlotMin(int TabPred[], int IndPixArrive);// pour trouver le flot minimal et augmenter les flots
//il renvoie le flot minimal sinon -1 en cas d'erreur

//-------------------------------------------------------------------------------
int GetCap(Pixel * AdPixelDepart, Pixel * AdPixelArrivee); // retourner la capacité d'un arc entre 2 Pixel
//renvoie -1 si arc introuvalbe

//-------------------------------------------------------------------------------
int GetFlot(Pixel * AdPixelDepart, Pixel * AdPixelArrivee); // retourner le Flot d'un arc entre 2 Pixel
//renvoie -1 si arc introuvalbe

//-------------------------------------------------------------------------------
int SetFlot(Pixel * AdPixelDepart, Pixel * AdPixelArrivee, int NewFlot); // modifie le Flot d'un arc entre 2 Pixel
//renvoie -1 si arc introuvalbe
};


#endif