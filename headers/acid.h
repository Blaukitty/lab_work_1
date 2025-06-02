// acid.h content

// acid_module.h
#pragma once
#include <string>
#include <vector>

class Acid {
private:
    std::vector<std::string> acid_id;
    std::vector<int> lvl_dwn;

    void level_down();

public:
    Acid();
    const std::vector<std::string>& GetAcidID() const;
    const std::vector<int>& GetLvlDwn() const;
};
