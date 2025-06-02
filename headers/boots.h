// boots.h content

// boots_module.h
#pragma once
#include <string>
#include <vector>

using namespace std;

class Boots {
private:
    vector<string> boots_id;
    vector<int> boots_speed;

    void setup_boots();

public:
    Boots();
    const vector<string>& GetBootsID() const;
    const vector<int>& GetBootsSpeed() const;
};

