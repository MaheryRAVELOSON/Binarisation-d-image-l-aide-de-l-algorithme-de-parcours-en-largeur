#include "graphe.h"
#include <stdio.h>


int main(void)
{
    Graphe TestGraphe;
    for(int i= 0; i<TestGraphe.Hauteur*TestGraphe.Largeur; i++)
    {
        cout<<TestGraphe.TabPixel[i].intensite<<endl;
    }
    return 0;
}