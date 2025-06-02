#pragma once
#include "your_carts.h"
#include "common.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class couse_troubles_bottom {
private:
    int couse{0};
    int couse2{0};
    vector<CardData> playerCards;

public:
    void load_from_player(const your_carts& player) {
        playerCards.clear();
        for (int i = 0; i < 4; ++i)
            playerCards.push_back({ player.Carts[i], player.Data[i] });
    }

    CardData choose_cart() {
        cout << "(1) — make problems, (0) — miss the opportunity: ";
        cin >> couse;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (couse != 0 && couse != 1) {
            cout << "Incorrect command! Use 0 or 1: ";
            cin >> couse;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (couse == 1) {
            cout << "Choose cart index (2-3): ";
            cin >> couse2;

            while (couse2 < 2 || couse2 > 3) {
                cout << "Incorrect index! Try again (2-3): ";
                cin >> couse2;
            }

            const auto& card = playerCards[couse2];
            cout << "AI use: " << card.name
                 << " (data: " << card.data << ")\n";
            return card;
        }
        return CardData{"", -1};
    }
};
