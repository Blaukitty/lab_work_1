//Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#include <iostream>
#include <numeric>
#include "your_carts.h"
#include "ai.h"
#include "race_class.h"
#include "field.h"
#include "level.h"
#include "logic.h"
#include "choose_cart_bottom.h"
#include "couse_troubles_bottom.h"
#include "doors_deck.h"
#include "cloth_deck.h"
#include "armor.h"
#include "gloves.h"
#include "boots.h"
#include "protection.h"

int main() {
    // 1. Инициализация объектов для колоды дверей
    Poison_apple poisonApple;
    Acid acid;
    Treasure treasure;
    Monsters monsters;
    Doors_deck doorsDeck(poisonApple, acid, treasure, monsters);

    // 2. Инициализация объектов для колоды одежды
    Armor armor;
    Gloves gloves;
    Boots boots;
    Protection protection;
    Cloth_deck clothDeck(armor, gloves, boots, protection);
    clothDeck.random_carts();

    // 3. Игрок
    your_carts playerCart;
    race playerRace;
    cl_ass playerClass;
    Level playerLevel;

    // 4. AI (бот)
    ai bot;
    race botRace;
    cl_ass botClass;

    // 5. Прочие объекты для игры
    Field myField;
    myField.loadMonstersFromDeck(monsters);

    choose_cart_bottom chooser;
    ai_learning aiBrain;
    couse_troubles_bottom troubles; 
    Logic gameLogic;

    // 6. Выбор расы и класса игроком
    playerRace.choosing_race(playerCart);
    playerClass.choosing_class(playerCart);

    // 7. Раздача стартовых карт игроку
    auto playerDoors = doorsDeck.drawInitialPlayerCards();
    playerCart.Carts[2] = playerDoors[0].first;
    playerCart.Carts[3] = playerDoors[1].first;
    playerCart.Data[2] = std::accumulate(playerDoors[0].second.begin(), playerDoors[0].second.end(), 0);
    playerCart.Data[3] = std::accumulate(playerDoors[1].second.begin(), playerDoors[1].second.end(), 0);

    playerCart.carts_getting(clothDeck);
    playerCart.data_getting(clothDeck);
    playerCart.damage += playerCart.Data[0];
    playerCart.protection += playerCart.Data[1];

    playerCart.showCarts();
    playerCart.showStatus(playerRace, playerClass);
    playerLevel.showLevel();

    // 8. AI выбор расы и класса
    botRace.choosing_race_ai(bot);
    botClass.choosing_class_ai(bot);

    bot.show_identity();
    bot.carts_getting_ai(clothDeck);
    bot.data_getting_ai(clothDeck);
    bot.damage_ai += bot.Data_ai[0];
    bot.protection_ai += bot.Data_ai[1];

    // 9. Выставление врага на поле (используем метод setEnemyCard вместо прямого доступа)
    auto enemyCard = doorsDeck.drawAndRecycleCard();
    myField.setEnemyCard(enemyCard.first, enemyCard.second);
    myField.show_enemy();
    
    // 10. Основной игровой цикл
    gameLogic.turns(playerCart, bot, myField, chooser, troubles, playerLevel, doorsDeck);

    return 0;
}
