
#include<iostream>

#ifndef COMBATUNIT_HPP
#define COMBATUNIT_HPP
#include <string>


class CombatUnit
{
public:
	CombatUnit(int maxHP,int maxDEF, int ATK, std::string name);
	int GetMaxHP();
	void SetMaxHP(int set);
	int GetCurrHP();
	int GetMaxDEF();
	int GetCurrDEF();
	std::string GetName();
	int GetATK();
	void SetATK( int newATK);
	bool GetIsPlayer();
	void TakeDamage(int damage);
	void SetHP(int set);
	void SetDEF(int set);
	bool isPlayer;
	int ATK;
	std::string name;
	int maxHP;
	int currHP;
	int maxDEF;
	int currDEF;


};
#endif