#include "Encounter.hpp"

Encounter::Encounter(std::list<Enemy*> enemys, Player* human)
{
	this->enemys = enemys;
	this->human = human;
	this->enemysHold = enemys;
}

bool Encounter::Fight() {
	std::list<Enemy*> enemysCopy = enemys;
	while (enemysCopy.size() > 0)
	{
		std::cout << enemysCopy.front()->GetName() << " ";
		if (enemysCopy.size() == 2)
		{
			std::cout << " and ";
		}
		enemysCopy.pop_front();
	}
	if (enemys.size() > 0)
	{
		std::cout << "approachs\n\n";
	}
	while (enemys.size() > 0)
	{
		if (blocking)
		{
			SetBlocking(false);
			human->SetDEF(human->GetCurrDEF() - 3);
		}

		PlayerTurn();
		CleanEnemys();
		EnemyTurns();
		if (human->GetCurrHP() <= 0)
		{
			ResetFight();
			return true;
		}
	}
	return false;
}
void Encounter::CleanEnemys()
{
	std::list<Enemy*> enemysCopy = this->enemys;
	std::list<Enemy*> write;
	while (enemysCopy.size() > 0)
	{
		if (enemysCopy.front()->GetCurrHP() > 0)
		{
			write.push_front(enemysCopy.front());
		}
		else
		{
			std::cout << enemysCopy.front()->GetName() << " became tame!\n";
		}
		enemysCopy.pop_front();
	}
	this->enemys = write;
}
void Encounter::EnemyTurns()
{	std::list<Enemy*> enemysCopy = enemys;

	while (enemysCopy.size() > 0 && human->GetCurrHP() > 0)
	{
		human->TakeDamage(enemysCopy.front()->GetATK());
		if (blocking)
		{
			std::cout << enemysCopy.front()->GetAttackText() << " dealing " << enemysCopy.front()->GetATK() - 3 << " damage\n";
			enemysCopy.pop_front();
		}
		else
		{
			std::cout << enemysCopy.front()->GetAttackText() << " dealing " << enemysCopy.front()->GetATK() << " damage\n";
			enemysCopy.pop_front();
		}
	}
	std::cout << std::endl;
}
void Encounter::ResetFight()
{
	this->enemys = this->enemysHold;
	std::list<Enemy*> enemysCopy = this->enemys;

	while (enemysCopy.size() > 0)
	{
		enemysCopy.front()->SetHP(enemysCopy.front()->GetMaxHP());
		this->enemys.push_front(enemysCopy.front());
		enemysCopy.pop_front();
	}

}
void Encounter::PlayerTurn()
{
	std::list<Enemy*> enemysCopy = enemys;
	std::string command;
	enemysCopy = enemys;

	bool playerTurn = true;
	while (playerTurn)
	{
		std::cout << std::endl;
		PrintEnemys(enemys);
		std::cout << std::endl << std::endl;
		human->ShowStatsQuick();
		std::cout << "what do? :";
		std::cout << "[attack] [look] [special] [block] [item]\n";
		getline(std::cin, command);
		if (command == "attack" || command == "a")
		{
			if (enemys.size() != 1)
			{
				bool enemyPicked = false;
				while (enemyPicked == false) {
					std::cout << "who do you wish to attack?: ";
					getline(std::cin, command);
					enemysCopy = enemys;
					if (command == "back")
					{
						enemyPicked = true;
					}
					while (enemysCopy.size() > 0 && command != "back" && enemyPicked == false)
					{
						if (enemysCopy.front()->GetName() == command || (1 == command.length() && command.at(0) == enemysCopy.front()->GetName().at(0)))
						{
							enemysCopy.front()->TakeDamage(human->GetATK());
							std:: cout << "\nyou attack " << enemysCopy.front()->GetName() << " for " << human->GetATK() - enemysCopy.front()->GetCurrDEF() << " damage\n\n";
							enemyPicked = true;
							playerTurn = false;
						}
						enemysCopy.pop_front();
					}
				}

			}
			else
			{
				enemys.front()->TakeDamage(human->GetATK());
				std:: cout << "\nyou attack " << enemys.front()->GetName() << " for " << human->GetATK() - enemys.front()->GetCurrDEF() << " damage\n\n";
				playerTurn = false;
			}
		}

		else if (command == "special" || command == "s")
		{
			std::string moveName;
			int power;
			int APUse;
			bool attackPicked = false;
			while (attackPicked == false)
			{	human->PrinSpecials();
				std::cout << "name special: ";
				getline(std::cin, command);
				if (human->UseMove(command, enemys) == true)
				{
					attackPicked = true;
					playerTurn = false;
				}
				else if (command == "back" || command == "b")
				{
					attackPicked = true;
				}
			}
			if (attackPicked == false)
			{
				std::cout << "invalad move!\n";
			}
		}






		else if (command == "look" || command == "l")
		{
			bool enemyPicked = false;
			while (enemyPicked == false)
			{
				std::cout << "Look at who?: ";
				getline(std::cin, command);
				if (command != "back")
				{
					enemysCopy = enemys;
					while (enemysCopy.size() > 0)
					{
						//enemysCopy.front()-
						if (enemysCopy.front()->GetName() == command || (1 == command.length() && command.at(0) == enemysCopy.front()->GetName().at(0)))
						{
							enemysCopy.front()->PrintStats();
							enemyPicked = true;
							playerTurn = false;
						}
						enemysCopy.pop_front();
					}

				}
				else
				{
					enemyPicked = true;
				}
			}
		}

		else if (command == "item" || command == "i")
		{
			bool optionPicked = false;
			bool itemPicked = false;
			while (itemPicked == false) {
				human->PrintInventory();
				std::cout << "what would you like to use?: ";
				getline(std::cin, command);
				if (human->UseItem(command))
				{
					itemPicked = true;
					optionPicked = true;
				}
				else if (command == "back" || command == "b")
				{
					itemPicked = true;

				}
				else
				{
					std::cout << "you do not have any " << command << std::endl;
				}
			}
			if (optionPicked)
			{
				playerTurn = false;
			}
		}




		else if (command == "block" || command == "b")
		{
			SetBlocking(true);
			human->SetDEF(human->GetCurrDEF() + 3);
			playerTurn = false;
		}
		else
		{
			std::cout << "please re enter command \n";
		}

	}
}

