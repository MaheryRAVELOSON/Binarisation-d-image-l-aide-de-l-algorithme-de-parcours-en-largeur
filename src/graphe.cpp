#include "graphe.h"


//---------------------------logarithme nepirien-------------------------------------
float ln(float x)
{
    return std::log(x) / std::log(M_E); //M_E est exponentielle (1) ==> e
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
    TabPixel[y].Sortant_Puit= &TabPixel[L*C+1];
  }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

//-------------------------------------------------------------------------------
int Graphe::GetIndPixel(const int i, const int j) // il transforme le i j en vrai indice à 1D
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
  assert(i*C+j>=0 && i*C+j<L*C);
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
        TabPixel[Ind_P_Courant].Sortant_Nord= GetAdPixel(i-1, j);
      }

      if((Ind_V_Sud>=0) && (Ind_V_Sud<(L*C)))
      {
        TabPixel[Ind_P_Courant].Sortant_Sud= GetAdPixel(i+1, j);
      }

      if((Ind_V_Est>=0) && (Ind_V_Est<(L*C)))
      {
        TabPixel[Ind_P_Courant].Sortant_Est= GetAdPixel(i, j+1);
      }

      if((Ind_V_Ouest>=0) && (Ind_V_Ouest<(L*C)))
      {
        TabPixel[Ind_P_Courant].Sortant_Ouest= GetAdPixel(i, j-1);
      }
    }
  }
}

//-------------------------------------------------------------------------------
void Graphe::SetCap()
{
  //Plus le alpha = sigma est grand, plus l'image est bien et plus le temps de calcule est énorme
  const float sigma= 0.9;//0.7 // !!! Il faut que le sigma soit inférieur ou égale à alpha !!!
  const float alpha= 0.9;//1.5 //plus on augmente, plus on aura des Cap_E_Source > à 0. => augmentation du flot max
  float H    = 100;

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
        float Diff_I = abs(Intensite_Actuel - Intensite_V_Nord);

        float capacite = H*exp(-(pow(Diff_I, 2)) / (2* pow(sigma, 2)));
        if(capacite<0)
        {
          capacite =0;
        }
        TabPixel[Ind_P_Actuel].Cap_S_Nord= capacite;
      }
//_________________Pour Arc Sud
      if(TabPixel[Ind_P_Actuel].Sortant_Sud != nullptr)
      {
        int Intensite_Actuel = TabPixel[Ind_P_Actuel].intensite;
        int Intensite_V_Sud = TabPixel[Ind_P_Actuel].Sortant_Sud->intensite;
        float Diff_I = abs(Intensite_Actuel - Intensite_V_Sud);

        float capacite = H*exp(-(pow(Diff_I, 2)) / (2* pow(sigma, 2)));
        if(capacite<0)
        {
          capacite =0;
        }
        TabPixel[Ind_P_Actuel].Cap_S_Sud= capacite;
      }
//_________________Pour Arc Est
      if(TabPixel[Ind_P_Actuel].Sortant_Est != nullptr)
      {
        int Intensite_Actuel = TabPixel[Ind_P_Actuel].intensite;
        int Intensite_V_Est = TabPixel[Ind_P_Actuel].Sortant_Est->intensite;
        float Diff_I = abs(Intensite_Actuel - Intensite_V_Est);

        float capacite = H*exp(-(pow(Diff_I, 2)) / (2* pow(sigma, 2)));
        if(capacite<0)
        {
          capacite =0;
        }
        TabPixel[Ind_P_Actuel].Cap_S_Est= capacite;
      }
//_________________Pour Arc Ouest
      if(TabPixel[Ind_P_Actuel].Sortant_Ouest != nullptr)
      {
        int Intensite_Actuel = TabPixel[Ind_P_Actuel].intensite;
        int Intensite_V_Ouest = TabPixel[Ind_P_Actuel].Sortant_Ouest->intensite;
        float Diff_I = abs(Intensite_Actuel - Intensite_V_Ouest);

        float capacite = H*exp(-(pow(Diff_I, 2)) / (2* pow(sigma, 2)));
        if(capacite<0)
        {
          capacite =0;
        }
        TabPixel[Ind_P_Actuel].Cap_S_Ouest= capacite;
      }
