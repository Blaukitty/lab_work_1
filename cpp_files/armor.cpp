// armor.cpp content

// armor_module.cpp
#include "armor.h"

Armor::Armor() {
    setup_armor();
}

void Armor::setup_armor() {
    armor_id = { "leather armor", "chain mail", "plate armor" };
    armor_protection = { 1, 2, 3 };
}

const std::vector<std::string>& Armor::GetArmorID() const {
    return armor_id;
}

const std::vector<int>& Armor::GetArmorProtection() const {
    return armor_protection;
}
