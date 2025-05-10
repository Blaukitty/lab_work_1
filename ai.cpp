// ai.cpp content
#include "ai.h"
#include <iostream>
using namespace std;

ai::ai() 
    : ai_id(0), cloth_goals_ai(0), treasure_goals_ai(0),
      damage_ai(1), protection_ai(1), speed_ai(1), money_ai(0),
      ai_rase(""), ai_cl_ass(""),
      Carts_ai{"", "", "", ""},  
      Data_ai{0, 0, 0, 0} {}

void ai::show_identity() const {
    cout << "\n--- AI Identity (=_=)  ---\n";
    cout << " Race: " << ai_rase << endl;
    cout << " Class: " << ai_cl_ass << endl;
}

void ai::carts_getting_ai(const Cloth_deck& clo) {
    auto temp = clo.GetYourCloth0();
    Carts_ai[0] = temp[0];
    Carts_ai[1] = temp[1];
}

void ai::data_getting_ai(const Cloth_deck& clo) {
    auto temp = clo.GetYourClothData();
    Data_ai[0] = temp[0];
    Data_ai[1] = temp[1];
}
