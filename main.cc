
#include "Header3.h"
#include "Header1.h"

#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

class your_carts {
public:
	int player_id;
	int cloth_goals;
	int treasure_goals;
	int damage;
	int protection;
	int speed;
	int money;
	array<string, 4> Carts;
	array<int, 4> Data;

	your_carts() {
		player_id = 0;
		cloth_goals = 0;
		treasure_goals = 0;
		damage = 1;
		protection = 1;
		speed = 1;
		money = 0;

		Data = { 0, 0, 0, 0 };       //  èíèöèàëèçàöèÿ
		Carts = { "", "", "", "" };
	}

	void showStatus(const race& ra, const cl_ass& as) { // ïîêàçûâàåì âñå äàííûå îá èãðîêå
		cout << "\n--- Player Status (>.<)  ---\n";
		cout << " Race: " << ra.race_n << endl;
		cout << " Class: " << as.cl_ass_n << endl;
		cout << " Damage: " << damage << endl;
		cout << " Protection: " << protection << endl;
		cout << " Speed: " << speed << endl;
		cout << " Money: " << money << endl;
	}


	void carts_getting(const Cloth_deck& cl) {  // íàçâàíèÿ êàðò èç øìîòîê
		auto temp = cl.GetYourCloth0();
		Carts[0] = temp[0];
		Carts[1] = temp[1];
	}

	void carts_gettingD(const Doors_deck& dr) { // íàçâàíèÿ êàðò èç äâåðåé
		auto temp = dr.GetYourDoors0();
		Carts[2] = temp[0];
		Carts[3] = temp[1];
	}

	void data_getting(const Cloth_deck& cl) {  // äàííûå êàðò èç îäåæäû
		auto temp = cl.GetYourClothData();
		Data[0] = temp[0];
		Data[1] = temp[1];
	}

	void data_gettingD(const Doors_deck& dr) { // äàííûå êàðò èç äâåðåé
		auto temp = dr.GetYourDoorsData();

		if (temp[0].size() == 1) {
			Data[2] = temp[0][0]; // îáû÷íàÿ êàðòà
		}
		else {
			// êàðòà ìîíñòðà: ñóììèðóåì èëè êàê-òî èíà÷å îáðàáàòûâàåì
			Data[2] = temp[0][1]; // damage íàïðèìåð
		}

		if (temp[1].size() == 1) {
			Data[3] = temp[1][0]; // îáû÷íàÿ êàðòà
		}
		else {
			Data[3] = temp[1][1]; // damage
		}

	}


	void showCarts(const Doors_deck& d) {
		cout << "\n--- Player Carts (^^) ---\n";

		// Îäåæäà
		cout << " Cloth Carts :\n";
		for (int i = 0; i < 2; i++) {
			cout << Carts[i] << " ... " << Data[i] << "\n";
		}

		// Äâåðè
		auto data = d.GetYourDoorsData();
		cout << " Doors Carts :\n";
		for (int g = 0; g < 2; g++) {
			cout << Carts[g + 2] << " ... ";
			for (int j = 0; j < data[g].size(); ++j) {
				cout << data[g][j] << " ";
			}
			cout << "\n";
		}
	}
};

class ai {
public:
	int ai_id;
	int cloth_goals_ai;
	int treasure_goals_ai;
	int damage_ai;
	int protection_ai;
	int speed_ai;
	int money_ai;
	array<string, 4> Carts_ai;
	array<int, 4> Data_ai;

	ai() {
		ai_id = 0;
		cloth_goals_ai = 0;
		treasure_goals_ai = 0;
		damage_ai = 1;
		protection_ai = 1;
		speed_ai = 1;
		money_ai = 0;

		Data_ai = { 0, 0, 0, 0 };       //  èíèöèàëèçàöèÿ
		Carts_ai = { "", "", "", "" };
	}

	void show_identity(const race& rai, const cl_ass& ass) {
		cout << "\n--- AI Identity (=_=)  ---\n";
		cout << " Race: " << rai.ai_rase << endl;
		cout << " Class: " << ass.ai_cl_ass << endl;
	};

	void carts_getting_ai(const Cloth_deck& clo) {  // íàçâàíèÿ êàðò èç øìîòîê
		auto temp = clo.GetYourCloth0();
		Carts_ai[0] = temp[0];
		Carts_ai[1] = temp[1];
	}

	void carts_gettingD_ai(const Doors_deck& drs) { // íàçâàíèÿ êàðò èç äâåðåé
		auto temp = drs.GetYourDoors0();
		Carts_ai[2] = temp[0];
		Carts_ai[3] = temp[1];
	}

	void data_getting_ai(const Cloth_deck& clo) {  // äàííûå êàðò èç îäåæäû
		auto temp = clo.GetYourClothData();
		Data_ai[0] = temp[0];
		Data_ai[1] = temp[1];
	}

	void data_gettingD_ai(const Doors_deck& drs) { // äàííûå êàðò èç äâåðåé
		auto temp = drs.GetYourDoorsData();

		if (temp[0].size() == 1) {
			Data_ai[2] = temp[0][0]; // îáû÷íàÿ êàðòà
		}
		else {
			// êàðòà ìîíñòðà: ñóììèðóåì èëè êàê-òî èíà÷å îáðàáàòûâàåì
			Data_ai[2] = temp[0][1]; // damage íàïðèìåð
		}

		if (temp[1].size() == 1) {
			Data_ai[3] = temp[1][0]; // îáû÷íàÿ êàðòà
		}
		else {
			Data_ai[3] = temp[1][1]; // damage
		}

	}
};


class race {
public: //ìîäèôèêàòîð äîñòóïà (privatå ïî óìîë÷àíèþ)
	string race_n;
	string ai_rase;

