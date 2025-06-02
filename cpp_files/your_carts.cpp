// your_carts.cpp content

// your_carts.cpp
#include "your_carts.h"
#include "race_class.h"    // Для классов race и cl_ass
#include <iostream>

using namespace std;

your_carts::your_carts()
    : player_id(0), cloth_goals(0), treasure_goals(0), damage(1), 
      protection(1), speed(1), money(0), 
      Data{0, 0, 0, 0}, Carts{"", "", "", ""} {}

void your_carts::showStatus(const race& ra, const cl_ass& as) {
    cout << "\n--- Player Status (>.<)  ---\n";
    cout << " Race: " << ra.race_n << endl;
    cout << " Class: " << as.cl_ass_n << endl;
    cout << " Damage: " << damage << endl;
    cout << " Protection: " << protection << endl;
    cout << " Speed: " << speed << endl;
    cout << " Money: " << money << endl;
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
    cout << "\n--- Player Carts (^^) ---\n";
    cout << "Cloth Cards:\n";
    for (int i = 0; i < 2; i++) {
        cout << Carts[i] << " ... " << Data[i] << "\n";
    }
    cout << "Door Cards:\n";
    for (int i = 2; i < 4; i++) {
        cout << Carts[i] << " ... " << Data[i] << "\n";
    }
}
