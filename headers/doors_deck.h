#pragma once
#include "acid.h"
#include "monsters.h"
#include "poison_apple.h"
#include "treasure.h"
#include <string>
#include <vector>
#include <deque>
#include <random>
#include <algorithm>

using namespace std;

#include <string>
#include <vector>
#include <deque>
#include <utility>

class Poison_apple;
class Acid;
class Treasure;
class Monsters;

class Doors_deck {
private:
    deque<pair<string, vector<int>>> deck;

public:
    Doors_deck(const Poison_apple& apple, const Acid& acid, 
              const Treasure& treasure, const Monsters& monsters);
    
    pair<string, vector<int>> drawAndRecycleCard();
    vector<pair<string, vector<int>>> drawInitialPlayerCards();
    void shuffleDeck();
    size_t deckSize() const;
};
