#ifndef ENCOUNTER_HPP
#define ENCOUNTER_HPP

#include <list>
#include "Enemy.hpp"
#include "Player.hpp"



class Encounter
{
public:
	Encounter(std::list<Enemy*> enemys, Player* human);
	bool Fight();
	void PlayerTurn();
	void EnemyTurns();
	void PrintEnemys(std::list<Enemy*> enemys);
    Enemy* GetEnemy(std::string name);
	bool GetIsBlocking();
	void SetBlocking(bool block);
	void CleanEnemys();
	void ResetFight();
	void FinalFight(std::string roomMateName);


private:
	std::list<Enemy*> enemysHold;
	std::list<Enemy*> enemys;
	Player* human;
	bool blocking = false;
};
#endif