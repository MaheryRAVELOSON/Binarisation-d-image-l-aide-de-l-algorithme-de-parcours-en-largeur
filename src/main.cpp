#include "graphe.h"
#include <stdio.h>
#include <string>
using namespace std;

int main(void)
{
    std::string nomFichier= "data/data.pgm";
    litFichierEntiers(nomFichier.c_str());
    return 0;
}