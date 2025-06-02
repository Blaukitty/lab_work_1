#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <random>
#include <array>

using namespace std;

class Armor {
private:
	vector<int> armor_goals;
	//int armor_id;
	vector<string> armor_name;
	//char bow;

	void damage_boost() {
		for (int i = 1; i != 6; i++) {
			armor_goals.push_back(i);

			if (i == 1) {
				armor_name.push_back("Sword of Honor");
			}
			else if (i == 2) {
				armor_name.push_back("Funny sword");
			}
			else if (i == 3) {
				armor_name.push_back("Elf bow");
			}
			else if (i == 4) {
				armor_name.push_back("Bow of the King");
			}
			else {
				armor_name.push_back("Athur sword");
			}
		}
	}
public:
	Armor() {
		damage_boost();
	}

	const vector<int>& GetArmorGoals() const {
		return armor_goals;
	}
	const vector<string>& GetArmorName() const {
		return armor_name;
	}
};

class Gloves {
private:
	vector<string> gloves_id;
	vector<int> gloves_goals;

	void money_boost() {
		for (int j = 0; j != 3; j++) {
			gloves_goals.push_back(j);

			if (j == 0) {
				gloves_id.push_back("Looser gloves");
			}
			else if (j == 1) {
				gloves_id.push_back("Gloves of worker");
			}
			else {
				gloves_id.push_back("Looser gloves");
			}
		}
	}

public:
	Gloves() {
		money_boost();
	}

	const vector<int>& GetGlovesGoals() const {
		return gloves_goals;
	}
	const vector<string>& GetGlovesID() const {
		return gloves_id;
	}
};

class Protection {
private:
	vector<string> protection_id;
	vector<int> protection_lvl;

	void protection_goals() {
		for (int k = 1; k != 6; k++) {
			protection_lvl.push_back(k);

			if (k == 1) {
				protection_id.push_back("iron protection");
			}
			else if (k == 2) {
				protection_id.push_back("silver protection");
			}
			else if (k == 3) {
				protection_id.push_back("golden protection");
			}
			else if (k == 4) {
				protection_id.push_back("dimond protection");
			}
			else {
				protection_id.push_back("magik protection");
			}
		}
	}

public:
	Protection() {
		protection_goals();
	}
	const vector<int>& GetProtectionGoals() const {
		return protection_lvl;
	}
	const vector<string>& GetProtectionID() const {
		return protection_id;
	}
};

class Boots {
private:
	vector<string> boots_id;
	vector<int> boots_goals;

	void fast_boost() {
		for (int f = 1; f != 6; f++) {
			boots_goals.push_back(f);

			if (f == 1) {
				boots_id.push_back("Demix shoeue");
			}
			else if (f == 2) {
				boots_id.push_back("Adidas neo");
			}
			else if (f == 3) {
				boots_id.push_back("Nike pro");
			}
			else if (f == 4) {
				boots_id.push_back("Miu miu mule");
			}
			else {
				boots_id.push_back("Versache bratz heels");
			}
		}

	}

public:
	Boots() {
		fast_boost();
	}

	const vector<int>& GetFastBoost() const {
		return boots_goals;
	}
	const vector<string>& GetBootsID() const {
		return boots_id;
	}
};

class Cloth_deck { // ìàññèâû ñ ìàññèâàìè âíóòðè. Èíäåêñàöèÿ èäåíòè÷íà
public:
	vector<string> cloth; // íàçâàíèÿ îäåæäû
	vector<int> charact;  //õàðàêòåðèñòèêè îäåæäû
	array<string, 2> YourCloth0; //ïî óìîë÷àíèþ, âûäàþòñÿ èãðîêó â íà÷àëå
	array<int, 2> YourClothData;

	Cloth_deck(const Armor& a, const Gloves& g, const Boots& b, const Protection& p) {
		cloth.insert(cloth.end(), a.GetArmorName().begin(), a.GetArmorName().end());
		cloth.insert(cloth.end(), g.GetGlovesID().begin(), g.GetGlovesID().end());
		cloth.insert(cloth.end(), b.GetBootsID().begin(), b.GetBootsID().end());
		cloth.insert(cloth.end(), p.GetProtectionID().begin(), p.GetProtectionID().end());
		charact.insert(charact.end(), a.GetArmorGoals().begin(), a.GetArmorGoals().end());
		charact.insert(charact.end(), g.GetGlovesGoals().begin(), g.GetGlovesGoals().end());
		charact.insert(charact.end(), b.GetFastBoost().begin(), b.GetFastBoost().end());
		charact.insert(charact.end(), p.GetProtectionGoals().begin(), p.GetProtectionGoals().end());
	};

	void random_carts() {
		if (cloth.size() < 2 || charact.size() < 2 || cloth.size() != charact.size()) return;

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(0, static_cast<int>(cloth.size()) - 1);

		for (int i = 0; i < 2; ++i) {
			int rndi = dist(gen);
			YourCloth0[i] = cloth[rndi];
			YourClothData[i] = charact[rndi];
		}
	}


	const array<string, 2>& GetYourCloth0() const {
		return YourCloth0;
	}

	const array<int, 2>& GetYourClothData() const {
		return YourClothData;
	}

};
