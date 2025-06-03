//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#include "doors_deck.h"
#include <algorithm>
#include <random>

Doors_deck::Doors_deck(const Poison_apple& apple, const Acid& acid, 
                      const Treasure& treasure, const Monsters& monsters) {
    // Добавляем карты Poison_apple
    for (size_t i = 0; i < apple.GetAppleID().size(); ++i) {
        deck.push_back(std::make_pair(apple.GetAppleID()[i], 
                        std::vector<int>{apple.GetAppleGoals()[i]}));
    }
    
    // Добавляем карты Acid
    for (size_t i = 0; i < acid.GetAcidID().size(); ++i) {
        deck.push_back(std::make_pair(acid.GetAcidID()[i], 
                        std::vector<int>{acid.GetLvlDwn()[i]}));
    }
    
    // Добавляем карты Treasure
    for (size_t i = 0; i < treasure.GetTreasureID().size(); ++i) {
        deck.push_back(std::make_pair(treasure.GetTreasureID()[i], 
                        std::vector<int>{treasure.GetLwlUp()[i]}));
    }
    
    // Добавляем карты Monsters
    auto monster_names = monsters.GetMonsterName();
    auto monster_stats = monsters.GetMonsterStatArrays();
    for (size_t i = 0; i < monster_names.size(); ++i) {
        std::vector<int> stats = {
            monster_stats[0][i], 
            monster_stats[1][i],
            monster_stats[2][i], 
            monster_stats[3][i]
        };
        deck.push_back(std::make_pair(monster_names[i], stats));
    }
    
    shuffleDeck();
}

pair<std::string, std::vector<int>> Doors_deck::drawAndRecycleCard() {
    if (deck.empty()) return {"", {0, 0, 0, 0}};

    auto card = deck.front();
    deck.pop_front();
    deck.push_back(card);
    return card;
}

std::vector<std::pair<std::string, std::vector<int>>> Doors_deck::drawInitialPlayerCards() {
    std::vector<std::pair<std::string, std::vector<int>>> initialCards;
    for (int i = 0; i < 2; ++i) {
        initialCards.push_back(drawAndRecycleCard());
    }
    return initialCards;
}

void Doors_deck::shuffleDeck() {
    std::vector<std::pair<std::string, std::vector<int>>> temp(deck.begin(), deck.end());
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(temp.begin(), temp.end(), g);
    deck = std::deque<std::pair<std::string, std::vector<int>>>(temp.begin(), temp.end());
}

size_t Doors_deck::deckSize() const {
    return deck.size();
}
