// Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru

#include "ai_learning.h"

aiCardData ai_learning::selectBestCard() {
    auto it = std::max_element(
        sel_ai_cards.begin(),
        sel_ai_cards.end(),
        [](const aiCardData& a, const aiCardData& b) {
            return a.data2 < b.data2;
        }
    );
    return aiCardData{ it->name2, it->data2 };
}

aiCardData ai_learning::selectWorstCard() {
    auto it = std::min_element(
        sel_ai_cards.begin(),
        sel_ai_cards.end(),
        [](const aiCardData& a, const aiCardData& b) {
            return a.data2 < b.data2;
        }
    );
    return aiCardData{ it->name2, it->data2 };
}

void ai_learning::respondToVictory(bool isMonsterCard, bool player2Won) {
    if (!isMonsterCard) return;

    if (player2Won && counter % 2 == 0) {
        aiCardData to_throw = selectWorstCard();
        std::cout << "AI is making troubles to you: " << to_throw.name2
                  << " (value: " << to_throw.data2 << ")\n";
    }
    counter++;
}

