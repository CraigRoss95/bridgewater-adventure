#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "CombatUnit.hpp"
#include "Enemy.hpp"
#include "Item.hpp"
#include "Move.hpp"

#include <list>

class Item;


class Player : public CombatUnit
{
public:
	Player(int maxHP, int maxDEF, int ATK, std::string name, int maxAP);
	int GetMaxAP();
	int GetCurrAP();
	void UseAP(int ap);
	void AddItem(Item* newItem);
	void Heal(int healed);
	bool UseItem(std::string itemName);
	bool LookItem(std::string itemName);
	void PrintInventory();
	std::list<Item*> RemoveItem(Item* item);
	void SetAP(int ap);
	void APHeal(int healed);
	void ShowStatsQuick();
	void ShowStatsFull();
	void SetMaxAP(int ap);
	void Learn(Move* move);
	bool UseMove(std::string moveName, std::list<Enemy*> enemyList);
	bool Cast(Move* move, std::list<Enemy*> enemyList);
	Enemy* PickEnemy(std::list<Enemy*> enemyList);
	void PrinSpecials();
	void AOE(std::list<Enemy*> enemyList, int damage);
	


private:
	int currAP;
	int maxAP;
	Enemy* target = nullptr;
	std::list<Item*> inventory;
	std::list<Move*> knownMoves;
};

#endif