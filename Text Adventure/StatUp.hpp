#ifndef STATUP_HPP
#define STATUP_HPP
#include "Item.hpp"
#include "Player.hpp"

class StatUp : public Item 
{
public:
	StatUp(std::string name, std::string description, int value, std::string stat);
	void UseItem(Player* player);
private:
	std::string name;
	std::string description;
	int value;
	std::string stat;
	
};
#endif