// Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#include "ai.h"
#include "cloth_deck.h"
#include <iostream>

ai::ai() 
    : ai_id(0), cloth_goals_ai(0), treasure_goals_ai(0), damage_ai(1), protection_ai(1),
      speed_ai(1), money_ai(0), ai_rase(""), ai_cl_ass(""), Carts_ai{"", "", "", ""},
      Data_ai{0, 0, 0, 0} {}

void ai::show_identity() const {
    std::cout << "\n--- AI Identity (=_=)  ---\n";
    std::cout << " Race: " << ai_rase << std::endl;
    std::cout << " Class: " << ai_cl_ass << std::endl;
}

void ai::carts_getting_ai(const Cloth_deck& clo) {
    auto temp = clo.GetYourCloth0();
    if (temp.size() >= 2) {
        Carts_ai[0] = temp[0];
        Carts_ai[1] = temp[1];
    }
}

void ai::data_getting_ai(const Cloth_deck& clo) {
    auto temp = clo.GetYourClothData();
    if (temp.size() >= 2) {
        Data_ai[0] = temp[0];
        Data_ai[1] = temp[1];
    }
}
