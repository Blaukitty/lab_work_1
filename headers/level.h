//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef LEVEL_H
#define LEVEL_H
#include "your_carts.h"
#include "ai.h"
#include <iostream>

class Level {
private:
    int lev;
    int lev_ai;

public:
    Level();
    void level_counter(your_carts& cart1);
    void level_counter(ai& cart2);
    void showLevel() const;
    int getPlayerLevel() const;
    int getAILevel() const;
};
#endif
