/*Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru*/
#ifndef ACID_H
#define ACID_H

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

#endif
