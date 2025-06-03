//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef FIELD_H
#define FIELD_H

#include <string>
#include <vector>
#include <numeric>
#include "monsters.h"

class Field {
private:
    std::string Cart_enemy;
    std::vector<int> Data_enemy;

public:
    void loadMonstersFromDeck(const Monsters& mons);
    void setEnemyCard(const std::string& name, const std::vector<int>& stats);
    void show_enemy() const;
    bool isCurrentEnemyMonster() const;
    int getEnemyDataSum() const;
    std::string getEnemyName() const;
};

#endif 
