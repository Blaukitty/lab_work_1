// Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru

#ifndef AI_LEARNING_H
#define AI_LEARNING_H
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

struct aiCardData {
    std::string name2;
    int data2;
};

class ai_learning {
    std::vector<aiCardData> sel_ai_cards;
    int counter = 0;

public:
    aiCardData selectBestCard();
    aiCardData selectWorstCard();
    void respondToVictory(bool isMonsterCard, bool player2Won);
};
#endif