	void choosing_race(your_carts& cart) {
		cout << "Choose character!\n You can be a human, a dwarf or an elf.\n";
		cout << "By the way, there are some special goals of every race.\n You will have +2 damege as a human, +2 speed as an elf or +2 protection as a dwarf";
		cin >> race_n;
		if (race_n == "human") {
			cart.damage += 2; // óâåëè÷èâàåì óðîí ÷åëîâåêà
		}
		else if (race_n == "elf") {
			cart.speed += 2; // óâåëè÷èâàåì ñêîðîñòü ýëüôà
		}
		else if (race_n == "dwarf") {
			cart.protection += 2; // óâåëè÷èâàåì çàùèòó ãíîìà
		}
		else {
			cout << "Incorrect race selected!\n";
		}
	}

	void choosing_race_ai(ai& cartA) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 3);
		int rndi = dist(gen);

		if (rndi == 1) {
			cartA.damage_ai += 2;
			ai_rase = "human";
		}
		else if (rndi == 2) {
			cartA.speed_ai += 2;
			ai_rase = "elf";
		}
		else {
			cartA.protection_ai += 2;
			ai_rase = "dwarf";
		}
	}

};

class cl_ass {
public:
	string cl_ass_n;
	string ai_cl_ass;

	void choosing_class(your_carts& cart0) {
		cout << "Now it's time to choose your class!\n You can be a hunter, a traveler or a knight.\n";
		cout << "There are also some special goals of every class.\n You will have +2 damege as a hunter, +2 speed as a traveler or +2 protection as a knight";
		cin >> cl_ass_n;
		if (cl_ass_n == "hunter") {
			cart0.damage += 2; // óâåëè÷èâàåì óðîí îõîòíèêà
		}
		else if (cl_ass_n == "traveler") {
			cart0.speed += 2; // óâåëè÷èâàåì ñêîðîñòü ïóòåøåñòâåííèêà
		}
		else if (cl_ass_n == "knight") {
			cart0.protection += 2; // óâåëè÷èâàåì çàùèòó ðûöàðÿ
		}
		else {
			cout << "Incorrect class selected!\n";
		}
	}

	void choosing_class_ai(ai& cartB) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 3);
		int rndiB = dist(gen);

		if (rndiB == 1) {
			cartB.damage_ai += 2;
			ai_cl_ass = "hunter";
		}
		else if (rndiB == 2) {
			cartB.speed_ai += 2;
			ai_cl_ass = "traveler";
		}
		else {
			cartB.protection_ai += 2;
			ai_cl_ass = "knight";
		}
	}

};



class level {  // êëàññ óðîâåíü
public:
	int lev; // ïîëå êëàññà
	int lev_ai;

	level() {
		lev = 1;
		lev_ai = 1;
	}

	void level_counter(your_carts& cart1) {   //ñîçäàåì ôóíêöèþ ïîäñ÷åòà óðîâíÿ äëÿ èãðîêà
		if (lev >= 11) {
			cout << "\n! Wow, you have the max level now !\n";  // çàäàëè ìàêñèìàëüíûé óðîâåíü
			return;
		}
		if (cart1.money == lev * 2) {
			lev += 1;
		}
	}

	void level_counter(ai& cart2) {   //ñîçäàåì ôóíêöèþ ïîäñ÷åòà óðîâíÿ äëÿ èãðîêà
		if (lev_ai >= 11) {
			cout << "\n! AI have the max level !\n";  // çàäàëè ìàêñèìàëüíûé óðîâåíü äëÿ èè
			return;
		}
		if (cart2.money_ai == lev_ai * 2) {
			lev_ai += 1;
		}
	}

	void if_trasure() { // äîáàâëÿåì óðîâåíü åñëè êàðòà íà ðóêàõ èç êëàññà treasure

	}

	void showLevel() {
		cout << "\n--- Players Level (>^w^<)  ---\n";  // ôóíêöèÿ îòîáðàæåíèÿ óðîâíÿ
		cout << " Your Level: " << lev << endl;
		for (int i = 0; i < lev; ++i) cout << " $ " << endl;

		cout << " AI Level: " << lev_ai << endl;
		for (int i = 0; i < lev_ai; ++i) cout << " * ";
	}

};


int main() {
	Poison_apple psn_apl;
	Acid acd;
	Treasure trsr;
	Monsters mnstr;
	Doors_deck deck2(psn_apl, acd, trsr, mnstr);
	deck2.random_cartsD(mnstr);

	Armor armr;  // from clothes deck
	Gloves glvs;
	Boots bts;
	Protection prtctn;
	Cloth_deck deck1(armr, glvs, bts, prtctn);
	deck1.random_carts();

	your_carts playerCart;  // for player
	race playerRace;
	cl_ass playerClass;
	level playerLevel;

	ai aiCart;

	playerRace.choosing_race(playerCart);
	playerClass.choosing_class(playerCart);
	playerLevel.level_counter(playerCart);
	playerCart.carts_getting(deck1);
	playerCart.carts_gettingD(deck2);
	playerCart.data_getting(deck1);
	playerCart.data_gettingD(deck2);
	playerCart.showCarts(deck2);
	playerCart.showStatus(playerRace, playerClass);
	playerLevel.showLevel();

	playerRace.choosing_race_ai(aiCart);
	playerClass.choosing_class_ai(aiCart);
	playerLevel.level_counter(aiCart);
	aiCart.carts_getting_ai(deck1);
	aiCart.carts_gettingD_ai(deck2);
	aiCart.data_getting_ai(deck1);
	aiCart.data_gettingD_ai(deck2);
	aiCart.show_identity(playerRace, playerClass);

	return 0;
}
