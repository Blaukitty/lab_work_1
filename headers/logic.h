#pragma once

#include <iostream>
#include "your_carts.h"
#include "ai.h"
#include "field.h"
#include "level.h"
#include "doors_deck.h"
#include "choose_cart_bottom.h"
#include "couse_troubles_bottom.h"

class Logic {
private:
    bool flag{true};                 // флаг работы игрового цикла

public:

 void turns(your_carts& player,
               ai&          bot,
               Field&       field,
               choose_cart_bottom&  chooser,
               couse_troubles_bottom& troubles,
               Level&       levelTracker,
               Doors_deck&  doorsDeck);

    /// Останавливает игровой цикл.
    void end();
};
