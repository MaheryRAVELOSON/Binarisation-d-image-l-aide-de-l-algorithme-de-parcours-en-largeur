#include "graphe.h"
#include <stdio.h>


int main(void)
{
    Graphe TestGraphe;
//___________________________Affichage des données
    /*cout<<endl<<"---Affichage des données---"<<endl;
    for(int i= 0; i<TestGraphe.L*TestGraphe.C; i++)
    {
        cout<<"pixel "<<TestGraphe.TabPixel[i].intensite<<endl;
    }
    cout<<endl<<"---Fin Affichage des données---"<<endl;*/

//___________________________Affichage des 4 voisins de la 1ère case en partant de 0:
    /*int i=0; //Ligne 0
    int j=1; //Colonne 1
    cout<<endl<<"---Affichage des 4 voisin de la case "<<
    TestGraphe.TabPixel[TestGraphe.GetIndPixel(i, j)].intensite<<": "<<endl;
    
    if((TestGraphe.GetIndPixel(i-1, j) >=0) && (TestGraphe.GetIndPixel(i-1, j)<TestGraphe.L*TestGraphe.C))
    {
        cout<<"Voisin Nord= "<<TestGraphe.TabPixel[TestGraphe.GetIndPixel(i, j)].Sortant_Nord->intensite<<endl;
    }
    if((TestGraphe.GetIndPixel(i+1, j) >=0) && (TestGraphe.GetIndPixel(i+1, j)<TestGraphe.L*TestGraphe.C))
    {
        cout<<"Voisin Sud= "<<TestGraphe.TabPixel[TestGraphe.GetIndPixel(i, j)].Sortant_Sud->intensite<<endl;
        cout<<"Remarque: pixel (i+1)*C+j = "<<TestGraphe.TabPixel[(i+1)*TestGraphe.C+j].intensite<<endl;
        //cout<<TestGraphe.TabPixel[641].intensite<<endl;
    }
    if((TestGraphe.GetIndPixel(i, j+1) >=0) && (TestGraphe.GetIndPixel(i, j+1)<TestGraphe.L*TestGraphe.C))
    {
        cout<<"Voisin Est= "<<TestGraphe.TabPixel[TestGraphe.GetIndPixel(i, j)].Sortant_Est->intensite<<endl;
    }
    if((TestGraphe.GetIndPixel(i, j-1) >=0) && (TestGraphe.GetIndPixel(i, j-1)<TestGraphe.L*TestGraphe.C))
    {
        cout<<"Voisin Ouest= "<<TestGraphe.TabPixel[TestGraphe.GetIndPixel(i, j)].Sortant_Ouest->intensite<<endl;
    }
    cout<<endl<<"---Fin Affichage des voisin---"<<endl;*/
    
//___________________________Affichage des capacité entrant depuis la source
    /*cout<<endl<<"---Affichage des capacité entrant depuis la source de chaque pixel: "<<endl;
    int k=0;
    for(int i=0; i<TestGraphe.C*TestGraphe.L; i++)
    {
        cout<<TestGraphe.TabPixel[i].Cap_E_Source<<endl;
        if(k<TestGraphe.TabPixel[i].Cap_E_Source)
        {
            k= TestGraphe.TabPixel[i].Cap_E_Source;
        }
    }
    cout<<endl<<"capacité max ="<< k<<endl;
    cout<<endl<<"---FIN Affichage des capacité entrant depuis la source de chaque pixel "<<endl;*/

//___________________________Affichage des capacité sortant vers le puit
    /*
    cout<<endl<<"---Affichage des capacité sortant vers le puit depuis chaque pixel: "<<endl;
    k=0;
    for(int i=0; i<TestGraphe.C*TestGraphe.L; i++)
    {
        cout<<"pixel d'intensité "<<TestGraphe.TabPixel[i].intensite<<" = "<<
        TestGraphe.TabPixel[i].Cap_S_Puit<<endl;

        if(k<TestGraphe.TabPixel[i].Cap_S_Puit)
        {
            k= TestGraphe.TabPixel[i].Cap_S_Puit;
        }
    }
    cout<<endl<<"capacité max ="<< k<<endl;
    cout<<endl<<"---FIN Affichage des capacité sortant vers le puit depuis chaque pixel: "<<endl;

    cout<<endl<<"ln de 0.5  = "<<ln(0.5)<<endl;
    cout<<endl<<"ln de 0 = "<<ln(0)<<endl;
    cout<<endl<<"ln de 1 = "<<ln(1)<<endl;
    */

//___________________________Affichage des capacités entre pixels 
    cout<<endl<<"---Affichage des capacités entre pixels  "<<endl;
    for (int i = 0; i < TestGraphe.L; i++)
    {
        cout<<endl<<" pixel = " << TestGraphe.TabPixel[i].intensite<<" :"<<endl;
        cout<<" Cap_S_Nord " << TestGraphe.TabPixel[i].Cap_S_Nord<<endl;
        cout<<" Cap_S_Sud " << TestGraphe.TabPixel[i].Cap_S_Sud<<endl;
        cout<<" Cap_S_Est " << TestGraphe.TabPixel[i].Cap_S_Est<<endl;
        cout<<" Cap_S_Ouest" << TestGraphe.TabPixel[i].Cap_S_Ouest<<endl;     
        cout<<endl<<endl;
        cout<<endl<<"--Fin de L'affichage des capacités entre pixels"<<endl;
    }
    
    cout<<TestGraphe.TabPixel[0].Sortant_Sud->intensite<<endl;

//___________________________Sauvegarde du fichier
    std::string nomFichier= "data/La_Notre.pgm";
    TestGraphe.sauver(nomFichier);
    return 0;
}