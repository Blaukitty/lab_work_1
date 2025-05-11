#pragma once
#include "your_carts.h"
#include "common.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class choose_cart_bottom {
private:
    string input;
    int input2;
    vector<CardData> selected_cards;

public:
    void choose_cart(const your_carts& crt) {
        cout << "Print (choose) to use card\n";
        cin >> input;

        // Проверка корректности ввода команды
        while (input != "choose") {
            cout << "Incorrect command. Try again: ";
            cin >> input;
        }


        if (input == "choose") {
            cout << "Now, choose cart you want to use (2, 3)\n";
            cin >> input2;
    
            while (input2 < 2 && input2 > 3) {
            cout << "Incorrect index. Try again! ";
            cin >> input2;
            }
            if (input2 == 2 || input2 == 3) {
                CardData card;
                card.name = crt.Carts[input2];
                card.data = crt.Data[input2];
                selected_cards.push_back(card);

                cout << "You chose cart: " << card.name
                          << " with data: " << card.data << endl;
            } 
        }
    }

    const vector<CardData>& get_selected_cards() const {
        return selected_cards;
    }
};
