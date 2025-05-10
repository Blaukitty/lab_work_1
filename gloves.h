// gloves.h content

// gloves_module.h
#pragma once
#include <string>
#include <vector>

using namespace std;

class Gloves {
private:
    vector<string> gloves_id;
    vector<int> gloves_damage;

    void setup_gloves();

public:
    Gloves();
    const vector<string>& GetGlovesID() const;
    const vector<int>& GetGlovesDamage() const;
};

