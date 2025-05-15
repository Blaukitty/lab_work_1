// level.h content

// level_module.h
#pragma once
#include "your_carts.h"
#include "ai.h"
#include <iostream>

class Level {
private:
    int lev;
    int lev_ai;

public:
    Level();
    void level_counter(your_carts& cart1); // +1 level
    void level_counter(ai& cart2);
    //+n level
    void gainLevel(your_carts& cart1, int delta);
    void gainLevel(ai& cart2, int delta);
    
    void showLevel() const;
    
    int getPlayerLevel() const;
    int getAILevel() const;
};
