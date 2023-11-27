#include "graphe.h"

//---------------------------logarithme nepirien-------------------------------------
int ln(int x)
{
    return std::log(x) / std::log(M_E); //M_E est exponentielle de e
}
//---------------------------Lecture fichier-------------------------------------
void Graphe::ouvrir(const string & filename)
{
  ifstream fichier (filename.c_str());

  assert(fichier.is_open());
	string mot;
  int rien;

	fichier >> mot >> C >> L >> rien;
	assert(C > 0 && L > 0);
  cout<<"Hauteur = " <<C<< " Et Largeur= "<<L<<endl;
  
	if (TabPixel != nullptr)
  {
    delete [] TabPixel;
  }
	TabPixel = new Pixel [L*C+2]; // Création du tableau de pointeur de Pixel
  
  for(int y=0; y<L*C; ++y)
  {
    fichier >> TabPixel[y].intensite;
  }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

//-------------------------------------------------------------------------------
int Graphe::GetIndPixel(const int i, const int j)
{
  return i*C+j;
}

//---------------------------Sauvegarde fichier-------------------------------------
void Graphe::sauver(const string & filename) {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P2" << endl;
    fichier << C << " " << L << endl;
    fichier << "255" << endl;
    for(int y=0; y<L; ++y)
        for(int x=0; x<C; ++x)
        {
            int pix = TabPixel[GetIndPixel(y, x)].intensite;
            fichier << +pix<< " ";
        }
    cout << endl << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}


//-------------------------------------------------------------------------------
Pixel * Graphe::GetAdPixel(const int i, const int j)
{
  return & TabPixel[i*C+j];
}

//-------------------------------------------------------------------------------
void Graphe::InitVoisin()
{
  for(int i= 0; i<L; i++)
  {
    for(int j=0; j<C; j++)
    {
      int Ind_V_Nord = GetIndPixel(i-1, j);
      int Ind_V_Sud = GetIndPixel(i+1, j);
      int Ind_V_Est = GetIndPixel(i, j+1);
      int Ind_V_Ouest = GetIndPixel(i, j-1);

      int Ind_P_Courant= GetIndPixel(i, j);
      
      if((Ind_V_Nord>=0) && (Ind_V_Nord<(L*C)))
      {
        TabPixel[Ind_P_Courant].Sortant_Nord= GetAdPixel(i-1, j); //le pixel pointé par l'entrant Nord
        TabPixel[Ind_P_Courant].Entrant_Nord= GetAdPixel(i-1, j); // est parail que celui pointé par
      }                                                           //le sortant Nord

      if((Ind_V_Sud>=0) && (Ind_V_Sud<(L*C)))
      {
        TabPixel[Ind_P_Courant].Sortant_Sud= GetAdPixel(i+1, j);
        TabPixel[Ind_P_Courant].Entrant_Sud= GetAdPixel(i+1, j);
      }

      if((Ind_V_Est>=0) && (Ind_V_Est<(L*C)))
      {
        TabPixel[Ind_P_Courant].Sortant_Est= GetAdPixel(i, j+1);
        TabPixel[Ind_P_Courant].Entrant_Est= GetAdPixel(i, j+1);
      }

      if((Ind_V_Ouest>=0) && (Ind_V_Ouest<(L*C)))
      {
        TabPixel[Ind_P_Courant].Sortant_Ouest= GetAdPixel(i, j-1);
        TabPixel[Ind_P_Courant].Entrant_Ouest= GetAdPixel(i, j-1);
      }
    }
  }
}

//-------------------------------------------------------------------------------
void Graphe::SetCap()
{
  int sigma= 0;
  float Moyenne= 0;
  int alpha= 1;
  float D1 = 0;
  float D2 = 0;

  for(int i=0; i<L; i++)
  {
    for(int j=0; j<C; j++)
    {
      int Ind_P_Actuel = GetIndPixel(i, j);
//_________________Pour Arc Nord
      if(TabPixel[Ind_P_Actuel].Sortant_Nord != nullptr)
      {
        int Intensite_Actuel = TabPixel[Ind_P_Actuel].intensite;
        int Intensite_V_Nord = TabPixel[Ind_P_Actuel].Sortant_Nord->intensite;
        int Diff_I = abs(Intensite_Actuel - Intensite_V_Nord);
        
        Moyenne = (Intensite_Actuel+ Intensite_V_Nord)/2;
        D1 =  pow((Intensite_Actuel- Moyenne), 2);
        D2 =  pow((Intensite_V_Nord- Moyenne), 2);
        sigma = sqrt(D1+D2);

        int capacite = exp(-(pow(Diff_I, 2)) / (2* pow(sigma, 2)));
        TabPixel[Ind_P_Actuel].Cap_E_Nord= capacite;
        TabPixel[Ind_P_Actuel].Cap_S_Nord= capacite;
      }
//_________________Pour Arc Sud
      if(TabPixel[Ind_P_Actuel].Sortant_Sud != nullptr)
      {
        int Intensite_Actuel = TabPixel[Ind_P_Actuel].intensite;
        int Intensite_V_Sud = TabPixel[Ind_P_Actuel].Sortant_Sud->intensite;
        int Diff_I = abs(Intensite_Actuel - Intensite_V_Sud);

        Moyenne = (Intensite_Actuel+ Intensite_V_Sud)/2;
        D1 =  pow((Intensite_Actuel- Moyenne), 2);
        D2 =  pow((Intensite_V_Sud- Moyenne), 2);
        sigma = sqrt(D1+D2);

        int capacite = exp(-(pow(Diff_I, 2)) / (2* pow(sigma, 2)));
        TabPixel[Ind_P_Actuel].Cap_E_Sud= capacite;
        TabPixel[Ind_P_Actuel].Cap_S_Sud= capacite;
      }
//_________________Pour Arc Est
      if(TabPixel[Ind_P_Actuel].Sortant_Est != nullptr)
      {
        int Intensite_Actuel = TabPixel[Ind_P_Actuel].intensite;
        int Intensite_V_Est = TabPixel[Ind_P_Actuel].Sortant_Est->intensite;
        int Diff_I = abs(Intensite_Actuel - Intensite_V_Est);

        Moyenne = (Intensite_Actuel+ Intensite_V_Est)/2;
        D1 =  pow((Intensite_Actuel- Moyenne), 2);
        D2 =  pow((Intensite_V_Est- Moyenne), 2);
        sigma = sqrt(D1+D2);

        int capacite = exp(-(pow(Diff_I, 2)) / (2* pow(sigma, 2)));
        TabPixel[Ind_P_Actuel].Cap_E_Est= capacite;
        TabPixel[Ind_P_Actuel].Cap_S_Est= capacite;
      }
//_________________Pour Arc Ouest
      if(TabPixel[Ind_P_Actuel].Sortant_Ouest != nullptr)
      {
        int Intensite_Actuel = TabPixel[Ind_P_Actuel].intensite;
        int Intensite_V_Ouest = TabPixel[Ind_P_Actuel].Sortant_Ouest->intensite;
        int Diff_I = abs(Intensite_Actuel - Intensite_V_Ouest);

        Moyenne = (Intensite_Actuel+ Intensite_V_Ouest)/2;
        D1 =  pow((Intensite_Actuel- Moyenne), 2);
        D2 =  pow((Intensite_V_Ouest- Moyenne), 2);
        sigma = sqrt(D1+D2);

        int capacite = exp(-(pow(Diff_I, 2)) / (2* pow(sigma, 2)));
        TabPixel[Ind_P_Actuel].Cap_E_Ouest= capacite;
        TabPixel[Ind_P_Actuel].Cap_S_Ouest= capacite;
      }
//_________________Pour Arc Source
      int Diff_I = 255-TabPixel[Ind_P_Actuel].intensite;
      int Cap_S  = - alpha * ln(Diff_I/255);
      TabPixel[Ind_P_Actuel].Cap_E_Source = Cap_S;

//_________________Pour Arc Puit
      int Cap_P  = - alpha * ln(TabPixel[Ind_P_Actuel].intensite/255);
      TabPixel[Ind_P_Actuel].Cap_S_Puit = Cap_P;
          
    }
  }
}

//----------------------------Constructeur graphe--------------------------------
Graphe::Graphe()
{
  TabPixel = nullptr;
  std::string nomFichier= "data/data.pgm";
  ouvrir(nomFichier); //remplissage des INTENSITEE seulement de chaque pixel
  InitVoisin(); //remplissage des 4 arcs voisins de chaque pixel.
}