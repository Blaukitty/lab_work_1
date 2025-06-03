//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef ARMOR_H
#define ARMOR_H
#include <string>
#include <vector>

class Armor {
private:
    std::vector<std::string> armor_id;
    std::vector<int> armor_protection;

    void setup_armor();

public:
    Armor();
    const std::vector<std::string>& GetArmorID() const;
    const std::vector<int>& GetArmorProtection() const;
};
#endif
