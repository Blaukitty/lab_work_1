// ai.h content
#pragma once

#include <string>
#include <array>
#include "cloth_deck.h"
#include "ai_learning.h"

using namespace std;

class ai {
public:
    ai_learning brain;
    int ai_id;
    int cloth_goals_ai;
    int treasure_goals_ai;
    int damage_ai;
    int protection_ai;
    int speed_ai;
    int money_ai;
    string ai_rase;
    string ai_cl_ass;
    array<string, 4> Carts_ai;
    array<int, 4> Data_ai;

    ai();

    void show_identity() const;
    void carts_getting_ai(const Cloth_deck& clo);
    void data_getting_ai(const Cloth_deck& clo);
};
