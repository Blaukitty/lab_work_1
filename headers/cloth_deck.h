//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef CLOTH_DECK_H
#define CLOTH_DECK_H
#include <array>
#include <vector>
#include <string>
#include <random>
#include <utility>

class Armor;
class Gloves;
class Boots;
class Protection;

class Cloth_deck {
private:
    std::vector<std::string> cloth_names;
    std::vector<int> cloth_stats;
    std::array<std::string, 2> YourCloth0;
    std::array<int, 2> YourClothData;

public:
    Cloth_deck(const Armor& arm, const Gloves& glv, const Boots& bts, const Protection& prot);
    
    void random_carts();
    const std::array<std::string, 2>& GetYourCloth0() const;
    const std::array<int, 2>& GetYourClothData() const;
};
#endif
