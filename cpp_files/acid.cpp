// Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru

#include "acid.h"

#include "acid.h"
#include <string>
#include <vector>

Acid::Acid() {
    level_down();
}

void Acid::level_down() {
    for (int n = 1; n != 4; ++n) {
        lvl_dwn.push_back(n);
        if (n == 1) {
            acid_id.push_back("metal acid");
        } else if (n == 2) {
            acid_id.push_back("rat acid");
        } else {
            acid_id.push_back("your mother's food");
        }
    }
}

const std::vector<std::string>& Acid::GetAcidID() const {
    return acid_id;
}

const std::vector<int>& Acid::GetLvlDwn() const {
    return lvl_dwn;
}

