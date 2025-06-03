// Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#include "treasure.h"

Treasure::Treasure() {
    setup_treasures();
}

void Treasure::setup_treasures() {
    treasure_id = { "magic ring", "blue diadem", "king's crown" };
    level_up = { 1, 2, 3 }; // Примеры повышения уровня
}

const std::vector<std::string>& Treasure::GetTreasureID() const {
    return treasure_id;
}

const std::vector<int>& Treasure::GetLwlUp() const {
    return level_up;
}
