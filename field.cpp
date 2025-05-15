// field.cpp content

// field_module.cpp
#include "field.h"
#include <iostream>

void Field::loadMonstersFromDeck(const Monsters& mons) {
    // Example: Load the first monster from the deck as the current enemy
    if (!mons.GetMonsterName().empty()) {
        Cart_enemy = mons.GetMonsterName()[0];
        Data_enemy = mons.GetStatByMonsterName(Cart_enemy);
    }
}

void Field::setEnemyCard(const std::string& name, const std::vector<int>& stats) {
    Cart_enemy = name;
    Data_enemy = stats;
}

void Field::show_enemy() const {
    std::cout << "\n--- Your enemy (x . x) ---\n";
    std::cout << Cart_enemy << " ... ";
    for (int stat : Data_enemy) {
        std::cout << stat << " \n";
    }
    std::cout << "\n";
}

bool Field::isCurrentEnemyMonster() const {
    return Data_enemy.size() >= 3 && (Data_enemy[2] > 0 || Data_enemy[3] > 0);
}

int Field::getEnemyDataSum() const {
    return std::accumulate(Data_enemy.begin(), Data_enemy.end(), 0);
}

std::string Field::getEnemyName() const {
    return Cart_enemy;
}
