// logic.cpp content

// logic_module.cpp
#include "logic.h"

using namespace std;

void Logic::turns(your_carts& plr, ai& bot, Field& field,
                 choose_cart_bottom& chooser, couse_troubles_bottom& troubles,
                 Level& levelTracker, Doors_deck& deck2) {
    int turn = 0;

    while (flag) {
        cout << "\n===== Turn: " << (turn == 0 ? "Player" : "AI") << " =====\n";

        if (turn == 0) {
            cout << "Player's turn to attack!\n";
            if (plr.damage >= field.getEnemyDataSum()) {
                cout << "Player wins this round!\n";
                plr.money += field.getEnemyDataSum();
                levelTracker.level_counter(plr);
            } else {
                cout << "Player loses this round.\n";
            }
        } else {
            cout << "AI's turn to attack!\n";
            if (bot.damage_ai >= field.getEnemyDataSum()) {
                cout << "AI wins this round!\n";
                bot.money_ai += field.getEnemyDataSum();
                levelTracker.level_counter(bot);
            } else {
                cout << "AI loses this round.\n";
            }
        }

        if (levelTracker.getPlayerLevel() >= 11) {
            cout << "\n Player wins the game!\n";
            break;
        }
        if (levelTracker.getAILevel() >= 11) {
            cout << "\n AI wins the game!\n";
            break;
        }

        turn = 1 - turn; // Switch turns
    }
}

void Logic::end() {
    flag = false;
}
