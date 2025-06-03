#include <gtest/gtest.h>
#include "monsters.h"       
#include "acid.h"           
#include "treasure.h"       
#include "poison_apple.h"  
#include "doors_deck.h"     
#include "cloth_deck.h"   
#include "boots.h"          
#include "armor.h"          
#include "gloves.h"         
#include "protection.h"    
#include "field.h"          

TEST(MonstersTest, Stats) { //проверка характеристик карты
    Monsters mons;
    ASSERT_TRUE(mons.IsMonster("Itachi"));
    auto stats = mons.GetStatByMonsterName("Itachi");
    ASSERT_EQ(stats.size(), 4u);
    EXPECT_EQ(stats[0], 6);
    EXPECT_EQ(stats[1], 6);
    EXPECT_EQ(stats[2], 5);
    EXPECT_EQ(stats[3], -1);
}

TEST(MonstersTest, NotFound) { //что будет если нет монстра
    Monsters mons;
    auto stats = mons.GetStatByMonsterName("NonExistentMonster");
    ASSERT_EQ(stats.size(), 4u);
    EXPECT_EQ(stats[0], -1);
    EXPECT_EQ(stats[1], -1);
    EXPECT_EQ(stats[2], -1);
    EXPECT_EQ(stats[3], -1);
}

TEST(AcidTest, ID_Levels) {
    Acid acid;
    const auto& ids = acid.GetAcidID();
    const auto& downs = acid.GetLvlDwn();
    ASSERT_EQ(ids.size(), 3u);
    EXPECT_EQ(ids[0], "metal acid");
    EXPECT_EQ(ids[1], "rat acid");
    EXPECT_EQ(ids[2], "your mother's food");
    ASSERT_EQ(downs.size(), 3u);
    EXPECT_EQ(downs[0], 1);
    EXPECT_EQ(downs[1], 2);
    EXPECT_EQ(downs[2], 3);
}

TEST(TreasureTest, Id_Levels) {
    Treasure tr;
    const auto& ids = tr.GetTreasureID();
    const auto& lups = tr.GetLwlUp();
    ASSERT_FALSE(ids.empty());
    ASSERT_EQ(ids.size(), lups.size());
    EXPECT_GT(ids.size(), 0u);
}


TEST(DoorsDeckTest, Sise) {
    Poison_apple apple;
    Acid acid;
    Treasure treasure;
    Monsters monsters;
    Doors_deck deck{apple, acid, treasure, monsters};
    EXPECT_EQ(deck.deckSize(), 2 + 3 + 3 + 12);
    auto initCards = deck.drawInitialPlayerCards();
    ASSERT_EQ(initCards.size(), 2u);
    EXPECT_EQ(deck.deckSize(), 20u);
}

TEST(DoorsDeckTest, Recycle) {
    Poison_apple apple;
    Acid acid;
    Treasure treasure;
    Monsters monsters;
    Doors_deck deck{apple, acid, treasure, monsters};
    size_t originalSize = deck.deckSize();
    auto card1 = deck.drawAndRecycleCard();
    EXPECT_EQ(deck.deckSize(), originalSize);
    auto card2 = deck.drawAndRecycleCard();
    EXPECT_EQ(deck.deckSize(), originalSize);
    EXPECT_FALSE(card1.first.empty());
    EXPECT_FALSE(card2.first.empty());
}

TEST(ClothDeckTest, NotEmpty) {
    Armor arm;
    Gloves glv;
    Boots bts;
    Protection prot;

    Cloth_deck cd{arm, glv, bts, prot};
    cd.random_carts();
    const auto& names = cd.GetYourCloth0();
    const auto& data = cd.GetYourClothData();
    ASSERT_EQ(names.size(), 2u);
    ASSERT_EQ(data.size(), 2u);
    EXPECT_FALSE(names[0].empty());
    EXPECT_FALSE(names[1].empty());
    EXPECT_GT(data[0], 0);
    EXPECT_GT(data[1], 0);
}

TEST(FieldTest, Enemy) {
    Field field;
    Monsters mons;
    field.loadMonstersFromDeck(mons);
    std::string expectedName = mons.GetMonsterName()[0];
    EXPECT_EQ(field.getEnemyName(), expectedName);
    auto stats = mons.GetStatByMonsterName(expectedName);
    EXPECT_EQ(field.getEnemyDataSum(), stats[0] + stats[1] + stats[2] + stats[3]);
    EXPECT_TRUE(field.isCurrentEnemyMonster());
}

TEST(FieldTest, SetEnemy) {
    Field field;
    std::string name = "TestEnemy";
    std::vector<int> stat = {1, 2, 3, 4};
    field.setEnemyCard(name, stat);
    EXPECT_EQ(field.getEnemyName(), "TestEnemy");
    EXPECT_TRUE(field.isCurrentEnemyMonster());
    EXPECT_EQ(field.getEnemyDataSum(), 1 + 2 + 3 + 4);
}
