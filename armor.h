// armor.h content

// armor_module.h
#pragma once
#include <string>
#include <vector>

class Armor {
private:
    std::vector<std::string> armor_id;
    std::vector<int> armor_protection;

    void setup_armor();

public:
    Armor();
    const std::vector<std::string>& GetArmorID() const;
    const std::vector<int>& GetArmorProtection() const;
};

