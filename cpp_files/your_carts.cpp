// Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#include "your_carts.h"
#include "race_class.h"    
#include <iostream>

your_carts::your_carts()
    : player_id(0), cloth_goals(0), treasure_goals(0), damage(1), 
      protection(1), speed(1), money(0), 
      Data{0, 0, 0, 0}, Carts{"", "", "", ""} {}

void your_carts::showStatus(const race& ra, const cl_ass& as) {
    std::cout << "\n--- Player Status (>.<)  ---\n";
    std::cout << " Race: " << ra.race_n << std::endl;
    std::cout << " Class: " << as.cl_ass_n << std::endl;
    std::cout << " Damage: " << damage << std::endl;
    std::cout << " Protection: " << protection << std::endl;
    std::cout << " Speed: " << speed << std::endl;
    std::cout << " Money: " << money << std::endl;
}

void your_carts::carts_getting(const Cloth_deck& cl) {
    auto temp = cl.GetYourCloth0();
    Carts[0] = temp[0];
    Carts[1] = temp[1];
}

void your_carts::data_getting(const Cloth_deck& cl) {
    auto temp = cl.GetYourClothData();
    Data[0] = temp[0];
    Data[1] = temp[1];
}

void your_carts::showCarts() {
    std::cout << "\n--- Player Carts (^^) ---\n";
    std::cout << "Cloth Cards:\n";
    for (int i = 0; i < 2; i++) {
        std::cout << Carts[i] << " ... " << Data[i] << "\n";
    }
    std::cout << "Door Cards:\n";
    for (int i = 2; i < 4; i++) {
        std::cout << Carts[i] << " ... " << Data[i] << "\n";
    }
}
