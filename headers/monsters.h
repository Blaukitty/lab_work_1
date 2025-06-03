//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef MONSTERS_H
#define MONSTERS_H
#include <string>
#include <vector>

class Monsters {
private:
    std::vector<std::string> monster_name;
    std::vector<int> speedM;
    std::vector<int> damageM;
    std::vector<int> protectionM;
    std::vector<int> moneyM;

    void setup_monsters();

public:
    Monsters();
    const std::vector<std::string>& GetMonsterName() const;
    std::vector<std::vector<int>> GetMonsterStatArrays() const;
    std::vector<int> GetStatByMonsterName(const std::string& name) const;
    bool IsMonster(const std::string& name) const;
};
#endif
