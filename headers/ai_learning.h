// ai_learning.h

#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

struct aiCardData {
    string name2;
    int data2;
};

class ai_learning {
    vector<aiCardData> sel_ai_cards;
    int counter = 0;

public:
    aiCardData selectBestCard();
    aiCardData selectWorstCard();
    void respondToVictory(bool isMonsterCard, bool player2Won);
};
