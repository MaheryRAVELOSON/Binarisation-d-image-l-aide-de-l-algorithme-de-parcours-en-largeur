#include "graphe.h"
//---------------------------Lecture fichier-------------------------------------
void litFichierEntiers(const char * nomFichier)
//preconditions : nomFichier chaine de caracteres designant le nom d'un fichier
//                contenant des entiers separes par des caracteres d'espacement
//postcondition : affichage du contenu du fichier sur la sortie standard
{
  std::ifstream ifs;
  ifs.open(nomFichier);
  if(ifs.bad())
    {std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en lecture \n"; exit(1);}
  int temp;
  while(ifs >> temp)
    std::cout<<"Entier suivant "<<temp<< std::endl;
  ifs.close();
}

//----------------------------Constructeur graphe
Graphe::Graphe()
{
}