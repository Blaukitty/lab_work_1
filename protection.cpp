// protection.cpp content

// protection_module.cpp
#include "protection.h"

Protection::Protection() {
    setup_protection();
}

void Protection::setup_protection() {
    protection_id = { "magic amulet", "shield charm", "guardian stone" };
    protection_value = { 1, 2, 3 };
}

const std::vector<std::string>& Protection::GetProtectionID() const {
    return protection_id;
}

const std::vector<int>& Protection::GetProtectionValue() const {
    return protection_value;
}
