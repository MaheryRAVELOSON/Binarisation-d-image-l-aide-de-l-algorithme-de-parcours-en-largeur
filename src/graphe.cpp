#include "graphe.h"
//---------------------------Lecture fichier-------------------------------------
void Graphe::ouvrir(const string & filename)
{
  ifstream fichier (filename.c_str());

  assert(fichier.is_open());
	string mot;
  int rien;

	fichier >> mot >> Hauteur >> Largeur >> rien;
	assert(Hauteur > 0 && Largeur > 0);
  cout<<"Hauteur = " <<Hauteur<< " Et Largeur= "<<Largeur<<endl;
  
	if (TabPixel != nullptr)
  {
    delete [] TabPixel;
  }
	TabPixel = new Pixel [Hauteur*Largeur];
  
  for(int y=0; y<Hauteur*Largeur; ++y)
  {
    fichier >> TabPixel[y].intensite;
  }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}


//----------------------------Constructeur graphe
Graphe::Graphe()
{
  TabPixel = nullptr;
  std::string nomFichier= "data/data.pgm";
  ouvrir(nomFichier);
}