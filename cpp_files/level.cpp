// Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#include "level.h"

Level::Level() : lev(1), lev_ai(1) {}

void Level::level_counter(your_carts& cart1) {
    if (lev >= 11) {
        std::cout << "\n! Wow, you have the max level now !\n";
        return;
    }
    if (cart1.money >= lev * 2) {
        lev++;
    }
}

void Level::level_counter(ai& cart2) {
    if (lev_ai >= 11) {
        std::cout << "\n! AI has the max level now !\n";
        return;
    }
    if (cart2.money_ai >= lev_ai * 2) {
        lev_ai++;
    }
}

void Level::showLevel() const {
    std::cout << "\n--- Players Level (>^w^<)  ---\n";
    std::cout << " Your Level: " << lev << std::endl;
    for (int i = 0; i < lev; ++i) std::cout << " $ ";

    std::cout << "\n AI Level: " << lev_ai << std::endl;
    for (int i = 0; i < lev_ai; ++i) std::cout << " * ";
    std::cout << "\n";
}

int Level::getPlayerLevel() const {
    return lev;
}

int Level::getAILevel() const {
    return lev_ai;
}
