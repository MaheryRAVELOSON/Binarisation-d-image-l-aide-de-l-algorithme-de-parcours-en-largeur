#include "pixel.h"

//-------------------------------------------------------------------------------
Pixel::Pixel()
{
    Entrant_Nord= nullptr;
    Cap_E_Nord= 0;
    flot_E_Nord= 0;

    Entrant_Sud= nullptr;
    Cap_E_Sud= 0;
    flot_E_Sud= 0;

    Entrant_Est= nullptr;
    Cap_E_Est= 0;
    flot_E_Est= 0;

    Entrant_Ouest= nullptr;
    Cap_E_Ouest= 0;
    flot_E_Ouest= 0;

    Sortant_Nord= nullptr;
    Cap_S_Nord= 0;
    flot_S_Nord= 0;

    Sortant_Sud= nullptr;
    Cap_S_Sud= 0;
    flot_S_Sud= 0;

    Sortant_Est= nullptr;
    Cap_S_Est= 0;
    flot_S_Est= 0;

    Sortant_Ouest= nullptr;
    Cap_S_Ouest= 0;
    flot_S_Ouest= 0;

    Entrant_Source= nullptr;
    Cap_E_Source= 0;
    flot_E_Source= 0;

    Sortant_Puit= nullptr;
    Cap_S_Puit= 0;
    flot_S_Puit= 0;
}