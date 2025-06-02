// treasure.h content

// treasure_module.h
#pragma once
#include <string>
#include <vector>

class Treasure {
private:
    std::vector<std::string> treasure_id;
    std::vector<int> level_up;

    void setup_treasures();

public:
    Treasure();
    const std::vector<std::string>& GetTreasureID() const;
    const std::vector<int>& GetLwlUp() const;
};
