
#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <array>
#include <random>

using namespace std;

class Poison_apple {  //ready to use
private:
    vector<string> apple_id;
    vector<int>  apple_goals;
 
    void money_down() { 
        for (int g = 2; g != 5; g++) {
            apple_goals.push_back(g);

            if (g == 2) {
                apple_id.push_back("poison apple");
            }
            else if (g == 3) {
                apple_id.push_back("apple of dead");
            }
            else {
                apple_id.push_back("snow white apple");
            }
        }
    }

public:
    Poison_apple() {
        money_down();
    }

    const vector<string>& GetAppleID() const {
        return apple_id;
    }

    const vector<int>& GetAppleGoals() const {
        return apple_goals;
    }
};

class Acid {  //ready to use
private:
    vector<string> acid_id;
    vector<int> lvl_dwn;

    void level_down() {
        for (int n = 1; n != 4; n++) {
            lvl_dwn.push_back(n);

            if (n == 1) {
                acid_id.push_back("metal acid");
            }
            else if (n == 2) {
                acid_id.push_back("rat acid");
            }
            else {
                acid_id.push_back("your mather's food");
            }
        }
    };
public:
    Acid() {
        level_down();
    }

    const vector<string> GetAcidID() const {
        return acid_id;
    }
    const vector<int> GetLvlDwn() const {
        return lvl_dwn;
    }
};


class Treasure {  //ready to use
private:
    vector<string> treasure_id;
    vector<int> lvl_up;

    void level_boost() {
        for (int j = 1; j != 4; j++) {
            lvl_up.push_back(j);

            if (j == 1) {
                treasure_id.push_back("magic ring");
            }
            else if (j == 2) {
                treasure_id.push_back("blue diadem");
            }
            else {
                treasure_id.push_back("King's crown");
            }
        }

    }
public:
    Treasure() {
        level_boost();
    }

    const vector<string>& GetTreasureID() const{
        return treasure_id;
    }

    const vector<int> GetLwlUp() const{
        return lvl_up;
    }
};

class Monsters {
private:
    vector<string> monster_name;
    vector<int> speedM;
    vector<int> demegeM;
    vector<int> protectionM;
    vector<int> moneyM;

    void money_change() {
        for (int m = 0; m <= 11; m++) {
            if (m == 0) {
                monster_name.push_back("Fool monster");
                speedM.push_back(m);
                demegeM.push_back(m + 1);
                protectionM.push_back(m + 1);
                moneyM.push_back(m);
            }
            else if (m == 1) {
                monster_name.push_back("Mike Vazovsky");
                speedM.push_back(m + 1);
                demegeM.push_back(m + 2);
                protectionM.push_back(m);
                moneyM.push_back(m);
            }
            else if (m == 2) {
                monster_name.push_back("Garden dworf");
                speedM.push_back(m);
                demegeM.push_back(m + 2);
                protectionM.push_back(m + 1);
                moneyM.push_back(m + 1);
            }
            else if (m == 3) {
                monster_name.push_back("Slendermen");
                speedM.push_back(m + 1);
                demegeM.push_back(m + 3);
                protectionM.push_back(m - 1);
                moneyM.push_back(m);
            }
            else if (m == 4) {
                monster_name.push_back("Toby");
                speedM.push_back(m + 2);
                demegeM.push_back(m + 1);
                protectionM.push_back(m);
                moneyM.push_back(m + 1);
            }
            else if (m == 5) {
                monster_name.push_back("Kisame");
                speedM.push_back(m + 2);
                demegeM.push_back(m + 1);
                protectionM.push_back(m);
                moneyM.push_back(m - 3);
            }
            else if (m == 6) {
                monster_name.push_back("Kakuzu");
                speedM.push_back(m);
                demegeM.push_back(m + 2);
                protectionM.push_back(m + 2);
                moneyM.push_back(m + 1);
            }
            else if (m == 7) {
                monster_name.push_back("Sasory");
                speedM.push_back(m);
                demegeM.push_back(m + 1);
                protectionM.push_back(m);
                moneyM.push_back(m + 1);
            }
            else if (m == 8) {
                monster_name.push_back("Daidara");
                speedM.push_back(m);
                demegeM.push_back(m + 1);
                protectionM.push_back(m);
                moneyM.push_back(m - 4);
            }
            else if (m == 9) {
                monster_name.push_back("Pain");
                speedM.push_back(m + 3);
                demegeM.push_back(m + 1);
                protectionM.push_back(m - 2);
                moneyM.push_back(m);
            }
            else if (m == 10) {
                monster_name.push_back("Itachy");
                speedM.push_back(m + 5);
                demegeM.push_back(m + 5);
                protectionM.push_back(m + 5);
                moneyM.push_back(m - 1);
            }
            else {
                monster_name.push_back("Magick dragon");
                speedM.push_back(m + 3);
                demegeM.push_back(m + 1);
                protectionM.push_back(m + 2);
                moneyM.push_back(m - 2);
            }
        }
    }

public:
    Monsters() {
        money_change();
    }

