// monsters.cpp content


// monsters_module.cpp
#include "monsters.h"
#include <algorithm>

Monsters::Monsters() {
    setup_monsters();
}

void Monsters::setup_monsters() {
    monster_name = { "Fool monster", "Mike Vazovsky", "Garden dwarf", "Slenderman", "Toby", "Kisame", "Kakuzu", "Sasori", "Deidara", "Pain", "Itachi", "Magic dragon" };

    speedM      = { 0, 2, 1, 4, 3, 3, 1, 1, 1, 5, 6, 4 };
    damageM     = { 1, 3, 3, 5, 4, 4, 3, 2, 2, 4, 6, 5 };
    protectionM = { 1, 1, 2, 1, 1, 1, 3, 1, 1, 2, 5, 3 };
    moneyM      = { 0, 0, 1, 0, 1, -3, 1, 1, -4, 0, -1, -2 };
}

const std::vector<std::string>& Monsters::GetMonsterName() const {
    return monster_name;
}

std::vector<std::vector<int>> Monsters::GetMonsterStatArrays() const {
    return { speedM, damageM, protectionM, moneyM };
}

std::vector<int> Monsters::GetStatByMonsterName(const std::string& name) const {
    for (size_t i = 0; i < monster_name.size(); ++i) {
        if (monster_name[i] == name) {
            return { speedM[i], damageM[i], protectionM[i], moneyM[i] };
        }
    }
    return { -1, -1, -1, -1 }; // Monster not found
}

bool Monsters::IsMonster(const std::string& name) const {
    return std::find(monster_name.begin(), monster_name.end(), name) != monster_name.end();
}
