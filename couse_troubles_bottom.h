#pragma once
#include "your_carts.h"
#include "common.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class couse_trubles_bottom {
private:
    int couse;
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
        cout << "(1) if u want to make problems or type (0)\n";
        cin.ignore();
        getline(cin, couse);

        while (ccouse != 0 && choice != 1) {
            cout << " Incorrect command! ";
            cin >> couse;
        }
        if (couse == (1)) {
            cout << "Choose a card index (2-3): ";
            cin >> couse2;

            while (couse2 < 2 || couse2 > 3) {
                cout << "Incorrect cart index! Try again /:";
                cin >> cardIndex;
            }
            if (couse2 >= 2 && couse2 < 4) {
                cout << "You threw: " << playerCards[couse2].name
                          << " (data: " << playerCards[couse2].data << ")\n";
                return playerCards[couse2];
            } 
        } 
        return { "", -1 }; // Return invalid card if cancelled or wrong input
    }
};
