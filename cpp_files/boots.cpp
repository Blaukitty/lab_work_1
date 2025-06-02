// boots.cpp content

// boots_module.cpp
#include "boots.h"

using namespace std;

Boots::Boots() {
    setup_boots();
}

void Boots::setup_boots() {
    boots_id = { "leather boots", "swift boots", "winged boots" };
    boots_speed = { 1, 2, 3 };
}

const vector<string>& Boots::GetBootsID() const {
    return boots_id;
}

const vector<int>& Boots::GetBootsSpeed() const {
    return boots_speed;
}
