#ifndef DRINK_HPP
#define DRINK_HPP
#include "Item.hpp"
#include "Player.hpp"

class Drink : public Item 
{
public:
	Drink(std::string name, std::string description, int value);
	void UseItem(Player* player);
private:
	std::string name;
	std::string description;
	int value;
	
};
#endif