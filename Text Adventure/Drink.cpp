#include "Drink.hpp"

Drink::Drink(std::string name, std::string description, int value) : Item(name, description)
{
	this->value = value;
}

void Drink::UseItem(Player* player)
{
	std::cout << "drank a " << this->GetName() << std::endl;
	player->APHeal(value);
}