//_________________Pour Arc Source
      float Diff_I = 255.0000000001-TabPixel[Ind_P_Actuel].intensite;
      float Cap_S  = - alpha * log(Diff_I/255.0000000002);
      TabPixel[Ind_P_Actuel].Cap_E_Source = Cap_S;
      if(TabPixel[Ind_P_Actuel].Cap_E_Source<0)
      {
        TabPixel[Ind_P_Actuel].Cap_E_Source= 0; //utile car il y a des valeur comme
      }   // -2147483648
      cout<<endl<<"Intensité = "<<TabPixel[Ind_P_Actuel].intensite<<" et Cap_E_Source: "<<Cap_S<<endl;

//_________________Pour Arc Puit
      float Int = float(TabPixel[Ind_P_Actuel].intensite + 0.0000000001);

      float final= (Int/255.0000000002);
      float Cap_P  = - alpha * log(final);
      TabPixel[Ind_P_Actuel].Cap_S_Puit = int(Cap_P);
      if(TabPixel[Ind_P_Actuel].Cap_S_Puit<0)
      {
        TabPixel[Ind_P_Actuel].Cap_S_Puit= 0;
      }

      //verification de la cohérence
      // if(TabPixel[Ind_P_Actuel].Cap_S_Puit != 0)
      // {
      //   assert(TabPixel[Ind_P_Actuel].Cap_E_Source == 0);
      // }
    }
  }
}

//-------------------------------------------------------------------------------
int Graphe::IndiceTab(Pixel * AdPixel)
{
  int i = 0;

  while ((&TabPixel[i]!= AdPixel) && (i < L*C))
  {
    if (&TabPixel[i]== AdPixel)
    {
      return i;
    }
    i++; 
  }

  if (&TabPixel[i]== AdPixel)
  {
    return i;
  }

   return -1; // en cas d'innéxistance
}

//-------------------------------------------------------------------------------
int Graphe::GetCap(Pixel * AdPixelDepart, Pixel * AdPixelArrivee)
{

  if((AdPixelDepart==nullptr) || (AdPixelArrivee==nullptr))
  {
    assert(1==2);
    return -1;
  }

  if(&TabPixel[L*C] == AdPixelArrivee) // si adresse de d'arrivée ==  @source
  {
    return 0; // on retourne 0
  }

  if(&TabPixel[L*C+1] == AdPixelDepart) // si @depart == au puit
  {
    return 0;// retourne 0
  }

  if(&TabPixel[L*C] == AdPixelDepart)
  {
    return AdPixelArrivee->Cap_E_Source;
  }

  if(AdPixelDepart->Sortant_Nord == AdPixelArrivee)
  {
    return AdPixelDepart->Cap_S_Nord;
  }

  if(AdPixelDepart->Sortant_Sud == AdPixelArrivee)
  {
    return AdPixelDepart->Cap_S_Sud;
  }

  if(AdPixelDepart->Sortant_Est == AdPixelArrivee)
  {
    return AdPixelDepart->Cap_S_Est;
  }

  if(AdPixelDepart->Sortant_Ouest == AdPixelArrivee)
  {
    return AdPixelDepart->Cap_S_Ouest;
  }

  if(AdPixelDepart->Sortant_Puit == AdPixelArrivee)
  {
    return AdPixelDepart->Cap_S_Puit;
  }

  //cout<<endl<<"---Test---"<<endl;
  
  assert(1==2);
  return -1;
}

