//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef GLOVES_H
#define GLOVES_H
#include <string>
#include <vector>

class Gloves {
private:
    std::vector<std::string> gloves_id;
    std::vector<int> gloves_damage;
    void setup_gloves();

public:
    Gloves();
    const std::vector<std::string>& GetGlovesID() const;
    const std::vector<int>& GetGlovesDamage() const;
};
#endif
