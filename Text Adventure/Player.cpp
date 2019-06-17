#include "Player.hpp"

Player::Player(int maxHP, int maxDEF, int ATK, std::string name, int maxAP) : CombatUnit(maxHP, maxDEF, ATK, name)
{
	this->maxAP = maxAP;
	this->currAP = maxAP;
	this->isPlayer = true;
}
void Player::SetAP(int ap)
{
	this->currAP = ap;
}
void Player::SetMaxAP(int ap)
{
	this->maxAP = ap;
}
int Player::GetMaxAP()
{
	return this->maxAP;
}

int Player::GetCurrAP()
{
	return currAP;
}
void Player::UseAP(int ap)
{
	currAP = currAP - ap;
}
void Player::Heal(int healed)
{
	if (this->GetCurrHP() + healed > this->GetMaxHP())
	{
		this->SetHP(this->GetMaxHP());
	}
	else
	{
		this->SetHP(this->GetCurrHP() + healed);
	}
}
void Player::AddItem (Item* newItem)
{
	this->inventory.push_front(newItem);
}
std::list<Item*> Player::RemoveItem(Item* item)
{
	bool itemPicked = false;
	std::list<Item*> inventoryCopy = inventory;
	std::list<Item*> wright;
	while (inventoryCopy.size() > 0)
	{
		if (item->GetName() == inventoryCopy.front()->GetName() && itemPicked == false)
		{
			itemPicked = true;
			inventoryCopy.pop_front();
		}
		else
		{
			wright.push_front(inventoryCopy.front());
			inventoryCopy.pop_front();

		}
	}
	return wright;
}

bool Player::UseItem(std::string itemName)
{
	bool itemFound = false;
	std::list<Item*> inventoryCopy = inventory;
	while (inventoryCopy.size() > 0 && itemFound == false)
	{
		if ((inventoryCopy.front()->GetName() ==  itemName || (1 == itemName.length() && itemName.at(0) == inventoryCopy.front()->GetName().at(0))) && itemFound == false)
		{
			inventoryCopy.front()->UseItem(this);
			inventory = RemoveItem(inventoryCopy.front());
			itemFound = true;
		}
		inventoryCopy.pop_front();
	}
	return itemFound;
}

