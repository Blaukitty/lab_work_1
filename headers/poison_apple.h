// poison_apple.h content

// poison_apple_module.h
#pragma once
#include <string>
#include <vector>

class Poison_apple {
private:
    std::vector<std::string> apple_id;
    std::vector<int> apple_goals;

    void setup_apples();

public:
    Poison_apple();
    const std::vector<std::string>& GetAppleID() const;
    const std::vector<int>& GetAppleGoals() const;
};
