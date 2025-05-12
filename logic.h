#pragma once
#include "your_carts.h"
#include "ai.h"
#include "field.h"
#include "level.h"
#include "doors_deck.h"
#include "choose_cart_bottom.h"
#include "cause_troubles_bottom.h"

class Logic {
private:
    bool flag = true;

public:
    void turns(your_carts& plr, ai& bot, Field& field, 
              choose_cart_bottom& chooser, couse_troubles_bottom& troubles,
              Level& levelTracker, Doors_deck& deck2);
    void end();
};
