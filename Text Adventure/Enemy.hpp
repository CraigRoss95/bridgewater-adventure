#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "CombatUnit.hpp"

class Enemy : public CombatUnit
{
public:
	Enemy(int maxHP, int maxDEF, int ATK, std::string name, std::string attackText, std::string bio);
	std::string GetAttackText();
	int GetAttackRNG();
	std::string GetBio();
	void PrintStats();
	
private:
	std::string attackText;
	std::string bio;
};
#endif