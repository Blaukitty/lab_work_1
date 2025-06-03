//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef DOORS_DECK_H
#define DOORS_DECK_H

#include "acid.h"
#include "monsters.h"
#include "poison_apple.h"
#include "treasure.h"
#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#include <random>

class Poison_apple;
class Acid;
class Treasure;
class Monsters;

class Doors_deck {
private:
    std::deque<std::pair<std::string, std::vector<int>>> deck;

public:
    Doors_deck(const Poison_apple& apple,
               const Acid& acid,
               const Treasure& treasure,
               const Monsters& monsters);

    std::pair<std::string, std::vector<int>> drawAndRecycleCard();
    std::vector<std::pair<std::string, std::vector<int>>> drawInitialPlayerCards();
    void shuffleDeck();
    size_t deckSize() const;
};

#endif 
