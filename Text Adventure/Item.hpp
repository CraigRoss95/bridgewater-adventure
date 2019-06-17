#ifndef ITEM_HPP
#define ITEM_HPP
#include "Player.hpp"

class Player;

class Item 
{
public:
	Item(std::string name, std::string description);
	virtual void UseItem(Player* player) = 0;
	std::string GetName();
	std::string GetDescription();
private:
	std::string name;
	std::string description;
};
#endif