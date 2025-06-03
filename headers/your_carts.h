// Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef YOUR_CARTS_H
#define YOUR_CARTS_H
#include <string>
#include <array>
#include "cloth_deck.h"  

class race;
class cl_ass;

class your_carts {
public:
    int player_id;
    int cloth_goals;
    int treasure_goals;
    int damage;
    int protection;
    int speed;
    int money;
    std::array<std::string, 4> Carts;
    std::array<int, 4> Data;

    your_carts();

    void showStatus(const race& ra, const cl_ass& as);
    void carts_getting(const Cloth_deck& cl);
    void data_getting(const Cloth_deck& cl);
    void showCarts();
};
#endif
