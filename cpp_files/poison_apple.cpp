// poison_apple.cpp content

// poison_apple_module.cpp
#include "poison_apple.h"

Poison_apple::Poison_apple() {
    setup_apples();
}

void Poison_apple::setup_apples() {
    apple_id = { "poison apple", "apple of death", "snow white apple" };
    apple_goals = { 2, 3, 4 }; // Примеры значений урона/цели
}

const std::vector<std::string>& Poison_apple::GetAppleID() const {
    return apple_id;
}

const std::vector<int>& Poison_apple::GetAppleGoals() const {
    return apple_goals;
}