//-------------------------------------------------------------------------------
int Graphe::GetFlot(Pixel * AdPixelDepart, Pixel * AdPixelArrivee)
{
  if((AdPixelDepart==nullptr) || (AdPixelArrivee==nullptr))
  {
    assert(1==2);
    return -1;
  }

  if(&TabPixel[L*C] == AdPixelDepart)
  {
    return AdPixelArrivee->flot_E_Source;
  }

  if(&TabPixel[L*C] == AdPixelArrivee)
  {
    return 0;
  }

  if(&TabPixel[L*C+1] == AdPixelDepart)
  {
    return 0;
  }

  if(AdPixelDepart->Sortant_Nord == AdPixelArrivee)
  {
    return AdPixelDepart->flot_S_Nord;
  }

  if(AdPixelDepart->Sortant_Sud == AdPixelArrivee)
  {
    return AdPixelDepart->flot_S_Sud;
  }

  if(AdPixelDepart->Sortant_Est == AdPixelArrivee)
  {
    return AdPixelDepart->flot_S_Est;
  }

  if(AdPixelDepart->Sortant_Ouest == AdPixelArrivee)
  {
    return AdPixelDepart->flot_S_Ouest;
  }

  if(AdPixelDepart->Sortant_Puit == AdPixelArrivee)
  {
    return AdPixelDepart->flot_S_Puit;
  }

  assert(1==2);
  return -1;
}

//-------------------------------------------------------------------------------
int Graphe::SetFlot(Pixel * AdPixelDepart, Pixel * AdPixelArrivee, int NewFlot)
{
  if((AdPixelDepart==nullptr) || (AdPixelArrivee==nullptr))
  {
    return -1;
  }

  if(&TabPixel[L*C] == AdPixelArrivee)
  {
    assert(1==2);
    return -1;
  }

  if(&TabPixel[L*C+1] == AdPixelDepart)
  {
    assert(1==2);
    return -1;
  }
  
  if(&TabPixel[L*C] == AdPixelDepart)
  {
    AdPixelArrivee->flot_E_Source = NewFlot;
    return 0;
  }
  
  if(AdPixelDepart->Sortant_Nord == AdPixelArrivee)
  {
    AdPixelDepart->flot_S_Nord = NewFlot;
    return 0;
  }

  if(AdPixelDepart->Sortant_Sud == AdPixelArrivee)
  {
    AdPixelDepart->flot_S_Sud = NewFlot;
    return 0;
  }

  if(AdPixelDepart->Sortant_Est == AdPixelArrivee)
  {
    AdPixelDepart->flot_S_Est = NewFlot;
    return 0;
  }

  if(AdPixelDepart->Sortant_Ouest == AdPixelArrivee)
  {
    AdPixelDepart->flot_S_Ouest = NewFlot;
    return 0;
  }

  if(AdPixelDepart->Sortant_Puit == AdPixelArrivee)
  {
    AdPixelDepart->flot_S_Puit = NewFlot;
    return 0;
  }

  return -1;
}

