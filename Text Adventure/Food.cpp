#include "Food.hpp"

Food::Food(std::string name, std::string description, int value) : Item(name, description)
{
	this->value = value;
}

void Food::UseItem(Player* player)
{
	std::cout << "ate a " << this->GetName() << std::endl;
	player->Heal(value);
}
