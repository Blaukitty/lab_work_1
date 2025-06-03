//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru

#ifndef PROTECTION_H
#define PROTECTION_H
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
#endif
