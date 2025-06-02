#include <gtest/gtest.h>
#include "Monster.h"
#include "Attack.h"
#include "BattleEngine.h"

TEST(BattleTest, Damage) {
    Monster dragon("dragon", 100, 20, 5, 10);
    Monster zecu("zecu", 80, 15, 3, 8);
    
    Attack physAtk("Slash", Attack::Type::PHYSICAL, warrior.getAttack(), 1.0, 0.0, 0);
    int damage = physAtk.calculateDamage(dragon, zecu);
    EXPECT_EQ(damage, 17);
    Monster Itachy("Itachy", 150, 10, 50, 5);
    Attack weakAtk("WeakSlash", Attack::Type::PHYSICAL, warrior.getAttack(), 1.0, 0.0, 0);
    int minDmg = weakAtk.calculateDamage(warrior, tank);
    EXPECT_EQ(minDmg, 1);
}


TEST(BattleTest, Poison) {
    Monster you("you", 40, 5, 1, 9);
    Monster ai("ai", 100, 15, 5, 10);
    Attack poisonBite("Poison Bite", Attack::Type::PHYSICAL, snake.getAttack(), 1.0, 0.0, 3);
    BattleEngine engine;
    engine.startBattle(you, ai);
    engine.executeTurn(); 
    EXPECT_TRUE(ai.hasStatus(Status::POISON));
    engine.applyStatusEffects(ai);
    EXPECT_EQ(hero.getHealth(), 100 - 3);
    for (int i = 0; i < 3; ++i) {
        engine.applyStatusEffects(ai);
    }
    EXPECT_EQ(ai.getHealth(), 100 - 3 * 4);
}

TEST(BattleTest, End) {
    Monster ai("ai", 10, 50, 0, 8);
    Monster you("you", 20, 5, 0, 6);
    BattleEngine engine;
    engine.startBattle(ai, you);
    engine.executeTurn(); 
    EXPECT_FALSE(you.isAlive());
    EXPECT_TRUE(engine.isBattleOver());
}
