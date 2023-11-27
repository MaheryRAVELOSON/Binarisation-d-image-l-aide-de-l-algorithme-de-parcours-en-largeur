#include "graphe.h"
#include <stdio.h>


int main(void)
{
    Graphe TestGraphe;
//___________________________Affichage des donnée
    cout<<endl<<"---Affichage des données---"<<endl;
    for(int i= 0; i<TestGraphe.L*TestGraphe.C; i++)
    {
        cout<<"pixel "<<TestGraphe.TabPixel[i].intensite<<endl;
    }
    cout<<endl<<"---Fin Affichage des données---"<<endl;

//___________________________Affichage des 4 voisin de la 1ère case en partant de 0:
    int i=0; //Ligne 0
    int j=1; //Colonne 1
    cout<<endl<<"---Affichage des 4 voisin de la case "<<
    TestGraphe.TabPixel[TestGraphe.GetIndPixel(i, j)].intensite<<": "<<endl;
    
    if((TestGraphe.GetIndPixel(i-1, j) >=0) && (TestGraphe.GetIndPixel(i-1, j)<TestGraphe.L*TestGraphe.C))
    {
        cout<<"Voisin Nord= "<<TestGraphe.TabPixel[TestGraphe.GetIndPixel(i, j)].Entrant_Nord->intensite<<endl;
    }
    if((TestGraphe.GetIndPixel(i+1, j) >=0) && (TestGraphe.GetIndPixel(i+1, j)<TestGraphe.L*TestGraphe.C))
    {
        cout<<"Voisin Sud= "<<TestGraphe.TabPixel[TestGraphe.GetIndPixel(i, j)].Entrant_Sud->intensite<<endl;
        cout<<"Remarque: pixel (i+1)*C+j = "<<TestGraphe.TabPixel[(i+1)*TestGraphe.C+j].intensite<<endl;
        //cout<<TestGraphe.TabPixel[641].intensite<<endl;
    }
    if((TestGraphe.GetIndPixel(i, j+1) >=0) && (TestGraphe.GetIndPixel(i, j+1)<TestGraphe.L*TestGraphe.C))
    {
        cout<<"Voisin Est= "<<TestGraphe.TabPixel[TestGraphe.GetIndPixel(i, j)].Entrant_Est->intensite<<endl;
    }
    if((TestGraphe.GetIndPixel(i, j-1) >=0) && (TestGraphe.GetIndPixel(i, j-1)<TestGraphe.L*TestGraphe.C))
    {
        cout<<"Voisin Ouest= "<<TestGraphe.TabPixel[TestGraphe.GetIndPixel(i, j)].Entrant_Ouest->intensite<<endl;
    }
    cout<<endl<<"---Fin Affichage des voisin---"<<endl;
    

//___________________________Sauvegarde du fichier
    std::string nomFichier= "data/La_Notre.pgm";
    TestGraphe.sauver(nomFichier);
    return 0;
}