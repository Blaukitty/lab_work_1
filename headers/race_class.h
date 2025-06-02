// race_class.h content

// race_class.h
#pragma once
#include <string>
#include <random>
#include <iostream>
#include "ai.h"

class your_carts;

class race {
public:
    std::string race_n;

    void choosing_race(your_carts& cart);
    void choosing_race_ai(ai& cartA);
};

class cl_ass {
public:
    std::string cl_ass_n;

    void choosing_class(your_carts& cart0);
    void choosing_class_ai(ai& cartB);
};