//-------------------------------------------------------------------------------
int Graphe::FlotMin(int TabPred[], int IndPixArrive)
{
  int TemponIndice= IndPixArrive;
  assert(TemponIndice>=0 && TemponIndice< L*C+2);
  
  //initialisation du flot minimal trouvé: par défaut le flot entre la puit et son prédecesseur car
  // ce chemin existe forcément sinon on n'aurai pas appeller la fontion FlotMin
  int FlotMin= TabPixel[TabPred[TemponIndice]].Cap_S_Puit - TabPixel[TabPred[TemponIndice]].flot_S_Puit;
  int Flot;

  assert(TabPred[IndPixArrive]< L*C+1);
  assert(TabPred[IndPixArrive]>= 0);
  assert(IndPixArrive>= 0 && IndPixArrive < L*C+2);

  int CapDepuisPredecesseur;
  
  //int CapVersPredecesseur= GetCap(&TabPixel[IndPixArrive], &TabPixel[TabPred[IndPixArrive]]);
  int FlotVersPredecesseur;
  
  int FlotDepuisPredecesseur;
  
  int verif= 0; //0= pas de problème et -1 sinon
  int x;
  int z= 0;

  while(TabPred[TemponIndice] > -1) //Recherche de la plus petite flot
  {
    //cout<<endl<<"-----Test1-----"<<endl;
    z++;

    CapDepuisPredecesseur = GetCap(&TabPixel[TabPred[TemponIndice]], &TabPixel[TemponIndice]);
    assert (CapDepuisPredecesseur >= 0); // sinon = à -1 donc problème

    FlotDepuisPredecesseur= GetFlot(&TabPixel[TabPred[TemponIndice]], &TabPixel[TemponIndice]);
    assert (FlotDepuisPredecesseur >= 0);

    FlotVersPredecesseur= GetFlot(&TabPixel[TemponIndice], &TabPixel[TabPred[TemponIndice]]);
    assert (FlotVersPredecesseur >= 0); // -1 si un pixel vers la source
    //cout<<endl<<FlotVersPredecesseur<<endl;

    Flot= CapDepuisPredecesseur - FlotDepuisPredecesseur + FlotVersPredecesseur;

    if((FlotMin>Flot) && (Flot>=0))
    {
      FlotMin = Flot;// 
    }

    TemponIndice = TabPred[TemponIndice]; //on reviens à chaque fois en arrière
  }
  cout <<endl<< "Nbr arc trouvé pour un chemin valide=" <<z << endl;
  TemponIndice= IndPixArrive;
  while(TabPred[TemponIndice] > -1) //Reglage des flot
  {
      
      //cout<<endl<<"-----Test2-----"<<endl; // Normalement mm nbr d'affichage du Test1
      
      CapDepuisPredecesseur = GetCap(&TabPixel[TabPred[TemponIndice]], &TabPixel[TemponIndice]);
      assert (CapDepuisPredecesseur >= 0); // sinon = à -1 donc problème

      FlotDepuisPredecesseur= GetFlot(&TabPixel[TabPred[TemponIndice]], &TabPixel[TemponIndice]);
      assert (FlotDepuisPredecesseur >= 0);

      FlotVersPredecesseur= GetFlot(&TabPixel[TemponIndice], &TabPixel[TabPred[TemponIndice]]);

      // assert (FlotVersPredecesseur >= 0); // -1 si un pixel vers la source
      
      if((FlotDepuisPredecesseur+FlotMin) > CapDepuisPredecesseur)
      {
        x= FlotVersPredecesseur - (FlotDepuisPredecesseur+FlotMin - CapDepuisPredecesseur); //flot inverse - le flot en trop
        if(x >= 0) //Si on peut le décremonter
        {//Impossible d'avoir TemponIndice = L*C grace à la condition du while car pred de L*C = -1
         //Impossible d'avoir x > 0 pour TemponIndice = L*C+1 car le flot min par défaut est celle du Cap_S_Puit - flot_S_Puit
          assert(TemponIndice != L*C);
          assert(TemponIndice != L*C+1);
          verif= SetFlot(&TabPixel[TabPred[TemponIndice]], &TabPixel[TemponIndice], CapDepuisPredecesseur);
          assert(verif > -1);
          verif= SetFlot(&TabPixel[TemponIndice], &TabPixel[TabPred[TemponIndice]], FlotVersPredecesseur- (FlotDepuisPredecesseur+FlotMin - CapDepuisPredecesseur));
          assert(verif > -1);
        }
        else
        {
          assert(1==2);
          return 0; // ou -1 (=erreur): à voir
        }
      }
      else
      {
        verif= SetFlot(&TabPixel[TabPred[TemponIndice]], &TabPixel[TemponIndice], (FlotDepuisPredecesseur+FlotMin));
        assert(verif > -1);
      }
      TemponIndice = TabPred[TemponIndice]; //on reviens à chaque fois en arrière
  }

  return FlotMin;
}

