//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#include "cloth_deck.h"
#include "armor.h"
#include "gloves.h"
#include "boots.h"
#include "protection.h"
#include <algorithm>
#include <random>

Cloth_deck::Cloth_deck(const Armor& arm, const Gloves& glv, 
                      const Boots& bts, const Protection& prot) {
    // Заполняем названия
    auto armor_names = arm.GetArmorID();
    auto gloves_names = glv.GetGlovesID();
    auto boots_names = bts.GetBootsID();
    auto prot_names = prot.GetProtectionID();
    
    cloth_names.insert(cloth_names.end(), armor_names.begin(), armor_names.end());
    cloth_names.insert(cloth_names.end(), gloves_names.begin(), gloves_names.end());
    cloth_names.insert(cloth_names.end(), boots_names.begin(), boots_names.end());
    cloth_names.insert(cloth_names.end(), prot_names.begin(), prot_names.end());
    
    // Заполняем характеристики
    auto armor_stats = arm.GetArmorProtection();
    auto gloves_stats = glv.GetGlovesDamage();
    auto boots_stats = bts.GetBootsSpeed();
    auto prot_stats = prot.GetProtectionValue();
    
    cloth_stats.insert(cloth_stats.end(), armor_stats.begin(), armor_stats.end());
    cloth_stats.insert(cloth_stats.end(), gloves_stats.begin(), gloves_stats.end());
    cloth_stats.insert(cloth_stats.end(), boots_stats.begin(), boots_stats.end());
    cloth_stats.insert(cloth_stats.end(), prot_stats.begin(), prot_stats.end());
}

void Cloth_deck::random_carts() {
    if (cloth_names.empty() || cloth_names.size() != cloth_stats.size()) return;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, static_cast<int>(cloth_names.size()) - 1);
    
    for (int i = 0; i < 2; ++i) {
        int idx = dist(gen);
        YourCloth0[i] = cloth_names[idx];
        YourClothData[i] = cloth_stats[idx];
    }
}

const std::array<std::string, 2>& Cloth_deck::GetYourCloth0() const {
    return YourCloth0;
}

const std::array<int, 2>& Cloth_deck::GetYourClothData() const {
    return YourClothData;
}
