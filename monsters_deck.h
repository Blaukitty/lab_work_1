
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
private:
    deque<pair<string, vector<int>>> deck;

public:
    Doors_deck(const Poison_apple& p_a, const Acid& ac, const Treasure& t, const Monsters& m) {
        auto apples = p_a.GetAppleID();
        auto acids = ac.GetAcidID();
        auto treasures = t.GetTreasureID();
        auto monsters = m.GetMonsterName();

        auto appleGoals = p_a.GetAppleGoals();
        auto acidLevels = ac.GetLvlDwn();
        auto treasureLevels = t.GetLwlUp();
        auto monsterStats = m.GetMonsterStatArrays();

        for (size_t i = 0; i < apples.size(); ++i)
            deck.push_back({ apples[i], {appleGoals[i], 0, 0, 0} });

        for (size_t i = 0; i < acids.size(); ++i)
            deck.push_back({ acids[i], {acidLevels[i], 0, 0, 0} });

        for (size_t i = 0; i < treasures.size(); ++i)
            deck.push_back({ treasures[i], {treasureLevels[i], 0, 0, 0} });
            
        for (size_t i = 0; i < monsters.size(); ++i)
            deck.push_back({
                monsters[i],
                {
                    monsterStats[0][i],
                    monsterStats[1][i],
                    monsterStats[2][i],
                    monsterStats[3][i]
                }
                });

        shuffleDeck();
    }

    void shuffleDeck() {
        vector<pair<string, vector<int>>> temp(deck.begin(), deck.end());
        auto rng = default_random_engine(random_device{}());
        shuffle(temp.begin(), temp.end(), rng);
        deck = deque<pair<string, vector<int>>>(temp.begin(), temp.end());
    }

    pair<string, vector<int>> drawAndRecycleCard() {
        if (deck.empty()) {
            cerr << "Deck is empty!\n";
            return { "", {} };
        }
        auto card = deck.front();
        deck.pop_front();
        deck.push_back(card);
        return card;
    }

    vector<pair<string, vector<int>>> drawInitialPlayerCards(int count = 2) {
        vector<pair<string, vector<int>>> cards;
        for (int i = 0; i < count; ++i)
            cards.push_back(drawAndRecycleCard());
        return cards;
    }

    size_t deckSize() const {
        return deck.size();
    }
};



