#include <gtest/gtest.h>
#include <vector>
#include "cloth_deck.h"
#include "doors_deck.h"
#include "your_carts.h"

TEST(DeckTest, Size) {
    Deck deck;
    deck.initializeStandard(); 
    EXPECT_EQ(deck.size(), 30);
}

TEST(DeckTest, Shuffle) {
    Deck deckA, deckB;
    deckA.initializeStandard();
    deckB.initializeStandard();

    deckA.shuffle(12345);
    deckB.shuffle(12345);

    EXPECT_EQ(deckA.getOrder(), deckB.getOrder());
}

TEST(DeckTest, Giving) {
    Deck deck;
    Player player;
    deck.initializeStandard();
    deck.shuffle(42);

    deck.dealInitialHand(player, 5);

    EXPECT_EQ(player.handSize(), 5);
    EXPECT_EQ(deck.size(), 30 - 5);
}

TEST(DeckTest, Total) {
    Deck deck;
    DiscardPile discard;
    Player player;

    deck.initializeStandard();        
    deck.shuffle(99);

    deck.dealInitialHand(player, 5);
    EXPECT_EQ(player.handSize(), 5);
    EXPECT_EQ(deck.size(), 25);

    std::vector<Card> temp;
    for (int i = 0; i < 4; ++i) {
        Card c = player.playCard(0);  
        temp.push_back(c);
    }
    for (auto &c : temp) {
        discard.add(c);
    }
    EXPECT_EQ(discard.size(), 4);
    EXPECT_EQ(player.handSize(), 1);  

    int total = deck.size() + player.handSize() + discard.size();
    EXPECT_EQ(total, 30);
}
