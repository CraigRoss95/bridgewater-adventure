#ifndef MOVE_HPP
#define MOVE_HPP

#include <string>


class Move
{
public:
	Move(std::string name, std::string discription, int cost);
	std::string GetName();
	void Use();
	int GetCost();

	
private:
	int cost;
	std::string name;
	std::string discription;
};
#endif