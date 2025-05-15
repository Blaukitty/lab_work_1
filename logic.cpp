#include "logic.h"
#include <iostream>

using std::cout;
using std::endl;

void Logic::turns(your_carts& player,
                  ai&          bot,
                  Field&       field,
                  choose_cart_bottom&  chooser,
                  couse_troubles_bottom& troubles,
                  Level&       levelTracker,
                  Doors_deck&  doorsDeck)
{
    int turn = 0; // 0 — Player, 1 — AI

    while (flag)
    {
        cout << "\n===== Turn: " << (turn == 0 ? "Player" : "AI") << " =====" << endl;

        // 1) Тянем новую карту "двери"
        auto card = doorsDeck.drawAndRecycleCard();

        // 2) Если это событие (не-монстр) — мгновенный эффект и проверка победы
        if (card.second.size() < 4)
        {
            int effect = card.second[0];
            cout << "Event card: " << card.first
                 << " (effect: " << effect << ")" << endl;

            if (turn == 0)
            {
                levelTracker.gainLevel(player, effect);
                if (levelTracker.getPlayerLevel() >= 11)
                {
                    cout << "\nPlayer wins the game!" << endl;
                    return;
                }
            }
            else
            {
                levelTracker.gainLevel(bot, effect);
                if (levelTracker.getAILevel() >= 11)
                {
                    cout << "\nAI wins the game!" << endl;
                    return;
                }
            }

            // Смена хода и следующий раунд
            turn = 1 - turn;
            continue;
        }

        // 3) Это монстр: показываем поле
        field.setEnemyCard(card.first, card.second);
        field.show_enemy();

        // 4) Ход игрока
        if (turn == 0)
        {
            cout << "Player's turn to attack!" << endl;
            player.showCarts();

            chooser.choose_cart(player);
            auto selected = chooser.get_selected_cards();

            // Саботаж картами игрока
            if (!selected.empty())
            {
                field.setEnemyCard(selected[0].name, { selected[0].data });
                cout << "Player uses sabotage card: " << selected[0].name << endl;
            }

            // Бой
            if (player.damage >= field.getEnemyDataSum())
            {
                cout << "Player wins this fight!" << endl;
                player.money += field.getEnemyDataSum();
                levelTracker.level_counter(player);
                if (levelTracker.getPlayerLevel() >= 11)
                {
                    cout << "\nPlayer wins the game!" << endl;
                    return;
                }
            }
            else
            {
                cout << "Player loses this fight." << endl;
            }
        }
        // 5) Ход AI
        else
        {
            cout << "AI's turn to attack!" << endl;
            troubles.load_from_player(player);
            CardData usedCard = troubles.choose_cart();

            if (usedCard.data != -1)
            {
                field.setEnemyCard(usedCard.name, { usedCard.data });
                cout << "AI sabotages with: " << usedCard.name << endl;
            }

            if (bot.damage_ai >= field.getEnemyDataSum())
            {
                cout << "AI wins this fight!" << endl;
                bot.money_ai += field.getEnemyDataSum();
                levelTracker.level_counter(bot);
                if (levelTracker.getAILevel() >= 11)
                {
                    cout << "\nAI wins the game!" << endl;
                    return;
                }
            }
            else
            {
                cout << "AI loses this fight." << endl;
            }
        }

        // 6) Смена хода
        turn = 1 - turn;
    }
}

void Logic::end()
{
    flag = false;
}
