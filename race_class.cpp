// race.cpp content

// race_class.cpp
#include "race_class.h"
#include "your_carts.h" 
using namespace std;

void race::choosing_race(your_carts& cart) {
    cout << "Choose character!\n You can be a human, a dwarf or an elf.\n";
    cout << "By the way, there are some special goals of every race.\n";
    cout << " You will have +2 damage as a human, +2 speed as an elf or +2 protection as a dwarf\n";
    cin >> race_n;

    if (race_n == "human") {
        cart.damage += 2;
    } else if (race_n == "elf") {
        cart.speed += 2;
    } else if (race_n == "dwarf") {
        cart.protection += 2;
    } else {
        cout << "Incorrect race selected!\n";
    }
}

void race::choosing_race_ai(ai& cartA) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 3);
    int rndi = dist(gen);

    if (rndi == 1) {
        cartA.damage_ai += 2;
        cartA.ai_rase = "human";
    } else if (rndi == 2) {
        cartA.speed_ai += 2;
        cartA.ai_rase = "elf";
    } else {
        cartA.protection_ai += 2;
        cartA.ai_rase = "dwarf";
    }
}

void cl_ass::choosing_class(your_carts& cart0) {
    cout << "Now it's time to choose your class!\n You can be a hunter, a traveler or a knight.\n";
    cout << "There are also some special goals of every class.\n";
    cout << " You will have +2 damage as a hunter, +2 speed as a traveler or +2 protection as a knight\n";
    cin >> cl_ass_n;

    if (cl_ass_n == "hunter") {
        cart0.damage += 2;
    } else if (cl_ass_n == "traveler") {
        cart0.speed += 2;
    } else if (cl_ass_n == "knight") {
        cart0.protection += 2;
    } else {
        cout << "Incorrect class selected!\n";
    }
}

void cl_ass::choosing_class_ai(ai& cartB) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 3);
    int rndiB = dist(gen);

    if (rndiB == 1) {
        cartB.damage_ai += 2;
        cartB.ai_cl_ass = "hunter";
    } else if (rndiB == 2) {
        cartB.speed_ai += 2;
        cartB.ai_cl_ass = "traveler";
    } else {
        cartB.protection_ai += 2;
        cartB.ai_cl_ass = "knight";
    }
}