bool Player::LookItem(std::string itemName)
{
	bool itemFound = false;
	std::list<Item*> inventoryCopy = inventory;
	while (inventoryCopy.size() > 0)
	{
		if ((inventoryCopy.front()->GetName() ==  itemName || (inventoryCopy.front()->GetName().at(0) == itemName.at(0) && itemName.length() == 1)) && itemFound == false)
		{
			std::cout << inventoryCopy.front()->GetDescription();
			itemFound = true;
		}
		inventoryCopy.pop_front();
	}
	return itemFound;
}
void Player::PrintInventory()
{
	int counter = 0;
	std::list<Item*> inventoryCopy = inventory;
	while (inventoryCopy.size() > 0)
	{
		if(counter % 3 == 0)
		{
			std::cout << std::endl;
		}
		std::cout << "[" << inventoryCopy.front()->GetName() << "]  ";
		inventoryCopy.pop_front();
		counter++;
	}
	std::cout << std::endl << std::endl;
}
void Player::APHeal(int healed)
{
	if (this->GetCurrAP() + healed > this->GetMaxAP())
	{
		this->SetAP(this->GetMaxAP());
	}
	else
	{
		this->SetAP(this->GetCurrAP() + healed);
	}
}
void Player::ShowStatsQuick()
{
	int hp = this->GetCurrHP();
	int hpEmpty = this->GetMaxHP() - hp;

	int ap = this->GetCurrAP();
	int apEmpty = this->GetMaxAP() - ap;
	std::cout << "-=" << this->GetName() << "=-\n";
	std::cout << "[HP = " << this->GetCurrHP() << "/" << this->GetMaxHP() << "]";
	for (int i = 0; i < hp; i++)
	{
		std::cout << "\\";
	}
	for (int i = 0; i < hpEmpty; i++)
	{
		std::cout << "-";
	}

	std::cout <<  "\n    [AP = " << this->GetCurrAP() << "/" << this->GetMaxAP() << "]";
	for (int i = 0; i < ap; i++)
	{
		std::cout << "/";
	}
	for (int i = 0; i < apEmpty; i++)
	{
		std::cout << "-";
	}

	std::cout << std::endl << std::endl;
}
void Player::ShowStatsFull()
{
	int hp = this->GetCurrHP();
	int hpEmpty = this->GetMaxHP() - hp;

	int ap = this->GetCurrAP();
	int apEmpty = this->GetMaxAP() - ap;
	std::cout << "-=" << this->GetName() << "=-\n";
	std::cout << "[HP = " << this->GetCurrHP() << "/" << this->GetMaxHP() << "]";
	for (int i = 0; i < hp; i++)
	{
		std::cout << "\\";
	}
	for (int i = 0; i < hpEmpty; i++)
	{
		std::cout << "-";
	}

	std::cout <<  "\n    [AP = " << this->GetCurrAP() << "/" << this->GetMaxAP() << "]";
	for (int i = 0; i < ap; i++)
	{
		std::cout << "/";
	}
	for (int i = 0; i < apEmpty; i++)
	{
		std::cout << "-";
	}
	std::cout << "\nDEF = " << this->GetCurrDEF() << "    ATK = " << this->GetATK();

	std::cout << std::endl << std::endl;
}
void Player::Learn(Move* move)
{
	this->knownMoves.push_front(move);
}
bool Player::UseMove(std::string moveName, std::list<Enemy*> enemyList)
{
	std::list<Move*> knownMovesCopy = this->knownMoves;
	bool moveUsed = false;
	while (knownMovesCopy.size() > 0)
	{
		if (moveUsed == false && (knownMovesCopy.front()->GetName() == moveName || (moveName.length() == 1 && knownMovesCopy.front()->GetName().at(0) == moveName.at(0)) && knownMovesCopy.front()->GetCost() <= this->currAP))
		{
			if (Cast(knownMovesCopy.front(), enemyList))
			{
				moveUsed = true;
			}
		}
		knownMovesCopy.pop_front();
	}
	if (moveUsed == true)
	{
		return true;
	}
	else
	{
		std::cout << "casting failed\n";
		return false;
	}
}
Enemy* Player::PickEnemy(std::list<Enemy*> enemyList)
{
	std::string command;
	bool enemySelected = false;
	while (enemySelected == false)
	{
		std::list<Enemy*> enemyListCopy = enemyList;
		std::cout << "which enenmy: ";
		getline(std::cin, command);
		if (command != "back")
		{
			while (enemyListCopy.size() > 0)
			{
				if (enemyListCopy.front()->GetName() == command || (command.length() == 1 && command.at(0) == enemyList.front()->GetName().at(0)))
				{
					this->target = enemyListCopy.front();
					return enemyListCopy.front();
					enemySelected = true;
				}
				enemyListCopy.pop_front();
			}
		}
		else
		{
			std::cout << "did not cast\n";
			return nullptr;
		}
	}


}
bool Player::Cast(Move* move, std::list<Enemy*> enemyList)
{
	bool hasNotCast = true;;;;
	while (hasNotCast) {
		if (move->GetName() == "slam" || move->GetName() == "s" )
		{

			if (PickEnemy(enemyList) != nullptr)
			{
				this->UseAP(5);
				target->TakeDamage(10);
				std::cout << "you slam " << target->GetName() << " for " << 10 - target->GetCurrDEF() << " damage\n";
				return true;
			}
			else
			{
				return false;
				std::cout << "could not find enemy\n";
			}
		}
		else if (move->GetName() == "dab" || move->GetName() == "d")
		{
			this->UseAP(0);
			if (this->GetCurrAP() + 5 > this->GetMaxAP())
			{
				this->SetAP(this->GetMaxAP());
			}
			else
			{
				this->SetAP(this->GetCurrAP() + 5);
			}
			return true;
		}
		else if ((move->GetName() == "firewave" || move->GetName() == "f") && this->GetCurrAP() >= 5)
		{
			this->UseAP(5);
			AOE(enemyList , 5);
			return true;
		}
		else if ((move->GetName() == "break" || move->GetName() == "b") && this->GetCurrAP() >= 7)
		{
			if (PickEnemy(enemyList) != nullptr)
			{
				this->UseAP(7);
				target->SetHP(target->GetCurrHP() - 12);
				std::cout << "you break the " << target->GetName() << "'s armor for " << 12 << " damage\n";
				return true;
			}
			else
			{
				return false;
				std::cout << "could not find enemy\n";
			}


		}
		else if ((move->GetName() == "voodoo" || move->GetName() == "v") && this->GetCurrHP() >= 10)
		{
			if (PickEnemy(enemyList) != nullptr)
			{
				this->SetHP(GetCurrHP() - 10);
				target->TakeDamage(20);
				std::cout << "cast blood magic on" << target->GetName() << " dealing " << 20 - target->GetCurrDEF() << " damage\n";
				return true;
			}
			else
			{
				return false;
				std::cout << "could not find enemy\n";
			}

		}
		else if ((move->GetName() == "heal" || move->GetName() == "h") && this->GetCurrAP() > 5)
		{
				this->SetAP(this->GetCurrAP() - 5);
				if((this->GetCurrHP() + 10) > this->GetMaxHP())
				{
					this->SetHP(this->GetMaxHP());
				}
				else
				{
					this->SetHP(this->GetCurrHP() + 10);
				}
				std::cout << "you heal yourself\n";
				return true;

		}

		else
		{
			std::cout << "not enough AP or HP\n";
			return false;
		}
	}
}

void Player::AOE(std::list<Enemy*> enemyList, int damage)
{
	std::list<Enemy*> enemyListCopy = enemyList;
	while (enemyListCopy.size() > 0)
	{
		enemyListCopy.front()->TakeDamage(damage);
		enemyListCopy.pop_front();
	}
}
void Player::PrinSpecials()
{
	std::list<Move*> knownMovesCopy = knownMoves;
	while (knownMovesCopy.size() > 0)
	{
		std::cout << "[" << knownMovesCopy.front()->GetName() << "(" << knownMovesCopy.front()->GetCost() << ")" << "] ";
		knownMovesCopy.pop_front();
	}
}
