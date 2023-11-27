#ifndef _PIXEL
#define _PIXEL

#include <iostream>
#include <cassert>
#include <ctime>

class Graphe;

class Pixel
{
    public:
    int intensite;
//------------------
    Pixel * Sortant_Nord; //"sortant" = qui part du pixel actuel vers un autre
    int Cap_S_Nord;
    int flot_S_Nord; // le flot sortant nord doit être inférieur à la capacité sortant Nord
//------------------
    Pixel * Sortant_Sud;
    int Cap_S_Sud;
    int flot_S_Sud;
//------------------
    Pixel * Sortant_Est;
    int Cap_S_Est;
    int flot_S_Est;
//------------------
    Pixel * Sortant_Ouest;
    int Cap_S_Ouest;
    int flot_S_Ouest;
//------------------
    Pixel * Entrant_Nord; // "Entrant" = Qui pointe vers le pixel actuel venant d'un autre pixel
    int Cap_E_Nord;
    int flot_E_Nord;
//------------------
    Pixel * Entrant_Sud;
    int Cap_E_Sud;
    int flot_E_Sud;
//------------------
    Pixel * Entrant_Est;
    int Cap_E_Est;
    int flot_E_Est;
//------------------
    Pixel * Entrant_Ouest;
    int Cap_E_Ouest;
    int flot_E_Ouest;
//------------------
    Pixel * Sortant_Puit;
    int Cap_S_Puit;
    int flot_S_Puit;
//------------------
    Pixel * Entrant_Source;
    int Cap_E_Source;
    int flot_E_Source;
    
//-------------------------------------------------------------------------------
    Pixel();
};


#endif