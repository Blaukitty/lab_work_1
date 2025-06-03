// Rodionova Ksenia 24-Б81-мм st132496@student.spbu.ru
#include "race_class.h"
#include "your_carts.h" 

void race::choosing_race(your_carts& cart) {
    std::cout << "Choose character!\n You can be a human, a dwarf or an elf.\n";
    std::cout << "By the way, there are some special goals of every race.\n";
    std::cout << " You will have +2 damage as a human, +2 speed as an elf or +2 protection as a dwarf\n";
    std::cin >> race_n;

    if (race_n == "human") {
        cart.damage += 2;
    } else if (race_n == "elf") {
        cart.speed += 2;
    } else if (race_n == "dwarf") {
        cart.protection += 2;
    } else {
        std::cout << "Incorrect race selected!\n";
    }
}

void race::choosing_race_ai(ai& cartA) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 3);
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
    std::cout << "Now it's time to choose your class!\n You can be a hunter, a traveler or a knight.\n";
    std::cout << "There are also some special goals of every class.\n";
    std::cout << " You will have +2 damage as a hunter, +2 speed as a traveler or +2 protection as a knight\n";
    std::cin >> cl_ass_n;

    if (cl_ass_n == "hunter") {
        cart0.damage += 2;
    } else if (cl_ass_n == "traveler") {
        cart0.speed += 2;
    } else if (cl_ass_n == "knight") {
        cart0.protection += 2;
    } else {
        std::cout << "Incorrect class selected!\n";
    }
}

void cl_ass::choosing_class_ai(ai& cartB) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 3);
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
