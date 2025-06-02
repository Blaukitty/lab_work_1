#include <gtest/gtest.h>
#include "Monster.h"
#include "Attack.h"
#include "BattleEngine.h"

TEST(BattleTest, PhysicalDamageCalculation) {
    Monster warrior("Warrior", 100, 20, 5, 10);
    Monster orc("Orc", 80, 15, 3, 8);
    Attack physAtk("Slash", Attack::Type::PHYSICAL, warrior.getAttack(), 1.0, 0.0, 0);
    int damage = physAtk.calculateDamage(warrior, orc);
    EXPECT_EQ(damage, 17);
    Monster tank("Tank", 150, 10, 50, 5);
    Attack weakAtk("WeakSlash", Attack::Type::PHYSICAL, warrior.getAttack(), 1.0, 0.0, 0);
    int minDmg = weakAtk.calculateDamage(warrior, tank);
    EXPECT_EQ(minDmg, 1);
}

TEST(BattleTest, CriticalHit) {
    Monster rogue("Rogue", 50, 10, 2, 12);
    Monster troll("Troll", 60, 12, 4, 7);
    Attack critAtk("Backstab", Attack::Type::PHYSICAL, rogue.getAttack(), 1.5, 1.0, 0);
    int damage = critAtk.calculateDamage(rogue, troll);
    EXPECT_EQ(damage, 26);
}

TEST(BattleTest, PoisonEffectOverTurns) {
    Monster snake("Snake", 40, 5, 1, 9);
    Monster hero("Hero", 100, 15, 5, 10);
    Attack poisonBite("Poison Bite", Attack::Type::PHYSICAL, snake.getAttack(), 1.0, 0.0, 3);
    BattleEngine engine;
    engine.startBattle(snake, hero);
    engine.executeTurn(); 
    EXPECT_TRUE(hero.hasStatus(Status::POISON));
    engine.applyStatusEffects(hero);
    EXPECT_EQ(hero.getHealth(), 100 - 3);
    for (int i = 0; i < 3; ++i) {
        engine.applyStatusEffects(hero);
    }
    EXPECT_EQ(hero.getHealth(), 100 - 3 * 4);
}

TEST(BattleTest, BattleEndsWhenHpZero) {
    Monster strong("Strong", 10, 50, 0, 8);
    Monster weak("Weak", 20, 5, 0, 6);
    BattleEngine engine;
    engine.startBattle(strong, weak);
    engine.executeTurn(); 
    EXPECT_FALSE(weak.isAlive());
    EXPECT_TRUE(engine.isBattleOver());
}
