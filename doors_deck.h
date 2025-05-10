// doors_deck.h content

// doors_deck.h
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

#pragma once
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
    std::deque<std::pair<std::string, std::vector<int>>> deck;

public:
    Doors_deck(const Poison_apple& apple, const Acid& acid, 
              const Treasure& treasure, const Monsters& monsters);
    
    std::pair<std::string, std::vector<int>> drawAndRecycleCard();
    std::vector<std::pair<std::string, std::vector<int>>> drawInitialPlayerCards();
    void shuffleDeck();
    size_t deckSize() const;
};
