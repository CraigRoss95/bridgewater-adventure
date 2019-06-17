#ifndef FOOD_HPP
#define FOOD_HPP
#include "Item.hpp"
#include "Player.hpp"

class Food : public Item 
{
public:
	Food(std::string name, std::string description, int value);
	void UseItem(Player* player);
private:
	std::string name;
	std::string description;
	int value;
	
};
#endif