//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef POISON_APPLE_H
#define POISON_APPLE_H
#include <string>
#include <vector>

class Poison_apple {
private:
    std::vector<std::string> apple_id;
    std::vector<int> apple_goals;

    void setup_apples();

public:
    Poison_apple();
    const std::vector<std::string>& GetAppleID() const;
    const std::vector<int>& GetAppleGoals() const;
};
#endif
