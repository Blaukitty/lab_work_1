// field.h content

// field_module.h
#pragma once
#include <string>
#include <vector>
#include <numeric>
#include "monsters.h"

using namespace std;

class Field {
private:
    string Cart_enemy;
    vector<int> Data_enemy;

public:
    void loadMonstersFromDeck(const Monsters& mons);
    void setEnemyCard(const string& name, const vector<int>& stats);
    void show_enemy() const;
    bool isCurrentEnemyMonster() const;
    int getEnemyDataSum() const;
    string getEnemyName() const;
};
