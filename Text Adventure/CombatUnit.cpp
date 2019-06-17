#include "CombatUnit.hpp"

CombatUnit::CombatUnit(int maxHP,int maxDEF, int ATK, std::string name)
{
	this->ATK = ATK;
	this->maxHP = maxHP;
	this->currHP = maxHP;
	this->maxDEF = maxDEF;
	this->currDEF = maxDEF;
	this->name = name;
}

int CombatUnit::GetMaxHP()
{
	return this->maxHP;
}
void CombatUnit::SetMaxHP(int set)
{
	this->maxHP = set;
}
int CombatUnit::GetCurrHP()
{
	return this->currHP;
}

int CombatUnit::GetMaxDEF()
{
	return this->maxDEF;
}

int CombatUnit::GetCurrDEF()
{
	return this->currDEF;
}
std::string CombatUnit::GetName()
{
	return this->name;
}
int CombatUnit::GetATK()
{
	return this->ATK;
}
void CombatUnit::SetATK( int newATK)
{
	this->ATK = newATK;
}
bool CombatUnit::GetIsPlayer()
{
	return this->isPlayer;
}
void CombatUnit::SetHP( int set)
{
	this->currHP = set;
}
void CombatUnit::SetDEF(int set)
{
	this->currDEF = set;
}
void CombatUnit::TakeDamage(int damage)
{
	damage = damage - this->currDEF;
	if(damage < 0)
	{
		damage = 0;
	}
	this->currHP = this->currHP - damage;
	
	
}