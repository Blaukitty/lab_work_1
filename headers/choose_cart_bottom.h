//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#ifndef CHOOSE_CART_BOTTOM_H
#define CHOOSE_CART_BOTTOM_H
#include "your_carts.h"
#include "common.h"
#include <string>
#include <vector>
#include <iostream>

class choose_cart_bottom {
private:
    std::string input;
    int input2;
    std::vector<CardData> selected_cards;

public:
    void choose_cart(const your_carts& crt) {
        std::cout << "Print (choose) to use card\n";
        std::cin >> input;

        // Проверка корректности ввода команды
        while (input != "choose") {
            std::cout << "Incorrect command. Try again: ";
            std::cin >> input;
        }


        if (input == "choose") {
            std::cout << "Now, choose cart you want to use (2, 3)\n";
            std::cin >> input2;
    
            while (input2 < 2 && input2 > 3) {
            std::cout << "Incorrect index. Try again! ";
            std::cin >> input2;
            }
            if (input2 == 2 || input2 == 3) {
                CardData card;
                card.name = crt.Carts[input2];
                card.data = crt.Data[input2];
                selected_cards.push_back(card);

                std::cout << "You chose cart: " << card.name
                          << " with data: " << card.data << std::endl;
            } 
        }
    }

    const std::vector<CardData>& get_selected_cards() const {
        return selected_cards;
    }
};
#endif
