#pragma once
#include "your_carts.h"
#include "common.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class couse_trubles_bottom {
private:
    string couse;
    int couse2;
    vector<CardData> playerCards;

public:
    void load_from_player(const your_carts& player) {
        playerCards.clear();
        for (int i = 0; i < 4; ++i) {
            playerCards.push_back(CardData{ player.Carts[i], player.Data[i] });
        }
    }

    CardData choose_cart() {
        cout << "Type 'ow, you want to couse some troubles... OK! I like it'\n";
        cin.ignore();
        getline(cin, couse);

        if (couse == "ow, you want to couse some troubles... OK! I like it") {
            cout << "Choose a card index (0-3): ";
            cin >> couse2;

            if (couse2 >= 0 && couse2 < 4) {
                cout << "You threw: " << playerCards[couse2].name
                          << " (data: " << playerCards[couse2].data << ")\n";
                return playerCards[couse2];
            } else {
                cout << "Incorrect index. No card thrown.\n";
            }
        } else {
            cout << "Cancelled.\n";
        }

        return { "", -1 }; // Return invalid card if cancelled or wrong input
    }
};