//----------------------------Parcours en Largeur--------------------------------
int Graphe::ParcoursLargeur() // la fonction s'arretra a chaque chemin valide 
{
  Pixel * courant ; // il va parcourir la file 
  Pixel TemponFilsCourant;
  vector<int> File; //pour stocker les INDICE de l'ordre des pixels dans la file pour le parcours en largeur
  int TabPredecesseur[L*C+2];// Pour stocker les indices des prédecesseur du pixel qui sont dans la file
  bool PixelDejaVu[L*C]; // pour marquer les indices des pixels deja exploiter
  assert(File.size()==0);
  
  for (int i = 0; i < L*C; i++) // Initialisation des tableau PixelDejaVu et TabPredecesseur
  {
   if((TabPixel[i].Cap_E_Source > 0) && ((TabPixel[i].Cap_E_Source - TabPixel[i].flot_E_Source) > 0))
   { // si le pixel est relié à la source et capacité non atteint => stockage de son indice sur les files 
    File.push_back(i); // rappelle: le File stocke l'indice
    TabPredecesseur[i]= L*C; //leur prédécesseur est la source
    PixelDejaVu[i]= true; // pour ne pas être stocker plusieurs fois.
   }
   else
   {
    TabPredecesseur[i]= -1;
   } 
   PixelDejaVu[i]= false; // car pas encore stocké dans la file
  }
  TabPredecesseur[L*C]= -1;
  TabPredecesseur[L*C+1] = -1;
//------------------------
  while (File.size() > 0 ) // tant que on a pas fini à lire l'entiérté de la file alors on continue
  {
    courant = &TabPixel[File[0]]; // on utilise la constante 0 car comme on manipule une "file", on ne peut
                                  // manipuler que la tête
    PixelDejaVu[File[0]]= true; // on le marque comme deja utilisé

// verification du chemin DIRECTE vers le Puit avant de continuer sur ses voisins
    int Flot = courant->Cap_S_Puit - courant->flot_S_Puit;
    //cout<<"indice n°"<<File[0]<<" Et flot libre = "<<Flot<<endl;
    if(Flot > 0)
    {
      TabPredecesseur[L*C+1]= File[0];
      //On cherche le flot minimal que si on a un chemin vers le puit libre: pas plein
      Flot = FlotMin(TabPredecesseur, L*C+1); //Augmentation du flot dans l'arc à max
      assert(Flot > 0);
      assert(TabPixel[File[0]].flot_S_Puit <= TabPixel[File[0]].Cap_S_Puit);
      return Flot;
    }

//------------emfilement du voisins Nord du pixel courant
    if(courant->Sortant_Nord != nullptr) // si il existe et qu'on a pas encore un chemin valide
    {
      int IndiceNord = IndiceTab(courant->Sortant_Nord); //Alors on cherche son indice.
      assert(IndiceNord >= 0 && IndiceNord< L*C);
//______Verification de l'accès vers le voisin nord
      if(PixelDejaVu[IndiceNord]== false) // il n'est pas encore dans la file
      {
        if(courant->flot_S_Nord < courant->Cap_S_Nord) // on verifie si l'arc menant au Nord n'est pas plein: 
        {//si il est encore accessible
          File.push_back(IndiceNord); // on le stocke dans la file donc
          PixelDejaVu[IndiceNord]= true; // on le marque comme deja traité pour éviter de le rajouter plusieurs
                                        //dans la file si il est le voisin des prochain pixel qu'on va traiter
          TabPredecesseur[IndiceNord]= File[0];
        }
      }
    }

//------------emfilement du voisins Sud du pixel courant
    if(courant->Sortant_Sud != nullptr) // si il existe et qu'on a pas encore un chemin valide
    {
      int IndiceSud = IndiceTab(courant->Sortant_Sud); //Alors on cherche son indice.
      assert(IndiceSud >= 0 && IndiceSud< L*C);
//______Verification de l'accès vers le voisin nord
      if(PixelDejaVu[IndiceSud]== false) // il n'est pas encore dans la file
      {
        if(courant->flot_S_Sud < courant->Cap_S_Sud) // on verifie si l'arc menant au Nord n'est pas plein: 
        {//si il est encore accessible
          File.push_back(IndiceSud); // on le stocke dans la file donc
          PixelDejaVu[IndiceSud]= true; // on le marque comme deja traité pour éviter de le rajouter plusieurs
                                        //dans la file
          TabPredecesseur[IndiceSud]= File[0];
        }
      }
    }

//------------emfilement du voisins Est du pixel courant
    if(courant->Sortant_Est != nullptr) // si il existe et qu'on a pas encore un chemin valide
    {
      int IndiceEst = IndiceTab(courant->Sortant_Est); //Alors on cherche son indice.
      assert(IndiceEst >= 0 && IndiceEst< L*C);
//______Verification de l'accès vers le voisin nord
      if(PixelDejaVu[IndiceEst]== false) // il n'est pas encore dans la file
      {
        if(courant->flot_S_Est < courant->Cap_S_Est) // on verifie si l'arc menant au Nord n'est pas plein: 
        {//si il est encore accessible
          File.push_back(IndiceEst); // on le stocke dans la file donc
          PixelDejaVu[IndiceEst]= true; // on le marque comme deja traité pour éviter de le rajouter plusieurs
                                        //dans la file
          TabPredecesseur[IndiceEst]= File[0];
        }
      }
    }
//------------emfilement du voisins Ouest du pixel courant
    if(courant->Sortant_Ouest != nullptr) // si il existe et qu'on a pas encore un chemin valide
    {
      int IndiceOuest = IndiceTab(courant->Sortant_Ouest); //Alors on cherche son indice.
      assert(IndiceOuest >= 0 && IndiceOuest< L*C);
//______Verification de l'accès vers le voisin nord
      if(PixelDejaVu[IndiceOuest]== false) // il n'est pas encore dans la file
      {
        if(courant->flot_S_Ouest < courant->Cap_S_Ouest) // on verifie si l'arc menant au Nord n'est pas plein: 
        {//si il est encore accessible
          File.push_back(IndiceOuest); // on le stocke dans la file donc
          PixelDejaVu[IndiceOuest]= true; // on le marque comme deja traité pour éviter de le rajouter plusieurs
                                        //dans la file
          TabPredecesseur[IndiceOuest]= File[0];
        }
      }
    }          

    File.erase(File.begin());// suppression l'élément de la file
  }
  // si on lit se ligne, c'est qu'on n'a plus de chemin valide.
  assert(File.size() <= 0);
  
  if(File.size() <= 0) //condition de sortie du while => file vide => plus de chemin disponible
  {
    return 0; //on retourne un flot de 0.
  }

  return -1;
}

