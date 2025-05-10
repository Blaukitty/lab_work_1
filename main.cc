
#include "Clothes_deck.h"
#include "monsters_deck.h"

#include <numeric>
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

		Data = { 0, 0, 0, 0 };       //  инициализация
		Carts = { "", "", "", "" };
	}

	void showStatus(const race& ra, const cl_ass& as) { // показываем все данные об игроке
		cout << "\n--- Player Status (>.<)  ---\n";
		cout << " Race: " << ra.race_n << endl;
		cout << " Class: " << as.cl_ass_n << endl;
		cout << " Damage: " << damage << endl;
		cout << " Protection: " << protection << endl;
		cout << " Speed: " << speed << endl;
		cout << " Money: " << money << endl;
	}

	void carts_getting(const Cloth_deck& cl) {  // названия карт из шмоток
		auto temp = cl.GetYourCloth0();
		Carts[0] = temp[0];
		Carts[1] = temp[1];
	}

	void data_getting(const Cloth_deck& cl) {  // данные карт из одежды
		auto temp = cl.GetYourClothData();
		Data[0] = temp[0];
		Data[1] = temp[1];
	}

	//void carts_gettingD(const Doors_deck& dr) { // названия карт из дверей
	//	auto card1 = dr.drawAndRecycleCard();
		//auto card2 = dr.drawAndRecycleCard();

//		Carts[2] = card1.first;
//		Carts[3] = card2.first;

	//	Data[2] = (card1.second[1] > 0) ? card1.second[1] : card1.second[0];
		//Data[3] = (card2.second[1] > 0) ? card2.second[1] : card2.second[0];
	//}

//	void data_gettingD(const Doors_deck& dr) { // данные карт из дверей
//		auto temp = dr.drawAndRecycleCard();

	//	if (temp[0].size() == 1) {
	//		Data[2] = temp[0][0]; // обычная карта
	//	}
	//	else {
			// карта монстра: суммируем или как-то иначе обрабатываем
	//		Data[2] = temp[0][1]; // damage например
	//	}

	//	if (temp[1].size() == 1) {
	//		Data[3] = temp[1][0]; // обычная карта
	// 	}

	//	else {
	//		Data[3] = temp[1][1]; // damage
	//	}

	//}
			

	void showCarts() {
		cout << "\n--- Player Carts (^^) ---\n";
		cout << "Cloth Cards:\n";
		for (int i = 0; i < 2; i++) {
			cout << Carts[i] << " ... " << Data[i] << "\n";
		}
		cout << "Door Cards:\n";
		for (int i = 2; i < 4; i++) {
			cout << Carts[i] << " ... " << Data[i] << "\n";
		}
	}
};


class ai {
public:
	ai_learning brain;
	int ai_id;
	int cloth_goals_ai;
	int treasure_goals_ai;
	int damage_ai;
	int protection_ai;
	int speed_ai;
	int money_ai;
	string ai_rase;
	string ai_cl_ass;
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
		ai_rase = "";
		ai_cl_ass = "";
		Data_ai = { 0, 0, 0, 0 };
		Carts_ai = { "", "", "", "" };
	}

	void show_identity() const {
		cout << "\n--- AI Identity (=_=)  ---\n";
		cout << " Race: " << ai_rase << endl;
		cout << " Class: " << ai_cl_ass << endl;
	}

	void carts_getting_ai(const Cloth_deck& clo) {
		auto temp = clo.GetYourCloth0();
		Carts_ai[0] = temp[0];
		Carts_ai[1] = temp[1];
	}

	void data_getting_ai(const Cloth_deck& clo) {
		auto temp = clo.GetYourClothData();
		Data_ai[0] = temp[0];
		Data_ai[1] = temp[1];
	}
};

class race {
public:
	string race_n;

	void choosing_race(your_carts& cart) {
		cout << "Choose character!\n You can be a human, a dwarf or an elf.\n";
		cout << "By the way, there are some special goals of every race.\n You will have +2 damage as a human, +2 speed as an elf or +2 protection as a dwarf\n";
		cin >> race_n;
		if (race_n == "human") {
			cart.damage += 2;
		}
		else if (race_n == "elf") {
			cart.speed += 2;
		}
		else if (race_n == "dwarf") {
			cart.protection += 2;
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
			cartA.ai_rase = "human";
		}
		else if (rndi == 2) {
			cartA.speed_ai += 2;
			cartA.ai_rase = "elf";
		}
		else {
			cartA.protection_ai += 2;
			cartA.ai_rase = "dwarf";
		}
	}
};

