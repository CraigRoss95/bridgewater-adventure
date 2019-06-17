#ifndef SCROLL_HPP
#define SCROLL_HPP
#include "Item.hpp"
#include "Player.hpp"
#include "Move.hpp"


class Scroll : public Item 
{
public:
	Scroll(std::string name, std::string description, Move* move);
	void UseItem(Player* player);
	Move* GetMove();
private:
	std::string name;
	std::string description;
	Move* move;
	
};
#endif