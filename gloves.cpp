// gloves.cpp content

// gloves_module.cpp
#include "gloves.h"

Gloves::Gloves() {
    setup_gloves();
}

void Gloves::setup_gloves() {
    gloves_id = { "leather gloves", "warrior gloves", "assassin gloves" };
    gloves_damage = { 1, 2, 3 };
}

const std::vector<std::string>& Gloves::GetGlovesID() const {
    return gloves_id;
}

const std::vector<int>& Gloves::GetGlovesDamage() const {
    return gloves_damage;
}
