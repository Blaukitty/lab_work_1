// logic.h content

// logic_module.h
#pragma once
#include "your_carts.h"
#include "ai.h"
#include "field.h"
#include "level.h"
#include "doors_deck.h"
#include <iostream>

class Logic {
private:
    bool flag = true;

public:
    void turns(your_carts& plr, ai& bot, Field& field, Level& levelTracker, Doors_deck& deck2);
    void end();
};