//------------------------------------CoupeGraphe--------------------------------
int Graphe::coupeGraphe()
{
  for(int i=0; i<L*C; i++)
  {
    if((TabPixel[i].Cap_E_Source - TabPixel[i].flot_E_Source) == 0) //=> relié à la source
    {
      TabPixel[i].intensite= 255;
    }
    else
    {
      TabPixel[i].intensite= 0;
    }
  }

  return 0;
}

//----------------------------Constructeur graphe--------------------------------
Graphe::Graphe(std::string nomFichier)
{
  FlotMaximal = 0;
  TabPixel = nullptr;
  //std::string nomFichier= "data/data2.pgm";
  ouvrir(nomFichier); //remplissage des INTENSITEE seulement de chaque pixel
  TabPixel[L*C].intensite= 0; // l'intensité de la source stockera le flot max.
  TabPixel[L*C+1].intensite= 0;
  InitVoisin(); //remplissage des 4 arcs voisins de chaque pixel.
  SetCap();
  cout<<endl<<"--Debut de recherche de chemin valide..."<<endl;

  int flot= 0;
  do{
    flot = ParcoursLargeur(); //Augmentation du flot en trouvant des chemin valide
    FlotMaximal = FlotMaximal + flot;
    //cout<<endl<<"flot = "<<flot<<" et flot max = "<<TabPixel[L*C].intensite<<endl;
    nomFichier= "data/La_Notre.pgm";
    coupeGraphe(); // pour le débogage
    sauver(nomFichier); // pour le débogage
    cout<<endl<<"Recherche de nouveaux chemin valide ..."<<endl;
    cout<<endl<<"Flot max tactuel= "<<FlotMaximal<<endl; // visible que pour des
    //sigma et alpha grand car si trop petit, le programme s'execute et finis très vite.
  }while(flot > 0);

  coupeGraphe();
} 