    const vector<string>& GetMonsterName() const {
        return monster_name;
    }
    
    vector<vector<int>> GetMonsterStatArrays() const {   //òóïî âîçâðàùàåò äàííûå
        return { speedM, demegeM, protectionM, moneyM };
    }

    vector<int> GetStatByMonsterName(const string& name) const { // âîçâðàùàåò äàííûå êîíêðåòíîãî ìîíñòðà ïî èìåíè
        for (size_t i = 0; i < monster_name.size(); ++i) {
            if (monster_name[i] == name) {
                return { speedM[i], demegeM[i], protectionM[i], moneyM[i] };
            }
        }
        return { -1, -1, -1, -1 };
    }

    bool IsMonster(const string& name) const { // ïðîâåðêà íà ìîíñòðà, ÷òîáû ïîòîì áûëî ëåãêî äîáàâëÿòü â êîëîäó ñðàçó âñå äàííûûå î ìîíñòðå
        return find(monster_name.begin(), monster_name.end(), name) != monster_name.end();
    } 
};


class Doors_deck {
public:
    vector<string> doors; // íàçâàíèÿ äâåðåé  
    vector<int> charactD;  // õàðàêòåðèñòèêè äâåðåé
    vector<string> YourDoors0; //ïî óìîë÷àíèþ, âûäàþòñÿ èãðîêó â íà÷àëå
    vector<vector<int>> YourDoorsData;

    Doors_deck(const Poison_apple& p_a, const Acid& ac, const Treasure& t, const Monsters& m) {  //äîáàâëÿåì êàðòû â êîëîäó
        auto temp0 = p_a.GetAppleID();
        auto temp1 = ac.GetAcidID();
        auto temp2 = t.GetTreasureID();
        auto temp6 = m.GetMonsterName();

        auto temp3 = p_a.GetAppleGoals();
        auto temp4 = ac.GetLvlDwn();
        auto temp5 = t.GetLwlUp();
        auto temp7 = m.GetMonsterStatArrays();
        for (const auto& vec : temp7) {
            charactD.insert(charactD.end(), vec.begin(), vec.end());
        };

        doors.insert(doors.end(), temp0.begin(), temp0.end());
        doors.insert(doors.end(), temp1.begin(), temp1.end());
        doors.insert(doors.end(), temp2.begin(), temp2.end());
        doors.insert(doors.end(), temp6.begin(), temp6.end());
        
        charactD.insert(charactD.end(), temp3.begin(), temp3.end());
        charactD.insert(charactD.end(), temp4.begin(), temp4.end());
        charactD.insert(charactD.end(), temp5.begin(), temp5.end());
        //for (const auto& vec : temp7) {
        //charactD.insert(charactD.end(), temp7.begin(), temp7.end());
        //}

    }

    void random_cartsD(const Monsters& m1) {
        
        int j = 0;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, static_cast<int>(doors.size()) - 1);
        YourDoors0.resize(2);
        YourDoorsData.clear();

        auto monster_names = m1.GetMonsterName();
        auto stats = m1.GetMonsterStatArrays();

        while (j <= 1) {
            int rndi0 = dist(gen);
            YourDoors0[j] = doors[rndi0];

            auto it = find(monster_names.begin(), monster_names.end(), doors[rndi0]);

            if (it != monster_names.end()) {
                size_t index = distance(monster_names.begin(), it);
                if (index < stats[0].size()) {
                    YourDoorsData.push_back({
                        stats[0][index], // speed
                        stats[1][index], // damage
                        stats[2][index], // protection
                        stats[3][index]  // money
                        });
                }
            }
            else {
                // åñëè íå ìîíñòð, ïðîñòî ïîëîæèì îäíî ÷èñëî (íàïðèìåð, êàê damage)
                YourDoorsData.push_back({ charactD[rndi0], 0, 0, 0 });
            }

            j++;
        }
    }


    const vector<string>& GetYourDoors0() const {
        return YourDoors0;
    }

    const vector<vector<int>>& GetYourDoorsData() const {
        return YourDoorsData;
    }

};
