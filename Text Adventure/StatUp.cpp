#include "StatUp.hpp"

StatUp::StatUp(std::string name, std::string description, int value, std::string stat) : Item(name, description)
{
	this->value = value;
	this->stat = stat;
}

void StatUp::UseItem(Player* player)
{
	std::cout << "equiped the " << this->GetName() << std::endl;
	if(this->stat == "hp")
	{

		player->SetMaxHP(value + player->GetMaxHP());
		std::cout<< "hit points went up by " << this->value;
	}
	else if(this->stat == "ap")
	{
		player->SetMaxAP(value + player->GetMaxAP());
		std::cout<< "ability points went up by " << this->value;
	}
	else if(this->stat == "def")
	{
	player->SetDEF(value + player->GetCurrDEF());
	std::cout<< "defence went up by " << this->value;
	}
	else if(this->stat == "atk")
	{
		player->SetATK(value + player->GetATK());
		std::cout<< "attack went up by " << this->value;
	}
	else
	{
		std::cout << "error useing item";
	}
}
