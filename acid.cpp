// acid.cpp content

#include "acid.h"

using namespace std;

Acid::Acid() {
    level_down();
}

void Acid::level_down() {
    for (int n = 1; n != 4; n++) {
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

const vector<string>& Acid::GetAcidID() const {
    return acid_id;
}

const vector<int>& Acid::GetLvlDwn() const {
    return lvl_dwn;
}