void Encounter::PrintEnemys(std::list<Enemy*> enemys)
{
	std::list<Enemy*> enemysCopy = enemys;
	while (enemysCopy.size() != 0)
	{
		if (enemysCopy.front()->GetIsPlayer() == false)
		{
			std::cout << enemysCopy.front()->GetName();
			std::cout << "(curr HP = " << enemysCopy.front()->GetCurrHP() << ")  ";
		}
		enemysCopy.pop_front();
	}
	std::cout << std::endl;
}
Enemy* Encounter::GetEnemy(std::string name)
{
	std::list<Enemy*> enemysCopy = enemys;
	while (enemysCopy.size() > 0)
	{
		if (enemysCopy.front()->GetName() == name && enemysCopy.front()->GetIsPlayer() == false)
		{

			return enemysCopy.front();
		}
		enemysCopy.pop_front();
	}
	return nullptr;
}

bool Encounter::GetIsBlocking()
{
	return this->blocking;
}
void Encounter::SetBlocking(bool block)
{
	this->blocking = block;
}
void Encounter::FinalFight(std::string roomMateName)
{	//(int maxHP, int maxDEF, int ATK, std::string name, int maxAP) : CombatUnit(maxHP, maxDEF, ATK, name)
	bool failedOnce = false;
	Enemy *FinalBoss = new Enemy(1000000000, 0, 20, "the bridgewater triangle", "decemates you", "the one behinde it all");

	this->enemys.push_back(FinalBoss);
	this->Fight();

	Player *finalPlayer = new Player(120, 10, 75, human->GetName(), 50);
	human = finalPlayer;

	std::list<std::string> midBattleCutscene;
	midBattleCutscene.push_back("its over...");
	midBattleCutscene.push_back("you lost to a shape!");
	midBattleCutscene.push_back("you pick yourself up and prepare to be struck down again");
	midBattleCutscene.push_back("prepared to go down fighting you hear a familiar voice");
	midBattleCutscene.push_back("\"now is no time for a nap lets end this\n");
	midBattleCutscene.push_back("its " + roomMateName + " and all of the others freed from the curse");
	midBattleCutscene.push_back("\ncome on " + human->GetName() + " lets finish this for good\n");
	midBattleCutscene.push_back(roomMateName + " gets you on your feed and you walk back twords the triangle");


	std::list<std::string> freindDamageText;
	std::list<int> freindDamageNumbers;

	freindDamageText.push_back("david and ali slam down with davids laptop");
	freindDamageNumbers.push_back(50);

	freindDamageText.push_back("craig memes on the triangle");
	freindDamageNumbers.push_back(69);

	freindDamageText.push_back("votie dabs as hard as they can");
	freindDamageNumbers.push_back(30);

	freindDamageText.push_back("cj scrums to the triangle and wails on it");
	freindDamageNumbers.push_back(50);

	freindDamageText.push_back("criss lays the smackdown with his \"bass\"");
	freindDamageNumbers.push_back(70);

	freindDamageText.push_back("throws a whole pizza at the triangle");
	freindDamageNumbers.push_back(40);

	freindDamageText.push_back("the local wildlife mauls the triangle");
	freindDamageNumbers.push_back(150);

	freindDamageText.push_back("the computer science dept. comes in for a tag team wrestling move");
	freindDamageNumbers.push_back(120);

	freindDamageText.push_back("griff comes in for a gank");
	freindDamageNumbers.push_back(60);

	freindDamageText.push_back("the dnd club comes rolls for dammage");
	freindDamageNumbers.push_back(100);

	freindDamageText.push_back("fred clark is back! he uppercuts");
	freindDamageNumbers.push_back(50);

	freindDamageText.push_back(roomMateName + " and suckerpunch the triangle");
	freindDamageNumbers.push_back(50);


	std::string enter;
	while (midBattleCutscene.size() > 0)
	{
		std::cout << midBattleCutscene.front() << std::endl;
		getline(std::cin, enter);
		midBattleCutscene.pop_front();
		std::cout << std::endl << std::endl;
	}


	this->enemys.push_back(FinalBoss);
	while (freindDamageText.size() > 0)
	{
		std::cout << "your freinds stand by you\n";

		PlayerTurn();

		std::cout << freindDamageText.front();
		FinalBoss->TakeDamage(freindDamageNumbers.front());
		std::cout << " dealing " << freindDamageNumbers.front() << " damage\n";

		freindDamageText.pop_front();
		freindDamageNumbers.pop_front();
		CleanEnemys();
		EnemyTurns();
		if (human->GetCurrHP() < 0)
		{
			std::cout << "\nyour freinds help you back up(30hp restored!)\n";
			human->SetHP(human->GetCurrHP() + 30);
		}
	}
	PlayerTurn();
	CleanEnemys();
	EnemyTurns();
	std::cout << "you all come in for one final attack dealing " << FinalBoss->GetCurrHP() << " damage!";
	FinalBoss->TakeDamage(FinalBoss->GetCurrHP());
	CleanEnemys();
}