class cl_ass {
public:
	string cl_ass_n;

	void choosing_class(your_carts& cart0) {
		cout << "Now it's time to choose your class!\n You can be a hunter, a traveler or a knight.\n";
		cout << "There are also some special goals of every class.\n You will have +2 damage as a hunter, +2 speed as a traveler or +2 protection as a knight\n";
		cin >> cl_ass_n;
		if (cl_ass_n == "hunter") {
			cart0.damage += 2;
		}
		else if (cl_ass_n == "traveler") {
			cart0.speed += 2;
		}
		else if (cl_ass_n == "knight") {
			cart0.protection += 2;
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
			cartB.ai_cl_ass = "hunter";
		}
		else if (rndiB == 2) {
			cartB.speed_ai += 2;
			cartB.ai_cl_ass = "traveler";
		}
		else {
			cartB.protection_ai += 2;
			cartB.ai_cl_ass = "knight";
		}
	}
};



class race {
public: //модификатор доступа (privatе по умолчанию)
	string race_n;
	string ai_rase;

	void choosing_race(your_carts& cart) {
		cout << "Choose character!\n You can be a human, a dwarf or an elf.\n";
		cout << "By the way, there are some special goals of every race.\n You will have +2 damege as a human, +2 speed as an elf or +2 protection as a dwarf";
		cin >> race_n;
		if (race_n == "human") {
			cart.damage += 2; // увеличиваем урон человека
		}
		else if (race_n == "elf") {
			cart.speed += 2; // увеличиваем скорость эльфа
		}
		else if (race_n == "dwarf") {
			cart.protection += 2; // увеличиваем защиту гнома
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
			cart0.damage += 2; // увеличиваем урон охотника
		}
		else if (cl_ass_n == "traveler") {
			cart0.speed += 2; // увеличиваем скорость путешественника
		}
		else if (cl_ass_n == "knight") {
			cart0.protection += 2; // увеличиваем защиту рыцаря
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



class level {  // класс уровень
public:
	int lev; // поле класса
	int lev_ai;

	level() {
		lev = 1;
		lev_ai = 1;
	}

	void level_counter(your_carts& cart1) {   //создаем функцию подсчета уровня для игрока
		if (lev >= 11) {
			cout << "\n! Wow, you have the max level now !\n";  // задали максимальный уровень
			return;
		}
		if (cart1.money == lev * 2) {
			lev += 1;
		}
	}

	void level_counter(ai& cart2) {   //создаем функцию подсчета уровня для игрока
		if (lev_ai >= 11) {
			cout << "\n! AI have the max level !\n";  // задали максимальный уровень для ии
			return;
		}
		if (cart2.money_ai == lev_ai * 2) {
			lev_ai += 1;
		}
	}

	void if_trasure() { // добавляем уровень если карта на руках из класса treasure

	}

	void showLevel() {
		cout << "\n--- Players Level (>^w^<)  ---\n";  // функция отображения уровня
		cout << " Your Level: " << lev << endl;
		for (int i = 0; i < lev; ++i) cout << " $ " << endl;

		cout << " AI Level: " << lev_ai << endl;
		for (int i = 0; i < lev_ai; ++i) cout << " * ";
	}

};

class Field {
	vector<string> monster_name;
	vector<int> speedM;
	vector<int> demegeM;
	vector<int> protectionM;
	vector<int> moneyM;

public:
	string Cart_enemy;
	vector<int> Data_enemy;

	void loadMonstersFromDeck(const Monsters& mons) {
		monster_name = mons.GetMonsterName();
		auto stats = mons.GetMonsterStatArrays(); // {speed, damage, protection, money}
		speedM = stats[0];
		demegeM = stats[0];
		protectionM = stats[0];
		moneyM = stats[0];
	}

	vector<int> GetStatByMonsterName(const string& name) const {
		for (size_t i = 0; i < monster_name.size(); ++i) {
			if (monster_name[i] == name) {
				return { speedM[i], demegeM[i], protectionM[i], moneyM[i] };
			}
		}
		return { 0, 0, 0, 0 }; // если монстр не найден
	}

	void show_enemy() {
		cout << "\n--- Your enemy (x . x) ---\n";
		cout << Cart_enemy << " ... ";
		for (int stat : Data_enemy) cout << stat << " ";
		cout << "\n";
	}

	bool isCurrentEnemyMonster() const {
		return Data_enemy[2] > 0 || Data_enemy[3] > 0;
	}

	int getEnemyDataSum() const {
		return accumulate(Data_enemy.begin(), Data_enemy.end(), 0);
	}

	string getEnemyName() const {
		return Cart_enemy;
	}
};

struct CardData {
	string name;
	int data;
};

class choose_cart_bottom{
private:
	string input;
	int input2;
	vector<CardData> selected_cards;
 
public:
	void choose_cart(const your_carts& crt) {
		cin >> input;

		if (input == "i want to choose cart") { // вводишь это и можно выбрать карту
			cout << "now, choose cart you want to use (2, 3)\n";
			cin >> input2;
			
			if (input2 == 2 || input2 == 3) {
				CardData card;
				card.name = crt.Carts[input2];
				card.data = crt.Data[input2];
				selected_cards.push_back(card);

				cout << "You choose cart: " << card.name
					<< " whith data: " << card.data << endl;
			}
			else {
				cout << "Incorrect cart index!\n";
			}
		}
	}

	const vector<CardData>& get_selected_cards() const {
		return selected_cards;
	}
};

struct aiCardData {
	string name2;
	int data2;
};

class ai_learning {
	vector<aiCardData> sel_ai_cards;
	int counter = 0; //условный счетчик

public:
	aiCardData selectBestCard() {   // выбирает свою сильнейшую карту
		auto it = max_element(
			sel_ai_cards.begin(),
			sel_ai_cards.end(),
			[](const aiCardData& a, const aiCardData& b) {
				return a.data2 < b.data2;
			}
		);
		return aiCardData{ it->name2, it->data2 };
	}

	aiCardData selectWorstCard() {  // выбирает свою слабейшую карту
		auto it = min_element(
			sel_ai_cards.begin(),
			sel_ai_cards.end(),
			[](const aiCardData& a, const aiCardData& b) {
				return a.data2 < b.data2;
			}
		);
		return aiCardData{ it->name2, it->data2 };
	}

	void respondToVictory(bool isMonsterCard, bool player2Won) {  // алгоритм подкидывания
		if (!isMonsterCard) return;

		if (player2Won && counter % 2 == 0) {
			aiCardData to_throw = selectWorstCard();
			cout << "Ai is making troubles to you: " << to_throw.name2
				<< " (value: " << to_throw.data2 << ")\n";
		}
		counter++;
	}

};

class couse_trubles_bottom {
private:
	string couse;
	int couse2;
	vector<CardData> playerCards;

public:
	void load_from_player(const your_carts& player) {
		playerCards.clear();
		for (int i = 0; i < 4; ++i) {
			playerCards.push_back(CardData{ player.Carts[i], player.Data[i] });
		}
	}

	CardData choose_cart() {
		cout << "Type 'ow, you want to couse some troubles... OK! I like it'\n";
		cin.ignore();
		getline(cin, couse);

		if (couse == "ow, you want to couse some troubles... OK! I like it") {
			cout << "Choose a card index (0-3): ";
			cin >> couse2;

			if (couse2 >= 0 && couse2 < 4) {
				cout << "You threw: " << playerCards[couse2].name << " (data: " << playerCards[couse2].data << ")\n";
				return playerCards[couse2];
			}
			else {
				cout << "Incorrect index. No card thrown.\n";
			}
		}
		else {
			cout << "Cancelled.\n";
		}
		return { "", -1 };
	}
};

struct FieldCardData {
	string name1;
	int data1;
};

class logic{ // собирательный класс для описания логики
	int yuor_turn;
	int ai_turn;
	bool flag = true;
	vector<FieldCardData> enemyCart;

	couse_trubles_bottom playerToss;

	bool playerHasThrown = false;
	bool aiHasThrown = false;


public:

	void study1(Field& fi, choose_cart_bottom& cho, ai_learning& ai1,
		your_carts& player, level& playerLevel, ai& bot,
		Doors_deck& deck2, bool& aiHasThrown) {

		cout << " --- It's your turn (@ _ @) --- \n";

		const auto& selected = cho.get_selected_cards();
		if (selected.empty()) {
			cout << "No card was selected by the player.\n";
			return;
		}

		int playerCardPower = selected.back().data;
		int enemyPower = fi.getEnemyDataSum();

		cout << "You chose: " << selected.back().name << " with power: " << playerCardPower << endl;
		cout << "Enemy: " << fi.getEnemyName() << " with total power: " << enemyPower << endl;

		bool enemyIsMonster = fi.isCurrentEnemyMonster();

		if (playerCardPower >= enemyPower) {
			cout << " **  \\ ( > w < ) You WIN this round ( > w < )/ ** \n";

			if (enemyIsMonster) {
				string enemyName = fi.getEnemyName();
				vector<int> stats = fi.GetStatByMonsterName(enemyName);
				int lootMoney = stats[3];

				if (lootMoney > 0) {
					player.money += lootMoney;
					cout << "You looted " << lootMoney << " coins from the monster!\n";
				}

				playerLevel.level_counter(player);
			}

			if (enemyIsMonster) {
				ai1.respondToVictory(true, true); // AI подбрасывает карту

				aiCardData extra = ai1.selectWorstCard();
				cout << "AI throws another card: " << extra.name2 << " with data: " << extra.data2 << endl;

				if (!aiHasThrown) {
					auto extraCard = deck2.drawAndRecycleCard();
					bot.Carts_ai[2] = extraCard.first;
					bot.Data_ai[2] = accumulate(extraCard.second.begin(), extraCard.second.end(), 0);
					aiHasThrown = true;
				}

				if (extra.data2 > 0) {
					int newPower = enemyPower + extra.data2;
					cout << "New combined enemy power: " << newPower << endl;

					if (playerCardPower >= newPower) {
						cout << "You defeat the new monster too! \n";
					}
					else {
						cout << "The second monster overpowers you... \n";
					}
				}
				else {
					cout << "The card was not a monster. You take damage!\n";
					playerCardPower = max(0, playerCardPower - 1);
					cout << "Your power is now reduced to: " << playerCardPower << endl;
					cout << "You still win the round, but your power is reduced for future turns.\n";
				}
			}
			else {
				cout << "This was not a monster. You take passive damage.\n";
				playerCardPower = max(0, playerCardPower - 1);
				cout << "Your power is now reduced to: " << playerCardPower << endl;
			}

		}
		else {
			cout << " ( x = x ) Enemy is stronger...( x = x ) \n";
		}
	}


	void study_ai_2(Field& fi, ai& bot, your_carts& player, couse_trubles_bottom& playerToss, level& playerLevel, Doors_deck& deck2) {
		cout << " --- It's AI turn (0 o 0) --- \n";

		int aiPower = bot.damage_ai;
		int enemyPower = fi.getEnemyDataSum();

		cout << "AI faces: " << fi.getEnemyName() << " with power: " << enemyPower << endl;
		cout << "AI base power: " << aiPower << endl;

		if (aiPower >= enemyPower) {
			cout << "AI wins this round.\n";

			string enemyName = fi.getEnemyName();
			vector<int> stats = fi.GetStatByMonsterName(enemyName);
			int lootMoney = stats[3];

			if (lootMoney > 0) {
				bot.money_ai += lootMoney;
				cout << "AI looted " << lootMoney << " coins!\n";
			}

			playerLevel.level_counter(bot); // <== УРОВЕНЬ ИИ

			// игрок может подкинуть карту
			playerToss.load_from_player(player);
			CardData extra = playerToss.choose_cart();
			
			if (!playerHasThrown && extra.data >= 0) {
				auto newCard = deck2.drawAndRecycleCard();
				player.Carts[2] = newCard.first;
				player.Data[2] = accumulate(newCard.second.begin(), newCard.second.end(), 0);
				playerHasThrown = true;
			}

			if (extra.data > 0) {
				int newTotal = enemyPower + extra.data;
				cout << "New total enemy power vs AI: " << newTotal << endl;

				if (aiPower >= newTotal) {
					cout << "AI still wins!\n";
				}
				else {
					cout << "AI loses to the reinforced enemy!\n";
					bot.damage_ai = max(0, bot.damage_ai - 1);
				}
			}
			else if (extra.data == 0) {
				cout << "Card had no effect.\n";
			}
			else {
				cout << "AI takes minor damage from card effect.\n";
				bot.damage_ai = max(0, bot.damage_ai - 1);
			}
		}
		else {
			cout << "AI is too weak. Loses this round.\n";
			bot.damage_ai = max(0, bot.damage_ai - 1);
		}
	}

	void end() {
		flag == false;
	}

	void decideTurn(ai& bot, const Field& field) {
		if (!field.isCurrentEnemyMonster()) {
			cout << "AI sees no monster. Turn skipped.\n";
			return;
		}

		string enemyName = field.getEnemyName();
		int total = field.getEnemyDataSum(); // теперь корректно считает все характеристики

		cout << "AI is thinking... his power: " << bot.damage_ai << "   vs   monster total stats: " << total << endl;

		if (bot.damage_ai >= total) {
			cout << "AI attacks and wins\n";
		}
		else {
			cout << "AI is weaker and loses\n";
			bot.damage_ai = max(0, bot.damage_ai - 1);
		}
	}

	void turns(your_carts& plr, ai& bot, Field& field,
		choose_cart_bottom& chooser, ai_learning& aiBrain,
		couse_trubles_bottom& playerToss, level& levelTracker, Doors_deck& deck2) {

		int turn = 0;
		while (flag) {
			cout << "\n===== Turn: " << (turn == 0 ? "Player" : "AI") << " =====\n";

			if (turn == 0) {
				cout << "Player's turn to attack!\n";
				if (plr.damage >= field.getEnemyDataSum()) {
					cout << "Player wins this round!\n";
					plr.money += field.Data_enemy[3];
					levelTracker.level_counter(plr);
				}
				else cout << "Player loses this round.\n";
			}
			else {
				cout << "AI's turn to attack!\n";
				if (bot.damage_ai >= field.getEnemyDataSum()) {
					cout << "AI wins this round!\n";
					bot.money_ai += field.Data_enemy[3];
					levelTracker.level_counter(bot);
				}
				else cout << "AI loses this round.\n";
			}

			if (levelTracker.lev >= 11) {
				cout << "🏆 Player wins the game!\n";
				break;
			}
			if (levelTracker.lev_ai >= 11) {
				cout << "💀 AI wins the game!\n";
				break;
			}

			turn = 1 - turn;
		}
	}
}; 





int main() {
	Poison_apple psn_apl;
	Acid acd;
	Treasure trsr;
	Monsters mnstr;
	Doors_deck deck2(psn_apl, acd, trsr, mnstr);

	Armor armr;
	Gloves glvs;
	Boots bts;
	Protection prtctn;
	Cloth_deck deck1(armr, glvs, bts, prtctn);
	deck1.random_carts();

	your_carts playerCart;
	race playerRace;
	cl_ass playerClass;
	level playerLevel;

	Field myField;
	myField.loadMonstersFromDeck(mnstr); // загрузка данных монстров

	ai bot;
	choose_cart_bottom chooser;
	ai_learning aiBrain;
	couse_trubles_bottom playerToss;

	logic game;

	playerRace.choosing_race(playerCart);
	playerClass.choosing_class(playerCart);
	playerLevel.level_counter(playerCart);

	auto playerDoors = deck2.drawInitialPlayerCards();
	playerCart.Carts[2] = playerDoors[0].first;
	playerCart.Carts[3] = playerDoors[1].first;
	playerCart.Data[2] = accumulate(playerDoors[0].second.begin(), playerDoors[0].second.end(), 0);
	playerCart.Data[3] = accumulate(playerDoors[1].second.begin(), playerDoors[1].second.end(), 0);

	playerCart.carts_getting(deck1);
	playerCart.data_getting(deck1);
	playerCart.damage += playerCart.Data[0];
	playerCart.protection += playerCart.Data[1];

	playerCart.showCarts();
	playerCart.showStatus(playerRace, playerClass);
	playerLevel.showLevel();

	race botRace;
	cl_ass botClass;

	botRace.choosing_race_ai(bot);
	botClass.choosing_class_ai(bot);

	bot.show_identity();

	auto enemyCard = deck2.drawAndRecycleCard();
	myField.Cart_enemy = enemyCard.first;
	myField.Data_enemy = enemyCard.second;

	myField.show_enemy();

	game.turns(playerCart, bot, myField, chooser, aiBrain, playerToss, playerLevel, deck2);

	return 0;
}
