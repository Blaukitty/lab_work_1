// Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#include "boots.h"

Boots::Boots() {
    setup_boots();
}

void Boots::setup_boots() {
    boots_id = { "leather boots", "swift boots", "winged boots" };
    boots_speed = { 1, 2, 3 };
}

const std::vector<std::string>& Boots::GetBootsID() const {
    return boots_id;
}

const std::vector<int>& Boots::GetBootsSpeed() const {
    return boots_speed;
}
