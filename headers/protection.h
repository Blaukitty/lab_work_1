// protection.h content

// protection.h
#pragma once
#include <string>
#include <vector>

class Protection {
private:
    std::vector<std::string> protection_id;
    std::vector<int> protection_value;

    void setup_protection();

public:
    Protection();
    const std::vector<std::string>& GetProtectionID() const;
    const std::vector<int>& GetProtectionValue() const;
};
