//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef COUSE_TROUBLES_BOTTOM_H
#define COUSE_TROUBLES_BOTTOM_H

#include "your_carts.h"
#include "common.h"
#include <string>
#include <vector>
#include <iostream>
#include <limits>

class couse_troubles_bottom {
private:
    int couse{0};
    int couse2{0};
    std::vector<CardData> playerCards;

public:
    void load_from_player(const your_carts& player) {
        playerCards.clear();
        for (int i = 0; i < 4; ++i) {
            playerCards.push_back({ player.Carts[i], player.Data[i] });
        }
    }

    CardData choose_cart() {
        std::cout << "(1) — make problems, (0) — miss the opportunity: ";
        std::cin >> couse;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (couse != 0 && couse != 1) {
            std::cout << "Incorrect command! Use 0 or 1: ";
            std::cin >> couse;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (couse == 1) {
            std::cout << "Choose cart index (2-3): ";
            std::cin >> couse2;

            while (couse2 < 2 || couse2 > 3) {
                std::cout << "Incorrect index! Try again (2-3): ";
                std::cin >> couse2;
            }

            const auto& card = playerCards[couse2];
            std::cout << "AI use: " << card.name
                      << " (data: " << card.data << ")\n";
            return card;
        }
        return CardData{"", -1};
    }
};

#endif 
