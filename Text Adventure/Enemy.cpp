#include "Enemy.hpp"


Enemy::Enemy(int maxHP, int maxDEF, int ATK, std::string name, std::string attackText, std::string bio) : CombatUnit(maxHP,maxDEF,ATK,name)
{
	this->attackText = attackText;
	this->isPlayer = false;
	this->bio = bio;
}
std::string Enemy::GetAttackText()
{
	return this->attackText;
}
void Enemy::PrintStats()
{
	std::cout << std::endl << this->name << std::endl;
	std::cout << "Info: " << this->bio << std::endl;
	std::cout << "DEF = " <<this->maxDEF << "\nATK = " << this->ATK << std::endl;
	std::cout << std::endl;
}