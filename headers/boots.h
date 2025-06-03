//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef BOOTS_H
#define BOOTS_H
#include <string>
#include <vector>

class Boots {
private:
    std::vector<std::string> boots_id;
    std::vector<int> boots_speed;
    void setup_boots();

public:
    Boots();
    const std::vector<std::string>& GetBootsID() const;
    const std::vector<int>& GetBootsSpeed() const;
};
#endif
